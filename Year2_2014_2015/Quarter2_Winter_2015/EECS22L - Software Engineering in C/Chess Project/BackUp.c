/*Test.c*/
/*Using to figure out if everything works*/

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*typedefs*/
typedef struct piece_traits PIECE;
typedef enum piece_type TYPE;
typedef enum piece_color COLOR;

/*Piece type Enum*/
enum piece_type
{
	Occupied,/*0*/
	Pawn,/*1*/
	Rook,/*2*/
	Knight,/*3*/
	Bishop,/*4*/
	Queen,/*5*/
	King/*6*/
};

/*Piece color Enum*/
enum piece_color
{
	Border,/*0*/
	White,/*1*/
	Black/*2*/
};

/*Piece Structure*/
struct piece_traits
{
	TYPE type;/*pawn, rook, knight, bishop, queen, king*/
	COLOR color;/*white or black*/
	int moved;/*A check for special moves, such as castling and en passant*/
	int position;/*position on board*/
};

/*Function Declarations*/

/*Prints an ASCI Board*/
void PrintBoard(PIECE *board[100]);
/*Setups up the game*/
PIECE *BoardSetup(int y);

int main(void)
{
	/*Array of Pointers that acts as the board and points to Pieces*/
	PIECE *board[100] = { NULL }; /*10x10 the inner 64 blocks are the board, the outer 36 are occupied pieces*/

	/*menu variables*/
	int menu = 1;
	int selection = 0;
	int x = 0; /*counter variable*/

	/*Game Startup*/
	printf("Welcome to DP Chess!\n");
	printf("1. Setup Game\n");
	printf("2. Print Board\n");

	/*Menu Loop*/
	while (1)/*true*/
	{
		scanf("%d", &selection);

		switch (selection)
		{
			case 1:
				for (x = 0; x < 100; x++)
				{
					/*Setup Board*/
					board[x] = BoardSetup(x);
				}
				menu--;
				break;
			case 2:
				/*Print game board*/
				PrintBoard(board);
				menu--;
				break;
			default:
				printf("Invalid menu selection");
				break;
		}

		if (menu < 1)
			break;
	}

	return 0;
}


