#!/bin/bash
gnuplot -persist << EOF
set key right bottom
plot "result.dat" u 1:2 pt 8  lc 8 lw 1 with linespoints title "uh","result.dat" u 1:3 w l lw 2 title "u"
pause -1
EOF
