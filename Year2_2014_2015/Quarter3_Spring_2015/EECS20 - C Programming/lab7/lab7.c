/* Jack Melcher*/
/* SID: 67574625*/
/* 5/18/2015 */
/* EECS 20 */
/* Lab 7: Traffic Light Controller */

#include <stdio.h>
#include <unistd.h>
#include <time.h>

/* Note: My sleep() values are in Seconds because I ran my program on the school's UNIX/LINUX Servers*/

int main (void){
	
	/*Variable Declarations*/
	int p = 0;
	printf("Welcome to Traffic Light Controller.\n");
	printf("Input 0 for Traffic light cycle.\n");
	printf("Input 1 for Pedestrian to cross.\n");
	printf("Input 3 to exit program.\n");

	/* Loop as long as p is not 3*/
	while (p != 3){
		/* Take in an input for p */
		printf("Please input request: ");
		scanf("%d", &p);
		/* Print what the Signals of the lights are*/
		switch (p){
			case 0:
				printf("No Pedestrian, Campus GREEN, Culver is RED\n");
				sleep(60);
				printf("No Pedestrian, Campus RED, Culver is GREEN\n");
				sleep(60);
				break;
			case 1:
				printf("Pedestrian is Passing, Campus RED, Culver is RED\n");
				sleep(120);
				printf("No Pedestrian, Campus GREEN, Culver is RED\n");
				sleep(60);
				printf("No Pedestrian, Campus RED, Culver is GREEN\n");
				sleep(60);
			case 3:
				break;
			default:
				printf("No Pedestrian, Campus GREEN, Culver is RED\n");
				sleep(60);
				printf("No Pedestrian, Campus RED, Culver is GREEN\n");
				sleep(60);
				break;
		}
	}

	return 0;
}
