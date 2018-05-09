/*Reading Map*/

#include<stdio.h>
#include <string.h>


int main()
{
	/*strcpy check var*/
	int check;
	/*integer to string test*/
	char word[20];

	/*counter*/
	int i = 0;
	/*File I/O variables*/
	FILE *ptr_file;
	char buff[1000];

	/*Stores East-West street names*/
	char ew_map[50][100];
	/*Stores North-South street names*/
	char ns_map[50][100];

	/* Get East-West Streets*/
	ptr_file = fopen("east_west.txt", "r");

	/*error check*/
	if (!ptr_file)
		return 1;

	/*read loop*/
	while (fgets(buff, 1000, ptr_file) != NULL)
	{
		strcpy(ew_map[i], buff);
		printf("%s", ew_map[i]);

		i++;
	}
	/*close file*/
	fclose(ptr_file);

	printf("check street names are valid\n");
	printf("%s", ew_map[0]);
	printf("%s", ns_map[0]);

	/*reset counter*/
	i = 0;
	printf("\n");

	/* Get North-South Streets*/
	ptr_file = fopen("north_south.txt", "r");
	/*read loop*/
	while (fgets(buff, 1000, ptr_file) != NULL)
	{
		strcpy(ns_map[i], buff);
		printf("%s", ns_map[i]);
		i++;
	}
	printf("%s", ew_map[0]);
	printf("\n");
	/*close file*/
	fclose(ptr_file);

	printf("check street names are valid\n");
	printf("%s", ew_map[0]);
	printf("%s", ns_map[0]);


	/*Test street compare names*/
	/*NS*/
	printf("Test reading street names\n");

	printf("%s", ns_map[0]);
	check = strcmp(ns_map[0], "1st Street");
	printf("check: %d\n", check);
	if (check == 0)
		printf("Test successful\n");
	else
		printf("Test Failed\n");

	/*Apparently, the carriage return is affecting value of string and how its printed*/
	/*carriage return has a value of 13, so i subtracted the check by 13*/
	printf("%s", ns_map[0]);
	check = strcmp(ns_map[0], "1st Street") - 13;
	printf("check: %d\n", check);
	if (check == 0)
		printf("Test successful\n");
	else
		printf("Test Failed\n");

	check = strcmp("1st Street", "1st Street");
	printf("check: %d\n", check);
	if (check == 0)
		printf("Test successful\n");
	else
		printf("Test Failed\n");

	/*integer to char test*/
	word[0] = 65;
	word[1] = 66;
	word[2] = 67;
	word[3] = 68;
	word[4] = 69;

	/*take line and */
	i = 0;
	printf("%s\n", word);
	while (ns_map[0][i] >= ' ')
	{
		word[i] = ns_map[0][i];
		i++;
	}
	printf("%s\n", word);
	printf("%s", ns_map[0]);

	check = strcmp(word, "1st Street");
	printf("check: %d\n", check);
	if (check == 0)
		printf("Test successful\n");
	else
		printf("Test Failed\n");

	return 0;


}