#!/bin/bash
gnuplot -persist << EOF
set title "QuasiNewton Method"
set title font "Helvetica Bold,14"
set logscale y
set key right top
set grid
set autoscale y
set xlabel "iterations"
set ylabel "log(error)"
plot "error_QuasiNewton.dat" u 1:2  pt 8  lc 7 lw 2 with linespoints title "error(xk-x)"
replot "error_QuasiNewton.dat" u 1:3 lw 3 lt 2 with linespoints title "bisection upper bound"
pause -1
EOF
