<!--
Capítulo 0 - Introdução
-->
\chapter*[Introdução]{Introdução}
\addcontentsline{toc}{chapter}{Introdução}
\label{ch:introducao}

Imagine que um grupo de pessoas concordam em obedecer certas regras e agir de forma individual, ou em grupos menores, sem violar as regras especificadas.
No final, suas ações como um todo levará a uma certa situação chamada resultado.
Os membros deste grupo são chamados de jogadores e as regras que eles concordaram em obedecer constitui um jogo.
Estes conceitos são exemplos das ideias utilizadas em análises baseadas na teoria dos jogos.

\section*{Objetivos}

O objetivo principal deste trabalho é realizar uma análise _minimax_ nas versões reduzidas do jogo _Big Points_.
O jogo foi reduzido em relação à quantidade e tipo de algumas peças, visto que para o jogo completo seria um trabalho computacional imenso.

\section*{Justificativa}

A pergunta que motivou o desenvolvimento deste projeto foi a questão do balanceamento do jogo _Big Points_, isto é, se os jogadores jogarem de forma ótima, a chance de vitória é a mesma para todos os jogadores?
Para responder esta pergunta, primeiro foi necessário fazer uma análise de viabilidade do cálculo computacional de todos os jogos.
Após chegar à conclusão que seria impossível calcular um jogo inteiro, foi escrito um programa para percorrer todas as possibilidades de jogadas de um jogo reduzido de _Big Points_ e, por fim, interpretar os resultados para responder se o jogo (reduzido) é ou não balanceado.

\section*{Organização do Trabalho}

Este trabalho foi dividido em quatro capítulos. O primeiro capítulo, Fundamentação Teórica, relata um pouco sobre a história da teoria dos jogos, esclarece alguns conceitos relevantes para o entendimento do trabalho, e explica as regras do próprio jogo.
Em seguida, tem-se o Capítulo \ref{ch:metodologia}, referente à análise e ao desenvolvimento do projeto até sua conclusão, e no Capítulo \ref{ch:resultados} os resultados desta análise são discutidos.
Por último, o Capítulo \ref{ch:conclusao} onde são feitas as considerações finais do trabalho e são citados alguns possíveis trabalhos futuros a partir do trabalho atual.


















<!--
Capítulo 1 - Fundamentação Teórica
-->
\chapter{Fundamentação Teórica}
\label{ch:fundamentacao_teorica}

Para um bom entendimento da análise realizada no jogo _Big Points_ é preciso um conhecimento básico sobre teoria dos jogos e programação dinâmica.
A primeira seção deste capítulo conta brevemente sobre a história da Teoria dos Jogos, com alguns nomes icônicos para esta área.
A Seção \ref{teoria-dos-jogos} explica um pouco sobre os conceitos da Teoria dos Jogos, mas apenas o necessário para o entendimento deste trabalho.
Na Seção \ref{programauxe7uxe3o-dinuxe2mica}, são apresentados os conceitos sobre programação dinâmica e, na última seção, as regras do jogo \textit{Big Points} são explicadas.

# Histórico da Teoria dos Jogos

Pode-se dizer que a análise de jogos é praticada desde o século XVIII, tendo como evidência uma carta escrita por James Waldegrave ao analisar uma versão curta de um jogo de baralho chamado \emph{le Her} \cite{Prague_severalmilestones}.
No século seguinte, o matemático e filósofo Augustin Cournot fez uso da teoria dos jogos para estudos relacionados à política \apud{cournot_1838}{sartini_IIbienaldasbm}.

Mais recentemente, em 1913, Ernst Zermelo publicou o primeiro teorema matemático da teoria dos jogos \apud{zermelo_1913}{sartini_IIbienaldasbm}.
Outros dois grandes matemáticos que se interessaram na teoria dos jogos foram Émile Borel e John von Neumann.
Nas décadas de 1920 e 1930, Emile Borel publicou vários artigos sobre jogos estratégicos \apud{borel_1921}{Prague_severalmilestones} \apud{borel_1924}{Prague_severalmilestones} \apud{borel_1927}{Prague_severalmilestones}, introduzindo uma noção abstrada sobre jogo estratégico e estratégia mista.

Em 1928, John von Neumann provou o teorema _minimax_, no qual há sempre uma solução racional para um conflito bem definido entre dois indivíduos cujos interesses são completamente opostos \apud{neumann_1928}{alecsandra_2006}.
Em 1944, Neumann publicou um trabalho junto a Oscar Morgenstern introduzindo a teoria dos jogos na área da economia e matemática aplicada \apud{neumann_1944}{sartini_IIbienaldasbm}.
Além destas contribuições, John von Neumann ainda escreveu trabalhos com grande impacto na área da computação, incluindo a arquitetura de computadores, princípios de programação, e análise de algoritmos \cite{miyazawa_2010}.

Um dos principais nomes da história da Teoria dos Jogos é John Forbes Nash Junior, um matemático estadunidense que conquistou o prêmio Nobel de economia em 1994.
Foi formado pela Universidade de Princeton, em 1950, com a tese _Non-Cooperative Games_ (Jogos Não-Cooperativos, publicada em 1951) \apud{johnforbesnashjunior1950}{alecsandra_2006}.
Nesta tese, Nash provou a existência de ao menos um ponto de equilíbrio em jogos de estratégias para múltiplos jogadores, mas para isso é necessário que os jogadores se comportem racionalmente \cite{alecsandra_2006}.

O equilíbrio de Nash era utilizado apenas para jogos de informação completa.
Posteriormente, com os trabalhos de Harsanyi e Selten, foi possível aplicar este método em jogos de informação incompleta.
A partir de então, surgiram novas técnicas de solução de jogos e a teoria dos jogos passou a ser aplicada em diferentes áreas de estudo, como na economia, biologia e ciências políticas \cite{alecsandra_2006}.

Entre 1949 e 1953, Nash escreveu mais artigos ligados à solução de jogos estratégicos: _The Bargaining Problema_ (O Problema da Barganha, 1949) \apud{nash_bargain1950}{alecsandra_2006} e _Two-Person Cooperative Games_ (Jogos Cooperativos de Duas Pessoas, 1953) \apud{johnforbesnashjunior1953}{alecsandra_2006}.
Também escreveu artigos de matemática pura sobre variedades algébricas em 1951, e de arquitetura de computadores em 1954 \cite{alecsandra_2006}.

Mais recentemente, dois trabalhos se destacaram na área de Teoria dos Jogos: o livro de Thomas Schelling, publicado em 1960, que se destacou em um ponto de vista social \apud{schelling1960strategy}{aguidetogametheory_2005}; e um livro de dois volumes de Elwyn Berlekamp, John Conway e Richard Guy que se tornou uma referência na área da teoria dos jogos combinatorial por explicar os conceitos fundamentais para a teoria dos jogos combinatorial \apud{elwyn_1982}{eyawtkagtbwata_2003}.

# Teoria dos Jogos

A Teoria dos Jogos pode ser definida como a teoria dos modelos matemáticos que estuda a escolha de decisões ótimas[^optimal_decision] sob condições de conflito[^conflict_condition].
Atualmente, o campo da teoria dos jogos divide-se em três áreas:
Teoria Econômica dos Jogos, que normalmente analisa movimentos simultâneos (Definição \ref{def:movimentossimultaneos}) de dois ou mais jogadores;
Teoria Combinatória dos Jogos, no qual os jogadores fazem movimentos alternadamente, e não faz uso de elementos de sorte, diferente da Teoria Econômica dos Jogos que também trata desse fenômeno; e
Teoria Computacional dos Jogos, que engloba jogos que são possíveis resolver por força bruta ou inteligência artificial \cite{eyawtkagtbwata_2003}, como jogo da velha e xadrez, respectivamente.
Nestre trabalho serão utilizados alguns conceitos da Teoria Econômica dos Jogos para analisar um jogo de movimentos alternados, a ser resolvido computacionalmente.

