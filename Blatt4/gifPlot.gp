set terminal gif animate delay 2;
set output 'plot.gif'
set xrange [-1:1]
set yrange [-1:1]
set size square

do for [i = 1:300] {
    plot 'p.txt' every ::1::i*2 using 2:3 with lines  
}
