


typedef struct piece_traits PIECE;

struct piece_traits
{
	piece_type Type;/*pawn, rook, knight, bishop, queen, king*/
	piece_color Color;/*white or black*/
};

typedef enum type piece_type;
enum piece_type
{
	Border,/*0*/
	Pawn,/*1*/
	Rook,/*2*/
	Knight,/*3*/
	Bishop,/*4*/
	Queen,/*5*/
	King/*6*/
};

typedef enum color piece_color;
enum piece_color
{
	White,/*0*/
	Black/*1*/
};

PIECE *board[10][10] /*the inner 64 blocks are the board, the outer 36 are null spaces*/


void CreatePiece(type, color, position)
{

}

check_rules(PIECE *board, int start, int end);