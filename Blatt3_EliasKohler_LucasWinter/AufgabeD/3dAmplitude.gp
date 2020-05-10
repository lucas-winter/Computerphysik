set terminal pdf

set output "Plots\test.pdf"
set hidden3d
set ylabel 'Dämpfung'
set xlabel 'Anregungsfrequenz'
set zlabel 'Amplitude'


splot "test.txt" with lines title ""