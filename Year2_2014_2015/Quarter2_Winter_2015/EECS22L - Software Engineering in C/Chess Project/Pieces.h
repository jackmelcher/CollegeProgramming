/*********************************************************/
/* Pieces.h: header file for Piece Structues             */
/*Jack Melcher 67574625                                  */
/*********************************************************/
#ifndef PIECES_H
#define PIECES_H

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

#endif

