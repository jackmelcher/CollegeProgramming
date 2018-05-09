#include <stdio.h>
#include <math.h>
int main(void)
{
	/*Declaration and Initialization*/
	float a,b,c,theta,radian,P,S;
	const float pi=3.14159;

		/*Input*/
		printf("Enter value of a (in cm):");
		scanf("%f",&a);
		printf("Enter value of b (in cm):");
		scanf("%f",&b);
		printf("Enter value of theta (in degrees):");
		scanf("%f",&theta);

			/*Calculations and Output*/
			radian = theta*pi / 180;
			c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a*b*cos(radian));

			P = a + b + c;
			printf("The Perimeter of the triangle is %fcm.\n", P);
				
			S = 0.5*a*b*sin(radian);
			printf("The Area of the triangle is %fcm^2.\n", S);

	return 0;
}