[^optimal_decision]: É considerado que os jogadores são seres racionais e possuem conhecimento completo das regras.

[^conflict_condition]: Condições de conflito são aquelas no qual dois ou mais jogadores possuem o mesmo objetivo.

\begin{mydef}
\label{def:movimentossimultaneos}
Em jogos com \textbf{movimentos simultâneos}, os jogadores devem escolher o que fazer ao mesmo tempo ou, o que leva à mesma situação, as escolhas de cada jogador é escondida de seu oponente. Em qualquer um dos dois casos, o jogador deve escolher sua jogada levando em consideração a possível jogada do outro \cite{aguidetogametheory_2005}.
\end{mydef}

Os elementos básicos de um jogo são: o conjunto de jogadores; o conjunto de estratégias para cada jogador; uma situação, ou perfil, para cada combinação de estratégias dos jogadores; e uma função utilidade para atribuir um _payoff_, ou ganho, para os jogadores no final do jogo.
Os **jogadores** são dois ou mais seres racionais que possuem um mesmo objetivo e, para alcançar esse objetivo, cada jogador possui um conjunto de **estratégias**.
A partir das escolhas de estratégias de cada jogador, tem-se uma **situação** ou **perfil** e, no final do jogo, um **resultado** para cada perfil \cite{sartini_IIbienaldasbm}.
Em outras palavras, os jogadores escolhem seus movimentos simultaneamente, como explicado na Definição \ref{def:movimentossimultaneos}, o que levará a vitória de algum deles no final do jogo, ou a um empate.

Em termos matemáticos é dito que um jogador tem uma **função utilidade**, que atribui um **_payoff_**, ou **ganho**, para cada situação do jogo.
Quando essa informação é inserida em uma matriz, tem-se uma **matriz de _payoff_** \cite{sartini_IIbienaldasbm}.
Em outras palavras, a matriz de ganho é a representação matricial dos _payoffs_ dos jogadores, onde as estratégia de um jogador estão representadas por cada linha e as de seu oponente estão representadas pelas colunas.

Para um melhor entendimento destes conceitos, será utilizado uma versão curta do jogo \emph{Nim}.
Esta versão simplificada do jogo começa com quatro palitos e dois montes (com dois palitos cada monte).
Cada um dos dois jogadores joga alternadamente retirando quantos palitos quiser, mas de apenas um dos montes.
O jogador que retirar o último palito do jogo perde \cite{jones_1980}.

Começando com o conceito de abstração e representação de um jogo, existe uma maneira de fazê-la chamada forma extensiva, a qual é descrita na Definição \ref{def:forma_extensiva}.
De acordo com esta definição, a árvore do jogo \emph{Nim} simplificado é representada na Figura \ref{fig:nim_tree}.

\begin{mydef}
\label{def:forma_extensiva}
É dito que um jogo está representado na sua \textbf{forma extensiva} se a árvore do jogo reproduzir cada estado possível, junto com todas as possíveis decisões que levam a este estado, e todos os possíveis resultados a partir dele \cite[grifo nosso]{jones_1980}. Os nós são os estados do jogo e as arestas são as possíveis maneiras de alterar aquele estado, isto é, os movimentos permitidos a partir daquele estado.
\end{mydef}

\nimtree

A ordem dos jogadores está sendo indicada ao lado esquerdo da figura, de forma que o jogador $J_1$ é o primeiro a realizar um movimento, o $J_2$ é o segundo, o terceiro movimento é do $J_1$ e assim por diante.
O estado do jogo é representado por cada nó da árvore, sendo que os quatro palitos estão divididos em dois montes dentro do retângulo.
Cada aresta representa uma jogada válida para o jogador que vai realizar o moviment (jogador atual).
Ao analisar a primeira jogada, percebe-se que $J_1$ possui quatro jogadas possíveis: retirar um palito do primeiro monte; retirar dois palitos do primeiro monte; retirar um palito do segundo monte; e retirar dois palitos do segundo monte.
As últimas jogadas foram omitidas da árvore do jogo por serem simétricas às outras duas primeiras.
Na aresta $(A,B)$[^aresta], o primeiro jogador pega apenas um palito de um dos montes de palito, enquanto a aresta $(A,C)$ representa o movimento de pegar todos os dois palitos de um monte.
Da mesma maneira, as arestas $(B,D)$, $(B,E)$, $(B,F)$, $(C,G)$ e $(C,H)$ são os movimentos de $J_2$ em resposta às jogadas de $J_1$.

[^aresta]: A aresta representada como $(A,B)$, sai do nó $A$ ao nó $B$. Uma notação alternativa seria $\overrightarrow{B}$, sendo a aresta que incide em $B$ \cite{algorithmsvelsky_1988}.

No final da Figura \ref{fig:nim_tree}, há uma representação para cada folha[^leaf] para indicar o vencedor no final daquela série de movimentos.
Nos nós terminais $N$, $O$ e $H$, o jogador $J_2$ retirou o último palito do jogo, resultando na vitória de $J_1$.
Para as folhas $J$, $L$ e $M$, a vitória é do segundo jogador.

[^leaf]: Um nó é considerado folha (ou nó terminal) quando não possuir nenhum filho.

Olhando para a árvore de baixo pra cima, o jogador $J_1$ ganha na folha $N$.
Na verdade, ele já havia ganhado no nó anterior ($I$), pois o jogador $J_2$ só tem uma jogada a fazer.
Como a decisão de chegar no nó $I$ é de escolha do primeiro jogador ao realizar a jogada $(D,I)$, pode-se dizer que essa jogada é um \emph{winning move}[^winning_move].

[^winning_move]: Movimento que garante a vitória.

Ao mesmo tempo que $J_1$ é um jogador inteligente que tenta sempre jogar da melhor maneira possível, o segundo jogador também fará as melhores jogadas que puder.
Sabendo que o nó $D$ garante sua derrota, $J_2$ fará de tudo para escolher outras jogadas.
De fato, ao observar essa árvore com cuidado, o jogador $J_2$ sempre irá vencer, pois há sempre um nó no qual, a partir dele, lhe garante à vitória.
Para entender melhor o por quê do jogador $J_2$ sempre ganhar, será utilizado uma análise partindo do conceito de estratégia pura (Definição \ref{def:estrategia_pura}).

\begin{mydef}
\label{def:estrategia_pura}
\textbf{Estratégia pura} é definida como um conjunto de decisões a serem feitas para cada ponto de decisão no jogo \cite[grifo nosso]{jones_1980}.
\end{mydef}

As estratégias pura do jogador $J_1$ são nomeadas $\sigma_i$ com $i \in \{1,\ldots,a\}$ e as do jogador $J_2$ são representadas por $\tau_j$ com $j \in \{1,\ldots,b\}$, onde $a$ e $b$ são a quantidade de estratégias pura de $J_1$ e $J_2$, respectivamente.
A estratégia pura também pode ser vista como um caminho[^path] único na árvore, que tem origem no primeiro nó de decisão do jogador e termina em uma folha.
No caso do jogador $J_1$, o caminho começa na raíz, e no caso do jogador $J_2$, o caminho pode começar em $B$ ou em $C$.
Devido à isso, $J_2$ deve considerar os dois casos e decidir de antemão o que fazer.
A partir da Definição \ref{def:estrategia_pura}, tem-se as estratégias de ambos os jogadores nas Tabelas \ref{tab:estrategia_pura_j1} e \ref{tab:estrategia_pura_j2}.

