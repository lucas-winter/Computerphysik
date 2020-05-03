set terminal pdf

set output "Plots\AvgError.pdf"
set xlabel 'Schrittweite h'
set ylabel 'Durschnittlicher Fehler'
set logscale y



plot "elAvgError" using 1:2 with lines title "Fehler Euler" ,\
     "rkAvgError" using 1:2 with lines title "Fehler Runge-Kutta" ,\
     "lfAvgError" using 1:2 with lines title "Fehler Leap Frog"
