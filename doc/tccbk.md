Simultâneos move games
-

Backward Induction
- As long as every player take turns you can start at the end of the game and make your way to the begin.
- One strategy for every decision node

Game Theory
the study of strategic interaction among rational decision makers
players: people playing the game; each player has a set of strategies
strategies: what they will do, how they'll respond
payoffs: result of the interaction of strategies

strategy is a set with what decision you will make for every decision making situation in the game

each players is chosen an strategy,
these strategies interact,
and the game plays out to its conclusion.

rationality and common knowledge

## Conceitos Fundamentais da Teoria dos Jogos

`Obs.: colocar um parágrafo aqui, explicando que nesta seção serão introduzidos
os conceitos fundamentais da teoria dos jogos, etc...`

### O que é um jogo?

A Teoria dos Jogos pode ser definida como a teoria dos modelos matemáticos que
estuda a escolha de decisões ótimas sob condições de conflito. Os elementos
básicos de um jogo são: o conjunto de **jogadores**, onde cada jogador possui um
conjunto de **estratégias**. A partir das escolhas de estratégias de cada
jogador, temos uma **situação** ou **perfil**.

Em termos matemáticos, é dito que um jogador tem uma **função utilidade**, que
atribui um **_payoff_** (ou **ganho**) para cada situação do jogo, quando este
jogador tem um certo interesse ou preferência à uma situação.

`A` **matriz de _payoffs_** é uma representação matricial dos _payoffs_ dos
jogadores, onde cada estratégia de um jogador ~~estão representadas~~ `é
representada` por ~~cada~~ `uma` linha e cada estratégia de seu oponente
~~estão~~ `é` representada por ~~cada~~ `uma` coluna.

### Soluções de um jogo






## Soluções de um jogo
\label{subsec:solucoes-de-um-jogo}
Uma solução de um jogo é uma prescrição ou previsão sobre o resultado do jogo. **Dominância** e **equilíbrio de Nash** são dois conceitos importantes para encontrar uma solução de um estado do jogo.




Zero-sum game: a vitória de um jogador implica na derrota do outro.
No Big Points, o jogador com maior pontuação vence. Pode-se dar pontuação 1 caso o jogador em questão é o vencedor, e -1 para o jogador que perdeu. Caso haja mais de um jogador com a maior pontuação do jogo, é dado 0 para o payoff dos dois jogadores.

Outra maneira, mais refinada, de demonstrar a vitória e derrota entre os jogadores é calcular a difereça da pontuação entre eles. O jogador com a maior pontuação mantém sua pontuação, e o restante tem sua pontuação subtraída daquela maior pontuação do jogo (dando um resultado negativo).







Em termos matemáticos é dito que um jogador tem uma **função utilidade**, que atribui um **_payoff_** ou **ganho** para cada situação do jogo. Quando essa informação é inserida na matriz da forma normal, tem-se uma **matriz de _payoff_**. Em outras palavras, **matriz de _payoff_** é a representação matricial dos _payoffs_ dos jogadores, onde cada estratégia de um jogador estão representadas por cada linha e cada estratégias de seu oponente estão representadas por cada coluna.

Uma solução de um jogo é uma prescrição ou previsão sobre o resultado do jogo.
**Dominância** e **Equilíbrio de Nash** são dois conceitos importantes para
encontrar uma solução de um estado do jogo.
## Soluções de um jogo
\label{subsec:solucoes-de-um-jogo}
Uma solução de um jogo é uma prescrição ou previsão sobre o resultado do jogo. Dois conceitos importantes para encontrar uma solução de um estado do jogo são **dominância** (minimax) e **equilíbrio de Nash**.

É dito que uma determinada estratégia é uma **estratégia dominante** quando esta
é a única estratégia restante após aplicar a técnica de **dominância estrita
iterada**. O encontro das estratégias dos jogadores é chamado de **equilíbrio de
estratégia dominante**.

**Dominância estrita iterada** nada mais é do que um processo onde se eliminam
as estratégias que são estritamente dominadas. `Obs.: faltou explicar o que é
uma estratégia dominada`.

**Solução estratégica** ou **Equilíbrio de _Nash_** é um conjunto de estratégias
para cada jogador onde cada um deles não tem incentivo de mudar sua estratégia
se os demais jogadores não o fizerem.

## Estratégias mistas