[^path]: Uma sequência de arestas onde o nó no final de uma aresta coincide com o nó no começo da próxima aresta, é chamado de \textbf{caminho} \cite[grifo nosso]{sometopics_1971}.

\begin{table}[htb]
	\centering
	\caption{Estratégias pura do jogador $J_1$ para o jogo \emph{Nim}}
	\label{tab:estrategia_pura_j1}

	\rowcolors{2}{gray!20}{white}
	\begin{tabular}{cccc}
		\toprule
		\textbf{Estratégia} & \textbf{$\mathbf{1}^{\b{\tiny{o}}}$ Turno} & \multicolumn{2}{c}{\textbf{$\mathbf{2}^{\b{\tiny{o}}}$ Turno}} \\
		                    &                                            & \footnotesize{Se em} & \footnotesize{Vá para}                  \\
		\midrule
		$\sigma_1$          & $A \rightarrow B$                          & $D$                  & $I$                                     \\
		$\sigma_2$          & $A \rightarrow B$                          & $D$                  & $J$                                     \\
		$\sigma_3$          & $A \rightarrow C$                          & \textendash          & \textendash                             \\
		\bottomrule
	\end{tabular}
\end{table}

\begin{table}[htb]
	\centering
	\caption{Estratégias pura do jogador $J_2$ para o jogo \emph{Nim}}
	\label{tab:estrategia_pura_j2}
	\begin{tabular}{ccc}
		\toprule
		\textbf{Estratégia}                             & \multicolumn{2}{c}{\textbf{$\mathbf{1}^{\b{\tiny{o}}}$ Turno}} \\
		                                                & \footnotesize{Se em} & \footnotesize{Vá para}                  \\
		\midrule
		\rowcolor{gray!20}								& $B$                  & $D$                                     \\
		\rowcolor{gray!20}\multirow{-2}{*}{$\tau_1$}	& $C$                  & $G$                                     \\
													    & $B$                  & $E$                                     \\
						  \multirow{-2}{*}{$\tau_2$}	& $C$                  & $G$                                     \\
		\rowcolor{gray!20}  						    & $B$                  & $F$                                     \\
		\rowcolor{gray!20}\multirow{-2}{*}{$\tau_3$}	& $C$                  & $G$                                     \\
													    & $B$                  & $D$                                     \\
						  \multirow{-2}{*}{$\tau_4$}	& $C$                  & $H$                                     \\
		\rowcolor{gray!20}							    & $B$                  & $E$                                     \\
		\rowcolor{gray!20}\multirow{-2}{*}{$\tau_5$}	& $C$                  & $H$                                     \\
													    & $B$                  & $F$                                     \\
						  \multirow{-2}{*}{$\tau_6$}	& $C$                  & $H$                                     \\
		\bottomrule
	\end{tabular}
\end{table}

Na Tabela \ref{tab:estrategia_pura_j1}, os movimentos de $J_1$ estão separadas em dois turnos.
O primeiro turno é o nó raiz ($A$).
A partir deste estado, o jogador possui duas escolhas $(A,B)$ ou $(A,C)$, representados na tabela como as estratégias pura $\sigma_1$ e $\sigma_3$.
Mas além dessa informação, ainda deve-se representar a próxima decisão a ser feita após escolher $(A,B)$.
Se $J_2$ escolher certos movimentos que chegue no $D$, o primeiro jogador ainda tem mais uma escolha a fazer.
Essa segunda escolha está representada nas colunas: _Se em_, no caso se o jogador estiver naquele nó; e _Vá para_, que são as possíveis jogadas a serem feitas a partir do nó em questão.
Então, a diferença de $\sigma_1$ e $\sigma_2$ é apenas nesta segunda escolha.
Ao chegar em um nó terminal, acaba também a descrição de uma estratégia pura.

\begin{mydef}
\label{def:jogo}
Considere um jogo no qual o jogador $J_1$ move primeiro e, a partir de então, ambos os jogadores alternam as jogadas.
Ao chegar em um nó terminal, tem-se uma função para atribuir um valor ao jogador $J_1$ naquela folha.
Essa sequência de movimento é chamado de \textbf{jogo}, e o valor na folha é chamado \textbf{resultado do jogo} \cite[p.~2]{algorithmsvelsky_1988}.
\end{mydef}

De acordo com a definição de um jogo (Definição \ref{def:jogo}), a versão reduzida do _Nim_ possui dezoito jogos no total, de forma que a quantidade de jogos pode ser calculado como $a b = 18$, com $a = 3$ e $b = 6$.
Alguns exemplos são mostrados a seguir:

\begin{align*}
\label{ex:jogossigmatau}
	\sigma_1 & \text{ e } \tau_1 \text{ resultam no jogo } A \rightarrow B \rightarrow D \rightarrow I \rightarrow N\text{,} \\
	\sigma_2 & \text{ e } \tau_1 \text{ resultam no jogo } A \rightarrow B \rightarrow D \rightarrow J \text{,} \\
	\sigma_3 & \text{ e } \tau_2 \text{ resultam no jogo } A \rightarrow C \rightarrow G \rightarrow M \text{.}
\end{align*}

Olhando para a tabela do jogador $J_2$ (Tabela \ref{tab:estrategia_pura_j2}), sua primeira jogada já depende da jogada do jogador $J_1$.
Por isso, cada estratégia $\tau_j$ com $j \in \{1,\cdots, b\}$ descreve duas possibiliades de movimento.
Observando $\tau_1$, no primeiro turno seu movimento será $(B,D)$ se estiver em $B$, caso contrário, jogará $(C,G)$.

\begin{mydef}
\label{def:forma_normal}
A \textbf{forma normal} é a representação do resultado do jogo a partir das escolhas de estratégia pura dos jogadores, onde, ciente das regras do jogo, cada jogador seleciona uma estratégia pura sem saber a escolha do outro.
\end{mydef}

Ao escolher suas estratégias pura, os jogadores percorrem a árvore até chegar a uma folha.
Essa sequência de movimentos (a escolha de uma estratégia pura $\sigma_i$ e uma $\tau_j$) é chamada de jogo.
Para cada combinação de estratégias de estratégias de $J_1$ e $J_2$, tem-se um jogo diferente.
Esses diferentes jogos são representados pela análise da forma normal (Definição \ref{def:forma_normal}) na Tabela \ref{tab:forma_normal}.

\begin{table}[htb]
	\centering
	\caption{Forma Normal para o jogo \emph{Nim}}
	\label{tab:forma_normal}
	\begin{tabular}{cccccccc}
		\toprule
															&				& \multicolumn{6}{c}{$\mathbf{J_2}$} \\
															&				& $\tau_1$ 	& $\tau_2$	& $\tau_3$	& $\tau_4$	& $\tau_5$	& $\tau_6$	\\
		\midrule
		\rowcolor{gray!20}									& $\sigma_1$	& $N$		& $O$		& $L$		& $N$		& $O$		& $L$		\\
												   			& $\sigma_2$	& $J$		& $O$		& $L$		& $J$		& $O$		& $L$		\\
		\rowcolor{gray!20}\multirow{-3}{*}{$\mathbf{J_1}$}	& $\sigma_3$	& $M$		& $M$		& $M$		& $H$		& $H$		& $H$		\\
		\bottomrule
	\end{tabular}
\end{table}

Nesta tabela, as estratégias dos jogadores estão nas linhas e colunas, e as letras representam as folhas, que são os resultados de caminhos tomados a partir de cada estratégia $\sigma_i$ e $\tau_j$.
Cada linha é uma estratégia pura de $J_1$ ($\sigma_i, i \in \{1, 2, 3\}$) e, cada coluna, uma estratégia de $J_2$ ($\tau_j, j \in \{1, 2, 3, 4, 5, 6\}$).
Para transformar esta tabela em uma matriz de _payoff_, basta substituir os nós terminais pelo ganho do jogo.
Se o primeiro jogador ganhar, seu ganho é $1$, e se o segundo jogador vencer, o resultado para $J_1$ é $-1$.


