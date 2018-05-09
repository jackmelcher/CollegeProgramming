#include<stdio.h>
#define size 5
void multiply(int c[], int size);//function prototype

int main(void)
{
	int a[size];
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Enter a value for a[%d]: ",i);
		scanf("%d", &a[i]);
	}
	
	multiply(a, size);

	for (i = 0; i < size; i++)
	{
		printf("a[%d] is now: %d\n", i, a[i]);
	}

	return 0;
}

void multiply(int c[], int size)//function
{
	int j;
	for (j = 0; j < size; j++)
	{
		c[j] = c[j] * 2;
	}
}