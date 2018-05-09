# Makefile: PhotoLab
# Jack Melcher

# Convenience Targets
all: PhotoLab PhotoLabTest

clean:
	rm -f *.o
	rm -f *.a
	rm -f PhotoLab
	rm -f PhotoLabTest

# Compilation Rules
PhotoLab: PhotoLab.c libFileIO.a libFilter.a
	gcc PhotoLab.c -lFileIO -lFilter -L. -o PhotoLab

PhotoLabTest: PhotoLab.c DebugFileIO.o DIPs.o Advanced.o
	gcc PhotoLab.c -DDEBUG DebugFileIO.o DIPs.o Advanced.o -o PhotoLabTest

FileIO.o: FileIO.c FileIO.h Constants.h
	gcc -Wall -ansi -c FileIO.c -o FileIO.o

DebugFileIO.o: FileIO.c FileIO.h Constants.h
	gcc -Wall -ansi -c -DDEBUG FileIO.c -o DebugFileIO.o 

DIPs.o: DIPs.c DIPs.h Constants.h
	gcc -Wall -ansi -c DIPs.c -o DIPs.o

Advanced.o: Advanced.c Advanced.h Constants.h FileIO.h
	gcc -Wall -ansi -c Advanced.c -o Advanced.o

libFileIO.a: FileIO.o
	ar rc libFileIO.a FileIO.o
	ranlib libFileIO.a

libFilter.a: DIPs.o Advanced.o
	ar rc libFilter.a DIPs.o Advanced.o
	ranlib libFilter.a
