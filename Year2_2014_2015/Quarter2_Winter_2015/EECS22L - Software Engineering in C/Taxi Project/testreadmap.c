/*Test Reading Map*/
/*Jack Melcher 67574625*/
/*3/1/2015*/

#include<stdio.h>
#include<string.h>

int main()
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

	/*stores list of street names [index][max string length]*/
	char ew_list[100][50];
	char ns_list[100][50];

	/*store landmark string info[index][max string length]*/
	char landmark_names[100][100];
	char landmark_entrances[100][100];
	char landmark_boundaries[100][100];

	/*landmark entrances[index][Entrance: NS STREET(X), EW STREET(Y)]*/
	/*landmark boundaries[Boundaries: West (X1), East (X2), North (Y1), South (Y2)]*/
	int landmark_entrance_coordinates[100][2];
	int landmark_boundary_coordinates[100][4];
	/*enable variables*/
	int name_enable = 1;
	int entrance_enable = 0;
	int boundary_enable = 0;

	/*store taxi stand location [Stand Number]
	[North-South Street (X),East-West Street (Y)]*/
	int taxi_stand_coordinates[10][2];
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
				printf("keyword_string is : %s\n", keyword_string);
				/*Check value of strcmp*/
#ifdef DEBUG
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
				printf("%s \n", ew_list[j]);
				/*move to next index*/
				j++;
				/*reset filling in string*/
				k = 0;
			}
			if (cfile == '.')
				eof_ew = j;
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
				printf("%s \n", ns_list[j]);
				/*move to next index*/
				j++;
				/*reset filling in string*/
				k = 0;
			}
			if (cfile == '.')
				eof_ns = j;
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
					printf("index : %d \n", j);
#endif
					printf("%s \n", landmark_names[j]);
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
					printf("index : %d \n", r);
#endif
					printf("%s \n", landmark_entrances[r]);

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
					printf("index : %d \n", u);
#endif
					printf("%s \n", landmark_boundaries[u]);

					/*move to next index*/
					u++;
					/*reset filling in string*/
					v = 0;
				}
			}
			/*Change what array of strings is being filled*/
			if (cfile == ';')
			{
				printf("Filling in entrance\n");
				name_enable = 0;
				entrance_enable = 1;
				boundary_enable = 0;
			}
			if (cfile == '*')
			{
				printf("Filling in boundary\n");
				name_enable = 0;
				entrance_enable = 0;
				boundary_enable = 1;
			}
			if (cfile == '/')
			{
				printf("Filling in name\n");
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
				printf("index : %d \n", j);
#endif
				printf("%s \n", taxi_stand_list[j]);
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
	printf("Taxi Stand Coordinates\n");
	for (j = 0; j < eof_taxi; j++)
	{
		/*NS Street (X)*/
		for (i = 0; i < eof_ns; i++)
		{
			if (strcmp(taxi_stand_list[j], ns_list[i]) == 0)
			{
				taxi_stand_coordinates[j][0] = i;
				printf("X coordinate: %d\n", taxi_stand_coordinates[j][0]);
				break;
			}
		}
		/*EW Street (Y)*/
		for (i = 0; i < eof_ew; i++)
		{
			if (strcmp(taxi_stand_list[j], ew_list[i]) == 0)
			{
				taxi_stand_coordinates[j][1] = i;
				printf("Y coordinate: %d\n", taxi_stand_coordinates[j][1]);
				break;
			}
		}
		printf("%s \n", taxi_stand_list[j]);
	}


	printf("Updated Landmark Entrance List\n");
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
							printf("Y coordinate: %d\n", landmark_entrance_coordinates[j][1]);
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
							printf("X coordinate: %d\n", landmark_entrance_coordinates[j][0]);
							break;
						}
					}
				}
			}
		}
		printf("%s \n", landmark_entrances[i]);
	}

	printf("Updated Landmark Boundary List\n");
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
							printf("Y1 coordinate: %d\n", landmark_boundary_coordinates[j][2]);
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
							printf("Y2 coordinate: %d\n", landmark_boundary_coordinates[j][3]);
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
							printf("X2 coordinate: %d\n", landmark_boundary_coordinates[j][1]);
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
							printf("X1 coordinate: %d\n", landmark_boundary_coordinates[j][0]);
							break;
						}
					}
				}
			}
		}
		printf("%s \n", landmark_boundaries[i]);
	}


	return 0;
}