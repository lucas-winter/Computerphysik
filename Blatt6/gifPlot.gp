set terminal gif animate delay 2;
set output 'plot.gif'
set xrange [0:1]
set yrange [0:1]
set size square

set xlabel "x"
set ylabel "Wert"


do for [i = 1:300] {
    plot 'data.txt' every :::i::i using 2:3 with lines title "Pendelbewegung"
}