set term png
set output 'netplot_susie.png'
set title "Mandelbrot Set: Susie Cyclic Timing for N x N Image with 64 Cores"
set xlabel "N (Pixels)"
set ylabel "Time (s)"
set grid
plot "results_susie.dat" notitle with linespoints