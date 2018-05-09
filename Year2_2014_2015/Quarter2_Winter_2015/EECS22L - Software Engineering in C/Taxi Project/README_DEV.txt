-----------------------------------------------
-------DP Studios: DPTaxi Alpha Package -------
-------Version 1.0 	3/1/2015	-------
-------Written by: Jack Melcher		-------
-----------------------------------------------


Contents:
-----------------------------------------------
-----------------------------------------------
copyright.txt		-copyright of DPStudios programs
install_dev.txt		-learn how to run the program
README_DEV.txt		-lists the contents of the package

Makefile		-top-level, tool-specific Makefile


bin/
-----------------------------------------------
Client 			-Client Request executable
Server			-Taxi Management System executable
Taxi			-Taxi Cab Client executable

doc/
-----------------------------------------------
Taxi_UserManual.pdf	-Explains how to use programs
Taxi_SoftwareSpec.pdf	-Explains the how our software was developed


inc/
-----------------------------------------------
Header files:

graphics.h		-declarations for Graphics function
readmap.h		-declarations for readmap function


src/
-----------------------------------------------
Makefile		-specifically for the source files

Source files:

Client.c		-Lets client send request for taxi from server
graphics.c		-Allows GTK display of server information
readmap.c		-Reads map.txt and provides the server with map info
Server.c		-Maintains and runs Taxi Management System
Taxi.c			-Keeps tracks of taxi cab info and receive info from server

Text files:

map.txt			-sample map format that is used by Server


test/
------------------------------------------------
testreadmap.c		- test a given map.txt file, makes sure info is read
