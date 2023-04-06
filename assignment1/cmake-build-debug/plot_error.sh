#!/bin/bash
gnuplot -persist << EOF
set logscale x 
set logscale y
set key right bottom
plot "error.dat" u 1:2  pt 8  lc 7 lw 2 with linespoints title "error_inf",x lw 3 lt 2 w l title "1/N",x**2 lw 3 lt 3 w l title "1/N^2"
pause -1
EOF