**Estratégias mistas**  ~~é uma~~ `são` alternativas quando não há equilíbrio de
_Nash_. Neste caso, cada jogador escolhe uma **distribuição probabilística**
sobre suas estratégias puras. Ou seja, há ~~um valor probabilístico~~
`probalidade $p$ ($0\leq p\leq 1$)` ~~entre 0 e 1~~ para cada estratégia pura
do jogador e a soma de ~~todos estes valores~~ `todas estas probabilidades` é
igual a 1.

O espaço de todos os perfis de estratégias mista é (dado pelo produto cartesiano)
é denomidado **espaço de estratégia mista** e cada vetor pertencente a este
espaço é denominado **perfil de estratégia mista**.

Cada perfil de estratégia mista determina um _payoff_ esperado. É feito uma
média dos _payoffs_ ponderada pelas distribuições de probabilidades. `Obs.: este
parágrafo ficou confuso: para que é feita a média dos payoffs?`

~~## Soluções em estratégias mistas~~

Todos os critérios básicos para soluções de jogos em estratégia puras, tanto
dominância estrita iterada quanto Equilíbrio de Nash, podem ser estendidas para
estratégias mistas.

### Existência de soluções

Há jogos que não possuem Equilíbrio de Nash em estratégias puras, mas todos os
exemplos descritos na seção _Exemplos_ possuem pelo menos um equilíbrio de Nash
em estratégias mistas. Existem dois teoremas de que comprovam a existência de
solução para jogos em geral: o **Teorema Minimax de Von Newmann** para jogos de
soma zero com dois jogadores e o **Teorema de Equilíbrios de Nash** para jogos
~~gerais~~ `em geral`.

~~## Teoremas~~

`Observação: enunciar os teoremas citados, além de definir antes o que vem a ser
um jogo de soma zero. Usar notação matemática: isto é, Definição...., Teorema:...`

1. Teorema Minimax
    - Para jogos de soma zero com dois jogadores
1. Equlíbrio de Nash
    - Para jogos gerais

~~### O teorema de minimax de von Neumann~~
~~#### Jogos de soma constante com dois jogadores~~  

`Escrever a definição abaixo na forma proposta e antes dos teoremas citados`

Um jogo de _soma constante com dois jogadores_ é um jogo com dois jogadores,
no qual o _payoff_ de suas estratégias na matriz somam a uma constante, i.e.
$a_{ij} + b_{ij} = c$. No caso particular em que a constante _c_ é zero, o jogo
é dito ter _soma zero_. `Observação: a notação ficou confusa: há uma única ou duas
matrizes? Pois a soma a_{ij} + b_{ji} dá a entender duas matrizes. Se for uma só,
arrumar este trecho, e também é bom nomea a matriz com uma variável (por exemplo, "na matriz $A$".`

## Exemplos

1. Dilema do prisioneiro
1. A batalha dos sexos
1. _Matching pennies_
1. Chefe e empregado
1. A tragédia dos comuns
 1. Troll na estrada ?

`Obs.: detalhar os exemplos. E também, ainda na fundamentação teórica, discutir
sobre análise de complexidade, análise combinátoria e programação dinâmica`
- Jogo a ser analisado
- *Regras do jogo* \label{sec:regras_do_jogo}


`Este capítulo de Materias e Métodos deve suceder a Fundamentação Teórica`
# Materiais e Métodos

`Desenvolver os tópicos listados abaixo na forma de parágrafo. Também é preciso, neste capítulo, listar
os equipamentos e softwares utilizados e a metodologia de desenvolvimento de
software utilizada`

- O jogo eletrônico está sendo implementado
- Foi feito uma análise para descobrir a possibilidade de computar a melhor
 jogada possível para um ou vários jogos. Nesta análise, levou-se em
 consideração:
	- A quantidade de memória necessária
	- O número de estados existentes
	- A complexidade assintótica do algoritmo (pois o número de entrada pro
 algorítimo é muito grande)
	- O tempo de processamento para um determinado número de estados

## Definições de termos em Teoria dos Jogos

**Forma extensiva** é a representação do jogo em uma árvore, onde os nós são estados do jogo e as arestas são as jogadas permitidas. [pg. 17]

**Estratégia pura** é um conjunto de escolhas a serem feitas a cada momento que uma decisão precisa ser feita no jogo. [pg. 20]

