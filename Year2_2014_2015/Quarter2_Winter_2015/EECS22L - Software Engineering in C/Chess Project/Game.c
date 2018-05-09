/*menu variables*/
menu = 1;
selection = 0;
playerW_aiB = 0;
playerB_aiW = 0;
player_color;
player_player = 0;

/*in-game variables*/
game = 1;
check_white = 0;
check_black = 0;
white = 1;
black = 0;

while (menu >= 1)/*true*/
{
	printf("Welcome to DP Chess!");
	printf("1. Player vs AI");
	printf("2. Player vs Player");
	printf("3. Exit");
	scanf("%d", &selection);

	switch (selection)
		case 1: /*Start Player versus AI*/
			printf("Choose your side: w for White");
			printf("                  b for Black");
			scanf(" %s", &player_color)
			if (player_color == w){
				playerW_ai++;
				menu--;
			}
			else if (player_color == b){
				playerB_ai++;
				menu--;
			}
			else
				printf("Invalid side selection");
			break;
		case 2:/*Start Player vs Player*/
			player_player++;
			menu--;
			break;
		case 3:/*Exit Chess Game*/
			menu--;
			break;
		default:
			printf("Invalid menu selection");
			break;
}

/*Initialize Game board*/
/*malloc all the piece structures*/
/*set each pointer on board to appropriate piece and the rest null*/

while (playerW_aiB == 1)
{
	printf("White's turn");
	while (white == 1)/*white's turn*/
	{
		/*pick a position on the board and postion to move piece*/
		if (/*position is null*/){
			/*continue and reset white's turn*/
		}
		if (/*position has a piece*/){
			if (/*piece is black*/){
				/*continue and reset white's turn*/
			}
			if (/*piece is white*/){
				if (check_white == 1){/*white is in check*/
					/*check piece type*/
					if (/*piece type != king*/){
						/*continue and reset white's turn*/
					}
				}
				/*check legality of move*/
				if (/*move is not legal*/){
					/*continue and reset white's turn*/
					if (/*move is legal*/){
						/*move the piece*/
					}
				}
			}
		}
		white--;/*end white's turn*/
		black++;/*start black's turn*/
	}
	/*Print game board*/

	/*Check to see if black is in check or is in checkmate*/
	if (/*black king is in check*/){
		check_black++;
		printf("Black King is in Check!");
	}
	if (/*black king is in checkmate*/){
		printf("Checkmate! White Wins");
		playerB_aiW--;/*game over, white wins*/
	}

	printf("Black's turn");
	/*Black side AI*/

	/*Print game board*/

	/*Check to see if black is in check or is in checkmate*/
	if (/*black king is in check*/){
		check_black++;
		printf("Black King is in Check!");
	}
	if (/*black king is in checkmate*/){
		printf("Checkmate! White Wins");
		playerB_aiW--;/*game over, white wins*/
	}
}
while (playerB_aiW == 1)
{
	printf("White's turn");
	/*White side AI*/

	/*Print game board*/

	/*Check to see if black is in check or is in checkmate*/
	if (/*black king is in check*/){
		check_black++;
		printf("Black King is in Check!");
	}
	if (/*black king is in checkmate*/){
		printf("Checkmate! White Wins");
		playerB_aiW--;/*game over, white wins*/
	}

	printf("Black's turn");
	while (black == 1)/*black's turn*/
	{
		/*pick a position on the board and postion to move piece*/
		if (/*position is null*/){
			/*continue and reset black's turn*/
		}
		if (/*position has a piece*/){
			if (/*piece is white*/){
				/*continue and reset black's turn*/
			}
			if (/*piece is black*/){
				/*check legality of move*/
				if (/*move is not legal*/){
					/*continue and reset black's turn*/
				}
				if (/*move is legal*/){
					/*move the piece*/
				}
			}
		}
		black--;/*end black's turn*/
		white++;/*start white's turn*/
	}
	/*Print game board*/

	/*Check to see if white is in check or is in checkmate*/
	if (/*white king is in check*/){
		check_white++;
		printf("White King is in Check!");
	}
	if (/*white king is in checkmate*/){
		printf("Checkmate! Black Wins");
		playerB_aiW--;/*game over, black wins*/
	}
}

while (player_player >= 1) /*true*/
{
	printf("White's turn");
	while (white == 1)/*white's turn*/
	{
		/*pick a position on the board and postion to move piece*/
		if (/*position is null*/){
			/*continue and reset white's turn*/
		}
		if (/*position has a piece*/){
			if (/*piece is black*/){
				/*continue and reset white's turn*/
			}
			if (/*piece is white*/){
				if (check_white == 1){/*white is in check*/
					/*check piece type*/
					if (/*piece type != king*/){
						/*continue and reset white's turn*/
					}
				}
				/*check legality of move*/
				if (/*move is not legal*/){
						/*continue and reset white's turn*/
					if (/*move is legal*/){
						/*move the piece*/
					}
				}
			}
		}
		white--;/*end white's turn*/
		black++;/*start black's turn*/
	}
	/*Print game board*/

	/*Check to see if black is in check or is in checkmate*/
	if (/*black king is in check*/){
		check_black++;
		printf("Black King is in Check!");
	}
	if (/*black king is in checkmate*/){
		printf("Checkmate! White Wins");
		player_player--;/*game over, white wins*/
	}
		
	printf("Black's turn");
	while (black == 1)/*black's turn*/
	{
		/*pick a position on the board and postion to move piece*/
		if (/*position is null*/){
			/*continue and reset black's turn*/
		}
		if (/*position has a piece*/){
			if (/*piece is white*/){
				/*continue and reset black's turn*/
			}
			if (/*piece is black*/){
				/*check legality of move*/
				if (/*move is not legal*/){
					/*continue and reset black's turn*/
				}
				if (/*move is legal*/){
					/*move the piece*/
				}
			}
		}
		black--;/*end black's turn*/
		white++;/*start white's turn*/
	}
	/*Print game board*/

	/*Check to see if white is in check or is in checkmate*/
	if (/*white king is in check*/){
		check_white++;
		printf("White King is in Check!");
	}
	if (/*white king is in checkmate*/){
		printf("Checkmate! Black Wins");
		player_player--;/*game over, black wins*/
	}
}