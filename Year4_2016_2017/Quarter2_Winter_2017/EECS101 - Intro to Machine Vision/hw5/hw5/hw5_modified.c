// Jack Melcher
// 67574625
// EECS 101
// HW5

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ROWS	480
#define COLUMNS	640
#define sqr(x)	((x)*(x))
#define pi 3.14159265359

void clear(unsigned char image[][COLUMNS]);
void header(int row, int col, unsigned char head[32]);

int main(int argc, char** argv)
{
	int				i, j, a, b, temp;
	int				dedx, dedy, sgm, sgm_array[ROWS][COLUMNS], gx_array[ROWS][COLUMNS], gy_array[ROWS][COLUMNS];
	int				sgm_threshold = 20, hough_threshold = 150, voting[180][400], theta_degrees, rho, delta_theta, delta_rho;
	float			sgm_max = 0, sgm_normalize, theta_rads, voting_max = 0, voting_normalize;
	FILE*			fp;
	unsigned char	image[ROWS][COLUMNS], sgm_image[ROWS][COLUMNS], sgm_bimage[ROWS][COLUMNS], voting_image[180][400], voting_bimage[180][400], reconstructed_image[ROWS][COLUMNS], head[32], head_b[32];
	char			filename[50], ch;

	strcpy(filename, "image.raw");
	memset(voting, 0, sizeof(int) * 180 * 400);
	header(ROWS, COLUMNS, head);
	header(180, 400, head_b);

	/* Open image */
	if (!(fp = fopen(filename, "rb")))
	{
		fprintf(stderr, "error: couldn't open %s\n", argv[1]);
		exit(1);
	}
	/* Copy to image array */
	for (i = 0; i < ROWS; i++)
		if (!(COLUMNS == fread(image[i], sizeof(char), COLUMNS, fp)))
		{
			fprintf(stderr, "error: couldn't read %s\n", argv[1]);
			exit(1);
		}
	fclose(fp);

	/* SGM Calculation */
	for (i = ROWS - 1; i > 0; i--) {
		for (j = COLUMNS - 1; j > 0; j--)
		{
			dedx =
				-image[i - 1][j - 1] + image[i - 1][j + 1] +
				-2 * image[i][j - 1] + 2 * image[i][j + 1] +
				-image[i + 1][j - 1] + image[i + 1][j + 1];

			gx_array[i][j] = dedx;

			dedy =
				-image[i - 1][j - 1] - 2 * image[i - 1][j] - image[i - 1][j + 1] +
				image[i + 1][j - 1] + 2 * image[i + 1][j] + image[i + 1][j + 1];

			gy_array[i][j] = dedy;

			sgm = sqr(dedx) + sqr(dedy);

			sgm_array[i][j] = sgm;

			if (sgm_max < sgm) {
				sgm_max = sgm;
			}
		}
	}

	/* Normalize SGM array to SGM Image */
	sgm_normalize = (float)255 / sgm_max;
	for (i = 1; i < ROWS - 1; i++) {
		for (j = 1; j < COLUMNS - 1; j++) {
			sgm = sgm_array[i][j] * sgm_normalize;
			if (sgm > 255) {
				sgm_image[i][j] = 255;
			}
			else {
				sgm_image[i][j] = sgm;
			}
		}
	}

	/* Write SGM Image */
	strcpy(filename, "sgm_image");
	if (!(fp = fopen(strcat(filename, ".ras"), "wb")))
	{
		fprintf(stderr, "error: could not open %s\n", filename);
		exit(1);
	}
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++) fwrite(sgm_image[i], 1, COLUMNS, fp);

	fclose(fp);


	/* Convert SGM Image to Binary Image using SGM Threshold*/
	for (i = 1; i < ROWS - 1; i++) {
		for (j = 1; j < COLUMNS - 1; j++) {

			if (sgm_image[i][j] >= sgm_threshold) {
				sgm_bimage[i][j] = 255; //White Pixel
			}
			else {
				sgm_bimage[i][j] = 0; //Black Pixel
			}
		}
	}

	/* Write SGM Binary Image */
	strcpy(filename, "sgm_bimage");
	if (!(fp = fopen(strcat(filename, ".ras"), "wb")))
	{
		fprintf(stderr, "error: could not open %s\n", filename);
		exit(1);
	}
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++) fwrite(sgm_bimage[i], 1, COLUMNS, fp);

	fclose(fp);

	/* Hough Transform, Find rho of edges for all theta*/
	for (i = 1; i < ROWS - 1; i++) {
		for (j = 1; j < COLUMNS - 1; j++) {
			if (sgm_bimage[i][j] == 255) {
				//Find rho for all theta
				for (theta_degrees = 0; theta_degrees < 180; theta_degrees++) {
					theta_rads = (float)theta_degrees * (float)pi / (float)180;
					rho = i*cos(theta_rads) - j*sin(theta_rads);

					//Accumulator / Voting function
					delta_rho = (rho/4) + 200;

					voting[theta_degrees][delta_rho]++;

					if (voting[theta_degrees][delta_rho] > voting_max) {
						voting_max = voting[theta_degrees][delta_rho];
					}
				}
			}
		}
	}

	/* Normalize Hough Transform */
	voting_normalize = (float)255 / voting_max;
	for (i = 1; i < ROWS - 1; i++) {
		for (j = 1; j < COLUMNS - 1; j++) {
			temp = voting[i][j] * voting_normalize;
			if (temp > 255) {
				voting_image[i][j] = 255;
			}
			else {
				voting_image[i][j] = temp;
			}
		}
	}


	/* Write Voting Image*/
	strcpy(filename, "voting_image");
	if (!(fp = fopen(strcat(filename, ".ras"), "wb")))
	{
		fprintf(stderr, "error: could not open %s\n", filename);
		exit(1);
	}
	fwrite(head_b, 4, 8, fp);

	for (i = 0; i < 180; i++) fwrite(voting_image[i], 1, 400, fp);

	fclose(fp);

	/* Reduce Noise in Voting Image */
	for (i = 0; i < 180; i++) {
		for (j = 0; j < 400; j++) {
			if (voting_image[i][j] > hough_threshold) {
				voting_bimage[i][j] = 255; //White Pixel
			}
			else {
				voting_bimage[i][j] = 0; //Black Pixel
			}
		}
	}

	/* Write Voting Binary Image*/
	strcpy(filename, "voting_bimage");
	if (!(fp = fopen(strcat(filename, ".ras"), "wb")))
	{
		fprintf(stderr, "error: could not open %s\n", filename);
		exit(1);
	}
	fwrite(head_b, 4, 8, fp);

	for (i = 0; i < 180; i++) fwrite(voting_bimage[i], 1, 400, fp);

	fclose(fp);


	/* Find Reconstructed Image*/
	printf("Reconstructing Image\n");
	for (i = 0; i < 180; i++) {
		for (j = 0; j < 400; j++) {
			if (voting_bimage[i][j] == 255) {
				//printf("Point Found\n");

				for (a = 1; a < ROWS - 1; a++) {
					for (b = 1; b < COLUMNS - 1; b++) {

						theta_rads = (float)i * (float)pi / (float)180;
						temp = (double)b*sin(theta_rads) - (double)a*cos(theta_rads) + ((j - 200)*4);
						//printf("temp = %d\n", temp);

						if (temp == 0) {
							//printf("Point Found. a = %d, b = %d\n", a, b);
							reconstructed_image[a][b] = 255;
						}

					}
				}

			}
		}
	}
	printf("Write Reconstructed Image\n");
	/* Write Reconstructed Image*/
	strcpy(filename, "reconstructed_image");
	if (!(fp = fopen(strcat(filename, ".ras"), "wb")))
	{
		fprintf(stderr, "error: could not open %s\n", filename);
		exit(1);
	}
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++) fwrite(reconstructed_image[i], 1, COLUMNS, fp);

	fclose(fp);


	//End of Program
	printf("Press any key to exit: ");
	gets(&ch);
	return 0;
}

