# Gnuplot script file for plotting data in file "rosslersystem.dat"
set autoscale
unset key
unset log
unset label
set xtic auto
set ytic auto
set terminal jpeg
set output 'rossler.jpg'
set title "phase portrait"
set xlabel "x"
set ylabel "y"

plot for[i=0:99] 'rosslersystem.dat' every:::i::i  u 3:4 w l 
#pt 7 ps .26
#plot for[i=0:9] 'differentbifurcation.dat' every:::i::i  u 2:3 w d
#plot for[i=0:99] 'doublewell.dat' every:::i::i  u 2:3 w l
