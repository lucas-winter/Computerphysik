set terminal pdf;
set output 'plot.pdf'
set xrange [-1:1]
set yrange [-1:1]
set size square
plot "p.txt" using 2:3 with lines 
