set terminal pdf
set output 'heat.pdf'


plot "p.txt" using 1:2:3 with image pixels