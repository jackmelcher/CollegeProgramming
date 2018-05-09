#include<stdio.h>

int * function(int array2[100])
{
	array2[0] = (array2[0]) * 2;
	return array2[100];
}

int * function(int array2[100]);
int main(void)
{
	int array1[100];

	printf("Enter a number: ");
	scanf("%d", &array1[0]);

	function(array1[100]);

	printf("This is the number now:%d\n", array1[0]);

	return 0;
}