void clear(unsigned char image[][COLUMNS])
{
	int	i, j;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLUMNS; j++) image[i][j] = 0;
}

void header(int row, int col, unsigned char head[32])
{
	int *p = (int *)head;
	char *ch;
	int num = row * col;

	/* Choose little-endian or big-endian header depending on the machine. Don't modify this */
	/* Little-endian for PC */

	*p = 0x956aa659;
	*(p + 3) = 0x08000000;
	*(p + 5) = 0x01000000;
	*(p + 6) = 0x0;
	*(p + 7) = 0xf8000000;

	ch = (char*)&col;
	head[7] = *ch;
	ch++;
	head[6] = *ch;
	ch++;
	head[5] = *ch;
	ch++;
	head[4] = *ch;

	ch = (char*)&row;
	head[11] = *ch;
	ch++;
	head[10] = *ch;
	ch++;
	head[9] = *ch;
	ch++;
	head[8] = *ch;

	ch = (char*)&num;
	head[19] = *ch;
	ch++;
	head[18] = *ch;
	ch++;
	head[17] = *ch;
	ch++;
	head[16] = *ch;


	/* Big-endian for unix */
	/*
	*p = 0x59a66a95;
	*(p + 1) = col;
	*(p + 2) = row;
	*(p + 3) = 0x8;
	*(p + 4) = num;
	*(p + 5) = 0x1;
	*(p + 6) = 0x0;
	*(p + 7) = 0xf8;
	*/
}

