#!/bin/bash
gnuplot -persist << EOF
set logscale y
set key right top
set grid
set autoscale y
plot "error_bisection.dat" u 1:2  pt 8  lc 7 lw 2 with linespoints title "error(xk-x)"
replot "error_bisection.dat" u 1:3 lw 3 lt 2 with linespoints title "upper bound by bisection"
pause -1
EOF
