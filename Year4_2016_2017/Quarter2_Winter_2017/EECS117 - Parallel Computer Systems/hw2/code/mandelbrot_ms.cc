/**
 *  \file mandelbrot_ms.cc
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
	int rank, size, send_row = 0, receive_row = 0, tag_work = 0, tag_data = 1;
	int *send_mandelbrot, *receive_mandelbrot;
	
	//Timing variables
	double t_start, t_elapsed;

	// MPI Start
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;

	/* Open a file for writing results */
	if (rank == 0) {
		fp = fopen("results_ms.dat", "a");
		assert(fp != NULL);
	}

	double it = (maxY - minY) / height;
	double jt = (maxX - minX) / width;
	double x, y;


	gil::rgb8_image_t img(height, width);
	auto img_view = gil::view(img);

	MPI_Barrier(MPI_COMM_WORLD); /* Synchronize the nodes */
	t_start = MPI_Wtime(); /* Start timer */

	// Master
	if (rank == 0) {
		receive_mandelbrot = (int*)malloc(height * width * sizeof(int));

		while (receive_row < height) {
			// Send row work to process
			for (int i = 1; i < size; i++) {
				if (send_row == height) {
					break;
				}
				//printf("Sending row: %d\n", send_row);
				MPI_Send(&send_row, 1, MPI_INT, i, tag_work, MPI_COMM_WORLD);
				send_row++;
			}
			// Receive computations from other processes
			for (int i = 1; i < size; i++) {
				if (receive_row == height) {
					break;
				}
				//printf("Receiving row: %d\n", receive_row);
				MPI_Recv(receive_mandelbrot+(receive_row*width), width, MPI_INT, i, tag_data, MPI_COMM_WORLD, &status);
				receive_row++;
			}
		}
		// Tell slaves to stop doing work
		send_row = -1;
		for (int i = 1; i < size; i++) {
			//printf("Ending work of process: %d\n", i);
			MPI_Send(&send_row, 1, MPI_INT, i, tag_work, MPI_COMM_WORLD);
		}

		//Render image
		if (rank == 0) {
			for (int i = 0; i < height; ++i) {
				for (int j = 0; j < width; ++j) {
					img_view(j, i) = render(receive_mandelbrot[(width*i) + j] / 512.0);
				}
			}
			gil::png_write_view("mandelbrot_ms.png", const_view(img));
		}

		t_elapsed = MPI_Wtime() - t_start; /* Stop timer */

		if (rank == 0) {
			/* Write the one-way transfer time data to results.dat */
			int num_pixels = height;
			double t_msg = t_elapsed;
			fprintf(fp, "%d\t%.10f\n", num_pixels, t_msg);
			fflush(fp);
			fclose(fp); /* Close results_ms.dat */
		}
	}
	// Slave
	else {
		send_mandelbrot = (int*)malloc(width * sizeof(int));

		do {
			MPI_Recv(&receive_row, 1, MPI_INT, 0, tag_work, MPI_COMM_WORLD, &status);
			if (receive_row != -1) {
				y = minY + (it * receive_row);
				x = minX;
				for (int j = 0; j < width; ++j) {
					send_mandelbrot[j] = mandelbrot(x, y);
					x += jt;
				}
				//printf("Process Sending computations: %d\n", receive_row);
				MPI_Send(send_mandelbrot, width, MPI_INT, 0, tag_data, MPI_COMM_WORLD);
			}
		}while (receive_row != -1);
		//printf("Process %d work done: %d\n", rank, receive_row);
	}

	// Free all the data
	if (rank == 0) {
		free(receive_mandelbrot);
	}
	else {
		free(send_mandelbrot);
	}

	//MPI End
	MPI_Finalize();
	return 0;
}

/* eof */
