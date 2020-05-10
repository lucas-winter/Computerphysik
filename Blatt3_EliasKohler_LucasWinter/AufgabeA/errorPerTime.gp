set terminal pdf

set output "Plots\ErrorPerTime.pdf"

plot "rkErrorTime" using 1:2 with lines title "Fehler RK2" ,\
     "elErrorTime" using 1:2 with lines title "Fehler Euler" ,\
     "lfErrorTime" using 1:2 with lines title "Fehler Leapfrog"