\begin{table}[htb]
	\centering
	\caption{Matriz de Ganho para o jogo \emph{Nim}}
	\label{tab:matriz_ganho}
	\begin{tabular}{cccccccc}
		\toprule
															&				& \multicolumn{6}{c}{$\mathbf{J_2}$} \\
															&				& $\tau_1$ 	& $\tau_2$	& $\tau_3$	& $\tau_4$	& $\tau_5$	& $\tau_6$	\\
		\midrule
		\rowcolor{gray!20}									& $\sigma_1$	& \texttt{ 1}	& \texttt{ 1}	& \texttt{-1}	& \texttt{ 1}	& \texttt{ 1}	& \texttt{-1} \\
												   			& $\sigma_2$	& \texttt{-1}	& \texttt{ 1}	& \texttt{-1}	& \texttt{-1}	& \texttt{ 1}	& \texttt{-1} \\
		\rowcolor{gray!20}\multirow{-3}{*}{$\mathbf{J_1}$}	& $\sigma_3$	& \texttt{-1}	& \texttt{-1}	& \texttt{-1}	& \texttt{ 1}	& \texttt{ 1}	& \texttt{ 1} \\
		\bottomrule
	\end{tabular}
\end{table}

Dessa forma, pode-se ver na Tabela \ref{tab:matriz_ganho} que a estratégia $\tau_4$ sempre garante a vitória para $J_2$ independente da estratégia do jogador $J_1$.

# Programação dinâmica

<!--
Dynamic programming typically applies to optimization problems in which we make a set of choices in order to arrive at an optimarl solutions.
As we make each choice, subproblems of the same form often arise.
Dynamic programming is effective when a given subproblem may arise from more than one partial set of choices; the key technique is to store the solution to each such subproblem in case it shoudl reapper.

Dynamic programming, like the divide-and-conquer method, solves problems by combining the solution to subproblems. Divide and conquer algorithms partition the the problem into disjoint subproblems, solve the subproblems recursively, and then combine their solutions to solve the original problem. In contrast, dynamic programming applies when the subproblems overlap - that is, when subproblems share subsubproblmes. In this contextm a divide-and-conquer algorithm does more work than necessary, repeatedly solving the common subsubproblems. A dynamic-programming algorithm solves each subsubproblem just once and then saves its answer in a table, thereby avoiding the work of recomputing the answer every time it solves each subsubproblem.

We typically apply dynamic programming to optimization problems.
Such problems can have many possible solutions.
Each solution has a value, and we wish to find a solution with the optimal (minimum or maximum) value.
We call such a solution an optimal solution to the problem, as opposed to the optimal solution. 
-->


Programação dinâmica é uma técnica de programação capaz de reduzir significantemente o tempo de processamento de um problema no qual os estados possam se repetir.
\cite{cormen2001introduction}
Um exemplo clássico é o programa de para calcular os números da sequência de _Fibonacci_.
No Código \ref{lst:fib_main}, \ref{lst:fib_ite}, \ref{lst:fib_rec} e \ref{lst:fib_mem} está escrito um programa simples para resolver este problema.

Take a problem, split in subproblems, solve the subproblems and reuse

\fibtree

Dependo da implementação do problema, o tempo de processamento para chegar no resultado desejado pode crescer exponencialmente.
Nos Códigos \ref{lst:fib_main}, \ref{lst:fib_ite}, \ref{lst:fib_rec} e \ref{lst:fib_mem}

\begin{lstlisting}[language=C++, label=lst:fib_main, caption=Funcao main de Fibonacci]
#include <iostream>	// std::cout
#include <map>		// std::map (PD)

// Protótipo (declaração) da função
int fibonacci(int);

int main()
{
	// Calcula e escreve o décimo quinto termo
    std::cout << fibonacci(15) << std::endl;

    return 0;
}
\end{lstlisting}

\begin{lstlisting}[language=C++, label=lst:fib_ite, caption=Fibonacci Iterativo]
int fibonacci(int n)
{
	// Declara e inicia a variável
    int fib_number = 0;

	// A sequência de fibonacci começa em: 1 e 1
    int a_0 = 1;
    int a_1 = 1;
    for (int i = 1; n > n; n++) {
		// a_n é igual a soma dos dois termos anteriores
        fib_number = a_0 + a_1;

		// Atualiza os termos
        a_0 = a_1;
        a_1 = fib_number;
    }

    return fib_number;
}
\end{lstlisting}


\begin{lstlisting}[language=C++, label=lst:fib_rec, caption=Fibonacci Recursivo]
int fibonacci(int n)
{
	// Declara e inicia a variável
	int fib_number = 0;

    if (n <= 2) {
		// Os dois primeiros termos são iguais a 1
		fib_number = 1;
	}	
	else {
		// Cada número em seguida são a soma dos dois anteriores
		fib_number = fibonacci(n-1) + fibonacci(n-2);
	}

	return fib_number;

}   
\end{lstlisting}


\begin{lstlisting}[language=C++, label=lst:fib_mem, caption=Fibonacci com Programação Dinâmica]
std::map<int,int> memoization;

int fibonacci(int n)
{
	// Verifica se a_n já foi calculado
    auto it = memoization.find(n);
    if (it != memoization.end()) {
		return memoization.at(n);
	}

	// Declara e inicia a variável
	int fib_number = 0;

    if (n <= 2) {
		// Os dois primeiros termos são iguais a 1
		fib_number = 1;
	}	
	else {
		// Cada número em seguida são a soma dos dois anteriores
		fib_number = fibonacci(n-1) + fibonacci(n-2);
	}
	
	// Armazena a_n para referências futuras
    memoization[n] = fib_number;

    return fib_number;
}
\end{lstlisting}

Os valores da sequência de \emph{Fibonacci} foram conferidos no site da enciclopédia online das sequências de números inteiros[^oeis].

[^oeis]: \emph{The Online Encyclopedia of Integers Sequences (OEIS)}, sequência A000045 no link https://oeis.org/A000045/a000045_3.txt

\begin{figure}[htb]
	\centering
	\includegraphics[width=\textwidth]{figuras/fib}
	\caption{Comparação entre implementações de \emph{Fibonacci}}
	\label{fig:fibonacci}
\end{figure}

Na Figura \ref{fig:fibonacci} fica claro que a implementação recursiva do algoritmo cresce exponencialmente de acordo com o número de cálculos a ser realizado.
Para tratar desse problema, a técnica de memorização armazena os valores da sequência de \emph{Fibonacci} em um \emph{map} e depois acessa seus valores ao invés de recalcular aquele $n$-ésimo termo.
Isso faz com que o tempo do cálculo se torne 

\section{\texorpdfstring{\emph{Big Points}}{}}\label{sec:big_points}

_Big Points_ é um jogo abstrato e estratégico com uma mecânica de colecionar peças que pode ser jogado de dois a cinco jogadores.
São cinco peões de cores distintas, que podem ser usadas por qualquer jogador, para percorrer um caminho de discos coloridos até chegar à escada.
Durante o percurso, os jogadores coletam alguns destes discos e sua pontuação final é determinada a partir da ordem de chegada dos peões ao pódio e a quantidade de discos adquiridos daquela cor.
Ganha o jogador com a maior pontuação.

