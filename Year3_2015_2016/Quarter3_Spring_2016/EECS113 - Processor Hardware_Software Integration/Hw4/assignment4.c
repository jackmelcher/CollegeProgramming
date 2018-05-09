/*
| Jack Melcher
| 67574625
| EECS 113 Assignment 4
| 5/15/2016
|
| file: assignment4.c
| this code performs keypad scanning and puts the ASCII of
| the detected key on P1 to be displayed on the connected
| LEDs.
| compile as follows:
| To compile, use the commands
| % sdcc --model-small -mmcs51 --Werror -I. -c assignment4.c
| % sdcc --model-small -mmcs51 --Werror -I. --iram-size 0x100 --code-size 0x1000 --code-loc 0x0000 --stack-loc 0x30 --data-loc 0x30 --out-fmt-ihx assignment4.rel
| % packihx assignment4.ihx > assignment4.hex
*/
#include <8051.h>

//LCD Defines
#define DB P1
#define RS P2_1
#define E P2_0

//Interrupt Defines
#define SW0 P3_2  // INT0
#define SW1 P3_3   // INT1

//LCD Functions
void returnHome(void);
void entryModeSet();
void displayOnOffControl(__bit display, __bit cursor, __bit blinking);
void cursorOrDisplayShift(__bit sc, __bit rl);
void functionSet(void);
void clearDisplay(void);
void setDdRamAddress(char address);

void sendChar(char c);
void sendString(char* str);
void delay(void);
void big_delay(void);

//Keypad Functions
void keypad(void);

//Timer Functions
void timer_delay(void);

//Helper Functions
void NumToChar(unsigned char num, unsigned char nums[2]);

//Global Variables
//Variables used for keeping count
__data __at (0x7A) unsigned char hour;
__data __at (0x7B) unsigned char minute;
__data __at (0x7C) unsigned char second;
__data __at(0x7D) unsigned char month;
__data __at(0x7E) unsigned char day;
__data __at(0x7F) unsigned char year;



void main(void) {

	//Variables used for keeping count
	//unsigned char hour = 0, minute = 0, second = 0;
	//unsigned char month = 1, day = 1, year = 0;

	//Variables for printing to screen/
	unsigned char hours[2] = { 0, 0 }, minutes[2] = { 0, 0 }, seconds[2] = { 0, 0 };
	unsigned char months[2] = { 0, 0 }, days[2] = { 0, 0 }, years[2] = { 0, 0 };

	//test
	hour = 0;
	minute = 0;
	second = 0;
	month = 1;
	day = 1;
	year = 0;

	IT0 = 1;   // make INT0 to edge triggered
	IT1 = 1;   // make INT1 to edge triggered
	IE = 0x85;  //enable external interrupt0 and external interrupt1

	//Setup LCD
	functionSet();
	entryModeSet(); // increment and no shift
	displayOnOffControl(1, 1, 1); // display on, cursor on and blinking on

	//Set Default Time and Date
	sendString("00:00:00");
	setDdRamAddress(0x40); // set address to start of second line
	sendString("01-01-00");

	while (1) {
		//Wait ~1 second
		timer_delay();

		//Update Values
		second++;
		if (second == 60) {
			minute++;
			second = 0;
		}
		if (minute == 60) {
			hour++;
			minute = 0;
		}
		if (hour == 24) {
			hour = 0;
			day++;
		}
		if (month == 2) {
			if (day > 28) {
				month++;
				day = 1;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day > 30) {
				month++;
				day = 1;
			}
		}
		else {//month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12
			if (day > 31) {
				month++;
				day = 1;
			}
		}
		if (month == 13) {
			year++;
			month = 1;
		}
		if (year == 100) {
			year = 0;
		}

		
		//Update Chars
		NumToChar(second, seconds);
		NumToChar(minute, minutes);
		NumToChar(hour, hours);
		NumToChar(day, days);
		NumToChar(month, months);
		NumToChar(year, years);

		//Update Display
		setDdRamAddress(0x00);
		sendChar(hours[0]);
		sendChar(hours[1]);
		sendChar(':');
		sendChar(minutes[0]);
		sendChar(minutes[1]);
		sendChar(':');
		sendChar(seconds[0]);
		sendChar(seconds[1]);

		setDdRamAddress(0x40);
		sendChar(months[0]);
		sendChar(months[1]);
		sendChar('-');
		sendChar(days[0]);
		sendChar(days[1]);
		sendChar('-');
		sendChar(years[0]);
		sendChar(years[1]);
		
	}
}

// LCD Module instructions -------------------------------------------

void returnHome(void) {
	RS = 0;
	P1 = 0x02; // LCD command to return home (the first location of the first lcd line)
	E = 1;
	E = 0;
	big_delay(); // This operation needs a bigger delay
}

