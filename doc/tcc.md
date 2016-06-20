# Resumo
A ~~área de~~ Teoria dos Jogos estuda as melhores estratégias dos jogadores em um
 determinado jogo. Aplicando suas teorias em um jogo de tabuleiro eletrônico,
 este trabalho propõe analisar o jogo _Big Points_ a partir de um determinado
 estado `da partida` e, como resultado, identificar as melhores heurísticas para  os jogadores e uma possível inteligência artificial.

# Introdução
A Teoria dos Jogos é uma ~~teoria~~ `área de estudos, derivada da` matemática, 
criada para se modelar fenômenos que podem ser observados quando dois ou mais 
agentes de decisão interagem entre si. Além de ser usada para estudar assuntos 
como eleições, leilões, balança de poder e evolução genética, a Teoria dos Jogos 
também pode ser estudada no campo de matemática pura.

Há uma diferença entre Teoria Econômica dos Jogos (motivações predominante 
econômicas) e Teoria Combinatória dos Jogos (aspectos combinatórios de jogos de 
mesa e não permite elementos imprevisíveis). `Obs.: completar dizendo qual das 
duas será abordada neste trabalho`.

'''
Observação: A seção seguinte, "História", deveria ser chamada "Histórico da 
Teoria dos Jogos" e deve ficar no capítulo "Fundamentação Teórica".
'''

# Fundamentação Teórica

## História

`No` século XVIII, James Waldergrave ~~analisa~~ `analisou` um jogo de cartas 
chamado _le Her_ e fornece uma solução que é um equilíbrio de estratégia mista, 
porém não estendeu sua abordagem a uma teoria geral. `Obs.:: inserir referência.`

`No` século XIX Augustin Cournot escreveu sobre o duopólio [3]. Em 1913, Ernst 
Zermelo publicou o primeiro teorema matemático da Teoria dos Jogos [21], 
afirmando que o xadrez é um jogo estritamente determinado, ou seja, em cada 
estágio do jogo há pelo menos uma estratégia que garantirá a vitória de um dos 
jogadoresl, ou no mínimo conduzirá o jogo a um empate.

Emile Borel reinventou as soluções **minimax** e publicou quatro artigos sobre 
jogos estratégicos. `Obs.: inserir referências a estes artigos`.
Em 1928, John von Neumann demonstrou que todo jogo finito de soma zero com duas 
pessoas possui uma solução em estratégias mistas [18], utilizando topologia e 
análise funcional.

Em 1937, Neumann forneceu uma nova demonstração baseada no teorema do ponto 
fixo de Brouwer. `Obs.: inserir referência`.
`Já` em 1944, publicou um trabalho na área da economia com Oscar Morgenstern 
[19]. Com isso, a Teoria dos Jogos invadiu a economia e a matemática aplicada.

Em 1950, John Forbes Nash Júnior publicou quatro artigos importantes para a 
teoria dos jogos não-cooperativos. Em "_Equilibrium Points in n-Person Games_" 
[14] <!--([13] ?)--> e "_Non-cooperative Games_" [16], Nash provou a existência 
de um equilíbrio de estratégias mistas para jogos não-cooperativos, denominado 
Equilíbrio de Nash.
Em 1994, John Forbes Nash Jr., John Harsanyi e Reinhard Selten receberam o 
prêmio Nobel por suas contribuições para a Teoria dos Jogos.

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

Uma solução de um jogo é uma prescrição ou previsão sobre o resultado do jogo. 
**Dominância** e **Equilíbrio de Nash** são dois conceitos importantes para 
encontrar uma solução de um estado do jogo.

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
<!-- 1. Troll na estrada ? -->

`Obs.: detalhar os exemplos. E também, ainda na fundamentação teórica, discutir
sobre análise de complexidade, análise combinátoria e programação dinâmica`

## Bibliografia

[3] A. A. Cournot, _Recherches sur les Principes Mathématiques de la Théorie des Richesses_, 1838. Traduzido por N. T. Bacon em _Reserches into the Mathematical Principles of the Theory of Wealth_, McMillan, New York, 1927.

[13] J. F. Nash Jr., _Equilibrium Points in n-person Games_. Proceedings of the National Academy of Sciences of the United States of America, pp. 48-49, 1950.

[14] J. F. Nash Jr., _Non-Cooperative Games_. PhD. Thesis. Princeton University Press, 1950.

[16] J. F. Nash Jr., _Non-Cooperative Games_. Annals of Mathematics, pp. 286-295, 1951.

[18] J. von Neumann. _Zur Theorie der Gesellschaftsspiele_. Mathematische Annalen, vol. 100, pp 295-320. Traduzido por S. Bargmann: _On the Theory of Games of Strategy_ em _Contributions to the Theory of Games_, vol. 4, pp. 13-42, A. W. Tucker e R. D. Luce (editores), Princeton University Press, 1959. <!--(1928 ?)-->

[19] J. von Neumann e O. Morgenstern, _Theory of Games and Economic Behavior_. Princeton University Press, 1944.

[21] E. Zermelo, _Über eine Anwendung der Mengdenlehre auf die theories des Schachspiels_. Atas do _Décimo Quinto Congresso Internacional de Matemáticos_, vol. 2, pp. 501-504, 1913.




`Esta parte sobre o Big Points deve fazer parte ainda da fundamentação Teórica`

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

<!--
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


<!--
\begin{equation*}
\begin{split}
  P_{layers}\quad=\{p_1, p_2,...,p_n\}\\
  \forall p_i \in P_{layers},\quad \exists s_{ij} \in S_i\\
  S_{i}\ =\ \{s_{i1},s_{i2},...,s_{ij}\},
\end{split}
\end{equation*}




% Sendo G = {g_1, g_2,...,g_n} um conjunto finito de jogadores. Cada jogador g_i \existsin G possui um conjunto finito S_i = {s_{i1}, s_{i2},...,s_{im_{i}}} de **estratégias puras** (m_i >= 2). Um vetor s = {s_{1j_1}, s_{2j_2},...,s_{nj_n}}, onde s_{ij_i} é uma estratégia pura para o jogador g_i \existsin G.

-->