O jogo é composto por cinco peões, como demonstrado na Figura, um de cada uma das seguintes cores, denominadas **cores comuns**: vermelha, verde, azul, amarela e roxo.
Para cada cor de peão, tem-se dez discos, como mostrado na Figura \ref{fig:content}, (totalizando cinquenta discos) denominados **discos comuns**, e cinco discos das cores branca e preta (totalizando dez discos) denominados **discos especiais**.

\begin{figure}[htb]
    \centering
   	\includegraphics[width=0.7\textwidth]{figuras/content}
   	\caption{Conteúdo do jogo \emph{Big Points}}
   	\label{fig:content}
\end{figure}

Por fim, há um pódio (ou escada) com um lugar para cada peão.
A escada determinará a pontuação equivalente a cada disco da cor do peão, de maneira que o peão que ocupar o espaço mais alto no pódio (o primeiro a subir) fará sua cor valer quatro pontos, o segundo peão, três pontos e assim por diante, até o último valer zero ponto.
No caso de um jogo com menos de cinco peões, a seguinte fórmula se aplica: $S = N_{c}-P_{pos}$, onde $S$ é a pontuação daquela determinada cor, $N_{c}$ é o número de discos comuns e $P_{pos}$ é a posição do peão no pódio.

\begin{figure}[htb]
    \centering
   	\includegraphics[width=0.7\textwidth]{figuras/setup}
   	\caption{Preparação do jogo \emph{Big Points}}
   	\label{fig:setup}
\end{figure}

A preparação do jogo ocorre em algumas etapas, envolvendo a posição dos peões, a aleatoriedade do tabuleiro e alguns discos ao lado da escada.
A primeira etapa é retirar um disco de cada cor comum e posicioná-los ao lado da escada: estes serão os discos coletados pelo jogador que levar o peão da sua cor para a escada.
Com isso, restará nove discos de cada uma das cinco cores comuns mais cinco discos de cada uma das duas cores especiais resultando em $(n_{dc}-1) \cdot n_{cc} + n_{de} \cdot n_{ce} = (10-1) \cdot 5 + 5 \cdot 2 = 55\ discos$, onde $n_{dc}$ é o número de discos comuns, $n_{cc}$ é o número de cores comuns, $n_{de}$ é o número de discos especiais, e $n_{ce}$ é o número de cores especiais.
Em seguida, deve-se embaralhar todos os 55 discos restantes e formar uma fila até a escada: estes são os discos possíveis de serem coletados e onde os peões andam até chegar na escada.
Por último, é preciso posicionar os peões no começo da fila de discos, de forma que fiquem opostos à escada.
No final da preparação, o jogo assumirá uma forma semelhante à apresentada na Figura \ref{fig:setup}.

Após preparar o jogo, deve-se escolher o primeiro jogador de forma aleatória.
Em sua vez, cada jogador deve escolher um peão, que não esteja na escada, para movê-lo até o disco à frente mais próximo de sua cor.
Caso não haja um disco de sua cor para movê-lo, o peão sobe na escada para a posição mais alta que não esteja ocupada e coleta o disco daquela cor que está ao lado da escada.
Em seguida, o jogador escolhe pegar o primeiro disco disponível[^available_disc] à frente ou atrás da nova posição do peão.
Caso o disco não esteja disponível, verifique o próximo disco até encontrar um que esteja disponível.
Ao encontrar um disco possa pegar, o jogador o retira do tabuleiro e o coloca em sua mão do jogador atual.
A sua vez termina e passa para o próximo escolher um peão e pegar um disco.
O jogo segue desta maneira até que todos os peões se encontrem na escada.
No final do jogo, conta-se os pontos e ganha o jogador que tiver a maior pontuação.

[^available_disc]: É dito disponível aquele disco presente no tabuleiro, e que não possui um peão em cima.

A pontuação do jogo é dependente da ordem de chegada dos peões na escada e da quantidade de discos de cada cor que o jogador tiver.
O primeiro peão que chegou na escada faz com que cada disco de sua cor valha quatro pontos.
Os jogadores devem então multiplicar a quantidade de discos daquela cor pelo valor da ordem de chegada do peão da sua cor na escada.

Exemplo: um jogador tem um disco da cor vermelha ($n_r$) , zero discos da cor verde ($n_g$), dois azuis ($n_b$), cinco amarelos ($n_y$), quatro roxos ($n_p$), dois brancos ($n_w$) e um preto ($n_k$).
A ordem de chegada dos peões são, respectivamente, vermelho ($p_r$), verde ($p_g$), azul ($p_b$), amarelo ($p_y$) e roxo ($p_p$).
Sua pontuação $S$ será descrita de acordo com a Equação \ref{eq:expontuacao}, onde $n_c$ é o número de cores distintas, com exceção da cor branca.

\begin{equation}
	\label{eq:expontuacao}
	%\tag{eq. Exemplo de pontuação}
	\begin{split}
		S &= n_r \cdot p_r + n_g \cdot p_g + n_b \cdot p_b + n_y \cdot p_y + n_p \cdot p_p + n_w \cdot n_c  \\
		S &= 1   \cdot 4   + 0   \cdot 3   + 2   \cdot 2   + 5   \cdot 1   + 4   \cdot 0   + 2   \cdot 5 \\
		S &= 23
	\end{split}
\end{equation}




















<!--
Capítulo 2 - Metodologia
-->
\chapter{Metodologia}
\label{ch:metodologia}

Após o entendimento dos conceitos de Teoria dos Jogos, Programação Dinâmica e das regras do jogo _Big Points_, serão explicados a metodologia seguida para a construção do projeto.
A primeira seção explica como foram as reuniões com o orientador e a organização das tarefas.
Na Seção \ref{anuxe1lise-do-jogo}, são feitas as análises da quantidade de jogos distintos e das jogadas para exaurir todas as possibilidades do jogo.
Em seguida, na Seção \ref{representauxe7uxe3o-e-codificauxe7uxe3o-dos-estados}, é explicado como os estados do jogo foram armazenados para ocupar o menor espaço possível.
Por último, a Seção \ref{implementauxe7uxe3o-da-programauxe7uxe3o-dinuxe2mica} trata sobre a implementação da programação dinâmica e a verificação e validação do programa.

# Fluxo de Trabalho