void entryModeSet() {
	RS = 0;
	P1 = 0x06;
	E = 1;
	E = 0;
	delay();
}

void displayOnOffControl(__bit display, __bit cursor, __bit blinking) {
	P1_7 = 0;
	P1_6 = 0;
	P1_5 = 0;
	P1_4 = 0;
	P1_3 = 1;
	P1_2 = display;
	P1_1 = cursor;
	P1_0 = blinking;
	E = 1;
	E = 0;
	delay();
}

void cursorOrDisplayShift(__bit sc, __bit rl) {
	RS = 0;
	P1_7 = 0;
	P1_6 = 0;
	P1_5 = 0;
	P1_4 = 1;
	P1_3 = sc;
	P1_2 = rl;
	P1_1 = 0;
	P1_0 = 0;
	E = 1;
	E = 0;
	delay();
}

void functionSet(void) {
	RS = 0;
	P1 = 0x38; // 8-bit mode, 2 lines LCD
	E = 1;
	E = 0;
	delay();
}

void clearDisplay(void) {
	RS = 0;
	P1 = 0x01; // command to clear LCD and return the cursor to the home position
	E = 1;
	E = 0;
	big_delay(); // This operation needs a bigger delay
}

void setDdRamAddress(char address) {  // Determine the place to place the next character - First LCD location address in 00h for line 1 and 40h for line 2
	RS = 0;
	P1 = address | 0x80;  // set the MSB to detect that this is an address
	E = 1;
	E = 0;
	delay();
}

// --------------------------------------------------------------------

void sendChar(char c) {  // Function to send one character to be displayed on the LCD
	RS = 1;
	P1 = c;
	E = 1;
	E = 0;
	delay();
}

void sendString(char* str) {  // Function to send a string of characters to be displayed on the lCD
	char c;
	while (c = *str++) {
		sendChar(c);
	}
}

void delay(void) {
	char c;
	for (c = 0; c < 50; c++);
}

void big_delay(void) {
	unsigned char c;
	for (c = 0; c < 255; c++);
}

//Keypad Functions
void keypad(void) {
	unsigned char row;   // Contains the required mask to clear one of the rows at a time
	unsigned char col;   // Contains the output of the columns
	unsigned char keypad[4][3] = {   // This array contains the ASCII of the keypad keys
		{ '3','2','1' },
		{ '6','5','4' },
		{ '9','8','7' },
		{ '#','0','*' }
	};
	unsigned char i;
	unsigned char gotkey = 0;
	while (1) {
		row = 0xf7;  // The first row (connected to P0.3) will be zero

		for (i = 0; i<4; ++i) { // loop over the 4 rows

			P0 = 0xff;     // Initialize the 4 rows to '1' and set the column ports to inputs
			P0 = P0 & row; // clear one row at a time
			col = P0 & 0x70;  // Read the 3 columns
			if (col != 0x70) { // If any column is zero i.e. a key is pressed
				col = (~col) & 0x70;  // because the selected column returns zero
				col = col >> 5;       // The column variable now contain the number of the selected column
				gotkey = keypad[i][col]; // Get the ASCII of the corresponding pressed key
				break;  // Since a key was detected -> Exit the for loop
			}
			row = row >> 1;   // No key is detected yet, try the next row
			row = row | 0xf0; // Only one of the least 4 significant bits is '0' at a time 

		}

		if (gotkey != 0) { break; }  // Since a key was detected -> exit the while loop

	}

	P1 = gotkey;  // Send the detected key to the output

}


//Timer Functions
void timer_delay(void) {

	unsigned char a = 20;
	TMOD = 0x01;
	while (a != 0) {
		TL0 = 0xAF;
		TH0 = 0x3C;
		TR0 = 1;
		while (!TF0);
		TR0 = 0;
		TF0 = 0;
		a = a - 1;

	}

}

//Helper Function
void NumToChar(unsigned char num, unsigned char nums[2]) {
	
	//first digit
	nums[0] = (num/10) + '0';

	//second digit
	nums[1] = (num%10) + '0';
}

// To make the interrupt work correctly with Edsim51
void _sdcc_gsinit_startup(void) {

	__asm
	mov sp, #0x5F
		__endasm;
	main();
}


