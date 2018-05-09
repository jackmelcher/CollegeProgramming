set term png
set output 'netplot_serial.png'
set title "Mandelbrot Set: Serial Timing for N x N Image"
set xlabel "N (Pixels)"
set ylabel "Time (s)"
set grid
plot "results_serial.dat" notitle with linespoints