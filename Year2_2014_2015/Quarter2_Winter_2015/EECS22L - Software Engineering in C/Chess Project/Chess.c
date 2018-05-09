/*Chess.c*/
/*Using to figure out if everything works*/

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Pieces.h"
#include "Rules.h"

/*Function Declarations*/

/*Prints an ASCI Board*/
void PrintBoard(PIECE *board[100]);
/*Moves Piece*/
int move(PIECE *board[100], char s[256], int turn);
/*Rules Check*/
int CheckRules(PIECE *Board[100], int initial, int end);

int main(void)
{
	/*Array of Pointers that acts as the board and points to Pieces*/
	PIECE *board[100] = { NULL }; /*10x10 the inner 64 blocks are the board, the outer 36 are occupied pieces*/

	/*Player input string*/
	char s[256];
	/*File pointer*/
	FILE *fp;

	/*counter variable*/
	int x;

	/*menu variables*/
	int menu = 1;
	int game = 0;
	int turn = 1; /*1 = White's turn, 2 = Black's turn*/
	int selection = 0;

	/*White Pieces*/
	PIECE WP1 = { Pawn, White, 0, 21 };
	PIECE WP2 = { Pawn, White, 0, 22 };
	PIECE WP3 = { Pawn, White, 0, 23 };
	PIECE WP4 = { Pawn, White, 0, 24 };
	PIECE WP5 = { Pawn, White, 0, 25 };
	PIECE WP6 = { Pawn, White, 0, 26 };
	PIECE WP7 = { Pawn, White, 0, 27 };
	PIECE WP8 = { Pawn, White, 0, 28 };
	PIECE WR1 = { Rook, White, 0, 11 };
	PIECE WR2 = { Rook, White, 0, 18 };
	PIECE WN1 = { Knight, White, 0, 12 };
	PIECE WN2 = { Knight, White, 0, 17 };
	PIECE WB1 = { Bishop, White, 0, 13 };
	PIECE WB2 = { Bishop, White, 0, 16 };
	PIECE WQ = { Queen, White, 0, 14 };
	PIECE WK = { King, White, 0, 15 };

	/*Black Pieces*/
	PIECE BP1 = { Pawn, Black, 0, 71 };
	PIECE BP2 = { Pawn, Black, 0, 72 };
	PIECE BP3 = { Pawn, Black, 0, 73 };
	PIECE BP4 = { Pawn, Black, 0, 74 };
	PIECE BP5 = { Pawn, Black, 0, 75 };
	PIECE BP6 = { Pawn, Black, 0, 76 };
	PIECE BP7 = { Pawn, Black, 0, 77 };
	PIECE BP8 = { Pawn, Black, 0, 78 };
	PIECE BR1 = { Rook, Black, 0, 81 };
	PIECE BR2 = { Rook, Black, 0, 88 };
	PIECE BN1 = { Knight, Black, 0, 82 };
	PIECE BN2 = { Knight, Black, 0, 87 };
	PIECE BB1 = { Bishop, Black, 0, 83 };
	PIECE BB2 = { Bishop, Black, 0, 86 };
	PIECE BQ = { Queen, Black, 0, 84 };
	PIECE BK = { King, Black, 0, 85 };

	/*Game Startup*/
	printf("Welcome to DP Chess!\n");
	printf("1. Player vs Player\n");
	printf("2. Exit\n");

	/*Menu Loop*/
	while (1)/*true*/
	{
		printf("Input Number: ");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			/*Setup Board*/
			/*White Side*/
			board[21] = &WP1;
			board[22] = &WP2;
			board[23] = &WP3;
			board[24] = &WP4;
			board[25] = &WP5;
			board[26] = &WP6;
			board[27] = &WP7;
			board[28] = &WP8;
			board[11] = &WR1;
			board[18] = &WR2;
			board[12] = &WN1;
			board[17] = &WN2;
			board[13] = &WB1;
			board[16] = &WB2;
			board[14] = &WQ;
			board[15] = &WK;
			/*Black Side*/
			board[71] = &BP1;
			board[72] = &BP2;
			board[73] = &BP3;
			board[74] = &BP4;
			board[75] = &BP5;
			board[76] = &BP6;
			board[77] = &BP7;
			board[78] = &BP8;
			board[81] = &BR1;
			board[88] = &BR2;
			board[82] = &BN1;
			board[87] = &BN2;
			board[83] = &BB1;
			board[86] = &BB2;
			board[84] = &BQ;
			board[85] = &BK;
			/*Border if ever needed in the future*/

			/*Print game board*/
			PrintBoard(board);

			/*Exit Menu*/
			menu--;
			/*Allow game to start*/
			game++;
			break;

		case 2:/*End Exectable*/
			/*Exit Menu*/
			menu--;
			turn = 0;
			break;
		default:
			printf("Invalid menu selection\n");
			break;
		}

		if (menu < 1)
			break;
	}

	/*open file stream and creates new logfile*/
	fp = fopen("output.txt", "w");

	/*Player vs Player loop*/
	while (turn > 0)
	{
		/*end en passant chance*/
		for (x = 0; x < 100; x++)
		{
			if (board[x]->type == Pawn && board[x]->color == White && board[x]->moved == 1)
			{
				board[x]->moved++;
			}
		}

		/*white's turn*/
		while (turn == 1)
		{
			printf("White's turn\n");
			printf("Input coordinate: ");
			scanf("%s", s);
			turn = move(board, s, turn);
			/*white's turn ends*/
			if (turn == 2)
			{
				fprintf(fp, "%s\n", s);
			}

		}

		/*end en passant chance*/
		for (x = 0; x < 100; x++)
		{
			if (board[x]->type == Pawn && board[x]->color == Black && board[x]->moved == 1)
			{
				board[x]->moved++;
			}
		}

		/*black's turn*/
		while (turn == 2)
		{
			printf("Black's turn\n");
			printf("Input coordinate: ");
			scanf("%s", s);
			turn = move(board, s, turn);
			/*black's turn ends*/
			if (turn == 1)
			{
				fprintf(fp, "%s\n", s);
			}
		}
	}

	/*close file stream*/
	fclose(fp);

	return 0;
}