//Interrupt of INT0
//Used to enter time setting mode 
void int0_isr(void) __interrupt(0) __using(1) {
	char count = 0;

	setDdRamAddress(count);

	while (SW0 == 0) {

		//acquire keypad input
		keypad();

		//0,1 : 3,4 : 6,7

		//Move cursor left
		if (P1 == '*') {
			count--;
			if (count < 0) {
				count = 7;
			}
			if (count == 2) {
				count = 1;
			}
			if (count == 5) {
				count = 4;
			}
			setDdRamAddress(count);
		}
		//Move cursor right
		else if (P1 == '#') {
			count++;
			if (count > 7) {
				count = 0;
			}
			if (count == 2) {
				count = 3;
			}
			if (count == 5) {
				count = 6;
			}
			setDdRamAddress(count);
		}
		//Inserting number for time
		else {
			switch (count) {
			//Hours
			case 0:
				if (P1 > '2') {
					break;
				}
				else {
					hour = (P1 - '0') * 10;
					sendChar(P1);
					count++;
					sendChar('0');
					setDdRamAddress(count);
					break;
				}
			case 1:
				if (P1 > '3' && hour >= 20) {
					break;
				}
				else {
					hour /= 10;
					hour *= 10;
					hour += (P1 - '0');
					sendChar(P1);
					count += 2;
					setDdRamAddress(count);
					break;
				}
			//Minutes
			case 3:
				if (P1 > '5') {
					break;
				}
				else {
					minute = (P1 - '0') * 10;
					sendChar(P1);
					count++;
					sendChar('0');
					setDdRamAddress(count);
					break;
				}
			case 4:
				minute /= 10;
				minute *= 10;
				minute += (P1 - '0');
				sendChar(P1);
				count += 2;
				setDdRamAddress(count);
				break;
			//Seconds	
			case 6:
				if (P1 > '5') {
					break;
				}
				else {
					second = (P1 - '0') * 10;
					sendChar(P1);
					count++;
					sendChar('0');
					setDdRamAddress(count);
					break;
				}
			case 7:
				second /= 10;
				second *= 10;
				second += (P1 - '0');
				sendChar(P1);
				count = 0;
				setDdRamAddress(count);
				break;
			}
		}
	}

}

//Interrupt of INT1
//Used to enter date setting mode
void int1_isr(void) __interrupt(2) __using(1) {
	
	char count = 0x40;

	setDdRamAddress(count);

	while (SW1 == 0) {

		//acquire keypad input
		keypad();

		//0,1 - 3,4 - 6,7

		//Move cursor left
		if (P1 == '*') {
			count--;
			if (count < 0x40) {
				count = 0x47;
			}
			if (count == 0x42) {
				count = 0x41;
			}
			if (count == 0x45) {
				count = 0x44;
			}
			setDdRamAddress(count);
		}
		//Move cursor right
		else if (P1 == '#') {
			count++;
			if (count > 0x47) {
				count = 0x40;
			}
			if (count == 0x42) {
				count = 0x43;
			}
			if (count == 0x45) {
				count = 0x46;
			}
			setDdRamAddress(count);
		}
		//Inserting number for time
		else {
			switch (count) {
			//Months
			case 0x40:
				if (P1 > '1') {
					break;
				}
				if (P1 == '0') {
					month = 1;
					sendChar(P1);
					count++;
					sendChar('1');

					setDdRamAddress(0x43);
					sendChar('0');
					sendChar('1');
					day = 1;

					setDdRamAddress(count);
					break;				
				}
				else {
					month = (P1 - '0') * 10;
					sendChar(P1);
					count++;
					sendChar('0');

					setDdRamAddress(0x43);
					sendChar('0');
					sendChar('1');
					day = 1;

					setDdRamAddress(count);
					break;
				}

			case 0x41:
				if (month >= 10 && P1 > '2') {
					break;
				}
				if (P1 == '0' && month < 10) {
					break;
				}
				else {
					month /= 10;
					month *= 10;
					month += (P1 - '0');
					sendChar(P1);
					count += 2;

					setDdRamAddress(0x43);
					sendChar('0');
					sendChar('1');
					day = 1;

					setDdRamAddress(count);
					break;
				}
			//Days
			case 0x43:
				if (P1 > '3') {
					break;
				}
				if (P1 > '2' && month == 2) {
					break;
				}
				if (P1 == '0') {
					day = 1;
					sendChar(P1);
					count++;
					sendChar('1');
					setDdRamAddress(count);
					break;
				}
				else {
					day = (P1 - '0') * 10;
					sendChar(P1);
					count++;
					sendChar('0');
					setDdRamAddress(count);
					break;
				}

			case 0x44:
				if (day >= 30 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && P1 > '1') {
					break;
				}
				if (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11) && P1 > '0') {
					break;
				}
				if (day >= 20 && month == 2 && P1 > '8') {
					break;
				}
				if (P1 == '0' && day < 10) {
					break;
				}
				else {
					day /= 10;
					day *= 10;
					day += (P1 - '0');
					sendChar(P1);
					count += 2;
					setDdRamAddress(count);
					break;
				}
				
			//Years
			case 0x46:
				year = (P1 - '0') * 10;
				sendChar(P1);
				count++;
				sendChar('0');
				setDdRamAddress(count);
				break;

			case 0x47:
				year /= 10;
				year *= 10;
				year += (P1 - '0');
				sendChar(P1);
				count = 0x40;
				setDdRamAddress(count);
				break;
			}
		}
	}
}