**Forma normal** é derivada do conjunto de estratégia pura dos jogadores. Matiz [pg.22]

: $$\Gamma = \langle I, \{S_{i}\}_{i\in I}, \{P_{i}\}_{i\in I}\rangle$$



## Análise combinatória
O jobo _Big Points_ possui 55 discos no tabuleiro e podem jogar de dois a cinco
jogadores. Com isso, tem-se que a quantidade de jogos distintos, como
 demonstrado na equação `Obs.: traga estas equações para esta parte do texto, não as deixe em apêndice`.
\ref{eq_partidas}, é maior do que $5\times 10^{41}$.
 Considerando a possibilidade de calcular a melhor estratégia para cada jogo por
 segundo, este cálculo levaria mais do que $10^{34}$ anos.

Dado uma partida inicial $\gammaup \in \Gamma$ de _Big Points_, sendo $\Gamma$
 o conjunto contendo todas as $5\times 10^{41}$ partidas distintas, foi calculado
 o número de estados de uma partida. Para calcular o número de estados, é
 preciso determinar as características que definem um estado do jogo.  ~~a
partir
 da regra na~~ `De acordo com a` Seção \ref{sec:regras_do_jogo}, tem-se que
essas características
 preciso determinar as características que definem um estado do jogo. a partir
 da regra na seção \ref{sec:regras_do_jogo}, tem-se que essas características
 são: o estado do tabuleiro, o estado dos peões, o estado da escada, o estado
 dos discos na mão dos jogadores e o ~~qual o jogador~~ atual. Como demonstrado
na equação \ref{eq_estados}, a quantidade de estados existentes para uma partida,
 considerando um caso geral, é maior do que $3\times 10^{30}$, levando mais de
 $9\times 10^{22}$ anos para calcular todos os estados a uma velocidade de
 $1 \nicefrac{E_{stado}}{M_{inuto}}$.

A quantidade de memória necessária para armazenar um _estado_ do jogo depende
~~de
 quais~~ `das` características `que` descrevem um _estado_. Como dito
anteriormente, o jogo
 pode ser jogado até cinco jogadores, possui um tabuleiro com 55 discos, uma
 escada com cinco degraus, e cinco peões no qual a posição varia entre 0 e 60.
 `Obs.: deste trecho em diante o texto ficou confuso. Favor reescrever` Considerando as estruturas _array<boolean>_  Feito um cálculo simples de soma
 das estruturas utilizadas, o valor, em bytes, para armazenar um _estado_ é 47
 bytes.

### Poda

A quantidade de estados distintos para cada partida ~~é~~ `foi` calculada da
seguinte
maneira: cada um dos cinco possíveis jogadores pode ter entre zero e cinco
discos das cores branco e preta, assim como pode ter entre zero e dez discos das
cores restantes; cada peão pode estar em uma posição entre zero e dez
(considerando apenas os de sua cor); e, por fim, cada espaço de disco no
tabuleiro pode ou não estar ocupado. Partindo destas informações, temos
~~o cálculo~~ `a Equação` \ref{eq_poda1}. `Obs.: novamente, trazer as equações
para este capítulo`.

- **Poda 1**

A posição dos peões pode ser `determinada considerando-se` apenas `as casas do
tabuleiro` de sua respectiva cor. Com essa poda, o número de estados distintos
de um jogo é reduzido, mas ainda se encontra na ordem de $10^{21}$.

`Obs.: escrever a expressão resultante da poda`

# Resultados
?

# Discussão e Conclusões
?

# Bibliografia

[1] Jones A. J., Game Theory 1980, pg. 69


Émile Borel The Theory of Play and Integral Equations with Skew Symmetric Kernels", 1921, Comptes Rendus Hebdomadaires des Seances de l'Academie des Sciences (transl., 1953, Econometrica)

Émile Borel "On Games that Involve Chance and the Skill of Players", 1924, in Elements de la Théorie des Probabilités (transl., 1953, Econometrica).

Émile Borel "On Systems of Linear Forms of Skew Symmetric Determinant and the General Theory of Play", 1927, Comptes Rendus Hebdomadaires des Seances de l'Academie des Sciences (transl., 1953, Econometrica)

Émile Borel Chapter 5, “Le jeu de poker” of his 1938 book, Applications aux Jeux des Hazard.

apud

