/**
 *  \file mandelbrot_susie.cc
 *
 *  \brief Implement your parallel mandelbrot set in this file.
 */

#include <iostream>
#include <cstdlib>
#include <mpi.h>

#include "render.hh"

using namespace std;

#define WIDTH 1000
#define HEIGHT 1000

int
mandelbrot(double x, double y) {
	int maxit = 511;
	double cx = x;
	double cy = y;
	double newx, newy;

	int it = 0;
	for (it = 0; it < maxit && (x*x + y*y) < 4; ++it) {
		newx = x*x - y*y + cx;
		newy = 2 * x*y + cy;
		x = newx;
		y = newy;
	}
	return it;
}

int
main(int argc, char* argv[]) {
	FILE *fp = NULL; /* output file, only valid on rank 0 */
	
	double minX = -2.1;
	double maxX = 0.7;
	double minY = -1.25;
	double maxY = 1.25;

	int height, width;
	if (argc == 3) {
		height = atoi(argv[1]);
		width = atoi(argv[2]);
		assert(height > 0 && width > 0);
	}
	else {
		fprintf(stderr, "usage: %s <height> <width>\n", argv[0]);
		fprintf(stderr, "where <height> and <width> are the dimensions of the image.\n");
		return -1;
	}

	//MPI variables
	int rank, size, height_new, N;
	int *send_mandelbrot, *receive_mandelbrot;
	
	//Timing variables
	double t_start, t_elapsed;

	// MPI Start
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	/* Open a file for writing results */
	if (rank == 0) {
		fp = fopen("results_susie.dat", "a");
		assert(fp != NULL);
	}

	// Divide the work and limit height arrays
	height_new = (height / size) * size;
	N = height / size;

	// Adjust it because of height_new
	double it = (maxY - minY) / height_new;
	double jt = (maxX - minX) / width;
	double x, y;

	gil::rgb8_image_t img(height_new, width);
	auto img_view = gil::view(img);

	MPI_Barrier(MPI_COMM_WORLD); /* Synchronize the nodes */
	t_start = MPI_Wtime(); /* Start timer */

	// Take rank and determine each node's range of calculation
	// Calculate and store each process data 
	send_mandelbrot = (int*)malloc(N * width * sizeof(int));

	// Set starting y based on rank
	y = minY + (it*rank);
	for (int i = 0; i < N; ++i) {
		x = minX;
		for (int j = 0; j < width; ++j) {
			send_mandelbrot[(width*i) + j] = mandelbrot(x, y);
			//printf("send_mandelbrot[%d] = %d\n", (width*i) + j, send_mandelbrot[(width*i) + j]);
			x += jt;
		}
		y += it*size;
	}

	// Have rank 0 process gather all the data, getting N elements from every process
	if (rank == 0) {
		receive_mandelbrot = (int*)malloc(height_new * width * sizeof(int));
	}
	MPI_Gather(send_mandelbrot, N*width, MPI_INT, receive_mandelbrot, N*width, MPI_INT, 0, MPI_COMM_WORLD);

	//Render the image
	if (rank == 0) {
		//int temp3 = 0;

		for (int i = 0; i < height_new; ++i) {
			for (int j = 0; j < width; ++j) {
				//printf("receive_mandelbrot[%d] = %d\n", (width*temp3) + j, receive_mandelbrot[(width*temp3) + j]);
				//img_view(j, i) = render(receive_mandelbrot[(width*temp3) + j] / 512.0);
				img_view(j, i) = render(receive_mandelbrot[(i%size)*(height_new /size*width)+(i/size)*width + j] / 512.0);
			}
			/*
			if (i % size == 0 && i != 0) {
				temp3 = i / size;
				//printf("row: %d\n", i / size);
				printf("temp3: %d\n", temp3);

			}
			else {
				temp3 += rank_rows[i % size];
				//printf("row: %d\n", i % size);
				if (temp3 == height) {
					temp3 = i+1 / size;
				}
				printf("temp3: %d\n", temp3);
			}
			*/
			 
		}
		gil::png_write_view("mandelbrot_susie.png", const_view(img));
	}

	t_elapsed = MPI_Wtime() - t_start; /* Stop timer */

	if (rank == 0) {
		/* Write the one-way transfer time data to results.dat */
		int num_pixels = height;
		double t_msg = t_elapsed;
		fprintf(fp, "%d\t%.10f\n", num_pixels, t_msg);
		fflush(fp);
		fclose(fp); /* Close results_susie.dat */
	}

	// Free all the data
	free(send_mandelbrot);
	if (rank == 0) {
		free(receive_mandelbrot);
	}

	//MPI End
	MPI_Finalize();
	return 0;
}


/* eof */
