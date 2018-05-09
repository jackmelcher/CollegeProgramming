/*
 | Jack Melcher
 | 67574625
 | EECS 113 Assignment 3
 | 4/28/2016
 | 
 | file: assignment3.c
 | this code performs keypad scanning and puts the ASCII of 
 | the detected key on P1 to be displayed on the connected 
 | LEDs.
 | compile as follows:
 | To compile, use the commands
 | % sdcc --model-small -mmcs51 --Werror -I. -c assignment3.c
 | % sdcc --model-small -mmcs51 --Werror -I. --iram-size 0x100 --code-size 0x1000 --code-loc 0x0000 --stack-loc 0x30 --data-loc 0x30 --out-fmt-ihx assignment3.rel
 | % packihx assignment3.ihx > assignment3.hex
 */
#include <8051.h>

//LCD Defines
#define DB P1
#define RS P3_3
#define E P3_2

#define clear P2_0  // SW0
#define msg1 P2_1   // SW1
#define msg2 P2_2   // SW2

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

void Main(void) {
	unsigned char key = 'A';
	unsigned int digits_a[5] = {0, 0, 0, 0, 0}, number_a = 0, numberOfDigitsA = 0;
	unsigned int digits_b[5] = {0, 0, 0, 0, 0}, number_b = 0, numberOfDigitsB = 0;
	int digit, check, i, j, sum_check = 0, sum_digit;
	unsigned int sum = 0;

	//Setup LCD
	functionSet();
	entryModeSet(); // increment and no shift
	displayOnOffControl(1, 1, 1); // display on, cursor on and blinking on
	
	//Calculator Loop
	while (1) {

		//Obtain First Number
		while (1) {

			//obtain character from keypad
			keypad();
			key = P1;

			if (key == '+') {
				//Print '+' to LCD
				sendChar(key);
				break;
			}

			//if character is a digit
			if (numberOfDigitsA < 5) {
				switch (key) {
				case '0':
					digits_a[numberOfDigitsA] = 0;
					numberOfDigitsA++;
					break;
				case '1':
					digits_a[numberOfDigitsA] = 1;
					numberOfDigitsA++;
					break;
				case '2':
					digits_a[numberOfDigitsA] = 2;
					numberOfDigitsA++;
					break;
				case '3':
					digits_a[numberOfDigitsA] = 3;
					numberOfDigitsA++;
					break;
				case '4':
					digits_a[numberOfDigitsA] = 4;
					numberOfDigitsA++;
					break;
				case '5':
					digits_a[numberOfDigitsA] = 5;
					numberOfDigitsA++;
					break;
				case '6':
					digits_a[numberOfDigitsA] = 6;
					numberOfDigitsA++;
					break;
				case '7':
					digits_a[numberOfDigitsA] = 7;
					numberOfDigitsA++;
					break;
				case '8':
					digits_a[numberOfDigitsA] = 8;
					numberOfDigitsA++;
					break;
				case '9':
					digits_a[numberOfDigitsA] = 9;
					numberOfDigitsA++;
					break;
				default:
					break;
				}
				//Print number to LCD
				sendChar(key);
			}

		}

		//Convert chars into int
		number_a = 0;
		check = numberOfDigitsA - 1;
		digit = 1;
		for (i = 0; i < numberOfDigitsA; i++) {
			digit = 1;
			for (j = 0; j < check; j++) {
				digit *= 10;
			}
			number_a += digits_a[i] * digit;
			check--;
		}

		//Obtain Second Number
		while (1) {

			//obtain character from keypad
			keypad();
			key = P1;

			if (key == '=') {
				//Print '=' to LCD
				sendChar(key);
				break;
			}

			//if character is a digit
			if (numberOfDigitsB < 5) {
				switch (key) {
				case '0':
					digits_b[numberOfDigitsB] = 0;
					numberOfDigitsB++;
					break;
				case '1':
					digits_b[numberOfDigitsB] = 1;
					numberOfDigitsB++;
					break;
				case '2':
					digits_b[numberOfDigitsB] = 2;
					numberOfDigitsB++;
					break;
				case '3':
					digits_b[numberOfDigitsB] = 3;
					numberOfDigitsB++;
					break;
				case '4':
					digits_b[numberOfDigitsB] = 4;
					numberOfDigitsB++;
					break;
				case '5':
					digits_b[numberOfDigitsB] = 5;
					numberOfDigitsB++;
					break;
				case '6':
					digits_b[numberOfDigitsB] = 6;
					numberOfDigitsB++;
					break;
				case '7':
					digits_b[numberOfDigitsB] = 7;
					numberOfDigitsB++;
					break;
				case '8':
					digits_b[numberOfDigitsB] = 8;
					numberOfDigitsB++;
					break;
				case '9':
					digits_b[numberOfDigitsB] = 9;
					numberOfDigitsB++;
					break;
				default:
					break;
				}
				//Print char to LCD
				sendChar(key);
			}

		}

		//Convert chars into int
		number_b = 0;
		check = numberOfDigitsB - 1;
		digit = 1;
		for (i = 0; i < numberOfDigitsB; i++) {
			digit = 1;
			for (j = 0; j < check; j++) {
				digit *= 10;
			}
			number_b += digits_b[i] * digit;
			check--;
		}

		//Print Answer to Screen
		sum = number_a + number_b;

		digit = 10000;
		sum_check = 0;
		for (i = 0; i < 5; i++) {
			sum_digit = sum / digit;

			if (sum_check == 0 && sum_digit != 0) {
				sum_check++;
			}
			if (sum_check > 0) {
				key = (sum_digit % 10) + '0';

				//Print char to LCD
				sendChar(key);
			}
			digit /= 10;
		}

		//Anymore inputs by the keypad will reset the calculator
		keypad();
		clearDisplay();
		key = 'A';
		digits_a[0] = 0;
		digits_a[1] = 0;
		digits_a[2] = 0;
		digits_a[3] = 0;
		digits_a[4] = 0;
		number_a = 0;
		numberOfDigitsA = 0;
		digits_b[0] = 0;
		digits_b[1] = 0;
		digits_b[2] = 0;
		digits_b[3] = 0;
		digits_b[4] = 0;
		number_b = 0;
		numberOfDigitsB = 0;
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
		{'3','2','1'},
		{'6','5','4'},
		{'9','8','7'},
		{'=','0','+'}
		};
	unsigned char i;
	unsigned char gotkey = 0;
	while(1){
		row = 0xf7;  // The first row (connected to P0.3) will be zero
		
		for (i=0;i<4;++i){ // loop over the 4 rows
			
			P0 = 0xff;     // Initialize the 4 rows to '1' and set the column ports to inputs
			P0 = P0 & row; // clear one row at a time
			col = P0 & 0x70;  // Read the 3 columns
			if (col != 0x70){ // If any column is zero i.e. a key is pressed
				col = (~col) & 0x70;  // because the selected column returns zero
				col = col >> 5;       // The column variable now contain the number of the selected column
				gotkey = keypad[i][col]; // Get the ASCII of the corresponding pressed key
				break;  // Since a key was detected -> Exit the for loop
			}
			row = row >> 1;   // No key is detected yet, try the next row
			row = row | 0xf0; // Only one of the least 4 significant bits is '0' at a time 
			
		}
		
		if (gotkey != 0){break;}  // Since a key was detected -> exit the while loop
		
	}

	P1 = gotkey;  // Send the detected key to the output
			
}

//Additional Functions
