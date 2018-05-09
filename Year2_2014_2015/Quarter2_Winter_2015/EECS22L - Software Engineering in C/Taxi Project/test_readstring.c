#include <stdio.h>
#include <string.h>

/*Function Declaration*/
int readmap(char ew_list[100][50], char ns_list[100][50], char landmark_names[100][100],
	int landmark_entrance_coordinates[100][2], int landmark_boundary_coordinates[100][4],
	int taxi_stand_coordinates[10][2], int size[2]);

int main ()
{
	/*readmap function variables*/
	char ew_list[100][50];
	char ns_list[100][50];
	char landmark_names[100][100];
	int landmark_entrance_coordinates[100][2];
	int landmark_boundary_coordinates[100][4];
	int taxi_stand_coordinates[10][2];
	int size[2];

	/*char reading[100] = "REQUEST RIDE FROM CORNER 1st Street AND Antbeater Road TO CORNER 10th Street AND Cauliflower Ave NOW";*/
	/*char reading[100] = "REQUEST RIDE FROM University of New Irvine TO Grand Park NOW";*/
	char reading[100] = "REQUEST RIDE FROM CORNER 1st Street AND Antbeater Road TO New Irvine Train Station NOW";

	/*Stores the streets that we ge from request line*/
	char store[4][100];
	int street_or_land[4];/* 0 for street, 1 for landmark*/
	int client_read_storage[][];

	/*counter variables*/
	int x = 0, y = 0;
	int i = 0;
	int j = 0, k = 0;

	/*boolean integers*/
	int storing = 0;

	/*Call readmap*/
	readmap(ew_list, ns_list, landmark_names, landmark_entrance_coordinates, landmark_boundary_coordinates, taxi_stand_coordinates, size);

	/* Read client request string */
	for (x = 0; x < 100; x++)
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

	/*Some sort of strcmp loop to get the pickup and dropoff coordinates of client*/
	/*Compare to all lists*/
	i = 0;
	for (x = 0; x < 100 ;x++)
	{
		for ()
		{
			if (strcmp(store[i], ew_list[x]) == 0)
			{

			}
			if (strcmp(store[i], ns_list[x]) == 0)
			{

			}
		}
	}


	return 0;
}


/*********************************************************/
/*readmap.c: source file for read map function           */
/*Jack Melcher 67574625                                  */
/*3/1/2015											     */
/*********************************************************/

/*Function Definition*/

/*stores list of street names [index][max string length]*/
/*store landmark names[index][max string length]*/
/*landmark entrances[index][Entrance: NS STREET(X), EW STREET(Y)]*/
/*landmark boundaries[index][Boundaries: West (X1), East (X2), North (Y1), South (Y2)]*/
/*store taxi stand location [index][North-South Street (X),East-West Street (Y)]*/
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