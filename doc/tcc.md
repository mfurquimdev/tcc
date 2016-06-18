# Resumo
A área de Teoria dos Jogos estuda as melhores estratégias dos jogadores em um
 determinado jogo. Aplicando suas teorias em um jogo de tabuleiro eletrônico,
 este trabalho propõe analisar o jogo _Big Points_ a partir de um determinado
 estado e, como resultado, identificar as melhores heurísticas para os jogadores
 e uma possível inteligência artificial.

# Introdução
De acordo com Sartini et. al. (2004) "A teoria dos jogos é uma teoria matemática criada para se modelar fenômenos que podem ser observados quando dois ou mais "agentes de decisão" interagem entre si". Pode ser usada para estudar assuntos como eleições, leilões, balança de poder, evolução genética, além de ser estudada no campo da matemática pura.

Existem duas frentes na teoria dos jogos: (a) _teoria econômica dos jogos_, o qual possui motivações predominante econômicas, e (b) _teoria combinatória dos jogos_, que faz uso dos aspectos combinatórios de jogos de mesa e não permite elementos imprevisíveis. Este trabalho fará uso de ambas abordagens, sendo que, a partir da primeira abordagem, é estabelecido um método para se maximizar o ganho (_payoff_) e, a partir da segunda, um método para identificar uma jogada que garantirá a vitória independente do resto do jogo.

## História
A análise de jogos é praticada desde o século XVIII, quando James Waldergrave analisa um jogo de cartas chamado _Le Her_. No século seguinte, Augustin Cournot faz uso da teoria dos jogos para estudos relacionados à política [3]. Mais recentemente, em 1913, Ernst Zermelo publica o primeiro teorema matemático da teoria dos jogos [21].

Dois grandes matemáticos que se interessaram na área de teoria dos jogos foram Emile Borel, o qual publicou quatro artigos sobre jogos estratégicos, e John von Neumann, que teve uma série de trabalhos relacionados à teoria dos jogos. Em 1928, John von Neumann demonstrou que todo jogo finito de soma zero\footnote{Um jogo soma zero é um jogo no qual a vitória de um jogador implica na derrota do outro.} com duas pessoas possui uma solução em estratégias mistas [18]. Em 1937, forneceu uma nova demonstração baseada em outro teorema (teorema do ponto fixo de Brouwer). Em 1944, Neumann publicou um trabalho, junto a Oscar Morgenstern [19], e com isso, a teoria dos jogos entrou na área da economia e matemática aplicada.

Outro matemático que contribuiu para a área foi John Forbes Nash Júnior, que publicou quatro artigos importantes para teoria dos jogos não-cooperativos. Dois destes artigos [13, 16] provando a existência de um equilíbrio de estratégias mistas para jogos não-cooperativos, denominado **equilíbrio de Nash**, que será explicado na seção \ref{subsec:solucoes-de-um-jogo}. Nash recebeu o prêmio Nobel em 1994, junto com John Harsanyi e Reinhard Selten, por sua contribuição para a teoria dos jogos.


<!--
Século XVIII, James Waldergrave analisa um jogo de cartas chamado "_le Her_" e fornece uma solução que é um equilíbrio de estratégia mista, porém não estendeu sua abordagem a uma teoria geral.
Século XIX, Augustin Cournot escreve sobre duopólio [3]. Em 1913, Ernst Zermelo publicou o primeiro teorema matemático da teoria dos jogos [21], afirmando que o xadrez é um jogo estritamente determinado, ou seja, em cada estágio do jogo há pelo menos uma estratégia que garantirá a vitória de um dos jogadoresl, ou no mínimo conduzirá o jogo a um empate.

Emile Borel reinventou as soluções **minimax** e publicou quatro artigos sobre jogos estratégicos.

Em 1928, John von Neumann demonstrou que todo jogo finito de soma zero com duas pessoas possui uma solução em estratégias mistas [18], utilizando topologia e análise funcional.

Em 1937, Neumann forneceu uma nova demonstração baseada no teorema do ponto fixo de Brouwer.

Em 1944, publicou um trabalho na área da economia com Oscar Morgenstern [19]. Com isso, a teoria dos jogos invadiu a economia e a matemática aplicada.
Em 1950, John Forbes Nash Júnior publicou quatro artigos importantes para a teoria dos jogos não-cooperativos. Em "_Equilibrium Points in n-Person Games_" [14] ([13] ?) e "_Non-cooperative Games_" [16], Nash provou a existência de um equilíbrio de estratégias mistas para jogos não-cooperativos, denominado **equilíbrio de Nash**.

