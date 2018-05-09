set term png
set output 'netplot_joe.png'
set title "Mandelbrot Set: Joe Block Timing for N x N Image with 64 Cores"
set xlabel "N (Pixels)"
set ylabel "Time (s)"
set grid
plot "results_joe.dat" notitle with linespoints