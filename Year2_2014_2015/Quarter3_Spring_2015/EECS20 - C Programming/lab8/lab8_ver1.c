/* Jack Melcher*/
/* SID: 67574625*/
/* 5/25/2015 */
/* EECS 20 */
/* Lab 8: Movie Theater Tickets*/

#include <stdio.h>

int main(void){
	/* section A: 1-50, section B: 51-100, section C, 101-200 */
	int seats[201];
	int section = 0;
	int number_of_seats = 0;

	/* counter variables*/
	int i = 0, j = 0, k = 0;

	/*initialize all seats as empty*/
	for (i = 0; i <= 200; i++){
		seats[i] = 0;
	}

	/* Ticket Booth Loop */
	while (seats[0] == 0){
		printf("Please type 1 for \"section A, $50/tickect\" \n");
		printf("Please type 2 for \"section B, $70/tickect\" \n");
		printf("Please type 3 for \"section C, $80/tickect\" \n");
		printf("Enter section number: ");
		scanf("%d", &section);
		printf("Enter number of tickets you want to purchase: ");
		scanf("%d", &number_of_seats);
		
		switch (section){
			/*Section A*/
			case 1:
				/* first loop checks to see if enough seats are available*/
				j = 0;
				for (i = 1; i <= 50; i++){
					if (seats[i] == 0){
						j++;
					}
				}
				if (j >= number_of_seats){
					/* second loop assigns the seats and prints the receipt */
					k = 0;
					for (i = 1; i <= 50 && k != number_of_seats; i++){
						if (seats[i] == 0){
							seats[i] = 1;
							printf("Section A, Seat %d\n", i);
							k++;
						}
					}
					printf("Total cost: %d\n", number_of_seats * 50);
				}
				else{
					printf("Not enough seats available in Section A. We are booked.\n");
				}

				break;
			/*Section B*/
			case 2:
				/* first loop checks to see if enough seats are available*/
				j = 0;
				for (i = 51; i <= 100; i++){
					if (seats[i] == 0){
						j++;
					}
				}
				if (j >= number_of_seats){
					/* second loop assigns the seats and prints the receipt */
					k = 0;
					for (i = 51; i <= 100 && k != number_of_seats; i++){
						if (seats[i] == 0){
							seats[i] = 1;
							printf("Section B, Seat %d\n", i);
							k++;
						}
					}
					printf("Total cost: %d\n", number_of_seats * 70);
				}
				else{
					printf("Not enough seats available in Section B. We are booked.\n");
				}
				break;
			/*Section C*/
			case 3:
				/* first loop checks to see if enough seats are available*/
				j = 0;
				for (i = 101; i <= 200; i++){
					if (seats[i] == 0){
						j++;
					}
				}
				if (j >= number_of_seats){
					/* second loop assigns the seats and prints the receipt */
					k = 0;
					for (i = 101; i <= 200 && k != number_of_seats; i++){
						if (seats[i] == 0){
							seats[i] = 1;
							printf("Section C, Seat %d\n", i);
							k++;
						}
					}
					printf("Total cost: %d\n", number_of_seats * 80);
				}
				else{
					printf("Not enough seats available in Section C. We are booked.\n");
				}
				break;
			default:
				printf("Invalid section selected.\n");
				break;
		}

		/* Check to see if all seats have been sold */
		for (i = 1; i <= 200; i++){
			if (seats[i] == 0){
				break;
			}
		}
		if (i == 201){
			seats[0] = 1;
			printf("Movie is sold out.\n");
		}
	}


	return 0;
}