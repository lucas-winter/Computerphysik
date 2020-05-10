
set terminal pdf

set output "eulerTest.pdf"

plot "eulerData.txt" using 1:2 with lines title "position",\
     "eulerData.txt" using 1:3 with lines title "velocity"