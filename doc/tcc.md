# Resumo
A área de Teoria dos Jogos estuda as melhores estratégias dos jogadores em um determinado jogo. Aplicando suas teorias em um jogo de tabuleiro eletrônico, este trabalho propõe analisar o jogo _Big Points_ a partir de um determinado estado e, como resultado, identificar as melhores heurísticas para os jogadores e uma possível inteligência artificial.

# Introdução

&#x2211; &forall;

- História da teoria dos jogos
- Definição de teoria dos jogos
- Jogo a ser analisado
- *Regra do jogo*

# Materiais e Métodos
- O jogo eletrônico está sendo implementado
- Foi feito uma análise combinatória inicial para descobrir a possibilidade de computar todas as possíveis jogadas de um ou de vários jogos. Chegou-se na conclusão que não era factível

## Análise combinatória

O jobo _Big Points_ possui cinco peões de cores distintas, pode ser jogado de dois a cinco jogadores, e dos 55 discos totais, cinco são brancos, cinco são pretos e nove de cada um das cinco cores restantes. Os peões podem estar em cima de um disco ou em uma das cinco posições da escada.

Cada partida diferente pode ser representado pela quantidade de jogadores e pela posição inicial dos discos, compondo o tabuleiro. Desta forma temos que o número de jogos distintos é $10^{41}$ < \#Jogos Distintos < $10^{42}$. Caso fosse possível exaurir todas as possibilidades de cada jogo em um segundo, o tempo necessário para fazer isso para todos os jogos distintos estaria em torno de $10^{35}$ anos.

A quantidade de memória necessária para armazenar um _estado_ do jogo depende de quais características descrevem um _estado_. Como dito anteriormente, o jogo pode ser jogado até cinco jogadores, possui um tabuleiro com 55 discos, uma escada com cinco degraus, e cinco peões no qual a posição varia entre 0 e 60. Considerando as estruturas _array<boolean>_  Feito um cálculo simples de soma das estruturas utilizadas, o valor, em bytes, para armazenar um _estado_ é 47 bytes.

A quantidade de estados distintos para cada partida é calculado da sequinte maneira: cada um dos cinco possíveis jogadores pode ter entre zero e cinco discos das cores branco e preta, assim como pode ter entre zero e dez discos das cores restantes; cada peão pode estar em uma posição entre zero e dez (considerando apenas os de sua cor); e, por fim, cada espaço de disco no tabuleiro pode ou não estar ocupado. Partindo destas informações, temos o cálculo \ref{eq_poda1}


- **Poda 1**
A posição dos peões pode ser apenas de sua respectiva cor. Com essa poda, o número de estados distintos de um jogo é reduzido, mas ainda se encontra na ordem de $10^{21}$.


# Resultados
?

# Discussão e Conclusões
?

# Apêndice
## Cálculos
### Número de partidas distintas
\begin{equation} \label{eq_partidas} \tag{e.q. Números de Partidas Distintas}
\begin{split}
Partidas\ &=\  (\#J-1) \times \binom{55}{5} \times \binom{50}{5} \times \binom{45}{9} \times \binom{36}{9} \times \binom{27}{9} \times \binom{18}{9} \times \binom{9}{9}\\
Partidas\ &=\ \dfrac{4 \times 55!}{2^{27} \times 3^{36} \times 5^7 \times 7^5}\\
Partidas\ &=\ \dfrac{2^{52} \times 3^{26} \times 5^{13} \times 7^{8} \times 11^{5} \times 13^{4} \times 17^{3} \times 19^{2} \times 23^{2} \times 29 \times 31 \times 37 \times 41 \times 43 \times 47 \times 53}{2^{27} \times 3^{36} \times 5^7 \times 7^5}\\
Partidas\ &=\ \dfrac{2^{25} \times 5^{6} \times 7^{3} \times 11^{5} \times 13^{4} \times 17^{3} \times 19^{2} \times 23^{2} \times 29 \times 31 \times 37 \times 41 \times 43 \times 47 \times 53}{3^{10}}\\
Partidas\ &=\ 560'483'776'167'774'018'942'304'261'616'685'408'000'000\\
\end{split}
\end{equation}

### Tempo de computação de todas as partidas
\begin{equation} \label{eq_anos_partidas} \tag{e.q. Tempo de Computação das Partidas}
\begin{split}
Anos\ &=\ \dfrac{N_{partidas\ distintos}}{\nicefrac{partida}{segundo}\times\nicefrac{segundos}{minuto}\times\nicefrac{minutos}{hora}\times\nicefrac{horas}{dia}\times\nicefrac{dias}{ano}}\\
Anos\ &=\ \dfrac{560'483'776'167'774'018'942'304'261'616'685'408'000'000}{\nicefrac{1}{1}\times\nicefrac{60}{1}\times\nicefrac{60}{1}\times\nicefrac{24}{1}\times\nicefrac{365}{1}}\\
Anos\ &=\ 17'772'823'952'554'985'379'956'375'622'041'013\\
\end{split}
\end{equation}

### Espaço de armazenamento na memória por estado
\begin{equation} \label{eq_bytes} \tag{e.q. Bytes na memória}
\begin{split}
Bytes\ &=\ \dfrac{55}{8} + 5 + 5\times 7\\
Bytes\ &=\ 47\ bytes
\end{split}
\end{equation}

### Número de estados
#### Caso Geral
\begin{equation} \label{eq_estados} \tag{e.q. Caso Geral}
\begin{split}
Estados\ &=\ 2^{55}\times 61\times 5\times (5\times 10 + 2\times 6)\\
Estados\ &=\ 2^{55}\times 61\times 5\times 72\\
Estados\ &=\ 791'192'382'536'448'737'280
\end{split}
\end{equation}

\begin{equation} \label{eq_anos_estados} \tag{e.q. Tempo de Computação dos Estados}
\begin{split}
Anos\ &=\ \dfrac{N_{estados\ distintos}}{\nicefrac{estado}{segundo}\times\nicefrac{segundos}{minuto}\times\nicefrac{minutos}{hora}\times\nicefrac{horas}{dia}\times\nicefrac{dias}{ano}}\\
Anos\ &=\ \dfrac{791'192'382'536'448'737'280}{\nicefrac{1}{1}\times\nicefrac{60}{1}\times\nicefrac{60}{1}\times\nicefrac{24}{1}\times\nicefrac{365}{1}}\\
Anos\ &=\ 25'088'545'869'369\\
\end{split}
\end{equation}

#### Poda 1
\begin{equation} \label{eq_poda1} \tag{e.q. Poda 1}
\begin{split}
Estados\ &=\ 2^{55}\times 11\times 5\times (5\times 10 + 2\times 6)\\
Estados\ &=\ 2^{55}\times 11\times 5\times 72\\
Estados\ &=\ 142'674'036'195'097'313'280
\end{split}
\end{equation}

\begin{equation} \label{eq_anos_estados} \tag{e.q. Tempo de Computação dos Estados}
\begin{split}
Anos\ &=\ \dfrac{N_{estados\ distintos}}{\nicefrac{estado}{segundo}\times\nicefrac{segundos}{minuto}\times\nicefrac{minutos}{hora}\times\nicefrac{horas}{dia}\times\nicefrac{dias}{ano}}\\
Anos\ &=\ \dfrac{142'674'036'195'097'313'280}{\nicefrac{1}{1}\times\nicefrac{60}{1}\times\nicefrac{60}{1}\times\nicefrac{24}{1}\times\nicefrac{365}{1}}\\
Anos\ &=\ 4'524'164'009'230\\
\end{split}
\end{equation}
