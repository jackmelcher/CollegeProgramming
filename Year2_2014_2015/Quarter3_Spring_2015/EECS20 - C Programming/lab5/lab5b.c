/* Jack C. Melcher */
/* SID: 67574625 */
/* EECS 20 */
/* Lab 5b*/

#include <stdio.h>

int main (void){
	
	int a = 0, b = 0, c = 0, d = 0;
	int sum, prod, mod;
	
	/* Input four integers */
	printf("Enter first integer: ");
	scanf("%d", &a);
	printf("Enter second integer: ");
	scanf("%d", &b);
	printf("Enter third integer: ");
	scanf("%d", &c);
	printf("Enter fourth integer: ");
	scanf("%d", &d);

	/* sum of four numbers */
	sum = a + b + c + d;
	printf("Sum of four numbers: %d\n", sum);
	/* product of four numbers */
	prod = a * b * c * d;
	printf("Product of four numbers: %d\n", prod);
	/* modulus of the first two numbers */
	mod = a % b;
	printf("Modulus of first two numbers: %d\n", mod);
	
	return 0;
}
