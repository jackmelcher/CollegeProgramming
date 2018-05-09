#include<stdio.h>
#include<math.h>
int main(void)
{
	float population,initial,rate,time,increments,t;
	const float e=2.71828;
	t = 0;

	printf("Enter the initial bacteria population:");
	scanf("%f",&initial);
	
	printf("Enter the bacterial growth rate:");
	scanf("%f",&rate);
	
	printf("Enter the time that the bacteria is allowed to reproduce(in minutes):");
	scanf("%f",&time);
	
	printf("Enter the increments of time(in minutes) you want to measure:");
	scanf("%f",&increments);
	
	if ((rate > 0)&&(rate < 1))
	{
		while (t <= time)
		{
			population = initial * pow(e, rate*t);
			printf("In %f minutes the bacteria population is %f\n", increments, population);
			t = t + increments;
		}
	}
	else
	{
		printf("Invalid entry. You must enter a number between 0 and 1!\n");
	}
	return 0;
}
