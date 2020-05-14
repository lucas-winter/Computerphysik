set terminal latex

set output "plotAmp.tex"
set xlabel "Anregungsfrequenz w"
set ylabel "Amplitude"

plot "amp" with lines title "Amplitude für $\\gamma = 0.3$"

