set terminal png enhanced #Define o tipo de arquivo de saída do grafico - por exemplo: eps, png. Outras informações como Tipo/Tamanho de fonte e resolução (e.g., 640x480) podem ser definidas
set output "graphtest.png" # Aqui diz qual o nome do arquivo de saída

set datafile separator ";" # Por padrao, o Gnuplot utiliza o espaco como separador. No caso, o nosso separador é ponto e vírgula ";"
set key above right # Por padrao, o Gnuplot coloca a legenda dentro do escopo do gráfico. Estou forçando que a legenda fique em cima (above) e no canto direito (right)

#comando que plota o grafico com pontos do tipo 7, com titulo "Legenda", com valores x na primera coluna ($1) e y na segunda ($2) a partir do arquivo "data.txt"

set title "Clusterization (centers as random points)" #titulo

plot "arquivo.txt" using (x=$1):(y=$2) title "Pontos" with points pt 7 , \
    "arquivo.txt" using  (x=$7): (y=$8) title "Centro" with points pt 9 ps 1.5 

set title "Clusterization (first iteration)" #titulo

set output "graphtt.png" # Aqui diz qual o nome do arquivo de saída
plot "arquivo.txt" using (x=$1):(y=$2) title "Pontos" with points pt 7 , \
    "arquivo.txt" using  (x=$5): (y=$6) title "Centro" with points pt 9 ps 1.5 

set title "Clusterization (100 iterations)" #titulo

set output "graphttt.png" # Aqui diz qual o nome do arquivo de saída
plot "arquivo.txt" using (x=$1):(y=$2) title "Pontos" with points pt 7 , \
    "arquivo.txt" using  (x=$3): (y=$4) title "Centro" with points pt 9 ps 1.5 

