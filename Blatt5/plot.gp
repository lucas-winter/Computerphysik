#Plotted die numerische und analytische Lösung der Poissiongleichung
set terminal pdf
set output 'numvPlot4.pdf'

set xlabel 'r'
set ylabel 'phi(r)'

plot 'numData.txt' using 1:3 with lines title 'korrigierte Lösung',\
     'numData.txt' using 1:4 with lines title 'analytische Lösung'