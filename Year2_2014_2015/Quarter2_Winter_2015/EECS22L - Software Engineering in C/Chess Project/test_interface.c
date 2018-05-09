/*test_interface.c*/


/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Pieces.h"

/*Prints an ASCI Board*/
void PrintBoard(PIECE *board[100]);
/*Moves Piece*/
int move(PIECE *board[100], char s[256], int turn);

int main(void)
{
	/*Array of Pointers that acts as the board and points to Pieces*/
	PIECE *board[100] = { NULL }; /*10x10 the inner 64 blocks are the board, the outer 36 are occupied pieces*/

	/*Player input string*/
	char s[256];

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
	printf("User input and board test\n");
	printf("Type a chess coordinates to move piece\n");
	printf("Example: a2a3\n");
	printf("Type exit to end test\n");

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

	/*Print game board*/
	PrintBoard(board);
	
	while (turn > 0)
	{
		/*white's turn*/
		while (turn == 1)
		{
			printf("Input coordinates: ");
			scanf("%s", s);
			turn = move(board, s, turn);
		}

		/*black's turn*/
		while (turn == 2)
		{
			printf("Input coordinates: ");
			scanf("%s", s);
			turn = move(board, s, turn);
		}
	}

	return 0;
}

/*Print Board*/
void PrintBoard(PIECE *board[100])
{
	int x;/*counter variable*/

	printf(" ");
	for (x = 90; x <= 99; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("8");
	for (x = 80; x <= 89; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("7");
	for (x = 70; x <= 79; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("6");
	for (x = 60; x <= 69; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("5");
	for (x = 50; x <= 59; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("4");
	for (x = 40; x <= 49; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("3");
	for (x = 30; x <= 39; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("2");
	for (x = 20; x <= 29; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("1");
	for (x = 10; x <= 19; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf(" ");
	for (x = 0; x <= 9; x++)
	{
		if (!board[x])
			printf(" ..");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	printf("  ..  A  B  C  D  E  F  G  H ..\n");
}

/*move piece function*/
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

	/*in my case, a1 = 11 and b2 = 22*/
	from = s[0] - 'a' + 1; /*a - a + 1 = 1*/
	from += (s[1] - '0') * 10;/*1 + 10 = 11*/
	to = s[2] - 'a' + 1;/* b - a + 1 = 2*/
	to += (s[3] - '0') * 10;/*2 + 20 = 22 */
	printf("from = %d. to = %d\n", from, to);

	if (!board[from]){
		return turn;
	}
	else{
		board[to] = board[from];
		board[from] = NULL;
	}

	/*Print game board*/
	PrintBoard(board);

	if (turn == 1)
		turn++;
	else if (turn == 2)
		turn--;

	return turn;
}