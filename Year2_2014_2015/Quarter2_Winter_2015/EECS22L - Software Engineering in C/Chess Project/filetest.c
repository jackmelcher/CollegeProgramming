#include <stdio.h>

int main()
{
	char s[100];
	printf("Input string: ");
	scanf("%s", s);
	FILE *fp;
	fp = fopen("output.txt", "w");
	fprintf(fp, "%s\n", s);
	fclose(fp);

	return 0;
}
