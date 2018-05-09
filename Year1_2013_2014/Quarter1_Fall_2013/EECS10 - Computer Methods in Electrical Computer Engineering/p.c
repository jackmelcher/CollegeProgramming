#include<stdio.h>

int square(int c);//function declaration

int main(void)
{
	int a = 0;
	int b = 0;

	printf("Enter a value for a: ");
	scanf("%d", &a);

	printf("Enter a value for b: ");
	scanf("%d", &b);
	
	printf("a is now: %d\n", square(a));
	printf("b is now: %d\n", square(b));

	return 0;
}

int square(int c)
{
	return c*c;
}