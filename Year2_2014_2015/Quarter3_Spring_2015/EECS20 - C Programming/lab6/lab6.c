/* Jack Melcher*/
/* SID: 67574625*/
/* 5/14/2015 */
/* EECS 20 */
/* Lab 6: Guessing Game*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	
	/*Decalare Variables*/
	int number = 0;
	int guess = 0;
	int game = 0;

	/*Initialize random number generator*/
	srand(time(NULL));
	number = rand()%3000 + 1;
	
	/*Game Start*/	
	printf("I have a number between 1 and 3000.\n");
	printf("Can you guess my number?\n");

	/*Game Loop*/
	while(game == 0){G
	
		printf("Please type your first guess: ");
		scanf("%d", &guess);
	
		/*Win*/
		if(guess == number){
			printf("Excellent! You guessed the number!\n");
			game++;
		}
		/*Too Low*/
		if(guess < number){
			printf("Too low. Try again.\n");
		}
		/*Too High*/
		if(guess > number){
			printf("Too high. Try again.\n");
		}
	}

	return 0;
}
