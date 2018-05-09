/*Jack Melcher*/
/*Homework 1*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main (void)
{
	/*Initialization and Declaration*/
	int playerHand = 0;
	int dealerHand = 0;
	int card = 0;
	int playerTurn = 0;
	int dealerTurn = 0;
	char playerSelection;
	
	/*Initialize the random number generator with the current time*/
	srand( time(NULL));

	/*Blackjack Game*/
	printf("**********************************\n");
	printf("** Welcome to EECS22 BlackJack! **\n");
	printf("**********************************\n");
	
	/*Draw a random card*/
	card = rand() % 13 + 1;
	
	/*Numbers One through Ten*/
	if (card < 11)
	{
		printf("Your first card is: %d\n", card);
	}
	/*Jack*/
	if (card == 11)
	{
		card = (card / card) * 10;
		printf("Your first card is: Jack\n");
	}
	/*Queen*/
	if (card == 12)
	{
		card = (card / card) * 10;
		printf("Your first card is: Queen\n");
	}
	/*King*/
	if (card == 13)
	{
		card = (card / card) * 10;
		printf("Your first card is: King\n");
	}
	
	
	playerHand = playerHand + card;
		
		/*Player's Turn*/
		while(playerTurn < 1)
		{
			printf("Do you want another card?\n");
			printf("Type 1 for Yes, 0 for No: ");
			scanf(" %c", &playerSelection);

			switch (playerSelection)
			{
				case'1':
				{
					if (playerHand <= 21)
					{
						/*Draw a random card*/
						card = rand() % 13 + 1;

						/*Numbers One through Ten*/
						if (card < 11)
						{
							printf("Your next card is: %d\n", card);
						}
						/*Jack*/
						if (card == 11)
						{
							card = (card / card) * 10;
							printf("Your next card is: Jack\n");
						}
						/*Queen*/
						if (card == 12)
						{
							card = (card / card) * 10;
							printf("Your next card is: Queen\n");
						}
						/*King*/
						if (card == 13)
						{
							card = (card / card) * 10;
							printf("Your next card is: King\n");
						}
						
						playerHand = playerHand + card;
						printf("Your combined value is: %d\n", playerHand);
					}

					/*When Player has 21*/
					if (playerHand == 21)
					{
						playerTurn = playerTurn + 1;
					}
					/*When Player has more than 21. End the blackjack game*/
					if (playerHand > 21)
					{
						printf("Sorry. You lose!\n");
						playerTurn = playerTurn + 1;
						dealerTurn = dealerTurn + 1;
					}
					break;

				}
				/*End Turn*/
				case'0':
				{
					playerTurn = playerTurn + 1;
					break;
				}
				/*If neither 0 nor 1 was typed*/
				default:
				{
					printf("Invalid Input.\n");
					break;
				}
			}
		}
		
		/*Dealer's Turn*/
		while (dealerTurn < 1)
		{
			if(dealerHand < playerHand)
			{
				printf("Dealer draws another card.\n");
				/*Draw a random card*/
				card = rand() % 13 + 1;

				/*Numbers One through Ten*/
				if (card < 11)
				{
					printf("Dealer’s card is: %d\n", card);
				}
				/*Jack*/
				if (card == 11)
				{
					card = (card / card) * 10;
					printf("Dealer’s card is: Jack\n");
				}
				/*Queen*/
				if (card == 12)
				{
					card = (card / card) * 10;
					printf("Dealer’s card is: Queen\n");
				}
				/*King*/
				if (card == 13)
				{
					card = (card / card) * 10;
					printf("Dealer’s card is: King\n");
				}

				dealerHand = dealerHand + card;
				printf("Dealer’s value is %d, you have %d.\n", dealerHand, playerHand);
			}
			
			if(dealerHand >= playerHand && dealerHand <= 21)
			{
				printf("Dealer wins. You lose.\n");
				dealerTurn = dealerTurn + 1;
			}

			if(dealerHand > 21)
			{
				printf("Congratulations! You Win!\n");
				dealerTurn = dealerTurn + 1;
			}
		}

	return 0;
}