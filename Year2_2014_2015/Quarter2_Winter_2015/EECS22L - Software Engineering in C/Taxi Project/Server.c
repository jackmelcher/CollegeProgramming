/* Server.c DPStudios */
/* Live free die hard */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include "readmap.h"
#include <math.h>
#include "graphics.h"

/*double calculateCost( int x1, int y1, int x2, int y2);
char * gps( int x1, int y1, int x2, int y2);*/ 
extern enum MAP_OBJ  Board[1000][1000] = {{0}};
char ** calculateRoute(int x1, int y1, int x2, int y2);
int distance(int x1, int y1, int x2, int y2, char ** route);
int landmark_entrance_coordinates[100][2],
	    landmark_boundary_coordinates[100][4],
	    taxi_stand_coordinates[10][2],
	    size[2];      

	
char ew_list[100][50],
	     ns_list[100][50],
	     landmark_names[100][100]; /* read map stuff */

int main(int argc, char *argv[]) {

	int l, n, i, j;
	int w = 0;
	int T = 0; 
	int P = 0; /* just counter variable */
	int ServSocketFD, /* Socket file descriptor for service */
	    DataSocketFD, /* Socket file descriptor for data */
	    SocketFD,     /* Socket file descriptor for acting as a client */
	    PortNo_S,
	    PortNo_C;       /* Port Number */
	socklen_t ClientLen;
	struct sockaddr_in
	    ServerAddress, /* server address (this host) */
	    ClientAddress; /* client address we connect with */
	struct hostent
	    *Server;
	char RecvBuf[5000]; /* message buffer for recieving input */
	char SendBuf[5000]; /* message buffer for sending a responce */
	char TaxiInfo[5000]; /* variable for sending info to Taxi */
	int  Loop = 0;  /* Variables for taxi and client communication loops */

	

	                         /* more readmap stuffs */
	
	char Output[5][100];
	char *ptr;
	char *delim = " AND"; 
	
	char ** route;
	/*Stores the streets that we ge from request line*/
	char store[4][100];
	int street_or_land[4];/* 0 for street, 1 for landmark*/
	char reading[100];
	/*counter variables*/
	int x = 0;
	int k = 0;
	
	int Cx, Cy, Dx, Dy;
	/*boolean integers*/
	int storing = 0;

	

	readmap(ew_list, ns_list, landmark_names, landmark_entrance_coordinates, landmark_boundary_coordinates, taxi_stand_coordinates, size);
	/* create the board */
	
	createBoard(); 

	do{ 	Loop = 0;
		printf("%s: starting...\n", argv[0]);
		if (argc < 4){
			fprintf(stderr, "Usage: %s hostname serverport clientport\n", argv[0]);
			exit(10);
		}
		PortNo_S = atoi(argv[2]);
		if (PortNo_S <= 2000){
			fprintf(stderr, "%d is an invalid port number, should be greater than 2000\n", PortNo_S);
			exit(10);
		}
		
		PortNo_C = atoi(argv[3]);
		if (PortNo_C <= 2000){
			fprintf(stderr, "%d is an invalid port number, should be greater than 2000\n", PortNo_C);
			exit(10);
		}
		/* Creating Socket for clients to use */
		ServSocketFD = socket(AF_INET, SOCK_STREAM, 0);
		if (ServSocketFD < 0){
			perror("Fatal Error, Service socket creation failed\n");
		}
		/* Making server address */
		memset(&ServerAddress, 0, sizeof(ServerAddress));
		ServerAddress.sin_family = AF_INET;
		ServerAddress.sin_port = htons(PortNo_S);
		ServerAddress.sin_addr.s_addr = INADDR_ANY;

		/* Assigning server name to socket */
		if ( bind(ServSocketFD, (struct sockaddr*)&ServerAddress, sizeof(ServerAddress)) < 0){
			perror("Binding server to socket failed\n");
		}

		printf("Listening on port %d... \n", PortNo_S);
		if (listen(ServSocketFD, 5) < 0) {
			perror("Listening on socket failed\n");
		}
	
		ClientLen = sizeof(ClientAddress);
		DataSocketFD = accept(ServSocketFD, (struct sockaddr*)&ClientAddress, &ClientLen);
		if (DataSocketFD < 0){
			perror("Data socket creation failed\n");
		}
		printf("Accepted connection from client\n");

		n = read(DataSocketFD, RecvBuf, sizeof(RecvBuf) - 1);
		if (n < 0){
			perror("reading from data socket failed\n");	
		}
		RecvBuf[n] = 0;
		/* Buffer fully recieved, send response */
		/* set the recieved buffer into the one being sent to taxi for now */
		strncpy(TaxiInfo, RecvBuf, sizeof(TaxiInfo)-1);
		
		/* reading request 
		while (w == 0) {
			i = 1;
			j = 2;
			strtok_r(RecvBuf, " ", &ptr);
			if (strcmp(RecvBuf, "REQUEST") == 0) {
				strcpy(RecvBuf, ptr);
				strtok_r(RecvBuf, " ", &ptr);
				strcpy(Output[0], RecvBuf);
				printf("%s\n", Output[0]);
				strcpy(RecvBuf, ptr);
			}

			else if (strcmp(RecvBuf, "RIDE") == 0 || strcmp(RecvBuf, "FROM") == 0) {
				strcpy(RecvBuf, ptr);
			}

			else if (strcmp(RecvBuf, "CORNER") == 0) {
				strcpy(RecvBuf, ptr);
				strtok_r(RecvBuf, "A", &ptr);
				strcpy(Output[i], RecvBuf);
				printf("%s\n", Output[1]);
				strcpy(RecvBuf, ptr);
				i++;
				i++;
			}
			else if (strcmp(RecvBuf, "ND") == 0) {
				strcpy(RecvBuf, ptr);
				strtok_r(RecvBuf, "TN", &ptr);
				strcpy(Output[j], RecvBuf);
				printf("%s\n", Output[2]);
				strcpy(RecvBuf, ptr);
				j++;
				j++;
			}

			else if (strcmp(RecvBuf, "O") == 0) {
				strcpy(RecvBuf, ptr);
			}
			
			else {
				w = 42;
			}

		
		}*/


		strcpy(reading, RecvBuf);
		i = 0;
		j = 0;
		k = 0;
		/* Read client request string */
		for (x = 0; x < 200; x++)
		{
			/*store street*/
			if (storing == 1)
			{
				store[j][k] = reading[x];
				k++;
			}
			/* Once we hit FROM, check to see if a landmark is being stored or street names*/
			if (reading[x] == 'F' && reading[x + 1] == 'R' && reading[x + 2] == 'O' && reading[x + 3] == 'M')
			{
				if (reading[x + 4] == ' ' && reading[x + 5] == 'C' && reading[x + 6] == 'O' && reading[x + 7] == 'R')
				{
					storing = 1;
					street_or_land[i] = 0;
					i++;
					/*Move to space before street name*/
					x += 11;
				}
				else
				{
					storing = 1;
					street_or_land[i] = 1;
					i++;
					/*Move to space before landmark name*/
					x += 4;
				}
			}
			/*move to 2nd street to store*/
			if (reading[x + 1] == ' ' && reading[x + 2] == 'A' && reading[x + 3] == 'N' && reading[x + 4] == 'D')
			{
				k = 0;
				j++;
				street_or_land[i] = 0;
				i++;
				x += 5;
			}
			/*Go to next item to store*/
			if (reading[x + 1] == ' ' && reading[x + 2] == 'T' && reading[x + 3] == 'O')
			{
				if (reading[x + 4] == ' ' && reading[x + 5] == 'C' && reading[x + 6] == 'O' && reading[x + 7] == 'R')
				{
					street_or_land[i] = 0;
					i++;
					/*Move to space before street name*/
					x += 11;
				}
				else
				{
					street_or_land[i] = 1;
					i++;
					/*Move to space before landmark name*/
					x += 4;
				}
				k = 0;
				j++;
			}
			/*End reading at NOW*/
			if (reading[x + 1] == ' ' && reading[x + 2] == 'N' && reading[x + 3] == 'O' && reading[x + 4] == 'W')
			{
				break;
			}
		}
		/*Display what was stored by the request string reading*/
		printf("This is what is stored\n");
		printf("%s\n", store[0]);
		printf("%s\n", store[1]);
		printf("%s\n", store[2]);
		printf("%s\n", store[3]);
		
		for (i = 0; i < 100; i++) {
			if (strcmp(store[0],ns_list[i]) == 0) {
				Cx = i;
			}
			if (strcmp(store[1],ew_list[i]) == 0) {
				Cy = i;
			}
			if (strcmp(store[2],ns_list[i]) == 0) {
				Dx = i;
			}
			if (strcmp(store[3],ew_list[i]) == 0) {
				Dy = i;
			}
		}
		route = calculateRoute(0, 0, 9, 3);

		/* Grid[Cx][Cy] = MIDDLE_CLIENT; */

		strncpy(SendBuf, "Message recieved", sizeof(SendBuf)-1);
		SendBuf[sizeof(SendBuf)-1] = 0;
		l = strlen(SendBuf);
		printf("Sending response: %s. \n", SendBuf);
		n = write(DataSocketFD, SendBuf, l);
		if (n < 0){
			perror("writing to data socket failed\n");
		}
		close(DataSocketFD);
		close(ServSocketFD);

		/* Acting as a Client for taxi */
		Server = gethostbyname(argv[1]);
		if (Server == NULL) {
			fprintf(stderr, "TaxiClient: no such host named: %s\n", argv[1]);
			exit(10);
		}
		
		/* creating client socket */
		SocketFD = socket(AF_INET, SOCK_STREAM, 0);
		if (SocketFD < 0) {
			perror("TaxiClient: socket creation failed\n");
		}
		
		/* memory copy for client */
		
		memset(&ServerAddress, 0, sizeof(ServerAddress));
		ServerAddress.sin_family = AF_INET;
		ServerAddress.sin_port = htons(PortNo_C);
		memcpy(&ServerAddress.sin_addr.s_addr, Server->h_addr_list[0], Server->h_length);

		printf("TaxiClient: Connecting to Taxi...\n");
		if (connect(SocketFD, (struct sockaddr*)&ServerAddress, sizeof(ServerAddress)) < 0) {
			perror("Connecting to Taxi Failed\n");
		}
		l = strlen(TaxiInfo);
		printf("TaxiClient: Sending message: %s\n", TaxiInfo);
		n = write(SocketFD, TaxiInfo, l);
		if (n < 0) {
			perror("Writing to socket failed\n");
		}

		n = read(SocketFD, RecvBuf, sizeof(RecvBuf)-1);
		if (n < 0) {
			perror("Reading from socket failed");
		}
		RecvBuf[n] = 0;
		

		printf("TaxiClient: Recieved response: %s\n", RecvBuf);

		close(SocketFD);
		Loop = 1;
	} while(!Loop);
	
	return 0;
}

