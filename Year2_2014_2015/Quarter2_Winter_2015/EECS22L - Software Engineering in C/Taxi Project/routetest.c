
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>


extern enum MAP_OBJ  Board[1000][1000] = {{0}};
char ** calculateRoute(int x1, int y1, int x2, int y2);
int distance(int x1, int y1, int x2, int y2, char ** route);


/*function declaration*/
int readmap(char ew_list[100][50], char ns_list[100][50], char landmark_names[100][100],
	int landmark_entrance_coordinates[100][2], int landmark_boundary_coordinates[100][4],
	int taxi_stand_coordinates[10][2], int size[2]);


int main()
{
	int landmark_entrance_coordinates[100][2],
		landmark_boundary_coordinates[100][4],
		taxi_stand_coordinates[10][2],
		size[2];


	char ew_list[100][50],
		ns_list[100][50],
		landmark_names[100][100]; /* read map stuff */

	readmap(ew_list, ns_list, landmark_names, landmark_entrance_coordinates, landmark_boundary_coordinates, taxi_stand_coordinates, size);
	
	/* create the board */
	createBoard();

	return 0;
}

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

int readmap(char ew_list[100][50], char ns_list[100][50], char landmark_names[100][100],
	int landmark_entrance_coordinates[100][2], int landmark_boundary_coordinates[100][4],
	int taxi_stand_coordinates[10][2], int size[2])
{
	FILE *ptr_file;
	char cfile;
	/*indexing variable*/
	int i = 0;/*keyword_string*/
	int j = 0, k = 0;/*ns_list or ew_list*/
	int m = 0; /*at_and_string*/
	int r = 0, s = 0;/*landmark entrance*/
	int u = 0, v = 0;/*landmark boundary*/

	/*enable variables*/
	int keyword_enable = 1;
	/*used to check for keyword*/
	char keyword_string[50];

	/*store landmark string info[index][max string length]*/
	char landmark_entrances[100][100];
	char landmark_boundaries[100][100];

	/*enable variables*/
	int name_enable = 1;
	int entrance_enable = 0;
	int boundary_enable = 0;

	/*Store taxi stand street names*/
	char taxi_stand_list[10][50];
	/*enable variables*/
	int at_and_enable = 1;
	char at_and_string[50];

	/*check end of lists*/
	int eof_ew;
	int eof_ns;
	int eof_name;
	int eof_entrance;
	int eof_boundary;
	int eof_taxi;

	/*open file stream*/
	ptr_file = fopen("map.txt", "r");
	/*Error check*/
	if (!ptr_file)
	{
		perror("Missing map.txt");
		return (-1);
	}
	/*Reading Loop*/
	do
	{
		/*holds asci character read in the text file*/
		cfile = fgetc(ptr_file);

		/*holds a keyword in string*/
		if (keyword_enable == 1 && cfile >= ' ')
		{
			keyword_string[i] = cfile;
			i++;
			/*disable the keyword checker*/
			if (cfile == ':')
			{
				keyword_enable = 0;
#ifdef DEBUG
				printf("keyword_string is : %s\n", keyword_string);
				/*Check value of strcmp*/
				printf("strcmp = %d\n", strcmp(keyword_string, "STREETS EAST-WEST:"));
				printf("strcmp = %d\n", strcmp(keyword_string, "STREETS NORTH-SOUTH:"));
				printf("strcmp = %d\n", strcmp(keyword_string, "LANDMARKS:"));
				printf("strcmp = %d\n", strcmp(keyword_string, "TAXI STANDS:"));
#endif			
			}
		}

		/*set it so the East-West list starts getting filled*/
		if (strcmp(keyword_string, "STREETS EAST-WEST:") == 0)
		{
			if (cfile != ',' && cfile != '.')
			{
				/*First character cannot be space*/
				if (k == 0 && cfile > ' ' && cfile != ':')
				{
					ew_list[j][k] = cfile;
					k++;
				}
				/*for remaining characters in string*/
				else if (k > 0 && cfile >= ' ' && cfile != '.')
				{
					ew_list[j][k] = cfile;
					k++;
				}
			}
			else if (cfile == ',' || cfile == '.')
			{
#ifdef DEBUG
				printf("%s \n", ew_list[j]);
#endif
				/*move to next index*/
				j++;
				/*reset filling in string*/
				k = 0;
			}
			if (cfile == '.')
			{
				size[0] = j;
				eof_ew = j;
			}
		}

		/*set it so the North-South list starts getting filled*/
		if (strcmp(keyword_string, "STREETS NORTH-SOUTH:") == 0)
		{
			if (cfile != ',' && cfile != '.')
			{
				/*First character cannot be space*/
				if (k == 0 && cfile > ' ' && cfile != ':')
				{
					ns_list[j][k] = cfile;
					k++;
				}
				/*for remaining characters in string*/
				else if (k > 0 && cfile >= ' ' && cfile != '.')
				{
					ns_list[j][k] = cfile;
					k++;
				}
			}
			else if (cfile == ',' || cfile == '.')
			{
#ifdef DEBUG
				printf("%s \n", ns_list[j]);
#endif
				/*move to next index*/
				j++;
				/*reset filling in string*/
				k = 0;
			}
			if (cfile == '.')
			{
				size[1] = j;
				eof_ns = j;
			}
		}

		/*set it so the Landmark list starts getting filled*/
		if (strcmp(keyword_string, "LANDMARKS:") == 0)
		{
			/*Store Landmark name strings*/
			if (name_enable == 1)
			{
				if (cfile != ';')
				{
					/*First character cannot be space*/
					if (k == 0 && cfile > ' ' && cfile != ':')
					{
						landmark_names[j][k] = cfile;
						k++;
					}
					/*for remaining characters in string*/
					else if (k > 0 && cfile >= ' ' && cfile != '.')
					{
						landmark_names[j][k] = cfile;
						k++;
					}
				}
				else if (cfile == ';')
				{
#ifdef DEBUG
					printf("%s \n", landmark_names[j]);
#endif
					/*move to next index*/
					j++;
					/*reset filling in string*/
					k = 0;
				}
			}

			/*Store Landmark Entrances strings*/
			if (entrance_enable == 1)
			{
				if (cfile != '*' && cfile != '/' && cfile != ',' && cfile != '.')
				{
					/*First character cannot be space*/
					if (s == 0 && cfile > ' ')
					{
						landmark_entrances[r][s] = cfile;
						s++;
					}
					/*for remaining characters in string*/
					else if (s > 0 && cfile >= ' ')
					{
						landmark_entrances[r][s] = cfile;
						s++;
					}
				}
				else if (cfile == '*' || cfile == '/' || cfile == ',' || cfile == '.')
				{
#ifdef DEBUG
					printf("%s \n", landmark_entrances[r]);
#endif
					/*move to next index*/
					r++;
					/*reset filling in string*/
					s = 0;
				}
			}
			/*Store Landmark Boundary strings*/
			if (boundary_enable == 1)
			{
				if (cfile != '*' && cfile != '/' && cfile != ',' && cfile != '.')
				{
					/*First character cannot be space*/
					if (v == 0 && cfile > ' ')
					{
						landmark_boundaries[u][v] = cfile;
						v++;
					}
					/*for remaining characters in string*/
					else if (v > 0 && cfile >= ' ')
					{
						landmark_boundaries[u][v] = cfile;
						v++;
					}
				}
				else if (cfile == '*' || cfile == '/' || cfile == ',' || cfile == '.')
				{
#ifdef DEBUG
					printf("%s \n", landmark_boundaries[u]);
#endif
					/*move to next index*/
					u++;
					/*reset filling in string*/
					v = 0;
				}
			}
			/*Change what array of strings is being filled*/
			if (cfile == ';')
			{
#ifdef DEBUG
				printf("Filling in entrance\n");
#endif
				name_enable = 0;
				entrance_enable = 1;
				boundary_enable = 0;
			}
			if (cfile == '*')
			{
#ifdef DEBUG
				printf("Filling in boundary\n");
#endif
				name_enable = 0;
				entrance_enable = 0;
				boundary_enable = 1;
			}
			if (cfile == '/')
			{
#ifdef DEBUG
				printf("Filling in name\n");
#endif
				name_enable = 1;
				entrance_enable = 0;
				boundary_enable = 0;
			}
			if (cfile == '.')
			{
				name_enable = 0;
				entrance_enable = 0;
				boundary_enable = 0;

				/*number of used indecies*/
				eof_name = j;
				eof_entrance = r;
				eof_boundary = u;
			}
		}

		/*set it so the Taxi Stand list starts getting filled*/
		if (strcmp(keyword_string, "TAXI STANDS:") == 0)
		{
			if (strcmp(at_and_string, "AT") == 0)
			{
				if (cfile != ',')
				{
					/*First character cannot be space*/
					if (k == 0 && cfile > ' ' && cfile != ':')
					{
						taxi_stand_list[j][k] = cfile;
						k++;
					}
					/*for remaining characters in string*/
					else if (k > 0 && cfile >= ' ' && cfile != '.')
					{
						taxi_stand_list[j][k] = cfile;
						k++;
					}
				}
			}
			if (strcmp(at_and_string, "AND") == 0)
			{
				if (cfile != ',')
				{
					/*First character cannot be space*/
					if (k == 0 && cfile > ' ' && cfile != ':')
					{
						taxi_stand_list[j][k] = cfile;
						k++;
					}
					/*for remaining characters in string*/
					else if (k > 0 && cfile >= ' ' && cfile != '.')
					{
						taxi_stand_list[j][k] = cfile;
						k++;
					}
				}
			}
			/*Check for AT or AND in text file*/
			if ((cfile == 'A' || cfile == 'T' || cfile == 'N' || cfile == 'D') && at_and_enable == 1)
			{
#ifdef DEBUG				
				printf("strcmp AT = %d\n", strcmp(at_and_string, "AT"));
				printf("strcmp AND = %d\n", strcmp(at_and_string, "AND"));
				printf("%c \n", cfile);
#endif	
				at_and_string[m] = cfile;
				m++;
				if (strcmp(at_and_string, "AT") == 0)
				{
#ifdef DEBUG
					printf("%s \n", at_and_string);
#endif
					at_and_enable = 0;
				}
				if (strcmp(at_and_string, "AND") == 0)
				{
#ifdef DEBUG
					printf("%s \n", at_and_string);
#endif
					at_and_enable = 0;
				}
			}
			if (cfile == ';')
			{
				/*reset at_and_string*/
				m = 0;
				at_and_enable = 1;
				memset(at_and_string, 0, 50);
			}
			if (cfile == ',' || cfile == '.')
			{
#ifdef DEBUG
				printf("%s \n", taxi_stand_list[j]);
#endif
				/*move to next index*/
				j++;
				/*reset filling in string*/
				k = 0;
				/*reset at_and_string*/
				m = 0;
				at_and_enable = 1;
				memset(at_and_string, 0, 50);
			}
			if (cfile == '.')
				eof_taxi = j;
		}

		/*set it so the Parking list starts getting filled*/
		if (strcmp(keyword_string, "PARKING:") == 0)
		{

		}

		/*Renable keyword reading, reset keyword_string, reset list indexing*/
		if (cfile == '.')
		{
			j = 0;
			k = 0;

			i = 0;
			keyword_enable = 1;
			memset(keyword_string, 0, 50);
		}


		/*Exits reading the file once end is reached*/
		if (feof(ptr_file))
		{
			break;
		}

	} while (1);
	/*close file stream*/
	fclose(ptr_file);

	/*fill in taxi_stand_coordinates*/
#ifdef DEBUG
	printf("Taxi Stand Coordinates\n");
#endif
	for (j = 0; j < eof_taxi; j++)
	{
		/*NS Street (X)*/
		for (i = 0; i < eof_ns; i++)
		{
			if (strcmp(taxi_stand_list[j], ns_list[i]) == 0)
			{
				taxi_stand_coordinates[j][0] = i;
#ifdef DEBUG
				printf("X coordinate: %d\n", taxi_stand_coordinates[j][0]);
#endif
				break;
			}
		}
		/*EW Street (Y)*/
		for (i = 0; i < eof_ew; i++)
		{
			if (strcmp(taxi_stand_list[j], ew_list[i]) == 0)
			{
				taxi_stand_coordinates[j][1] = i;
#ifdef DEBUG
				printf("Y coordinate: %d\n", taxi_stand_coordinates[j][1]);
#endif		
				break;
			}
		}
#ifdef DEBUG
		printf("%s \n", taxi_stand_list[j]);
#endif
	}

#ifdef DEBUG
	printf("Updated Landmark Entrance List\n");
#endif	
	/*Fix the street names in the landmark entrance list*/
	for (i = 0; i < eof_entrance; i++)
	{
		cfile = landmark_entrances[i][1];
#ifdef DEBUG
		printf("%c \n", cfile);
#endif
		/*Shifting contents of string*/
		for (j = 0; j < 99; j++)
		{
			/*For street names that have AT*/
			if (cfile == 'T')
			{
				landmark_entrances[i][j] = landmark_entrances[i][j + 3];
				if (j == 98)
				{
					for (k = 0; k < eof_ew; k++)
					{
						if (strcmp(landmark_entrances[i], ew_list[k]) == 0)
						{
							/* Y */
							landmark_entrance_coordinates[j][1] = k;
#ifdef DEBUG
							printf("Y coordinate: %d\n", landmark_entrance_coordinates[j][1]);
#endif					
							break;
						}
					}
				}
			}
			/*For street names that have AND*/
			if (cfile == 'N')
			{
				landmark_entrances[i][j] = landmark_entrances[i][j + 4];
				if (j == 98)
				{
					for (k = 0; k < eof_ns; k++)
					{
						if (strcmp(landmark_entrances[i], ns_list[k]) == 0)
						{
							/* X */
							landmark_entrance_coordinates[j][0] = k;
#ifdef DEBUG		
							printf("X coordinate: %d\n", landmark_entrance_coordinates[j][0]);
#endif
							break;
						}
					}
				}
			}
		}
#ifdef DEBUG
		printf("%s \n", landmark_entrances[i]);
#endif
	}
#ifdef DEBUG
	printf("Updated Landmark Boundary List\n");
#endif
	/*Fix the street names in the landmark boundary list*/
	for (i = 0; i < eof_boundary; i++)
	{
		cfile = landmark_boundaries[i][0];
#ifdef DEBUG
		printf("%c \n", cfile);
#endif
		for (j = 0; j < 99; j++)
		{
			/*For street names that have AT*/
			if (cfile == 'N')
			{
				landmark_boundaries[i][j] = landmark_boundaries[i][j + 6];
				/*Compare string with ns_list to determine coordinate boundary*/
				if (j == 98)
				{
					for (k = 0; k < eof_ew; k++)
					{
						if (strcmp(landmark_boundaries[i], ew_list[k]) == 0)
						{
							/*North (Y1)*/
							landmark_boundary_coordinates[j][2] = k;
#ifdef DEBUG
							printf("Y1 coordinate: %d\n", landmark_boundary_coordinates[j][2]);
#endif
							break;
						}
					}
				}
			}
			/*For street names that have AND*/
			if (cfile == 'S')
			{
				landmark_boundaries[i][j] = landmark_boundaries[i][j + 6];
				/*Compare string with ns_list to determine coordinate boundary*/
				if (j == 98)
				{
					for (k = 0; k < eof_ew; k++)
					{
						if (strcmp(landmark_boundaries[i], ew_list[k]) == 0)
						{
							/*South (Y2)*/
							landmark_boundary_coordinates[j][3] = k;
#ifdef DEBUG
							printf("Y2 coordinate: %d\n", landmark_boundary_coordinates[j][3]);
#endif					
							break;
						}
					}
				}
			}
			/*For street names that have AND*/
			if (cfile == 'E')
			{
				landmark_boundaries[i][j] = landmark_boundaries[i][j + 5];
				/*Compare string with ns_list to determine coordinate boundary*/
				if (j == 98)
				{
					for (k = 0; k < eof_ns; k++)
					{
						if (strcmp(landmark_boundaries[i], ns_list[k]) == 0)
						{
							/*East (X2)*/
							landmark_boundary_coordinates[j][1] = k;
#ifdef DEBUG
							printf("X2 coordinate: %d\n", landmark_boundary_coordinates[j][1]);
#endif
							break;
						}
					}
				}
			}
			/*For street names that have AND*/
			if (cfile == 'W')
			{
				landmark_boundaries[i][j] = landmark_boundaries[i][j + 5];
				/*Compare string with ns_list to determine coordinate boundary*/
				if (j == 98)
				{
					for (k = 0; k < eof_ns; k++)
					{
						if (strcmp(landmark_boundaries[i], ns_list[k]) == 0)
						{
							/*West (X1)*/
							landmark_boundary_coordinates[j][0] = k;
#ifdef DEBUG
							printf("X1 coordinate: %d\n", landmark_boundary_coordinates[j][0]);
#endif	
							break;
						}
					}
				}
			}
		}
#ifdef DEBUG
		printf("%s \n", landmark_boundaries[i]);
#endif
	}

	return 0;
}