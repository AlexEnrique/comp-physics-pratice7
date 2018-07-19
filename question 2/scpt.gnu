#set multiplot layout 1,3
set yr[-1.25:1.45]

# 1
plot 'graph1.dat' w l title '10 points'

# 2
replot 'graph2.dat' w l title '1000 points'

# 3
replot 'graph2.dat' w l title '100000 points'

unset multiplot
