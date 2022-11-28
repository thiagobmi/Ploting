set terminal png enhanced 


set datafile separator ";"
set key above right 

set title "Clusterization (10 iterations)" #titulo

set output "graph6.png"

plot "arquivo.txt" using (x=$1): (y=$2) title "Pontos" with points pt 7 ps 0.5 , \
    "arquivo.txt" using  (x=$3): (y=$4) title "Centro" with points pt 9 ps 1 

set output "graph7.png"

plot "arquivo.txt" using ($4 == 1447085.38? x=$1 : 1/0):($4 == 1447085.38 ? y=$2 : 1/0) title "Pontos" with points pt 7 ps 0.5 , \
    "arquivo.txt" using  (x=$3): (y=$4) title "Centro" with points pt 9 ps 1 

set output "graph8.png"

plot "arquivo.txt" using ($4 == 1456958.88 ? x=$1 : 1/0):($4 == 1456958.88 ? y=$2 : 1/0) title "Pontos" with points pt 7 ps 0.5 , \
    "arquivo.txt" using  (x=$3): (y=$4) title "Centro" with points pt 9 ps 1 

set output "graph9.png"

plot "arquivo.txt" using ($4 == 1372144.62 ? x=$1 : 1/0):($4 == 1372144.62 ? y=$2 : 1/0) title "Pontos" with points pt 7 ps 0.5 , \
    "arquivo.txt" using  (x=$3): (y=$4) title "Centro" with points pt 9 ps 1 

set output "graph10.png"

plot "arquivo.txt" using ($4 == 1439849.88 ? x=$1 : 1/0):($4 == 1439849.88 ? y=$2 : 1/0) title "Pontos" with points pt 7 ps 0.5 , \
    "arquivo.txt" using  (x=$3): (y=$4) title "Centro" with points pt 9 ps 1 