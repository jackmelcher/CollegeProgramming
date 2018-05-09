#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(void)
{
	/*Initialization and Declaration*/
	float a, b, c, d, f, g, conjugate, modulus;
	char selection;
	
		while (1)
		{
			printf("Press + to add two complex numbers\n");
			printf("Press - to subtract two complex numbers\n");
			printf("Press * to multiply two complex numbers\n");
			printf("Press c to find the conjugate of two complex numbers\n");
			printf("Press m to find the complex modulus of two complex numbers\n");
			printf("Press e to exit\n");
			printf("Please select your operation:");
			scanf(" %c", &selection);

			switch (selection)
			{
			/*Sum*/
			case'+':
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
				/*Calculation of Sum*/
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
				break;
			/*Difference*/
			case'-':
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
				/*Calculation of Difference*/
				f = (a - c);
				g = (b - d);
				
				if (g >= 0)
				{
					printf("The difference of the two complex numbers is %f+%fi\n", f, g);
				}
				else
				{
					printf("The difference of the two complex numbers is %f%fi\n", f, g);
				}
				break;
			/*Multiplication*/
			case'*':
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
				/*Calculation of Multiplication*/
				f = (a*c - b*d);
				g = (a*d + b*c);

				if (g >= 0)
				{
					printf("The product of the two complex numbers is %f+%fi\n", f, g);
				}
				else
				{
					printf("The product of the two complex numbers is %f%fi\n", f, g);
				}
				break;
			/*Conjugate*/
			case'c':
				printf("Enter a and b where the complex number is a + bi\n");
				printf("a=");
				scanf("%f", &a);
				printf("b=");
				scanf("%f", &b);
				/*Finds the Conjugate*/
				if (b <= 0)
				{
					printf("The complex conjugate of (%f%fi)", a, b);
					conjugate = b*(-1);
					printf("is %f+%fi\n", a, conjugate);
				}
				else
				{
					printf("The complex conjugate of (%f+%fi)", a, b);
					conjugate = b*(-1);
					printf("is %f%fi\n", a, conjugate);
				}
				break;
			/*Modulus*/
			case'm':printf("Enter a and b where the complex modulus is\n");
					printf("a=");
					scanf("%f", &a);
					printf("b=");
					scanf("%f", &b);
				/*Finds the Modulus*/
				if (b <= 0)
				{
					printf("The complex modulus of |%f%fi|", a, b);
					modulus = sqrt(pow(a, 2) + pow(b, 2));
					printf("is %f\n", modulus);
				}
				else
				{
					printf("The complex modulus of |%f+%fi|", a, b);
					modulus = sqrt(pow(a, 2) + pow(b, 2));
					printf("is %f\n", modulus);
				}
				break;

			case'e':
				/*Terminates Program*/
				exit(0);
				break;

			}

		}
	
	return 0;
}