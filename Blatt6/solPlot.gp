
#Plottet die resultierende Amplitude abhänig von der Dämpfung und der Anregungsfrequenz
set terminal pdf

set output "plot1.pdf"
set xrange [0:1]
set yrange [0:1]
set size square
set ylabel 'phi(x)'
set xlabel 'Strecke x'



plot 'data.txt' every :::0::0 using 2:3 with lines title 't = 0' ,\
     'data.txt' every :::100::100 using 2:3 with lines title 't = 0.1' ,\
     'data.txt' every :::500::500 using 2:3 with lines title 't = 0.5' ,\
     'data.txt' every :::2000::2000 using 2:3 with lines title 't = 2' ,\