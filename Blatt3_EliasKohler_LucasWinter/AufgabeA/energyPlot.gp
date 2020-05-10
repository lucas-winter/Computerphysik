set terminal pdf 
set output 'energyPlot.pdf'
set xlabel 'Zeit t'
set ylabel 'Energie E'

plot "energy"  using 1:3 with lines title "Energie Euler" ,\
     "energy"  using 1:4 with lines title "Energie Runge-Kutta" ,\
     "energy"  using 1:5 with lines title "Energie Leap Frog" 