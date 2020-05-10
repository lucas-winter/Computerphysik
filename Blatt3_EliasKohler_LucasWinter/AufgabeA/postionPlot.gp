set terminal pdf 
set output 'positionPlot.pdf'
set xlabel 'Zeit t'
set ylabel 'Position x(t)'

plot "position"  using 1:3 with lines title "Positon Euler" ,\
     "position"  using 1:4 with lines title "Position Runge-Kutta" ,\
     "position"  using 1:5 with lines title "Positon Leap Frog" ,\
     "position"   using 1:2 with lines title "Analytische Losung"