[3] A. A. Cournot, _Recherches sur les Principes Mathématiques de la Théorie des Richesses_, 1838. Traduzido por N. T. Bacon em _Reserches into the Mathematical Principles of the Theory of Wealth_, McMillan, New York, 1927.

[14] J. F. Nash Jr., _Non-Cooperative Games_. PhD. Thesis. Princeton University Press, 1950.


[18] J. von Neumann. _Zur Theorie der Gesellschaftsspiele_. Mathematische Annalen, vol. 100, pp 295-320. Traduzido por S. Bargmann: _On the Theory of Games of Strategy_ em _Contributions to the Theory of Games_, vol. 4, pp. 13-42, A. W. Tucker e R. D. Luce (editores), Princeton University Press, 1959. <!--(1928 ?)-->

[19] J. von Neumann e O. Morgenstern, _Theory of Games and Economic Behavior_. Princeton University Press, 1944.

[21] E. Zermelo, _Über eine Anwendung der Mengdenlehre auf die theories des Schachspiels_. Atas do _Décimo Quinto Congresso Internacional de Matemáticos_, vol. 2, pp. 501-504, 1913.




# Apêndice
## Cálculos
### Número de partidas distintas
<!-- Partidas\ &=\ \dfrac{4 \times 55!}{2^{27} \times 3^{36} \times 5^7 \times 7^5}\\ -->
\begin{equation} \label{eq_partidas} \tag{e.q. Números de Partidas Distintas}
\begin{split}
Partidas\ &=\  (\#J-1) \times \binom{\#D_T}{\#D_W} \times \binom{\#D_{L1}}{\#D_K} \times \binom{\#D_{L2}}{\#D_R} \times \binom{\#D_{L3}}{\#D_G} \times \binom{\#D_{L4}}{\#D_B} \times \binom{\#D_{L5}}{\#D_Y} \times \binom{\#D_{L6}}{\#D_P}\\
Partidas\ &=\  4\times \binom{55}{5} \times \binom{50}{5} \times \binom{45}{9} \times \binom{36}{9} \times \binom{27}{9} \times \binom{18}{9} \times \binom{9}{9}\\
Partidas\ &=\ 560'483'776'167'774'018'942'304'261'616'685'408'000'000\\
Partidas\ &\approx 5\times 10^{41}
\end{split}
\end{equation}

### Tempo de computação de todas as partidas
\begin{equation} \label{eq_anos_partidas} \tag{e.q. Tempo de Computação das Partidas}
\begin{split}
Anos\ &=\ \dfrac{N_{partidas\ distintas}}{\nicefrac{partida}{segundo}\times\nicefrac{segundos}{minuto}\times\nicefrac{minutos}{hora}\times\nicefrac{horas}{dia}\times\nicefrac{dias}{ano}}\\
Anos\ &=\ \dfrac{560'483'776'167'774'018'942'304'261'616'685'408'000'000}{\nicefrac{1}{1}\times\nicefrac{60}{1}\times\nicefrac{60}{1}\times\nicefrac{24}{1}\times\nicefrac{365}{1}}\\
Anos\ &=\ 96'526'964'154'064'571'465'728\\
Anos\ &\approx 9\times 10^{34}
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
Estados\ &=\ 2^{55}\times 61^{5}\times (10^{5} + 6^{2})\\
Estados\ &=\ 3'044'074'341'562'580'507'100'339'765'248\\
Estados\ &\approx 3\times 10^{31}
\end{split}
\end{equation}

\begin{equation} \label{eq_anos_estados} \tag{e.q. Tempo de Computação dos Estados}
\begin{split}
Anos\ &=\ \dfrac{N_{estados\ distintos}}{\nicefrac{estado}{segundo}\times\nicefrac{segundos}{minuto}\times\nicefrac{minutos}{hora}\times\nicefrac{horas}{dia}\times\nicefrac{dias}{ano}}\\
Anos\ &=\ \dfrac{3'044'074'341'562'580'507'100'339'765'248}{\nicefrac{1}{1}\times\nicefrac{60}{1}\times\nicefrac{60}{1}\times\nicefrac{24}{1}\times\nicefrac{365}{1}}\\
Anos\ &=\ 96'526'964'154'064'571'465'728
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
Anos\ &=\ 4'524'164'009'230
\end{split}
\end{equation}


\begin{equation*}
\begin{split}
  P_{layers}\quad=\{p_1, p_2,...,p_n\}\\
  \forall p_i \in P_{layers},\quad \exists s_{ij} \in S_i\\
  S_{i}\ =\ \{s_{i1},s_{i2},...,s_{ij}\},
\end{split}
\end{equation*}




% Sendo G = {g_1, g_2,...,g_n} um conjunto finito de jogadores. Cada jogador g_i \existsin G possui um conjunto finito S_i = {s_{i1}, s_{i2},...,s_{im_{i}}} de **estratégias puras** (m_i >= 2). Um vetor s = {s_{1j_1}, s_{2j_2},...,s_{nj_n}}, onde s_{ij_i} é uma estratégia pura para o jogador g_i \existsin G.


# Notes
pro universo dos

validar os estudos
replicar os

extrapolada para a economia, política e biologia no campo de evolução genética.

## O que é um jogo?

Jogo é interativo

Jogo pode ser simétrico (quando as regras são as mesmas para todos os jogadores)

Common Knowledge, todo mundo sabe as regras do jogo e todos sabem que todo mundo sabe as regras do jogo.

Game Theory
Strategic interactive decision making

The Strategy of Conflict (1960) Thomas C. Schelling
Nobel in economics for his work in Game Theory

John von Neumann started think about the optimal way to playing poker

1928 von Neumann publish his first work
minimax theorem

Reinhard Selten
1930
examples are simple, but this are make them useful in developing an intuition on how to solve problem in real world.
They are anologies

ex post rationality
fail to look ahead, they rather look behind and see how it was played

Game theory provides a baseline for comparison

1944, The theory of Games and Economic Behavior, John von Neumann & Oskar Morgenstern

Game Theory is the study of strategic interaction among rational players

strategic interaction decision making

games of incomplete information

The tragedy of the commons

<!--

\newtheorem*{JFN}{Definição. Jogo de n-jogadores na Forma Normal}

\begin{JFN}
é definido como uma tupla (2n+1)
$$(J; S_1,...,S_n; u_1(s_1,...,s_n),...,u_n(s_1,...,s_n))$$
onde $n \geq 2$ é um número natural; $J = \{1,2,...,n\}$ é um dado conjunto finito chamado \textbf{conjunto de jogadores}, onde seus elementos são os jogadores; $\forall i\in \{1,2,...,n\}$, $S_i$ é um conjunto arbitrário chamado \textbf{conjunto de estratégias do jogador} $i$, e $$u_i: S_1 \times S_2 \times ...\times S_n$$
\end{JFN}


\chapter[Fundamentação Teórica]{Fundamentação Teórica}
\section{Histórico da Inteligência Artifical aplicada à Jogos}

No final do século XIX, Von Kempelen inventou um dispositivo chamado \emph{Maelzel Chess Automaton}, capaz de jogar uma partida inteira de xadrez \cite{shannon_1950}. Porém, vários artigos foram publicados após a exibição de tal máquina, incluindo um trabalho por Edgard Allan Poe entitulado \emph{Maelzel's Chess Player} explicando que a máquina era operada por uma pessoa. Uma tentativa mais honesta foi feita em 1914 por Torres y Quevendo, que construiram um dispositivo que jogava um jogo final de xadrez (rei e torre contra rei) \cite{vigneron_1914}. O objetivo da máquina era forçar um cheque-mate no jogador.

Há anos programadores tem se interessado em inteligência artificial com uma perspectiva de programar um computador que consiga ganhar de um ser humano \cite{samuel_1959} \cite{samuel_1967}

De acordo com \cite{sartini_IIbienaldasbm}, a teoria dos jogos pode ser vista como "a teoria dos modelos matemáticos que estuda a escolha de decisões ótimas sob condições de conflito". Para isso, é preciso definir um jogo de tal maneira que os conflitos sejam evidentes. Uma maneira de representar um jogo não cooperativo é fazer uso de sua forma normal \cite{jones_1980}, no qual é feito uma matriz com cada estratégia de cada jogador. Para cada estratégia do jogador \emph{linha} tem-se uma estratégia do jogador \emph{coluna}, e o conflito é representado nesta célula da matriz.

Cada caminho\footnote{Um caminho na árvore é um conjunto de arestas partindo da raíz até uma de suas folhas.} nessa árvore representa uma estra

-->