Em 1994, John Forbes Nash Jr., John Harsanyi e Reinhard Selten receberam o prêmio Nobel por suas contribuições para a Teoria dos Jogos.
-->

## O que é um jogo?

A teoria dos jogos pode ser definida como a teoria dos modelos matemáticos que estuda a escolha de decisões ótimas sob condições de conflito. Os elementos básicos de um jogo são: o conjunto de **jogadores**, onde cada jogadore possui um conjunto de **estratégias**. A partir das escolhas de estratégias de cada jogador, temos uma **situação** ou **perfil**.

Em termos matemáticos é dito que um jogador tem uma **função utilidade**, que atribui um **payoff** ou **ganho** para cada situação do jogo, quando este jogador tem um certo interesse ou preferência a uma situação.

**Matriz de _payoffs_** é uma representação matricial dos _payoffs_ dos jogadores, onde cada estratégia de um jogador estão representadas por cada linha e cada estratégias de seu oponente estão representadas por cada coluna.

## Soluções de um jogo
\label{subsec:solucoes-de-um-jogo}
Uma solução de um jogo é uma prescrição ou previsão sobre o resultado do jogo. **Dominância** e **equilíbrio de Nash** são dois conceitos importantes para encontrar uma solução de um estado do jogo.

É dito que uma determinada estratégia é uma **estratégia dominante** quando esta é a única estratégia restante após aplicar a técnica de **dominância estrita iterada**. O encontro das estratégias dos jogadores é chamado de **equilíbrio de estratégia dominante**.

**Dominância estrita iterada** nada mais é do que um processo onde se eliminam as estratégias que são estritamente dominadas.

**Solução estratégica** ou **equilíbrio de _Nash_** é um conjunto de estratégias para cada jogador onde cada um deles não tem incentivo de mudar sua estratégia se os demais jogadores não o fizerem.

## Estratégias mistas

**Estratégias mistas** é uma alternativa quando não há equilíbrio de _Nash_. Neste caso, cada jogador escolhe uma **distribuição probabilística** sobre suas estratégias puras. Ou seja, há um valor probabilístico entre 0 e 1 para cada estratégia pura do jogador e a soma de todos estes valores é igual a 1.

O espaço de todos os perfis de estratégias mista é (dado pelo produto cartesiano) é denomidado **espaço de estratégia mista** e cada vetor pertencente a este espaço é denominado **perfil de estratégia mista**.

Cada perfil de estratégia mista determina um _payoff_ esperado. É feito uma média dos _payoffs_ ponderada pelas distribuições de probabilidades.

## Soluções em estratégias mistas

Todos os critérios básicos para soluções de jogos em estratégia puras, tanto dominância estrita iterada quanto equilíbrio de nash, podem ser estendidas para estratégias mistas.

## Existência de soluções

Há jogos que não possuem equilíbrio de Nash em estratégias puras, mas todos os exemplos descritos na seção _Exemplos_ possuem pelo menos um equilíbrio de Nash em estratégias mistas. Existem dois teoremas de que comprovam a existência de solução para jogos em geral: o **teorema minimax de von Newmann** para jogos de soma zero com dois jogadores e o **teorema de equilíbrios de Nash** para jogos gerais.

## Teoremas

1. Teorema Minimax
    - Para jogos de soma zero com dois jogadores
1. Equlíbrio de Nash
    - Para jogos gerais

### O teorema de minimax de von Neumann
#### Jogos de soma constante com dois jogadores

Um jogo de _soma constante com dois jogadores_ é um jogo com dois jogadores, no qual o _payoff_ de suas estratégias na matriz somam a uma constante, i.e. $a_{ij} + b_{ij} = c$. No caso particular em que a constante _c_ é zero, o jogo é dito ter _soma zero_.

## Exemplos

1. Dilema do prisioneiro
1. A batalha dos sexos
1. _Matching pennies_
1. Chefe e empregado
1. A tragédia dos comuns
<!-- 1. Troll na estrada ? -->

- Jogo a ser analisado
- *Regras do jogo* \label{sec:regras_do_jogo}


