/* Jack C. Melcher */
/* SID: 67574625 */
/* EECS 20 */
/* Lab 5c*/

#include <stdio.h>

int main (void){

	int one, two, three, four, five, six;
	int number;

	printf("Enter an integer that is up to 6 digits long: ");
	scanf("%d",&number);
	
	one = number/100000;
	number = number - one*100000;
	two = number/10000;
	number = number - two*10000;
	three = number/1000;
	number = number - three*1000;
	four = number/100;
	number = number - four*100;
	five = number/10;
	number = number - five*10;
	six = number;
	
	printf("The digits are: %d %d %d %d %d %d\n",one,two,three,four,five,six);

	return 0;
}
