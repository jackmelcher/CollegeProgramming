#include<stdio.h>

void multiply(int c[]);//function prototype

int main(void)
{
	int a[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("Enter a value for a[%d]: ",i);
		scanf("%d", &a[i]);
	}
	
	multiply(a);

	for (i = 0; i < 5; i++)
	{
		printf("a[%d] is now: %d\n", i, a[i]);
	}

	return 0;
}

void multiply(int c[])//function
{
	int j;
	for (j = 0; j < 5; j++)
	{
		c[j] = c[j] * 2;
	}
}