## O jogo Big Points
### Conceito do jogo
_Big Points_ é um jogo abstrato e estratégico com uma mecânica de colecionar peças. São cinco peões de cores distintas, que podem ser usadas por qualquer jogador, para percorrer um caminho de discos coloridos até chegar ao pódio. Durante o percurso, os jogadores coletam alguns destes discos. A pontuação de cada jogador é determinada a partir da ordem de chegada dos peões ao pódio e a quantidade de discos adquiridos de cada cor. Ganha o jogador com a maior pontuação.

### Regras do jogo
O jogo _Big Points_ pode ser jogado de dois a cinco jogadores. No seu turno, o jogador escolhe qualquer um dos cinco peões, que possuem cores distintas, e o move para cima do próximo\footnote{Apenas é pertmitido um movimento para trás utilizando-se de um disco preto.} disco de sua mesma cor. Em seguida, o jogador deve pegar o próximo disco disponível\footnote{É dito indisponível aqueles discos que já foram pegos por algum jogador ou que possuem um peão em cima.} à frente ou atrás deste peão. Caso não haja discos atrás (à frente) do peão, o jogador deve pegar o disco que está à frente (atrás). <!--e de maneira análoga (semelhante) no caso de não haver discos à frente, o jogador deve pegar o disco atrás.-->



# Materiais e Métodos
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
 demonstrado na equação \ref{eq_partidas}, é maior do que $5\times 10^{41}$.
 Considerando a possibilidade de calcular a melhor estratégia para cada jogo por
 segundo, este cálculo levaria mais do que $1\times 10^{34}$ anos.

Dado uma partida inicial $\gammaup \in \Gamma$ de _Big Points_, sendo $\Gamma$ o
 conjunto contendo todas as $5\times 10^{41}$ partidas distintas, foi calculado
 o número de estados de uma partida. Para calcular o número de estados, é
 preciso determinar as características que definem um estado do jogo. a partir
 da regra na seção \ref{sec:regras_do_jogo}, tem-se que essas características
 são: o estado do tabuleiro, o estado dos peões, o estado da escada, o estado
 dos discos na mão dos jogadores, e o qual o jogador atual. Como demonstrado na
 equação \ref{eq_estados}, a quantidade de estados existentes para uma partida,
 considerando um caso geral, é maior do que $3\times 10^{30}$, levando mais de
 $9\times 10^{22}$ anos para calcular todos os estados a uma velocidade de
 $1 \nicefrac{E_{stado}}{M_{inuto}}$.

A quantidade de memória necessária para armazenar um _estado_ do jogo depende de
 quais características descrevem um _estado_. Como dito anteriormente, o jogo
 pode ser jogado até cinco jogadores, possui um tabuleiro com 55 discos, uma
 escada com cinco degraus, e cinco peões no qual a posição varia entre 0 e 60.
 Considerando as estruturas _array<boolean>_  Feito um cálculo simples de soma
 das estruturas utilizadas, o valor, em bytes, para armazenar um _estado_ é 47
 bytes.


### Poda


A quantidade de estados distintos para cada partida é calculado da sequinte maneira: cada um dos cinco possíveis jogadores pode ter entre zero e cinco discos das cores branco e preta, assim como pode ter entre zero e dez discos das cores restantes; cada peão pode estar em uma posição entre zero e dez (considerando apenas os de sua cor); e, por fim, cada espaço de disco no tabuleiro pode ou não estar ocupado. Partindo destas informações, temos o cálculo \ref{eq_poda1}


- **Poda 1**
A posição dos peões pode ser apenas de sua respectiva cor. Com essa poda, o número de estados distintos de um jogo é reduzido, mas ainda se encontra na ordem de $10^{21}$.


# Resultados
?

# Discussão e Conclusões
?

# Bibliografia

apud

[3] A. A. Cournot, _Recherches sur les Principes Mathématiques de la Théorie des Richesses_, 1838. Traduzido por N. T. Bacon em _Reserches into the Mathematical Principles of the Theory of Wealth_, McMillan, New York, 1927.

[13] J. F. Nash Jr., _Equilibrium Points in n-person Games_. Proceedings of the National Academy of Sciences of the United States of America, pp. 48-49, 1950.

[14] J. F. Nash Jr., _Non-Cooperative Games_. PhD. Thesis. Princeton University Press, 1950.

[16] J. F. Nash Jr., _Non-Cooperative Games_. Annals of Mathematics, pp. 286-295, 1951.

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
