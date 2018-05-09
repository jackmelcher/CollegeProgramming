#!/bin/bash
#$ -N Mandelbrot
#$ -q eecs117,pub64,free64
#$ -pe one-node-mpi 64
#$ -R y

# Grid Engine Notes:
# -----------------
# 1) Use "-R y" to request job reservation otherwise single 1-core jobs
#    may prevent this multicore MPI job from running.   This is called
#    job starvation.

# Module load boost
module load boost/1.57.0

# Module load OpenMPI
module load openmpi-1.8.3/gcc-4.9.2

# Remove result files
rm results_serial.dat
rm results_joe.dat
rm results_susie.dat
rm results_ms.dat

# Run the program 
mpirun -np 1   ./mandelbrot_serial 64 64
mpirun -np 1   ./mandelbrot_serial 128 128
mpirun -np 1   ./mandelbrot_serial 256 256
mpirun -np 1   ./mandelbrot_serial 512 512
mpirun -np 1   ./mandelbrot_serial 1024 1024
mpirun -np 1   ./mandelbrot_serial 2048 2048
mpirun -np 64  ./mandelbrot_joe 64 64
mpirun -np 64  ./mandelbrot_joe 128 128
mpirun -np 64  ./mandelbrot_joe 256 256
mpirun -np 64  ./mandelbrot_joe 512 512
mpirun -np 64  ./mandelbrot_joe 1024 1024
mpirun -np 64  ./mandelbrot_joe 2048 2048
mpirun -np 64  ./mandelbrot_susie 64 64
mpirun -np 64  ./mandelbrot_susie 128 128
mpirun -np 64  ./mandelbrot_susie 256 256
mpirun -np 64  ./mandelbrot_susie 512 512
mpirun -np 64  ./mandelbrot_susie 1024 1024
mpirun -np 64  ./mandelbrot_susie 2048 2048
mpirun -np 64  ./mandelbrot_ms 64 64
mpirun -np 64  ./mandelbrot_ms 128 128
mpirun -np 64  ./mandelbrot_ms 256 256
mpirun -np 64  ./mandelbrot_ms 512 512
mpirun -np 64  ./mandelbrot_ms 1024 1024
mpirun -np 64  ./mandelbrot_ms 2048 2048

# Generate netplot.png
gnuplot netplot_serial.gnu
gnuplot netplot_joe.gnu
gnuplot netplot_susie.gnu
gnuplot netplot_ms.gnu
