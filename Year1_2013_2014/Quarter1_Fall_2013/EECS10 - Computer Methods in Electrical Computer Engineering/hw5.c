#include <stdio.h>
#include <string.h>
int main (void)
{
	char horizontal[70];//total size of string
	char vertical[70];//total size of string
	int y = 0;//counter for character in vertical string
	int i = 0;//counter for length between sides
	
	printf("This program is used to print a rectangle using 2 words\n");

	/*Input strings*/
	printf("Enter a word to be the length (vertical):");
	scanf("%s", vertical);
	printf("Enter a word to be the width (horizontal):");
	scanf("%s", horizontal);

	int lengthA = strlen(horizontal);//provides the length of string
	int lengthB = strlen(vertical);//provides the length of string

	/*Top of Rectangle*/
	printf(" %s\n", horizontal);
	
	/*Sides of Rectangle*/
	while (y < lengthB)
	{
		printf("%c", vertical[y]);

		for (i = 0; i < lengthA; i++)
		{
			printf(" ");
		}
		printf("%c\n", vertical[y]);
		y = y + 1;
	}

	/*Bottom of Rectangle*/
	printf(" %s\n", horizontal);

	return 0;
}