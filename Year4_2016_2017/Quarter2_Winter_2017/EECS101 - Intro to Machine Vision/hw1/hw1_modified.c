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

	// Constants Problem 1
	const float x0_p1 = 0.5;
	const float y0_p1 = -1;
	const float z0_p1 = 0;
	const float a_p1 = 0;
	const float b_p1 = 1;
	const float c_p1 = -1;
	const float fprime = 1;

	// Constants Problem 2
	const float x1_p2 = 0.5;
	const float x2_p2 = -0.5;
	const float y1_p2 = -1;
	const float y2_p2 = -1;
	const float z0_p2_i = -1;
	const float z0_p2_ii = -2;
	const float z0_p2_iii = -3;
	const float a_p2 = 1;
	const float b_p2 = 1;

	// Constants Problem 3
	const float x1_p3 = -1;
	const float x2_p3 = 1;
	const float y0_p3 = -1;
	const float z0_p3 = 0;
	const float b_p3_i = 0;
	const float b_p3_ii = 1;
	const float b_p3_iii = -1;
	const float c_p3_i = 1;
	const float c_p3_ii = -1;
	
	//Variables Problem 2 and 3
	float xhat, yhat, zhat;
	//END

// Start Problem 1
	// Orthographic Projection
	clear(image);
	for (t = 0.01; t <= 5; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 1
		x = x0_p1 + t*a_p1;
		y = y0_p1 + t*b_p1;
		z = z0_p1 + t*c_p1;

		/* Modify these according to the projection */
		// Orthographic Projection
		xprime = x;
		yprime = y;		

		plot_logical_point(xprime, yprime, image);
	}
	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem1orthographic.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
	
	// Perspective Projection
	clear(image);
	for (t = 0.2; t <= 50; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 1
		x = x0_p1 + t*a_p1;
		y = y0_p1 + t*b_p1;
		z = z0_p1 + t*c_p1;

		/* Modify these according to the projection */
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);
	}
	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem1perspective.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// Problem 1 END

// Start Problem 2a
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 2
		x = x1_p2 + t*a_p2;
		xhat = x2_p2 + t*a_p2;
		y = y1_p2 + t*b_p2;
		yhat = y2_p2 + t*b_p2;
		z = z0_p2_i;
		zhat = z0_p2_i;
	
		/* Modify these according to the projection */
		//Problem 2, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;		

		plot_logical_point(xprime, yprime, image);

		//Problem 2, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem2orthographic1.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem2a

// Start Problem 2b
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 2
		x = x1_p2 + t*a_p2;
		xhat = x2_p2 + t*a_p2;
		y = y1_p2 + t*b_p2;
		yhat = y2_p2 + t*b_p2;
		z = z0_p2_ii;
		zhat = z0_p2_ii;

		/* Modify these according to the projection */
		//Problem 2, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;

		plot_logical_point(xprime, yprime, image);

		//Problem 2, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem2orthographic2.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem2b

// Start Problem 2c
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 2
		x = x1_p2 + t*a_p2;
		xhat = x2_p2 + t*a_p2;
		y = y1_p2 + t*b_p2;
		yhat = y2_p2 + t*b_p2;
		z = z0_p2_iii;
		zhat = z0_p2_iii;

		/* Modify these according to the projection */
		//Problem 2, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;

		plot_logical_point(xprime, yprime, image);

		//Problem 2, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem2orthographic3.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem2c


// Start Problem 2d
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 2
		x = x1_p2 + t*a_p2;
		xhat = x2_p2 + t*a_p2;
		y = y1_p2 + t*b_p2;
		yhat = y2_p2 + t*b_p2;
		z = z0_p2_i;
		zhat = z0_p2_i;

		/* Modify these according to the projection */
		//Problem 2, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 2, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem2perspective1.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem2d

// Start Problem 2e
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 2
		x = x1_p2 + t*a_p2;
		xhat = x2_p2 + t*a_p2;
		y = y1_p2 + t*b_p2;
		yhat = y2_p2 + t*b_p2;
		z = z0_p2_ii;
		zhat = z0_p2_ii;

		/* Modify these according to the projection */
		//Problem 2, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 2, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem2perspective2.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem2e

