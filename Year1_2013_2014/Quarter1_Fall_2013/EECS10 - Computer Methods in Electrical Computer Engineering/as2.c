				 lude <stdio.h>
#inc l ude < m ath.h>
int main(void)
{
	printf("This program calculates the Perimeter and Area of a Triangle when a,b, and theta are inputed\n");

	float a,b,c,theta,radian,P,S;

	const float pi=3.14159;

		printf("Enter value a in centimeters:");
		scanf("%f",&a);
		printf("Enter value b in centimeters:");
		scanf("%f",&b);
		printf("Enter value theta in degrees:");
		scanf("%f",&theta);

		if(a > 0)&&(b > 0)&&(theta < 180)&&(theta > 0)
		{
			radian = theta*pi / 180;
			c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a*b*cos(radian));
			P = a + b + c;
			printf("The Perimeter of the triangle is %f\n", P);
			S = 0.5*a*b*sin(radian);
			printf("The Area of the triangle is %f\n", S);
		}
		else
		{
			printf("invalid values for a, b, or theta. Please try again.\n");
		}
	return 0;
}