O _framework_ _Scrum_ é ideal para o desenvolvimento de projetos complexos no qual a produtividade e a criatividade são essenciais para a entrega de um produto de alto valor \cite{the_scrum_guide}.
Inicialmente, tal método de organização e gerenciamento do projeto foi aplicado para o desenvolvimento do sistema em questão.
O _kanban_ do \href{https://waffle.io/mfurquim/tcc}{\emph{waffle.io}}[^waffleio] foi utilizado para registrar tarefas devido à sua integração com as _issues_ do \emph{GitHub}[^github].
Reuniões com o orientador foram realizadas para discutir aspectos técnicos do jogo, como as estruturas de dados a serem utilizadas para reduzir os dados armazenados, e alguns métodos importantes para agilizar o processamento.

[^waffleio]:https://waffle.io/mfurquim/tcc
[^github]:https://github.com/mfurquim/tcc

Porém, ao longo do tempo, o esforço para manter a rastreabilidade das tarefas tornou-se muito alto em relação à complexidade do projeto, e ao tamanho da equipe.
As tarefas passaram a ser _branches_ locais com nomes significativos, representando a funcionalidade a ser desenvolvida.
Após a conclusão da tarefa, testes simples e manuais foram aplicados para então unir à _branch_ mestre[^git_merge].
Por fim, para trabalhar em outra _branch_, sempre foi necessário atualizá-la em relação à mestre[^git_rebase] para garantir a consistência do trabalho.

[^git_merge]: \texttt{\$ git checkout <to-branch>; git merge <from-branch>}
[^git_rebase]: \texttt{\$ git rebase <from-branch> <to-branch>}

# Análise do jogo \textit{Big Points}

Para analisar o jogo _Big Points_, foram rastreadas todas as jogadas de todos os jogos possíveis.
Em seguida, foi feita uma simulação onde cada jogador, na sua vez, escolheria uma jogada que lhe garantisse a vitória ou, se houver mais de uma possibilidade, escolhe a que resultasse em maior pontuação.
Caso não existisse uma jogada que levasse à vitória, o jogador deveria minimizar a pontuação de seu adversário.
Após fazer isso para um jogo escolhido, os resultados foram escritos em um arquivo _csv_[^csv] para análise.
Esse procedimento foi repetido para _cada_ combinação possível do tabuleiro inicial.

[^csv]: O tipo arquivo _csv_ (_comma separated value_) possui seu conteúdo separado por vírgula.

## Quantidade de partidas

Para estudar a viabilidade de solucionar o jogo, foi preciso calcular a quantidade de partidas distintas do jogo \emph{Big Points}.
A característica do jogo que muda de uma partida para outra são a quantidade de jogadores e o arranjo dos discos formando o tabuleiro.
Para a quantidade $P$ de jogadores, tem-se $J \in [2,5]$.
Agora, para a organização dos discos, faz-se uma combinação de cada cor, com a quantidade restante de discos.

\begin{equation}
	\label{eq:partidas}
	%\tag{eq. Quantidades de Partidas Distintas}
	\begin{split}
		P\ &=\  (J-1) \binom{d_t}{n_w} \binom{d_{l1}}{n_k} \binom{d_{l2}}{n_r} \binom{d_{l3}}{n_g} \binom{d_{l4}}{n_b} \binom{d_{l5}}{n_y} \binom{d_{l6}}{n_p}\\
		P\ &=\  4 \binom{55}{5} \binom{50}{5} \binom{45}{9} \binom{36}{9} \binom{27}{9} \binom{18}{9} \binom{9}{9}\\
		P\ &=\ 560.483.776.167.774.018.942.304.261.616.685.408.000.000\\
		P\ &\approx 5\times 10^{41}
	\end{split}
\end{equation}

Na Equação \ref{eq:partidas}, a quantidade de discos de uma determinada cor é indicado por $n$, então para a quantidade de discos da cor vermelha, verde, azul, amarela, roxa, branca, e preta são, respectivamente, $n_r$, $n_g$, $n_b$, $n_y$, $n_p$, $n_w$, e $n_k$.
Para encurtar o cálculo, foi utilizado variáveis auxiliares para indicar a quantidade total de discos $d_t$ e a quantidade restante dos discos após a combinação anterior ($d_{l1}$, $d_{l2}$, $d_{l3}$, $d_{l4}$, $d_{l5}$ e $d_{l6}$).

O valor total $d_t$ de peças é igual a $d_t = n_r + n_g + n_b + n_y + n_p + n_w + n_k$ que valem, como dito na Seção \ref{sec:big_points}, $n_w = n_k = 5$ para as cores especiais, e $n_r = n_g = n_b = n_y = n_p = 9$ para as cores comuns.
As outras variáveis restantes após as combinações são: $d_{l1} = d_t - d_w$, para a combinação dos discos totais com os discos brancos; $d_{l2} = d_{l1} - d_k$, para a combinação dos discos restantes da combinação passada com os discos pretos; e assim por diante.

## Quantidade de jogadas

O próximo passo é exaurir todas as possibilidades de jogadas.
Porém, o trabalho computacional é imenso e cresce exponencialmente de acordo com o tamanho do jogo.
Para um jogo pequeno, com apenas dois discos e duas cores comuns (sem especiais), as jogadas possíveis são: mover o peão vermelho e pegar o disco da direita, ou da esquerda; e mover o peão verde e pegar o disco da direita ou da esquerda.
Um jogo deste tamanho termina, em média, no quarto turno, como será mostrado na Sub-Seção \ref{verificauxe7uxe3o-dos-estados}.
Isso gera uma árvore onde cada nó possui quatro filhos (jogadas possíveis) e altura média de quatro (número de turnos), totalizando uma quantidade de estados de aproximadamente $\sum_{h=0}^{4}f^{h} \approx 341$, com $f = 4$.

Seguindo esta linha de raciocínio, um jogo completo (com 55 discos e todas as cores disponíeveis) teriam as possibilidades de jogada: mover os peões vermelho, verde, azul, amarelo, ou roxo; pegar o disco da direita ou da esquerda; e utiliziar, ou não, o disco preto para jogar novamente.
Com $5$ peões, $2$ opções para pegar os discos (esquerda ou direita) e a opção de usar ou não a peça preta, totaliza $5 \cdot 2 \cdot 2 = 20$ possibilidades de jogada.
Como o jogo possui 55 discos, pode-se estimar que o jogo irá terminar no quinquagésimo quinto turno, totalizando $\sum_{h=0}^{55} f^{h} \approx 3 \times 10^{71}$ estados possíveis[^num_jogadas].
 
[^num_jogadas]: $\sum_{h=0}^{55} f^{h} \approx 379250494936462821052631578947368421052631578947368421052631578947368421$.

# Representação e Codificação dos Estados

Para escrever a rotina de programação dinâmica capaz de otimizar o processamento recursivo, foi necessário identificar as variáveis do jogo que representam um **estado**. 
Um estado do jogo, como mostrado na Figura \ref{fig:estadouml}, depende dos discos do tabuleiro, dos peões que estão na escada, da mão dos jogadores, e do jogador atual (o jogador que fará a próxima jogada).

\begin{figure}[htb]
	\centering
	\includegraphics[width=0.8\textwidth]{figuras/estadouml}
	\caption{Diagrama UML da Classe \emph{State}}
	\label{fig:estadouml}
\end{figure}

Devido à enorme quantidade de estados do jogo _Big Points_, se fez necessário armazenar essas informações na menor quantidade de _bits_.
Para isso foi proposto uma função para codificar, e outra para decodificar, uma a classe em uma variável, como mostrado no Código \ref{lst:coddecod}, com o objetivo de reduzir o espaço ocupado na memória.
Após implementar e testar nos limites da capacidade da maior variável disponível (\texttt{unsigned long long int}), percebeu-se um erro quando o cálculo utilizava quatro cores e cinco discos, o que levou a outra solução: a implementação dos estados por _bit fields_, implementado no capítulo seguinte.

\begin{lstlisting}[language=C++, label=lst:coddecod, caption=Função de Codificação e Decodificação]
// Inicialização da classe
State state = new State();

// Protótipo das funções
unsigned long long int codificacao(State);
State decodificacao(unsigned long long int);
\end{lstlisting}

# Verificação dos estados

Para garantir a implementação correta da PD, foram escritos em \textit{post-it}s os estados, e suas transições, do menor jogo possível, como mostrado na Figura \ref{fig:}.

\begin{figure}[htb]
	\centering
	\includegraphics[width=0.8\textwidth]{figuras/board_state_tree0}
	\caption{Resultados ordenado por número de cores}
	\label{fig:board_state_tree0}
\end{figure}


\begin{figure}
    \centering
    \begin{subfigure}[b]{0.48\textwidth}
    	\includegraphics[width=\textwidth]{figuras/board_state_tree2}
    	\caption{Conteúdo do jogo \textbf{Big Points}}
    	\label{fig:content}
    \end{subfigure}
	\quad
    \begin{subfigure}[b]{0.48\textwidth}
    	\includegraphics[width=\textwidth]{figuras/board_state_tree3}
    	\caption{Preparação do jogo \textbf{Big Points}}
    	\label{fig:setup}
    \end{subfigure}
    \caption{Organização do jogo \textbf{Big Points}}\label{fig:organization}
\end{figure}
















<!--
Capítulo 3 - Resultados
-->
\chapter{Resultados}
\label{ch:resultados}

Após identificar quais características representam um estado no jogo, e qual a melhor abordagem para escrever o código, foi feito um cálculo para saber quanto de memória foi necessário para armazenar um estado do jogo. Neste capítulo, são relatados os passos necessários para implementar a PD do jogo e seus resultados.


# Implementação da Estrutura de Armazenamento



Dentro da estrutura \texttt{State} foram declaradas duas estruturas anônimas[^anonymous_struct] utilizando _bit fields_. As duas estruturas servem para garantir a utilização correta dos _bits_ quando as variáveis chegarem próximo ao limite da sua capacidade. Essas estruturas possuem variáveis do tipo \texttt{unsigned long long int}, que ocupa  64 _bits_. Após a declaração de um membro da estrutura, é declarado a quantidade de _bits_ que será utilizado para ele, de modo que \texttt{ll \_tabuleiro :20} ocupe apenas 20 _bits_ da variável \texttt{unsigned long long int}, \texttt{ll \_peao :15} ocupe 15 _bits_, e assim por diante de forma que não ultrapsse os 64 _bits_ da variável. Como o comportamento do armazenamento é indeterminado quando a variável é ultrapassada, e para garantir consistência no armazenamento, foram utilizadas duas _structs_ com, tamanho máximo igual uma variável \texttt{unsigned long long int} (64 _bits_).

[^anonymous_struct]: Estruturas anônimas permitem acesso às suas variáveis de forma direta, como por exemplo: \texttt{state.\_tabuleiro} acessa a variável \texttt{\_tabuleiro} dentro da estrutura anônima, que por sua vez se encontra dentro da estrutura \texttt{State}.

A estrutura \texttt{State} possui cinco membros:
\texttt{\_tabuleiro}, no qual pode armazenar informações sobre um tabuleiro até 20 discos[^tabuleiro];
\texttt{\_peao}, que representa a posição do peão $p_i \in \{0, 1,...,n_d, n_d+1\}$, onde $n_d$ é o número de discos de cores comuns no jogo e $p_i$ é o peão da cor $i$[^cor_peao];
\texttt{\_escada}, que indica as posições dos peões na escada, sendo a $p_i$_-ésima_ posição de \texttt{\_escada} é a posição do peao $p_i$;
\texttt{\_jogadores}, possui informações sobre os discos coletados dos dois jogadores;
e por fim, a variável \texttt{\_atual} que representa o jogador que fará a jogada.
Esta estrutura está apresentada no Código \ref{lst:estrutura_state}.

[^tabuleiro]: Cinco cores e quatro discos.
[^cor_peao]: As cores de peão seguem a ordem RGBYP começando do $0$, onde $\textbf{R}ed = 0$, $\textbf{G}reen = 1$, $\textbf{B}lue = 2$, $\textbf{Y}ellow = 3$, e $\textbf{P}urple = 4$.

# Projeto da Programação Dinâmica

Programação dinâmica é um método para a construção de algoritmos no qual há uma memorização de cada estado distinto para evitar recálculo, caso este estado apareça novamente. A memorização dos estados do jogo _Big Points_ foi feita em uma _hash_, com a chave sendo o estado do jogo e o valor armazenado, a pontuação máxima dos dois jogadores a partir daquele nó.

a melhor jogada para ganhar maximizar seus pontos. Caso não Na vez de cada
Caso a quantidade de jogos vencidos pelo primeiro jogador seja aproximadamente $50\%$

Para analizar o jogo, é preciso exaurir todas as jogadas possíveis a partir de um jogo inicial. Como

utilizando programação dinâmica[^dynamic_programing]
onde os estados são armazenados em uma _hash_, tem-se que o número de estados distintos varia entre 17 e 25.

Devido ao imenso número de jogadas possíveis ao longo do do jogo, decidiu-se utilizar a programação dinâmica para
- Duas funções para melhor entendimento da DP e regras do jogo

A função \texttt{dp} possui os casos base para retornar a função,

\lstinputlisting[language=C++, firstnumber=129, linerange={129-156}, caption=Programação Dinâmica]{../../pd/src/dp.cpp}


A função \texttt{play} foi implementada com o objetivo de separar a lógica do jogo da lógica da programação dinâmica.

\lstinputlisting[language=C++, firstnumber=13, linerange={13-127}, caption=Função Play]{../../pd/src/dp.cpp}

- Explicação da DP e da função Play (função para realizar as jogadas)

# Implementação do Minimax

\lstinputlisting[language=C++, firstnumber=158, linerange={158-228}, caption=Implementação do \emph{Minimax}]{../../pd/src/dp.cpp}
_long long int_, de forma que cada estado ocupasse apenas 64 _bits_ na memória.

Na figura \ref{fig:diagram_struct}

\diagramstruct

\lstinputlisting[language=C++, label=lst:estrutura_state, firstnumber=10, linerange={10-31}, caption=Definição da estrutura \texttt{State}]{../../pd/inc/state.h}

O cálculo para determinar os _bits_ necessários para armazenar as informações de cada variável foi realizado será explicado a seguir.

O cálculo de bits do atributo \texttt{tabuleiro} é apresentado na equação \ref{eq:bitstabuleiro}.

\begin{equation}
	\label{eq:bitstabuleiro}
	%\tag{eq. \emph{bits} de \_tabuleiro}
	\begin{split}
		\texttt{\_tabuleiro} &= n_c \cdot n_d\\
		\texttt{\_tabuleiro} &= 5 \cdot 4\\
		\texttt{\_tabuleiro} &= 20\ \emph{bits}
	\end{split}
\end{equation}

Na Equação \ref{eq:bitstabuleiro}, $n_c$ e $n_d$ são o número de cores e o número de discos do jogo, respectivamente. Seus valores são no máximo $n_c = 5$ e $n_d = 4$.

O cálculo de bits do atributo \texttt{peao} é apresentado na equação \ref{eq:bitspeao}.

\begin{equation}
	\label{eq:bitspeao}
	%\tag{eq. \emph{bits} de \_peao}
	\begin{split}
		\texttt{\_peao} &= \lceil \log_2(n_d+1) \rceil \cdot n_p\\
		\texttt{\_peao} &= \lceil \log_2(5 + 1)\rceil \cdot 4\\
		\texttt{\_peao} &= 3 \cdot 4\\
		\texttt{\_peao} &= 15\ \emph{bits}
	\end{split}
\end{equation}

Na Equação \ref{eq:bitspeao}, o valor de $n_d$ é o número de discos e $n_p$ é o número de peões do jogo, que por sua vez é igual a $n_c$ (número de cores comuns). Cada peão pode estar: fora do tabuleiro, com $peao(p_i) = 0$; em cima de um disco da sua cor, com $peao(p_i) \in \{1, 2,..., n_d\}$ ; e na escada, com $peao(p_i) = n_d+1$.

O cálculo de bits do atributo \texttt{escada} é apresentado na equação \ref{eq:bitsescada}.


\begin{equation}
	\label{eq:bitsescada}
	%\tag{eq. \emph{bits} de \_escada}
	\begin{split}
		\texttt{\_escada} &= \lceil \log_2(n_p+1) \rceil\cdot n_p\\
		\texttt{\_escada} &= \lceil \log_2(6) \rceil \cdot 5\\
		\texttt{\_escada} &= 15\ \emph{bits}
	\end{split}
\end{equation}

A Equação \ref{eq:bitsescada} possui as variáveis $n_p$ e $n_c$ com $n_p, n_c \in \{2, 3, 4, 5\}$ e $n_p = n_c$. Cada peão tem um local na escada, que armazena a posição dele de forma que $0 \leqslant escada(p_i) \leqslant n_c$. As situações possíveis são: $escada(p_i) = 0$ quando o peão não estiver na escada; e $escada(p_i) \in \{1, 2, 3, 4, 5\}$ sendo a ordem de chegada do peão na escada[^chegada_escada].

[^chegada_escada]: O primeiro peão $p_i$ a chegar na escada é indicado com $escada(p_i) = 1$.

O cálculo de bits do atributo \texttt{jogadores} é apresentado na equação \ref{eq:bitsjogadores}.


\begin{equation}
	%\tag{eq. \emph{bits} de \_jogadores}
	\begin{split}
		\texttt{\_jogadores} &= \lceil \log_2(n_d+1) \rceil \cdot n_c \cdot n_j\\
		\texttt{\_jogadores} &= \lceil \log_2(4+1) \rceil \cdot 5 \cdot 2\\
		\texttt{\_jogadores} &= 3 \cdot 5 \cdot 2\\
		\texttt{\_jogadores} &= 30\ \emph{bits}
	\end{split}
	\label{eq:bitsjogadores}
\end{equation}

A capacidade da variável \texttt{\_jogadores} é de 30 \emph{bits}, como demonstrado na equação \ref{eq:bitjogadores}. As variáveis utilizadas nessa equação são: $n_d$, o número de discos $n_d \in \{1, 2, 3, 4, 5\}$; $n_c$, o número de cores $n_c \in \{1, 2, 3, 4, 5\}$; e $n_j$, o número de jogadores $n_j = 2$. A informação armazenada na mão dos jogadores, para cada disco, vai até o número máximo de discos mais um, pois o jogador pode pegar todos os discos no tabuleiro e o disco adquirido ao mover o peão para a escada. Para armazenar o número seis, são necessários $\lceil \log_2(6) \rceil = 3 \emph{bits}$

O cálculo de bits do atributo \texttt{atual} é apresentado na equação \ref{eq:bitsatual}.

\begin{equation}
	\label{eq:bitsatual}
	%\tag{eq. \emph{bits} de \_atual}
	\begin{split}
		\texttt{\_atual} &= \lceil \log_2(2) \rceil\\
		\texttt{\_atual} &= 1\ \emph{bit}
	\end{split}
\end{equation}

# Funções de acesso da estrutura \texttt{State}

A estrutura possui um construtor que atribui valores às variáveis através de RAII[^RAII], dessa forma não se faz necessário nenhuma extra implementação. Todas as variáveis possuem um valor padrão, verdadeiro para qualquer tamanho de tabuleiro $t_i$, onde $4 \leqslant t_i \leqslant 20$.

\lstinputlisting[language=C++, firstnumber=33, linerange={33-39}, caption=Construtor da estrutura \texttt{State}]{../../pd/inc/state.h}

[^RAII]: _Resource Aquisition Is Initialization_ é uma técnica de programação que vincula o ciclo de vida do recurso ao da estrutura \cite{cppreferenceraii}.

cpp programing language criador do c++

Atributo \texttt{tabuleiro}
\lstinputlisting[language=C++, firstnumber=41, linerange={41-47}, caption=Funções de acesso ao atributo \texttt{tabuleiro}]{../../pd/inc/state.h}

Atributo \texttt{peao}
\lstinputlisting[language=C++, firstnumber=50, linerange={50-60}, caption=Funções de acesso ao atributo \texttt{peão}]{../../pd/inc/state.h}

Atributo \texttt{escada}
\lstinputlisting[language=C++, firstnumber=63, linerange={63-69}, caption=Funções de acesso ao atributo \texttt{escada}]{../../pd/inc/state.h}

Atributo \texttt{jogador}
\lstinputlisting[language=C++, firstnumber=72, linerange={72-83}, caption=Funções de acesso ao atributo \texttt{jogador}]{../../pd/inc/state.h}

Atributo \texttt{atual}
\lstinputlisting[language=C++, firstnumber=86, linerange={86-92}, caption=Funções de acesso ao atributo \texttt{atual}]{../../pd/inc/state.h}

# Comparador da estrutura \texttt{State}

\lstinputlisting[language=C++, firstnumber=95, linerange={95-102}, caption=Comparado da estrutura \texttt{State}]{../../pd/inc/state.h}


Ao final do cálculo deste jogo reduzido, temos que o número de estados distintos varia entre 17 e 25, dependendo do estado inicial do tabuleiro.
Devido a este grande número de estados repetidos, escrever o algoritmo fazendo uso de programação dinâmica economizou bastante tempo e processamento.

O jogo seria um jogo balanceado se ambos os jogadores ganharem aproximadamente metade das vezes.
Se existem seis jogos diferentes (combinação de duas cores com dois discos cada), o jogo é considerado balanceado se cada jogador ganhar três jogos.
Neste caso, temos os jogos $j_i \in \{1122, 1212, 1221, 2112, 2121, 2211\}$, e para cada $j_i$ temos a pontuação máxima e a quantidade de estados distintos, como demonstrado na tabela +@tbl:1.

\begin{table}[htb]
	\centering
	\caption{Pontuação utilizando \emph{minimax}}
	\label{tab:pont_minimax}
	\rowcolors{2}{white}{gray!20}
	\begin{tabular}{cccc}
		\toprule
		\textbf{Jogo}	& $\mathbf{J_1}$	& $\mathbf{J_2}$	&	\textbf{\#Estados}	\\
		\midrule
		1122			& 2					& 1					& 17					\\
		1212			& 2					& 0					& 25					\\
		1221			& 2					& 1					& 25					\\
		2112			& 2					& 1					& 25					\\
		2121			& 2					& 1					& 25					\\
		2211			& 2					& 0					& 17					\\
		\bottomrule
	\end{tabular}
\end{table}

Em todos as possíveis combinações de tabuleiros iniciais, o primeiro jogador sempre ganha com dois pontos enquanto o segundo jogador consegue fazer no máximo um ponto, na maioria das vezes. Isso torna o jogo desequilibrado.

\begin{figure}[htb]
	\centering
	\includegraphics[width=0.8\textwidth]{figuras/ordem_num_cores}
	\caption{Resultados ordenados por número de cores}
	\label{fig:bigpoints_cores}
\end{figure}

\begin{figure}[htb]
	\centering
	\includegraphics[width=0.8\textwidth]{figuras/ordem_num_discos}
	\caption{Resultados ordenados por número de discos}
	\label{fig:bigpoints_discos}
\end{figure}

\begin{figure}[htb]
	\centering
	\includegraphics[width=0.8\textwidth]{figuras/ordem_tamanho}
	\caption{Resultados ordenados por número total de peças}
	\label{fig:bigpoints_total}
\end{figure}




_long long int_, de forma que cada estado ocupasse apenas 64 _bits_ na memória.
















<!--
Capítulo 4 - Considerações Finais
-->
\chapter{Considerações Finais}
\label{ch:conclusao}

A análise utilizada para solucionar[^jogo_solucao] o jogo neste trabalho foi o teorema _minimax_, onde cada jogador tenta aumentar sua pontuação e diminuir a pontuação do oponente.
Os resultados obtidos ao final da análise computacional baseadas neste teorema sugere a possibilidade do jogo completo ser desbalanceado[^jogo_balanceado], dando ao primeiro jogador uma maior chance de vencer o jogo.

[^jogo_solucao]: Solucionar um jogo é percorrer todas as sua possibilidades de movimento e seus resultados.

[^jogo_balanceado]: É dito um jogo balanceado aquele que a chance dos jogadores de ganhar é a mesma.

# Trabalhos futuros

Desenvolvimento de uma I.A. para competir contra um jogador humano.
Análise mais complexa do jogo _Big Points_, utilizando processamento paralelo e distribuído.




