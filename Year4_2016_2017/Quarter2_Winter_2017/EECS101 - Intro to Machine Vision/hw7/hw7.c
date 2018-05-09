// Jack Melcher
// 67574625
// EECS 101
// HW7

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ROWS	480
#define COLS	640

#define sqr(x)	((x)*(x))

void clear(unsigned char image[][COLS]);
void header(int row, int col, unsigned char head[32]);

void angular_bisector(double v_hat[3], double s_hat[3], double h_hat[3]);
double angle_via_dot_product(double a_hat[3], double b_hat[3]);
double lambertian_reflection(double s_hat[3], double n_hat[3]);
double specular_reflection(double h_hat[3], double n_hat[3], double m);
double scene_radiance(double a, double Ll, double Ls);

int main(int argc, char** argv)
{
	FILE *fp;
	char number[2] = "A", ch;
	char filename[50];
	unsigned char image[ROWS][COLS], head[32];
	int x, y, i, j, k, u, v;

	double s_hat[3], v_hat[3] = {0, 0, 1}, h_hat[3], n_hat[3];
	double p, q, Ll, Ls;

	double s_hat_x[9] = {0, 1 / sqrt(3), 1, 0, 0, 0, 0, 0, 0};
	double s_hat_y[9] = {0, 1 / sqrt(3), 0, 0, 0, 0, 0, 0, 0};
	double s_hat_z[9] = {1, 1 / sqrt(3), 0, 1, 1, 1, 1, 1, 1};
	double r[9] = {50, 50, 50, 10, 100, 50, 50, 50, 50};
	double a[9] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.1, 1, 0.5, 0.5};
	double m[9] = {1, 1, 1, 1, 1, 1, 1, 0.1, 10000};

	header(ROWS, COLS, head);

	for (u = 0; u < 9; u++) {
		//clear image
		clear(image);

		//Set s_hat
		s_hat[0] = s_hat_x[u];
		s_hat[1] = s_hat_y[u];
		s_hat[2] = s_hat_z[u];

		//Determine h_hat
		angular_bisector(v_hat, s_hat, h_hat);

		


		//Calculate scene_radiance and put into image
		for (i = 0; i < ROWS; i++) {
			for (j = 0; j < COLS; j++) {

				x = i - ROWS / 2;
				y = j - COLS / 2;

				//Only operate on x and y that are less than or equal to radius of sphere
				if ((pow(x, 2) + pow(y, 2)) <= pow(r[u], 2)) {
					//Determine n_hat
					if ((pow(x, 2) + pow(y, 2)) == pow(r[u], 2)) {
						n_hat[0] = -y / r[u];
						n_hat[1] = -x / r[u];
						n_hat[2] = 0;
					}
					else {
						p = -x / sqrt(pow(r[u], 2) - (pow(x, 2) + pow(y, 2)));
						q = -y / sqrt(pow(r[u], 2) - (pow(x, 2) + pow(y, 2)));
						n_hat[0] = -p / sqrt(pow(p, 2) + pow(q, 2) + 1);
						n_hat[1] = -q / sqrt(pow(p, 2) + pow(q, 2) + 1);
						n_hat[2] = 1 / sqrt(pow(p, 2) + pow(q, 2) + 1);
					}

					Ll = lambertian_reflection(s_hat, n_hat);
					if (acos(Ll) >= (3.142 / 2)) {
						Ll = 0;
					}

					Ls = specular_reflection(h_hat, n_hat, m[u]);

					image[i][j] = scene_radiance(a[u], Ll, Ls) * 255;
				}
			}
		}


		// Save image
		strcpy(filename, "image");
		strcat(filename, number);

		if (!(fp = fopen(strcat(filename, ".ras"), "wb")))
		{
			fprintf(stderr, "error: could not open %s\n", filename);
			exit(1);
		}
		fwrite(head, 4, 8, fp);
		for (i = 0; i < ROWS; i++) fwrite(image[i], 1, COLS, fp);
		fclose(fp);

		//Increment image number
		number[0]++;

		printf("Saved %s\n", filename);
	}
	//End of Program
	printf("Press any key to exit: ");
	gets(&ch);
	return 0;
}

void angular_bisector(double v_hat[3], double s_hat[3], double h_hat[3]) {
	double magnitude;

	h_hat[0] = v_hat[0] + s_hat[0];
	h_hat[1] = v_hat[1] + s_hat[1];
	h_hat[2] = v_hat[2] + s_hat[2];

	magnitude = sqrt(pow(h_hat[0], 2) + pow(h_hat[1], 2) + pow(h_hat[2], 2));

	h_hat[0] /= magnitude;
	h_hat[1] /= magnitude;
	h_hat[2] /= magnitude;
}

double angle_via_dot_product(double a_hat[3], double b_hat[3]) {
	return acos(a_hat[0]*b_hat[0]+ a_hat[1] * b_hat[1] + a_hat[2] * b_hat[2]);
}


double lambertian_reflection(double s_hat[3], double n_hat[3]) {
	double theta = angle_via_dot_product(s_hat, n_hat);
	
	return cos(theta);
}

double specular_reflection(double h_hat[3], double n_hat[3], double m){
	double alpha = angle_via_dot_product(h_hat, n_hat);
	
	return exp(-1 * pow((alpha / m), 2));
}

double scene_radiance(double a, double Ll, double Ls) {
	return a*Ll + (1 - a)*Ls;
}


void clear(unsigned char image[][COLS])
{
	int	i, j;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++) image[i][j] = 0;
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

