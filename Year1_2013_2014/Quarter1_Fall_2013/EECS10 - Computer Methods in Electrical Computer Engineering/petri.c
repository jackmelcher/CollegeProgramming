#include<stdio.h>
#include<math.h>
int main(void)
{
	/*Declaration and initialization*/
	int population, initial;
	float rate,time,increments,t;
	const float e=2.71828;
	t = 0;
	/*Input*/
	printf("Enter the initial bacteria population:");
	scanf("%d",&initial);
	
	printf("Enter the bacterial growth rate:");
	scanf("%f",&rate);
	
	printf("Enter the time that the bacteria is allowed to reproduce(in minutes):");
	scanf("%f",&time);
	
	printf("Enter the increments of time(in minutes) you want to measure:");
	scanf("%f",&increments);
	/*Calculation and Output*/
	if ((rate > 0)&&(rate < 1)&&(time >= 0)&&(initial >= 0)&&(increments > 0))
	{
		while (t <= time)
		{
			population = initial * pow(e, rate*t);
			printf("In %f minutes the bacteria population is %d\n", t, population);
			t = t + increments;
		}
	}
	else
	{
		printf("Invalid entry. The growth rate entered must be between 0 and 1!\n");
		printf("Invalid entry. The time entered must be greater than or equal to 0!\n");
		printf("Invalid entry. The initial population entered must be greater than or equal to 0!\n");
		printf("Invalid entry. The increments of time must be greater than 0!\n");
	}
	return 0;
}
