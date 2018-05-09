#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS   		 		 128
#define COLS				 128
#define LOGICAL_X_MIN		-4.0
#define LOGICAL_X_MAX		 4.0
#define LOGICAL_Y_MIN		-4.0
#define LOGICAL_Y_MAX		 4.0

void clear(unsigned char image[][COLS]);
int plot_logical_point(float x, float y, unsigned char image[][COLS]);
int plot_physical_point(int x, int y, unsigned char image[][COLS]);
int in_range(int x, int y);
void header(int row, int col, unsigned char head[32]);/*write header for the output images, do not modify this*/


int main(int argc, char **argv){
	int				i;
	float			t, x, y, z, xprime, yprime;
	FILE			*fp;
	char			 *ofile;
	unsigned char	image[ROWS][COLS];
	unsigned char head[32];

	//Stuff I added
	// Constants Problem 1
	//const float x0 = 0.5;
	//const float y0 = -1;
	//const float z0 = 0;
	//const float a = 0;
	//const float b = 1;
	//const float c = -1;
	//const float fprime = 1;

	// Constants Problem 2
	//const float x1 = 0.5;
	//const float x2 = -0.5;
	//const float y1 = -1;
	//const float y2 = -1;
	//const float z0 = -1;
	//const float z0 = -2;
	//const float z0 = -3;
	//const float a = 1;
	//const float b = 1;
	//const float fprime = 1;
	//Variables Problem 2
	//float xhat, yhat, zhat;

	// Constants Problem 3
	const float x1 = -1;
	const float x2 = 1;
	const float y0 = -1;
	const float z0 = 0;
	//const float b = 0;
	//const float b = 1;
	const float b = -1;
	//const float c = 1;
	const float c = -1;
	const float fprime = 1;
	//Variables Problem 3
	float xhat, yhat, zhat;
	//END

	//T ranges
	// Example
	//float tmin = 0.01;
	//float tmax = 10000;
	
	// Problem1 Orthographic
	//float tmin = -3;
	//float tmax = 5;
	// Problem1 Perspective
	float tmin = 0.01;
	float tmax = 10000;
	
	
	//END

	clear(image);
	
	for (t = tmin; t <= tmax; t += 0.01){  //change the t range
		/*Modify the coefficiences according to questions*/
		//x = 0.5 + t * 0.0;
		//y = -1.0 + t;
		//z = -t;
		
		//Parametric Equations Problem 1
		//x = x0 + t*a;
		//y = y0 + t*b;
		//z = z0 + t*c;

		//Parametric Equations Problem 2
		//x = x1 + t*a;
		//xhat = x2 + t*a;
		//y = y1 + t*b;
		//yhat = y2 + t*b;
		//z = z0;
		//zhat = z0;

		//Parametric Equations Problem 3
		x = x1;
		xhat = x2;
		y = y0 + t*b;
		yhat = y0 + t*b;
		z = z0 + t*c;
		zhat = z0 + t*c;

		/* Modify these according to the projection */
		
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;
		// Orthographic Projection
		//xprime = x;
		//yprime = y;		

		plot_logical_point(xprime, yprime, image);

		//Problem 2 and 3, additional plotting
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;
		// Orthographic Projection
		//xprime = xhat;
		///yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */ 
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	//ofile = "hw1ex1.ras";
	//ofile = "hw1problem1orthographic.ras";
	//ofile = "hw1problem1perspective.ras";
	//ofile = "hw1problem2orthographic1.ras";
	//ofile = "hw1problem2orthographic2.ras";
	//ofile = "hw1problem2orthographic3.ras";
	//ofile = "hw1problem2perspective1.ras";
	//ofile = "hw1problem2perspective2.ras";
	//ofile = "hw1problem2perspective3.ras";
	//ofile = "hw1problem3orthographic1.ras";
	//ofile = "hw1problem3orthographic2.ras";
	//ofile = "hw1problem3orthographic3.ras";
	//ofile = "hw1problem3orthographic4.ras";
	//ofile = "hw1problem3orthographic5.ras";
	//ofile = "hw1problem3orthographic6.ras";
	//ofile = "hw1problem3perspective1.ras";
	//ofile = "hw1problem3perspective2.ras";
	//ofile = "hw1problem3perspective3.ras";
	//ofile = "hw1problem3perspective4.ras";
	//ofile = "hw1problem3perspective5.ras";
	ofile = "hw1problem3perspective6.ras";



	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++) 
		fwrite(image[i], 1, COLS, fp);
	
	fclose(fp);

	return 0;
}

void clear(unsigned char image[][COLS]){
	int	i, j;
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++) image[i][j] = 0;
}

int plot_logical_point(float x, float y, unsigned char image[][COLS]){
	int	nx, ny;
	float	xc, yc;
	xc = COLS / ((float)LOGICAL_X_MAX - LOGICAL_X_MIN);
	yc = ROWS / ((float)LOGICAL_Y_MAX - LOGICAL_Y_MIN);
	nx = (x - LOGICAL_X_MIN) * xc;
	ny = (y - LOGICAL_Y_MIN) * yc;
	return plot_physical_point(nx, ny, image);
}

int plot_physical_point(int x, int y, unsigned char image[][COLS]){
	if (in_range(x, y)) //return 0;
	return image[y][x] = 255;
}

int in_range(int x, int y){
	return x >= 0 && x < COLS && y >= 0 && y < ROWS;
}

void header(int row, int col, unsigned char head[32]){
	int *p = (int *)head;
	char *ch;
	int num = row * col;

	/* Choose little-endian or big-endian header depending on the machine. Don't modify the contents */
	
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

	/*
	// Big-endian for unix
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