#Makefile: DPChess
# Jack Melcher

#Convenince Targets
all: DPChess

test: DPChessTest

graphics: RunBoard OldRunBoard

clean:
	rm -f DPChess
	rm -f *.o
	rm -f RunBoard
	rm -f OldRunBoard

#Compilation Rules
DPChess: Chess.o Rules.o
	gcc -Wall -ansi Chess.o Rules.o -o DPChess

Chess.o: Chess.c Pieces.h Rules.h
	gcc -Wall -ansi -c Chess.c -o  Chess.o

Rules.o: Rules.c Pieces.h Rules.h
	gcc -Wall -ansi -lm -c Rules.c -o Rules.o

RunBoard: Graphics2.o RunBoard.o Rules.o
	gcc -Wall -ansi -lSDL Graphics2.o RunBoard.o Rules.o -o RunBoard

Graphics2.o: Graphics2.c
	gcc -c -Wall -ansi -lSDL Graphics2.c -o Graphics2.o

RunBoard.o: RunBoard.c
	gcc -c -Wall -ansi -lSDL RunBoard.c -o RunBoard.o

OldRunBoard: Graphics.o OldRunBoard.o
	gcc -Wall -ansi -lSDL Graphics.o OldRunBoard.o -o OldRunBoard

Graphics.o: Graphics.c
	gcc -c -Wall -ansi -lSDL Graphics.c -o Graphics.o

OldRunBoard.o: OldRunBoard.c
	gcc -c -Wall -ansi -lSDL OldRunBoard.c -o OldRunBoard.o

