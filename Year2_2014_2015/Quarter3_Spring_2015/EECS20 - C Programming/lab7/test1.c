#include <stdio.h>
int main()
{
	int c;
	int i;
	for (i = 0; i < 10; i++){
		printf("Enter a value :");
		c = getchar();

		printf("\nYou entered: ");
		putchar(c);
	}
	return 0;
}