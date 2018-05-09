/*Reading Map*/

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
	char landmark_names[100][500];
	char landmark_entrances[100][500];
	char landmark_boundaries[100][500];
	/*store landmark entrances and boundaries[index]
	[Entrance: NS STREET(X), EW STREET(Y),
	Boundaries: West (X1), East (X2), North (Y1), South (Y2)]*/
	int landmark_entrance_coordinates[100][2];
	int landmark_boundary_coordinates[100][4];
	/*enable variables*/
	int name_enable = 1;
	int entrance_enable = 0;
	int boundary_enable = 0;

	/*Store taxi stand street names*/
	char taxi_stand_list[10][50];
	/*store taxi stand location [Stand Number]
	[North-South Street (X),East-West Street (Y)]*/
	int taxi_stand_coordinates[10][2];
	/*enable variables*/
	int at_and_enable = 1;
	char at_and_string[50];
	
	/*check end of lists*/
	int eof_ew;
	int eof_ns;
	int eof_taxi;

	/*open file stream*/
	ptr_file = fopen("map.txt", "r");
	/*Error check*/
	if (!ptr_file)
		return (-1);

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
#ifdef DEBUG
				printf("%s \n", ns_list[j]);
#endif
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
					printf("index : %d \n", j);
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
				if (strcmp(at_and_string, "AT") == 0)
				{
					if (cfile != ',')
					{
						/*First character cannot be space*/
						if (s == 0 && cfile > ' ' && cfile != ':')
						{
							landmark_entrances[r][s] = cfile;
							s++;
						}
						/*for remaining characters in string*/
						else if (s > 0 && cfile >= ' ' && cfile != '.')
						{
							landmark_entrances[r][s] = cfile;
							s++;
						}
					}
				}
				if (strcmp(at_and_string, "AND") == 0)
				{
					if (cfile != ',')
					{
						/*First character cannot be space*/
						if (s == 0 && cfile > ' ' && cfile != ':')
						{
							landmark_entrances[r][s] = cfile;
							s++;
						}
						/*for remaining characters in string*/
						else if (s > 0 && cfile >= ' ' && cfile != '.')
						{
							landmark_entrances[r][s] = cfile;
							s++;
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
						printf("%s \n", at_and_string);
						at_and_enable = 0;
					}
					if (strcmp(at_and_string, "AND") == 0)
					{
						printf("%s \n", at_and_string);
						at_and_enable = 0;
					}
				}
			}
			
			/*Store Landmark Boundary strings*/
			if (boundary_enable == 1)
			{

			}






			if (cfile == ';')
			{
				printf("%s \n", landmark_names[j]);
				/*reset at_and_string*/
				m = 0;
				at_and_enable = 1;
				memset(at_and_string, 0, 50);
			}
			if (cfile == ',' || cfile == '.')
			{
				printf("index : %d \n", j);
				printf("%s \n", landmark_entrances[r]);
				/*move to next index*/
				r++;
				/*reset filling in string*/
				s = 0;
				/*reset at_and_string*/
				m = 0;
				at_and_enable = 1;
				memset(at_and_string, 0, 50);
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
					printf("%s \n", at_and_string);
					at_and_enable = 0;
				}
				if (strcmp(at_and_string, "AND") == 0)
				{
					printf("%s \n", at_and_string);
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
				printf("index : %d \n", j);
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

	/*fill in taxi_stand_coordinates*/
	for (j = 0; j < eof_taxi; j++)
	{
		/*NS Street (X)*/
		for (i = 0; i < 100; i++)
		{
			if (strcmp(taxi_stand_list[j], ns_list[i]) == 0)
			{
				taxi_stand_coordinates[j][0] = i;
				printf("X coordinate: %d\n", taxi_stand_coordinates[j][0]);
				break;
			}
		}
		/*EW Street (Y)*/
		for (i = 0; i < 100; i++)
		{
			if (strcmp(taxi_stand_list[j], ew_list[i]) == 0)
			{
				taxi_stand_coordinates[j][1] = i;
				printf("Y coordinate: %d\n", taxi_stand_coordinates[j][1]);
				break;
			}
		}
	}

	/*close file stream*/
	fclose(ptr_file);

	return 0;
}