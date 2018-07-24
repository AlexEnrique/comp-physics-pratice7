set multiplot layout 1,3

# 1
set yr[-1.25:1.25]
set title '10 points'
plot 'graph1.dat' w l

# 2
set yr[-1.25:1.25]
set title '1000 points'
plot 'graph2.dat' w l

# 3
set yr[-1.25:1.25]
set title '100000 points'
plot 'graph2.dat' w l

unset multiplot
