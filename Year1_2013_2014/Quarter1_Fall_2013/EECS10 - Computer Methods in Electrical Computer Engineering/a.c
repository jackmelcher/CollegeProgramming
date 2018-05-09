#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void)
{
	/*Initialization and Declaration*/
	float a, b, c, d, f, g;
	
	printf("Enter a and b where the first complex number is a + bi\n");
				printf("a=");
				scanf("%f", &a);
				printf("b=");
				scanf("%f", &b);

				printf("Enter c and d where the second complex number is c+di\n");
				printf("c=");
				scanf("%f", &c);
				printf("d=");
				scanf("%f", &d);

				f = (a + c);
				g = (b + d);
				
				if (g >= 0)
				{
					printf("The sum of the two complex numbers is %f+%fi\n", f, g);
				}
				else
				{
					printf("The sum of the two complex numbers is %f%fi\n", f, g);
				}
	return 0;
}