/*Print Board*/
void PrintBoard(PIECE *board[100])
{
	int x, y;/*counter variable*/

	printf("  ..  A  B  C  D  E  F  G  H ..\n");
	printf(" ");
	for (x = 9; x >= 0; x--)
	{
		if (x < 9 && x > 0)
			printf("%d", x);
		for (y = (x * 10); y <= (x * 10 + 9); y++)
		{
			if (!board[y])
				printf(" ..");
			if (board[y])
				printf(" %d%d", board[y]->color, board[y]->type);
		}
		if (x < 9 && x > 0)
			printf(" %d", x);
		printf("\n");
		if (x == 1)
			printf(" ");
	}
	printf("  ..  A  B  C  D  E  F  G  H ..\n");
}

int move(PIECE *board[100], char s[256], int turn)
{
	int from, to;
	int validMove;

	/*quit the game*/
	if (s[0] == 'e' && s[1] == 'x' && s[2] == 'i' && s[3] == 't')
	{
		turn = 0;
		return turn;
	}

	/*check for valid coordinate*/
	if (s[0] < 'a' || s[0] > 'h' ||
		s[1] < '0' || s[1] > '9' ||
		s[2] < 'a' || s[2] > 'h' ||
		s[3] < '0' || s[3] > '9')
	{
		printf("Invalid move command\n");
		return turn;
	}
	/*coordinate to decimal conversion*/
	/*in my case, a1 = 11 and b2 = 22*/
	from = s[0] - 'a' + 1; /*a - a + 1 = 1*/
	from += (s[1] - '0') * 10;/*1 + 10 = 11*/
	to = s[2] - 'a' + 1;/* b - a + 1 = 2*/
	to += (s[3] - '0') * 10;/*2 + 20 = 22 */
	printf("from = %d. to = %d\n", from, to);

	/*Check if initally chosen space is NULL*/
	if (!board[from])
	{
		printf("Invalid move. Empty space chosen\n");
		return turn;
	}

	/*Check if White is picking White piece*/
	if (turn == 1 && board[from]->color == Black)
	{
		printf("Invalid move. Not your piece\n");
		return turn;
	}
	/*Check if Black is picking Black piece*/
	if (turn == 2 && board[from]->color == White)
	{
		printf("Invalid move. Not your piece\n");
		return turn;
	}

	/*Rule check goes here*/
	validMove = CheckRules(board, from, to);

	if (validMove == 1)
	{
		/*Move Piece to valid space*/
		board[to] = board[from];
		/*Update position integer*/
		board[to]->position = to;
		/*Increment piece moved*/
		board[to]->moved += 1;
		/*Make original space NULL*/
		board[from] = NULL;
	}
	else
	{
		printf("Invalid move.\n");
		return turn;
	}

	/*Print game board*/
	PrintBoard(board);

	if (turn == 1)/*change to Black's turn*/
		turn++;
	else if (turn == 2)/*Change to White's turn*/
		turn--;

	return turn;
}
