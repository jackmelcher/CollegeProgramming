/**
 *  \file mandelbrot_serial.cc
 *  \brief Lab 2: Mandelbrot set serial code
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
    newy = 2*x*y + cy;
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
    height = atoi (argv[1]);
    width = atoi (argv[2]);
    assert (height > 0 && width > 0);
  } else {
    fprintf (stderr, "usage: %s <height> <width>\n", argv[0]);
    fprintf (stderr, "where <height> and <width> are the dimensions of the image.\n");
    return -1;
  }

  //MPI variables
  int rank, size;
  
  //Timing variables
  double t_start, t_elapsed;

  // MPI Start
  MPI_Init(&argc, &argv);
  //printf("MPI Start\n");
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  /* Open a file for writing results */
  if (rank == 0) {
	  fp = fopen("results_serial.dat", "a");
	  assert(fp != NULL);
  }

  double it = (maxY - minY)/height;
  double jt = (maxX - minX)/width;
  double x, y;


  gil::rgb8_image_t img(height, width);
  auto img_view = gil::view(img);

  MPI_Barrier(MPI_COMM_WORLD); /* Synchronize the nodes */
  t_start = MPI_Wtime(); /* Start timer */

  y = minY;
  for (int i = 0; i < height; ++i) {
    x = minX;
    for (int j = 0; j < width; ++j) {
      img_view(j, i) = render(mandelbrot(x, y)/512.0);
      x += jt;
    }
    y += it;
  }
  gil::png_write_view("mandelbrot.png", const_view(img));

  t_elapsed = MPI_Wtime() - t_start; /* Stop timer */

  if (rank == 0) {
	  /* Write the one-way transfer time data to results.dat */
	  int num_pixels = height;
	  double t_msg = t_elapsed;
	  fprintf(fp, "%d\t%.10f\n", num_pixels, t_msg);
	  fflush(fp);
	  fclose(fp); /* Close results.dat */
  }

  MPI_Finalize();
  return 0;
}

/* eof */