// Start Problem 2f
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 2
		x = x1_p2 + t*a_p2;
		xhat = x2_p2 + t*a_p2;
		y = y1_p2 + t*b_p2;
		yhat = y2_p2 + t*b_p2;
		z = z0_p2_iii;
		zhat = z0_p2_iii;

		/* Modify these according to the projection */
		//Problem 2, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 2, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem2perspective3.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem2f

// Start Problem 3a
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_i;
		yhat = y0_p3 + t*b_p3_i;
		z = z0_p3 + t*c_p3_i;
		zhat = z0_p3 + t*c_p3_i;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3orthographic1.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3a

// Start Problem 3b
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_ii;
		yhat = y0_p3 + t*b_p3_ii;
		z = z0_p3 + t*c_p3_i;
		zhat = z0_p3 + t*c_p3_i;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3orthographic2.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3b

// Start Problem 3c
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_iii;
		yhat = y0_p3 + t*b_p3_iii;
		z = z0_p3 + t*c_p3_i;
		zhat = z0_p3 + t*c_p3_i;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3orthographic3.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3c

// Start Problem 3d
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_i;
		yhat = y0_p3 + t*b_p3_i;
		z = z0_p3 + t*c_p3_ii;
		zhat = z0_p3 + t*c_p3_ii;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3orthographic4.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3d

// Start Problem 3e
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_ii;
		yhat = y0_p3 + t*b_p3_ii;
		z = z0_p3 + t*c_p3_ii;
		zhat = z0_p3 + t*c_p3_ii;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3orthographic5.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3e

// Start Problem 3f
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_iii;
		yhat = y0_p3 + t*b_p3_iii;
		z = z0_p3 + t*c_p3_ii;
		zhat = z0_p3 + t*c_p3_ii;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Orthographic Projection
		xprime = x;
		yprime = y;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Orthographic Projection
		xprime = xhat;
		yprime = yhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3orthographic6.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3f

// Start Problem 3g
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_i;
		yhat = y0_p3 + t*b_p3_i;
		z = z0_p3 + t*c_p3_i;
		zhat = z0_p3 + t*c_p3_i;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3perspective1.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3g

// Start Problem 3h
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_ii;
		yhat = y0_p3 + t*b_p3_ii;
		z = z0_p3 + t*c_p3_i;
		zhat = z0_p3 + t*c_p3_i;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3perspective2.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3h

// Start Problem 3i
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_iii;
		yhat = y0_p3 + t*b_p3_iii;
		z = z0_p3 + t*c_p3_i;
		zhat = z0_p3 + t*c_p3_i;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3perspective3.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3i

// Start Problem 3j
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_i;
		yhat = y0_p3 + t*b_p3_i;
		z = z0_p3 + t*c_p3_ii;
		zhat = z0_p3 + t*c_p3_ii;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3perspective4.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3j

// Start Problem 3k
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_ii;
		yhat = y0_p3 + t*b_p3_ii;
		z = z0_p3 + t*c_p3_ii;
		zhat = z0_p3 + t*c_p3_ii;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3perspective5.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3k

// Start Problem 3l
	clear(image);

	for (t = 0.01; t <= 10000; t += 0.01) {
		/*Modify the coefficiences according to questions*/
		//Parametric Equations Problem 3
		x = x1_p3;
		xhat = x2_p3;
		y = y0_p3 + t*b_p3_iii;
		yhat = y0_p3 + t*b_p3_iii;
		z = z0_p3 + t*c_p3_ii;
		zhat = z0_p3 + t*c_p3_ii;

		/* Modify these according to the projection */
		//Problem 3, Plotting First Line
		// Perspective Projection
		xprime = fprime * x / z;
		yprime = fprime * y / z;

		plot_logical_point(xprime, yprime, image);

		//Problem 3, Plotting Second Line
		// Perspective Projection
		xprime = fprime * xhat / zhat;
		yprime = fprime * yhat / zhat;

		plot_logical_point(xprime, yprime, image);
	}

	//_CRT_SECURE_NO_WARNINGS
	/* Create a header */
	header(ROWS, COLS, head);

	// this is the name of your output file, modify the name according to the requirements
	ofile = "hw1problem3perspective6.ras";

	if (!(fp = fopen(ofile, "wb")))
		fprintf(stderr, "error: could not open %s\n", ofile), exit(1);

	/* Write the header */
	fwrite(head, 4, 8, fp);

	for (i = 0; i < ROWS; i++)
		fwrite(image[i], 1, COLS, fp);

	fclose(fp);
// END Problem3l




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