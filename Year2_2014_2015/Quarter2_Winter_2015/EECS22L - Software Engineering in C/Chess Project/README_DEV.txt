-----------------------------------------------
-------DP Studios: DPChess Alpha Package-------
-------Version 1.0 1/25/2015		-------
-------Written by Jack Melcher		-------
-----------------------------------------------


Contents:
-----------------------------------------------
copyright.txt		-copyright of DPChess
install.txt		-learn how to run the program
Makefile		-top-level, tool-specific Makefile
bin/
-----------------------------------------------
DPChess 		-DPChess executable file

doc/
-----------------------------------------------
Taxi_UserManual.pdf	-Explains how to use programs
Taxi_SoftwareSpec.pdf	-Explains the how our software was developed

inc/
-----------------------------------------------
Header files:

AI.h			-declarations for AI function
Graphics.h		-declarations for Graphics function
MovesList.h		-
PieceList.h		-
Pieces.h		-piece structures
Rules.h			-declarations for Rules functions

src/
-----------------------------------------------
Makefile		-specifically for the source files

Source files:

AI.c			-AI functions
Chess.c			-DPChess ASCI based interface
Graphics.c		-version 1 of SDL based display
Graphics2.c		-version 2 of SDL based display
MovesList.c		-
OldRunBoard.c		-version 1, aids in SDL display
RunBoard.c		-version 2, aids in SDL display
Rules.c			-checks for legality of moves


Graphics:

w_square.bmp
b_square.bmp

b_bishop.bmp
b_king.bmp
b_knight.bmp
b_pawn.bmp
b_queen.bmp
b_rook.bmp

w_bishop.bmp
w_king.bmp
w_knight.bmp
w_pawn.bmp
w_queen.bmp
w_rook.bmp

test/
------------------------------------------------
test_interface.c	- test user input conversion and board display
test_rulecheck.c	- test our check rules function