double calculateCost( int x1, int y1, int x2, int y2)
{
	int x = abs(x2-x1); 
	int y = abs(y2-y1); 

	double distance = x + y; 
	return (distance/4.0) * 2 + 3.75;	
}


/*calculates which taxi stand to use*/
/*int calculatetaxi(int x1, int y1)	
{
	int use_i = 0;
	int use_taxi = 1000;

	for(n = 0; n < #taxi stands; n++)
	{
		int x = street name 1;
		int y = street name 2;

		int tx = abs(x - x1);
		int ty = abs(x - y1);
		int taxi_distance = tx + ty;

		if (taxi_distance < use_taxi)
		{
			use_taxi = taxi_distance;
			use_i = i;
		}
	}
	return use_i
}
*/

/* NEEDS TO BE TESTED */
/* finds the directions from point A to B no calculation of taxi stand */
char ** routeAtoB(int x1, int y1, int x2, int y2)
{	
	static char * route[100]; 
	int i = 0; 
	int j = 0; 
	int a = 0;
	
	/* clear the route buffer */
	for (j = 0; j < 100; j++)
	{
		route[j] = NULL; 
	}
	
	
	/* this while loop calculates the route to the taxi's final destination after it has picked up the customer */
	while (x1 != x2 && y1 != y2)
	{
		/* first start with x coordinate */
		
		if ( (x2 > x1) && (y2 < y1) )
		{
			if (Board[x1+1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				route[i] = "north";
				y1--; 
			}
			else
			{
				route[i] = "east"; 
				x1++; 
			}
		}
		else if ( (x2 < x1) && (y2 < y1) )
		{
			if (Board[x1-1][y1] >= 20 && Board[x1-1][y1] < 30)
			{
				route[i] = "north";
				y1--;
			}
			else
			{
				route[i] = "west";
				x1--;
			}
		}
		else if ((x2 < x1) && (y2 > y1))
		{
			if(Board[x1 -1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				route[i] = "south";
				y1++;
			}
			else
			{
				route[i] = "west";
				x1--;
			}
		}
		else if ((x2 > x1) && (y2 > y1))
		{
			if(Board[x1+1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				route[i] = "east";
				x1++; 
			}
			else
			{
				route[i] = "south";
				y1++; 
			}
		}
		else if ((y1 == y2) && (x1 < x2)) /* if on same street */
		{	
			if(Board[x1+1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				route[i] = "north";
				y1++; 
			}
			else
			{
				route[i] = "east";
				x1++; 
			}
		}
		else if ( (y1 == y2) && (x1 > x2) )
		{
			if(Board[x1-1][y1] >= 20 && Board[x1-1][y1] < 30)
			{
				route[i] = "north";
				y1++; 
			}
			else
			{
				route[i] = "west";
				x1--; 
			}
		}
		else if ( (x1 == x2) && (y1 < y2) )
		{
			if(Board[x1][y1+1] >= 20 && Board[x1+1][y1+1] < 30)
			{
				route[i] = "east";
				x1++; 
			}
			else
			{
				route[i] = "south";
				y1++; 
			}
		}
		else if ( (x1 == x2) && (y1 > y2) )
		{
			if(Board[x1+1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				route[i] = "east";
				x1++; 
			}
			else
			{
				route[i] = "north";
				y1--; 
			}
		}
		
		
		
		i++; 

	} /* END WHILE */
		
	return route; 
} 

char ** calculateRoute(int x1, int y1, int x2, int y2)
{
	static char * route[1000]; 
	char ** path1; 
	char ** path2; 
	char ** path3;
	int i = 0; 
	int j = 0; 
	int xShortest = 0; 
	int yShortest = 0; 
	int shortestDistance; 
	int closestTaxiStand = 0; /* array index of closest taxi stand */
	
	/* clear the route buffer */
	for (j = 0; j < 1000; j++)
	{
		route[j] = NULL; 
	}
	
	/* calculates the shortest route from taxi stand to passanger */
	for (i = 0; i < 10; i++)
	{
		 if (distance(taxi_stand_coordinates[i][0], taxi_stand_coordinates[i][1], x1, y1, route) < shortestDistance)
		 {
			shortestDistance = distance(taxi_stand_coordinates[i][0], taxi_stand_coordinates[i][1], x1, y1, route);
			xShortest = taxi_stand_coordinates[i][0];
			yShortest = taxi_stand_coordinates[i][1];
		 }
	}
	
	
	path1 = routeAtoB(xShortest,yShortest,x1,y1); 
	path2 = routeAtoB(x1,y1,x2,y2);
	path3 = routeAtoB(x2,y2,xShortest,yShortest); 
	
	i = 0; 
	j = 0; 
	while(path1[i] != NULL)
	{	
		strcpy(route[j], path1[i]); 
		j++; 
		i++; 
	}
	
	i = 0; 
	while(path2[i] != NULL)
	{	
		strcpy(route[j], path2[i]); 
		j++; 
		i++; 
	}
	
	i = 0; 
	while(path3[i] != NULL)
	{
		strcpy(route[j], path3[i]); 
		j++; 
		i++;
	}
	
	return route; 
	
}

/*
extern enum MAP_OBJ  Board[1000][1000] = {{0}};
char ** calculateRoute(int x1, int y1, int x2, int y2);
int distance(int x1, int y1, int x2, int y2, char ** route);
int landmark_entrance_coordinates[100][2],
	    landmark_boundary_coordinates[100][4],
	    taxi_stand_coordinates[10][2],
	    size[2];      

	
char ew_list[100][50],
	     ns_list[100][50],
	     landmark_names[100][100]; 
*/
void createBoard()
{
	int x = 0; 
	int y = 0; 
	int k = 0; 
	int i = 0; 
	int j = 0; 
	int a = 0; 
	int b = 0; 
	
	for (x = 0; x < size[0]; x++)
	{
		for(y = 0; y < size[1]; y++)
		{
			
			for( k = 0; k < 100; k++)
			{
				if (landmark_boundary_coordinates[k][0] == x && landmark_boundary_coordinates[k][1] == y)
				{
					
					
					/* draw the top of the landmark */
					for (i = x; i <= landmark_boundary_coordinates[k][2]; i++)
					{
						if (i == x)
						{
							Board[i][y] = TOP_LEFT_BLANK;
						}
						else if ( i == landmark_boundary_coordinates[k][2] )
						{
							Board[i][y] = TOP_RIGHT_BLANK;
						}
						else
						{
							Board[i][y] = TOP_LAND_BLANK;
						}
						
					}
					
					/* draw middle of landmark */
					for(a = y+1; a <= landmark_boundary_coordinates[k][3]-1; a++)
					{
						for(b = x+1; b <= landmark_boundary_coordinates[k][2]-1; b++)
						{
							Board[b][a] = MIDDLE_LAND_BLANK; 
						}
					}
					
					/* draw bottom of landmark */
					for (i = x; i <= landmark_boundary_coordinates[k][2]; i++)
					{
						if (i == x)
						{
							Board[i][y] = BOT_LEFT_BLANK; 
						}
						else if (i == landmark_boundary_coordinates[k][2])
						{
							Board[i][y] = BOT_RIGHT_BLANK; 
						}
						else
						{
							Board[i][y] = BOT_LAND_BLANK;
						}
					} 
					
					/* draw left side of landmark */
					for (a = y+1; a <= landmark_boundary_coordinates[k][3]-1; a++)
					{
						Board[landmark_boundary_coordinates[k][0]][a] = LEFT_LAND_BLANK;
					}
					
					/* draw right side of landmark */
					for (a = y+1; a <= landmark_boundary_coordinates[k][3]-1; a++)
					{
						Board[landmark_boundary_coordinates[k][0]][a] = RIGHT_LAND_BLANK;
					}
					
					
				}
			
				
				
			}
		}
	}
	
}

int distance(int x1, int y1, int x2, int y2, char ** route)
{	
	
	int i = 0; 
	int j = 0; 
	int a = 0;
	int distance = 0; 
	
	/* clear the route buffer */
	for (j = 0; j < 100; j++)
	{
		route[j] = NULL; 
	}
	
	
	/* this while loop calculates the route to the taxi's final destination after it has picked up the customer */
	while (x1 != x2 && y1 != y2)
	{
		/* first start with x coordinate */
		
		if ( (x2 > x1) && (y2 < y1) )
		{
			if (Board[x1+1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				
				y1--; 
				distance++; 
			}
			else
			{
				 
				x1++; 
				distance++; 
			}
		}
		else if ( (x2 < x1) && (y2 < y1) )
		{
			if (Board[x1-1][y1] >= 20 && Board[x1-1][y1] < 30)
			{
				
				y1--;
				distance++; 
			}
			else
			{
				
				x1--;
				distance++; 
			}
		}
		else if ((x2 < x1) && (y2 > y1))
		{
			if(Board[x1 -1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				
				y1++;
				distance++; 
			}
			else
			{
				
				x1--;
				distance++; 
			}
		}
		else if ((x2 > x1) && (y2 > y1))
		{
			if(Board[x1+1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				
				x1++; 
				distance++; 
			}
			else
			{
				
				y1++; 
				distance++; 
			}
		}
		else if ((y1 == y2) && (x1 < x2)) /* if on same street */
		{	
			if(Board[x1+1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				
				y1++; 
				distance++; 
			}
			else
			{
			
				x1++; 
				distance++; 
			}
		}
		else if ( (y1 == y2) && (x1 > x2) )
		{
			if(Board[x1-1][y1] >= 20 && Board[x1-1][y1] < 30)
			{
				
				y1++; 
				distance++; 
			}
			else
			{
				
				x1--; 
				distance++; 
			}
		}
		else if ( (x1 == x2) && (y1 < y2) )
		{
			if(Board[x1][y1+1] >= 20 && Board[x1+1][y1+1] < 30)
			{
				
				x1++; 
				distance++; 
			}
			else
			{
				
				y1++; 
				distance++; 
			}
		}
		else if ( (x1 == x2) && (y1 > y2) )
		{
			if(Board[x1+1][y1] >= 20 && Board[x1+1][y1] < 30)
			{
				
				x1++; 
				distance++; 
			}
			else
			{
				
				y1--; 
				distance++; 
			}
		}
		
		
		
		i++; 

		
	} /* END WHILE */
		
	return distance; 
} 
