set term png
set output 'netplot_ms.png'
set title "Mandelbrot Set: Master/Slave Timing for N x N Image with 64 Cores"
set xlabel "N (Pixels)"
set ylabel "Time (s)"
set grid
plot "results_ms.dat" notitle with linespoints