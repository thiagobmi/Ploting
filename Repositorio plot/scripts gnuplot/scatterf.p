set terminal png enhanced 


set datafile separator ";"
set key above right 

set title "Clusterization (10 iterations)" #titulo

set output "graph69.png"

plot "arquivo.txt" using (x=$1): (y=$2) title "Pontos" with points pt 7 ps 0.5 , \
    "arquivo.txt" using  (x=$3): (y=$4) title "Centro" with points pt 9 ps 1 
