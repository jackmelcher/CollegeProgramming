#Makefile: Taxi Management System

GTKINC	= `PKG_CONFIG_PATH=/usr/share/pkgconfig pkg-config --cflags gtk+-2.0`
GTKLIBS	= `PKG_CONFIG_PATH=/usr/share/pkgconfig pkg-config --libs gtk+-2.0`

INC	= $(GTKINC)
LIBS	= $(GTKLIBS)

#Convenience Targets
all: Client DPServer Taxi Server

clean:
	rm -f *.o
	rm -f Client
	rm -f DPServer
	rm -f Taxi
	rm -f Server

test: testreadmap testreadstring testboard

#Compilation Rules

Client: Client.c
	gcc -g -Wall -ansi Client.c -o Client
	
Server.o: Server.c readmap.h graphics.h
	gcc -g -c -Wall -ansi $(INC) $(LIBS) Server.c -o Server.o
	
Taxi.o: Taxi.c readmap.h
	gcc -g -c -Wall -ansi Taxi.c -o Taxi.o

readmap.o: readmap.h readmap.c
	gcc -g -c -Wall -ansi readmap.c -o readmap.o

graphics.o: graphics.c graphics.h
	gcc -g -c  -Wall -ansi $(INC) $(LIBS) graphics.c -o graphics.o

DPServer: Server.o readmap.o graphics.o
	gcc -g  -Wall -ansi $(INC) $(LIBS) readmap.o Server.o graphics.o -o DPServer

Server: Server.o readmap.o
	gcc -g -Wall -ansi $(INC) $(LIBS) readmap.o Server.o -o Server

Taxi: Taxi.o readmap.o
	gcc -g -Wall -ansi readmap.o Taxi.o -o Taxi

testboard: graphics.o
	gcc -g -Wall -ansi $(INC) $(LIBS) graphics.o -o testboard

testreadmap: testreadmp.c
	gcc -g -Wall -ansi testreadmap.c -o testreadmap

test_readstring: test_readstring.c
	gcc -g -Wall -ansi test_readstring.c -o test_readstring

routetest: routetest.o readmap.o 
	gcc -g -Wall -ansi routetest.o readmap.o -o routetest

routetest.o: routetest.c 
	gcc -g -Wall -ansi routetest.c -c -o routetest.o