PIECE *BoardSetup(int y)
{
	PIECE *ptr;
	ptr = (PIECE*)malloc(sizeof(PIECE));

	/*Border Space*/
	if ((y >= 0 && y <= 9) || y == 10 || y == 20 || y == 30 || y == 40 || y == 50 || y == 60 || y == 70 || y == 80 || (y >= 90 && y <= 99) || y == 19 || y == 29 || y == 39 || y == 49 || y == 59 || y == 69 || y == 79 || y == 89)
	{
		ptr->type = Occupied;
		ptr->color = Border;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Empty Space*/
	if (y >= 21 && y <= 28)
	{
		ptr = NULL;
	}
	/*White Pieces*/
	/*Pawn*/
	if (y >= 21 && y <= 28)
	{
		ptr->type = Pawn;
		ptr->color = White;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Rook*/
	if (y == 11 || y == 18)
	{
		ptr->type = Rook;
		ptr->color = White;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Knight*/
	if (y == 12 || y == 17)
	{
		ptr->type = Knight;
		ptr->color = White;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Bishop*/
	if (y == 13 || y == 16)
	{
		ptr->type = Bishop;
		ptr->color = White;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Queen*/
	if (y == 14)
	{
		ptr->type = Queen;
		ptr->color = White;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*King*/
	if (y == 15)
	{
		ptr->type = King;
		ptr->color = White;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Black Pieces*/
	/*Pawn*/
	if (y >= 61 && y <= 68)
	{
		ptr->type = Pawn;
		ptr->color = Black;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Rook*/
	if (y == 71 || y == 78)
	{
		ptr->type = Rook;
		ptr->color = Black;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Knight*/
	if (y == 72 || y == 77)
	{
		ptr->type = Knight;
		ptr->color = Black;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Bishop*/
	if (y == 73 || y == 76)
	{
		ptr->type = Bishop;
		ptr->color = Black;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*Queen*/
	if (y == 74)
	{
		ptr->type = Queen;
		ptr->color = Black;
		ptr->moved = 0;
		ptr->position = y;
	}
	/*King*/
	if (y == 75)
	{
		ptr->type = King;
		ptr->color = Black;
		ptr->moved = 0;
		ptr->position = y;
	}
	return ptr;
}

void PrintBoard(PIECE *board[100])
{
	int x;/*counter variable*/

	for (x = 90; x <= 99; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 80; x <= 89; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 70; x <= 79; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 60; x <= 69; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 50; x <= 59; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 40; x <= 49; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 30; x <= 39; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 20; x <= 29; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 10; x <= 19; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
	for (x = 0; x <= 9; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", board[x]->color, board[x]->type);
	}
	printf("\n");
}

int move(PIECE *board[100], char s[256])
{
	int from, to;
	/*a = 97, b = 98, c = 99, d = 100, e = 101, f = 102, g = 103, h = 104*/

	scanf("%s", s);
	if (s[0] < 'a' || s[0] > 'h' ||
		s[1] < '0' || s[1] > '9' ||
		s[2] < 'a' || s[2] > 'h' ||
		s[3] < '0' || s[3] > '9')
	{
		printf("Invalid move command\n");
		return 0;
	}



	/*a1 to b2*/
	from = s[0] - 'a';/*a - a = 97 - 97 = 0*/
	from += 8 * (8 - (s[1] - '0'));/*0 + 8*(8 - ( 1 - 0)) = 56*/
	to = s[2] - 'a';/*b - a = 98 - 97 = 1*/
	to += 8 * (8 - (s[3] - '0'));/*1 + 8*(8 - ( 2 - 0)) = 49*/

	/*in my case, a1 = 11 and b2 = 22*/
	from = s[0] - 'a' + 1; /*a - a + 1 = 1*/
	from += (s[1] - '0') * 10;/*1 + 10 = 11*/
	to = s[2] - 'a' + 1;/* b - a + 1 = 2*/
	to += (s[3] - '0') * 10;/*2 + 20 = 22 */
}

int move(PIECE *board[100], char s[256], int turn)
{
	int from, to;
	/*a = 97, b = 98, c = 99, d = 100, e = 101, f = 102, g = 103, h = 104*/
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
	}
	else/*When correct coordinate command*/
	{
		/*in my case, a1 = 11 and b2 = 22*/
		from = s[0] - 'a' + 1; /*a - a + 1 = 1*/
		from += (s[1] - '0') * 10;/*1 + 10 = 11*/
		to = s[2] - 'a' + 1;/* b - a + 1 = 2*/
		to += (s[3] - '0') * 10;/*2 + 20 = 22 */

		/*When White's turn*/
		if (board[from]->color == White && turn == 1)
		{
			if (!board[to])
			{
				board[to] = board[from];
				board[from] = NULL;
				turn++;
			}
			else
			{
				if (board[from]->color == board[to]->color)
				{
					printf("Invalid Move. Attempt to capture own Piece");
				}
				else
				{
					board[to] = board[from];
					board[from] = NULL;
					turn++;
				}
			}
		}
		else if (board[from]->color == White && turn == 2)
		{
			printf("Invalid Move. Not your Piece");
		}

		/*When Black's turn*/
		if (board[from]->color == Black && turn == 2)
		{
			if (!board[to])
			{
				board[to] = board[from];
				board[from] = NULL;
				turn--;
			}
			else
			{
				if (board[from]->color == board[to]->color)
				{
					printf("Invalid Move. Attempt to capture own Piece");
				}
				else
				{
					board[to] = board[from];
					board[from] = NULL;
					turn--;
				}
			}
		}
		else if (board[from]->color == Black && turn == 1)
		{
			printf("Invalid Move. Not your Piece");
		}
	}

	return turn;

}

int move(PIECE *board[100], char s[256], int turn)
{
	int from, to;

	board[31] = board[21];
	board[21] = NULL;

	/*in my case, a1 = 11 and b2 = 22*/
	from = s[0] - 'a' + 1; /*a - a + 1 = 1*/
	from += (s[1] - '0') * 10;/*1 + 10 = 11*/
	to = s[2] - 'a' + 1;/* b - a + 1 = 2*/
	to += (s[3] - '0') * 10;/*2 + 20 = 22 */
	printf("from = %d. to = %d\n", from, to);

	turn = 0;
	return turn;
}


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

/*Player vs Player*/
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

PIECE *BoardSetup()
{
	PIECE *board;

}

PIECE *CreatePiece(type, color, position)
{

}


void PrintBoard()
{
	for (x = 90; x == 99; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 80; x == 89; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 70; x == 79; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 60; x == 69; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 50; x == 59; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 40; x == 49; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 30; x == 39; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 20; x == 29; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 10; x == 19; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");
	for (x = 0; x == 9; x++)
	{
		if (!board[x])
			printf("  .");
		if (board[x])
			printf(" %d%d", *board[x]->Color, *board[x]->Type);
	}
	printf("\n");

	return 0;
}

int CheckRules(PIECE *Board[100], int initial, int end)
{
	int initialtype, initialcolor, initialmovestate, endtype, endcolor, endmovestate;

	initialtype = Board[initial]->type;
	initialcolor = Board[initial]->color;
	initialmovestate = Board[initial]->moved;

	printf("initial = %d. end = %d\n", initial, end);

	if (Board[end])
	{
		endtype = Board[end]->type;
		endcolor = Board[end]->color;
		endmovestate = Board[end]->moved;
	}


	printf("initial = %d. end = %d\n", initial, end);

	int i;
	int valid;

	/*First switch to check for valid move assuming nothing in the way*/
	switch (initialtype)
	{
		/*Pawn*/
	case Pawn:
		/*if moved piece color is white*/
		if (initialcolor == White)
		{
			/*Hasn't moved yet*/
			if (initialmovestate == 0)
			{
				if (end - initial == 10 || end - initial == 20 || end - initial == 9 || end - initial == 11)
				{
					valid = 1;
					break;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			/*Moved already*/
			else if (initialmovestate == 1)
			{
				if (end - initial == 10 || end - initial == 9 || end - initial == 11)
				{
					valid = 1;
					break;
				}
				else
				{
					valid = 0;
					break;
				}
			}
		}

		/*if moved piece color is black*/
		else if (initialcolor == Black)
		{
			/*Hasn't moved yet*/
			if (initialmovestate == 0)
			{
				if (initial - end == 10 || initial - end == 20 || initial - end == 9 || initial - end == 11)
				{
					valid = 1;
					break;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			/*Moved already*/
			else if (initialmovestate == 1)
			{
				if (initial - end == 10 || initial - end == 9 || initial - end == 11)
				{
					valid = 1;
					break;
				}
				else
				{
					valid = 0;
					break;
				}
			}
		}
		/*Rook*/
	case Rook:
		if ((abs(end - initial) % 10 == 0) || (initial / 10 == end / 10))
		{
			valid = 1;
			break;
		}
		else
		{
			valid = 0;
			break;
		}
		/*Knight*/
	case Knight:
		if ((abs(end - initial) == 21) || (abs(end - initial) == 19) || (abs(end - initial) == 12) || (abs(end - initial) == 8))
		{
			valid = 1;
			break;
		}
		else
		{
			valid = 0;
			break;
		}
		/*Bishop*/
	case Bishop:
		if ((abs(end - initial) % 9 == 0) || (abs(end - initial) % 11 == 0))
		{
			valid = 1;
			break;
		}
		else
		{
			valid = 0;
			break;
		}
		/*Queen*/
	case Queen:
		if ((abs(end - initial) % 9 == 0) || (abs(end - initial) % 11 == 0))
		{
			valid = 1;
			break;
		}
		else if ((abs(end - initial) % 10 == 0) || (initial / 10 == end / 10))
		{
			valid = 1;
			break;
		}
		else
		{
			valid = 0;
			break;
		}
		/*King*/
	case King:
		if ((abs(end - initial) == 9) || (abs(end - initial) == 11))
		{
			valid = 1;
			break;
		}
		else if ((abs(end - initial) == 10) || (abs(end - initial) == 1))
		{
			valid = 1;
			break;
		}
		else
		{
			valid = 0;
			break;
		}

		/*default case*/
	default:
		valid = 0;
		break;

	}

	/*Checks to see if kill movement is valid or if pieces are in the way of movement*/
	switch (initialtype)
	{
		/*pawn*/
	case Pawn:
		/*checking to see if there’s something in the pawns basic movement path*/
		if (abs(end - initial) == 10)
		{
			if (Board[end] == NULL)
			{
				valid = 1;
			}
			else if (endcolor == 1 || endcolor == 2)
			{
				valid = 0;
			}
		}
		/*checking to see which color is in attack path*/
		else if ((abs(end - initial) == 9) || (abs(end - initial) == 11))
		{
			if (Board[end] == NULL || endcolor == initialcolor)
			{
				valid = 0;
			}
			else if (endcolor != initialcolor)
			{
				valid = 1;
			}
		}
		break;

		/*rook*/
	case Rook:
		if (abs(end - initial) % 10 == 0)
		{
			for (i = initial; i < end; i += 10)
			{
				if (Board[i] == NULL)
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
				break;
			}
			break;
		}
		else if ((initial / 10) == (end / 10))
		{
			for (i = initial; i < end; i += 1)
			{
				if (Board[i] == NULL)
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
				break;
			}
			break;
		}

		/*knight*/
	case Knight:
		if (endcolor == initialcolor)
		{
			valid = 0;
			break;
		}
		else if (endcolor != initialcolor || Board[end] == NULL)
		{
			valid = 1;
			break;
		}

		/*bishop*/
	case Bishop:
		if (abs(end - initial) % 9 == 0)
		{
			for (i = initial; i < end; i += 9)
			{
				if (Board[i] == NULL)
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
				break;
			}
			break;
		}
		else if (abs(end - initial) % 11 == 0)
		{
			for (i = initial; i < end; i += 11)
			{
				if (Board[i] == NULL)
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
				break;
			}
			break;
		}

		/*Queen*/
	case Queen:
		if (abs(end - initial) % 9 == 0)
		{
			for (i = initial; i < end; i += 9)
			{
				if (Board[i] == NULL)
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
				break;
			}
			break;
		}
		else if (abs(end - initial) % 11 == 0)
		{
			for (i = initial; i < end; i += 11)
			{
				if (Board[i] == NULL)
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
				break;
			}
			break;
		}
		else if (abs(end - initial) % 10 == 0)
		{
			for (i = initial; i < end; i += 10)
			{
				if (Board[i] == NULL)
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
				break;
			}
			break;
		}
		else if ((initial / 10) == (end / 10))
		{
			for (i = initial; i < end; i += 1)
			{
				if (Board[i] == NULL)
				{
					valid = 1;
				}
				else
				{
					valid = 0;
					break;
				}
			}
			if (endcolor == initialcolor)
			{
				valid = 0;
				break;
			}
			break;
		}

		/*King*/
	case King:
		if (initialcolor == endcolor)
		{
			valid = 0;
			break;
		}
		else if (initialcolor != endcolor || Board[end] == NULL)
		{
			valid = 1;
			break;
		}

	default:
		valid = 0;
		break;
	}

	/*returns valid as 0 or 1 depending on whether move was valid (1) or not (0)*/
	return valid;
}