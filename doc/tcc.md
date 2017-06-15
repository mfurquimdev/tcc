<!--
Capítulo 1 - Introdução
-->
\chapter{Introdução}
\label{ch:introducao}

Imagine que um grupo de pessoas concordam em obedecer certas regras e agir de forma individual, ou em grupos menores, sem violar as regras especificadas.
No final, suas ações como um todo levará a uma certa situação chamada **resultado**.
Os membros deste grupo são chamados de **jogadores** e as regras que eles concordaram em obedecer constitui um **jogo**.
Estes conceitos são pequenos exemplos utilizados em análises baseadas na **teoria dos jogos**.

A proposta deste trabalho foi realizar uma destas análise em um jogo de tabuleiro chamado _Big Points_.
A motivação que levou à realização deste trabalho foi identificar uma heurística na qual tem-se uma maior chance de ganhar uma partida.
Dessa forma, seria possível a implementação de uma inteligência artificial (I.A.) com diferentes dificuldades para jogar contra uma pessoa.
Dito isso, o objetivo principal deste trabalho foi analisar várias partidas distintas de uma versão reduzida do jogo.

Uma análise possível para solucionar[^jogo_solucao] o jogo é utilizar o teorema _minimax_, onde cada jogador tenta aumentar sua pontuação e diminuir a pontuação do oponente.
Os resultados obtidos ao final dessa análise computacional baseadas no teorema _minimax_ sugere a possibilidade do jogo completo ser desbalanceado[^jogo_balanceado], dando ao primeiro jogador uma maior chance de vencer o jogo.

[^jogo_solucao]: Solucionar um jogo é percorrer todas as sua possibilidades de movimento e seus resultados.

[^jogo_balanceado]: É dito um jogo balanceado aquele que a chance dos jogadores de ganhar é a mesma.

A estrutura do trabalho foi dividida em cinco capítulos, sendo o primeiro esta introdução.
O capítulo seguinte (\ref{ch:fundamentacao_teorica}), Fundamentação Teórica, relata um pouco sobre a história da teoria dos jogos, esclarece alguns conceitos relevantes para o entendimento do trabalho, e explica as regras do próprio jogo.
Em seguida, tem-se o capítulo \ref{ch:metodologia}, referente à análise e ao desenvolvimento do projeto até sua conclusão, e no capítulo \ref{ch:resultados} os resultados desta análise são discutidos.
Por último, o capítulo \ref{ch:conclusao} onde são feitas as considerações finais do trabalho e são citados alguns possíveis trabalhos futuros em cima do trabalho atual.

<!--
Capítulo 2 - Fundamentação Teórica
-->
\chapter{Fundamentação Teórica}
\label{ch:fundamentacao_teorica}

Para um bom entendimento da análise realizada no jogo _Big Points_ é preciso ter um conhecimento básico sobre teoria dos jogos e programação dinâmica.
A primeira seção deste capítulo conta brevemente sobre a história da teoria dos jogos, com alguns nomes icônicos para esta área.
A seção \ref{teoria-dos-jogos} explica um pouco sobre os conceitos da teoria dos jogos, mas apenas o necessário para este trabalho.
Na seção \ref{programauxe7uxe3o-dinuxe2mica}, são explicados os conceitos sobre programação dinâmica e, na última seção (\ref{regras-do-big-points}), as regras do jogo \textit{Big Points} são explicadas.

# Histórico da Teoria dos Jogos

Pode-se dizer que a análise de jogos é praticada desde o séculco XVIII tendo como evidência uma carta escrita por James Waldegrave ao analisar uma versão curta de um jogo de baralho chamado \emph{le Her} \cite{Prague_severalmilestones}.
No século seguinte, o matemático e filósofo Augustin Cournot fez uso da teoria dos jogos para estudos relacionados à política \apud{cournot_1838}{sartini_IIbienaldasbm}.

Mais recentemente, em 1913, Ernst Zermelo publicou o primeiro teorema matemático da teoria dos jogos \apud{zermelo_1913}{sartini_IIbienaldasbm}.
Outros dois grandes matemáticos que se interessaram na teoria dos jogos foram Émile Borel e John von Neumann.
Nas décadas de 1920 e 1930, Emile Borel publicou três artigos sobre jogos estratégicos \apud{borel_1921}{Prague_severalmilestones} \apud{borel_1924}{Prague_severalmilestones} \apud{borel_1927}{Prague_severalmilestones}, introduzindo uma noção abstrada sobre jogo estratégico e estratégia mista.

Em 1928, John von Neumann provou o teorema _minimax_, no qual há sempre uma solução racional para um conflito bem definido entre dois indivíduos cujos interesses são completamente opostos \apud{neumann_1928}{alecsandra_2006}.
Em 1944, Neumann publicou um trabalho junto a Oscar Morgenstern introduzindo a teoria dos jogos na área da economia e matemática aplicada \apud{neumann_1944}{sartini_IIbienaldasbm}.
Além destas contribuições, John von Neumann ainda escreveu trabalhos com grande impacto na área da computação, incluindo a arquitetura de computadores, princípios de programação, e análise de algoritmos \cite{miyazawa_2010}.

Várias publicações contribuíram para o este marco histórico da teoria dos jogos, mas o livro de Thomas Schelling, publicado em 1960, se destacou em um ponto de vista social\apud{schelling1960strategy}{aguidetogametheory_2005}.
Em 1982, Elwyn Berlekamp, John Conway e Richard Guy publicaram um livro em dois volumes \apud{elwyn_1982}{eyawtkagtbwata_2003} que se tornou uma referência na área da teoria dos jogos combinatorial \cite{eyawtkagtbwata_2003} por explicar os conceitos fundamentais para a teoria dos jogos combinatorial. 

# Teoria dos Jogos

O campo da teoria dos jogos divide-se em três áreas:
1) Teoria Econômica dos Jogos (T.E.J.), que normalmente analisa movimentos simultâneos de dois ou mais jogadores;
2) Teoria Combinatória dos Jogos (T.C.J.), no qual os jogadores fazem movimentos alternadamente, e não faz uso de elementos de sorte, diferente da T.E.J. que também trata desse fenômeno; e
3) Teoria Computacional dos Jogos, que engloba jogos que são possíveis resolver por força bruta ou inteligência artificial, como jogo da velha e xadrez respectivamente.

É possível abstrair um jogo de várias maneiras para facilitar sua análise. Uma dessas maneiras é descrito na definição \ref{def:forma_extensiva}.

\begin{mydef}
\label{def:forma_extensiva}
A \textbf{forma extensiva} de um jogo elimina as informações de como jogá-lo e passa a ser representado pelos movimentos possíveis e como o estado do jogo é alterado \cite{jones_1980}.
Sua forma de representar o jogo é por uma árvore, onde os nós são os estados do jogo e as arestas são as possíveis maneiras de alterar aquele estado ou, em outras palavras, os movimentos permitidos a partir daquele estado.
\end{mydef}

Considere o jogo _Nim_ \cite{eyawtkagtbwata_2003}. De acordo com a definição \ref{def:forma_extensiva}, a árvore do jogo _Nim_ fica como mostrado na figura \label{fig:nim_tree}.
A árvore está representada apenas pela metade pois a outra metade dela é simétrica.



\begin{figure}[htb]
	\centering
	\begin{tikzpicture}
	[
		grow = down,
		edge from parent/.style = {draw, -latex},
		every node/.style = {font=\footnotesize},
		sloped,
		level 1/.style = {
			sibling distance = 5.3cm,
			level distance = 1.5cm
		},
		level 2/.style = {
			sibling distance = 2.4cm,
			level distance = 1.5cm
		},
		level 3/.style = {
			sibling distance = 1.5cm,
			level distance = 1.5cm
		},
		level 4/.style = {
			sibling distance = 1.5cm,
			level distance = 1.5cm
		}
	]
	\draw (-10,0) node {A};
	\draw [->][thick] (-9,0) -- (-8,0);
	\draw (-10,-1.5) node {B};
	\draw [->][thick] (-9,-1.5) -- (-8,-1.5);
	\draw (-10,-3) node {A};
	\draw [->][thick] (-9,-3) -- (-8,-3);
	\draw (-10,-4.5) node {B};
	\draw [->][thick] (-9,-4.5) -- (-8,-4.5);
	\draw (-10,-6) node {A};
	\draw [->][thick] (-9,-6) -- (-8,-6);
	\node (1) { 1 
		\begin{tikzpicture} {
			\draw (0,0) rectangle (1,0.7);
			\draw
			(0.15,0.15) -- (0.15,0.55)
			(0.3 ,0.15) -- (0.3 ,0.55)
			(0.7 ,0.15) -- (0.7 ,0.55)
			(0.85,0.15) -- (0.85,0.55);
		} \end{tikzpicture}
	}
	child {
		node (2) { 2
			\begin{tikzpicture} {
				\draw (0,0) rectangle (1,0.7);
				\draw
				(0.3 ,0.15) -- (0.3 ,0.55)
				(0.7 ,0.15) -- (0.7 ,0.55)
				(0.85,0.15) -- (0.85,0.55);
			} \end{tikzpicture}} {
			child {
				node (4) { 4
					\begin{tikzpicture} {
						\draw (0,0) rectangle (1,0.7);
						\draw
						(0.15,0.35) -- (0.4 ,0.35)
						(0.7 ,0.15) -- (0.7 ,0.55)
						(0.85,0.15) -- (0.85,0.55);
					} \end{tikzpicture}}
				child {
					node (9) { 9
					\begin{tikzpicture} {
						\draw (0,0) rectangle (1,0.7);
						\draw
						(0.15,0.35) -- (0.4,0.35)
						(0.7 ,0.15) -- (0.7,0.55);
					} \end{tikzpicture}
					} 
					child {
						node (14) { 14
							\begin{tikzpicture} {
								\draw (0,0) rectangle (1,0.7);
								\draw
								(0.15,0.35) -- (0.4 ,0.35)
								(0.6 ,0.35) -- (0.85,0.35);
							} \end{tikzpicture}
						}
					}
				}
				child {
					node (10) { 10
						\begin{tikzpicture} {
							\draw (0,0) rectangle (1,0.7);
							\draw
							(0.15,0.35) -- (0.4 ,0.35)
							(0.6 ,0.35) -- (0.85,0.35);
						} \end{tikzpicture}
					}
				}
			}
			child {
				node (5) { 5
					\begin{tikzpicture} {
						\draw (0,0) rectangle (1,0.7);
						\draw
						(0.3,0.15) -- (0.3,0.55)
						(0.7,0.15) -- (0.7,0.55);
					} \end{tikzpicture}
				} 
				child {
					node (11) { 11
						\begin{tikzpicture} {
							\draw (0,0) rectangle (1,0.7);
							\draw
							(0.3 ,0.15) -- (0.3 ,0.55)
							(0.6 ,0.35) -- (0.85,0.35);
						} \end{tikzpicture}
					} 
					child {
						node (15) { 15
							\begin{tikzpicture} {
								\draw (0,0) rectangle (1,0.7);
								\draw
								(0.15,0.35) -- (0.4 ,0.35)
								(0.6 ,0.35) -- (0.85,0.35);
							} \end{tikzpicture}
						} 
					}
				}
			}
			child {
				node (6) { 6
					\begin{tikzpicture} {
						\draw (0,0) rectangle (1,0.7);
						\draw
						(0.3 ,0.15) -- (0.3 ,0.55)
						(0.6 ,0.35) -- (0.85,0.35);
					} \end{tikzpicture}
				} 
				child {
					node (12) { 12
						\begin{tikzpicture} {
							\draw (0,0) rectangle (1,0.7);
							\draw
							(0.15,0.35) -- (0.4 ,0.35)
							(0.6 ,0.35) -- (0.85,0.35);
						} \end{tikzpicture}
					} 
				}
			}
		}
	}
	child {
		node (3) { 3
			\begin{tikzpicture} {
				\draw (0,0) rectangle (1,0.7);
				\draw
				(0.15,0.35) -- (0.4 ,0.35)
				(0.7 ,0.15) -- (0.7 ,0.55)
				(0.85,0.15) -- (0.85,0.55);
			} \end{tikzpicture}
		} { 
			child {
				node (7) { 7
					\begin{tikzpicture} {
						\draw (0,0) rectangle (1,0.7);
						\draw
						(0.15,0.35) -- (0.4 ,0.35)
						(0.7 ,0.15) -- (0.7 ,0.55);
					} \end{tikzpicture}
				} 
				child {
					node (13) { 13
						\begin{tikzpicture} {
							\draw (0,0) rectangle (1,0.7);
							\draw
							(0.15,0.35) -- (0.4 ,0.35)
							(0.6 ,0.35) -- (0.85,0.35);
						} \end{tikzpicture}
					} 
				}
			}
			child {
				node (8) { 8
					\begin{tikzpicture} {
						\draw (0,0) rectangle (1,0.7);
						\draw 
						(0.15,0.35) -- (0.4 ,0.35)
						(0.6 ,0.35) -- (0.85,0.35);
					} \end{tikzpicture}
				}
			}
		}
	};
	\draw ($(14.south west)+(-1,-0.6)$) node {Vencedor:};
	\draw ($(14.south west)+(1.1,-0.6)$) node {A};
	\draw ($(14.south west)+(2.6,-0.6)$) node {B};
	\draw ($(14.south west)+(4.3,-0.6)$) node {A};
	\draw ($(14.south west)+(6.6,-0.6)$) node {B};
	\draw ($(14.south west)+(8.4,-0.6)$) node {B};
	\draw ($(14.south west)+(10.6,-0.6)$) node {A};
	\end{tikzpicture}
	\caption{Árvore do jogo Renée v Peter}
	\label{fig:nim_tree}
\end{figure}

\begin{mydef}
\label{def:algo}
Em jogos com \textbf{movimentos simultâneos}, os jogadores devem escolher o que fazer ao mesmo tempo ou, o que leva à mesma situação, as escolhas de cada jogador é escondida de seu oponente. Em qualquer um dos dois casos, o jogador deve escolher sua jogada levando em consideração a possível jogada do outro \cite{aguidetogametheory_2005}.
\end{mydef}

\begin{mydef}
Jogos de \textbf{soma zero} são jogos de puro conflito, no qual apenas um jogador pode vencer o jogo. Em outras palavras, a vitória de um jogador implica na derrota do outro.
\end{mydef}

## Minimax

O teorema minimax provado por John von Neumann é a peça principal da maior parte do trabalho matemático em economia e em atividades onde os atos das decisões são racionais.

Segundo o teorema minimax, há sempre uma solução racional para um conflito entre dois indivíduos cujos interesses são completamente opostos, ou seja, o que é ganho por um lado é perdido pelo outro. Esse é um exemplo da chamada situação soma zero, uma vez que os ganhos dos dois jogadores somam zero.

A combinação de estratégias, na qual o máximo dos mínimos é igual ao mínimo dos máximos, chama-se de ponto de equilíbrio do jogo, pois ao escolherem essas estratégias, os jogadores garantem para si um ganho mínimo independente do que o adversário venha a escolher.

Trabalhando com estratégias puras, utilizamos o critério maximin para definir os valores máximo e mínimo do jogo.

Em um jogo de dois jogadores com soma zero é racional para cada jogador escolher a estratégia que maximiza seu ganho mínimo ou que minimize o ganho máximo do adversário, conforme figura 1.

Agora, considerando o uso de estratégias mistas, ou seja, aumentando as possibilidades de escolha, podemos usar o mesmo critério para definir os novos valores máximo e mínimo.

Por exemplo, dois jogadores, na disputa por par ou ímpar, cada um com duas alternativas de escolha. O ganho será representado por 1 e perda por -1. O jogador par obterá ganho se ambos fizerem a mesma escolha, e neste cas ípar 








A área de teoria combinatória dos jogos analisa os jogos de uma perspectiva um pouco diferente. É considerado que dois jogadores alternam os movimentos em um jogo que não possui elementos de chance (rolagem de dados, saque de cartas, etc.) e que ambos jogadores possuem informação completa. É dito que os jogadores possuem informação completa se eles tiverem conhecimento de tudo o que está acontecendo no jogo a todo momento \cite{eyawtkagtbwata_2013}. Ao chegar na vez de algum jogador e ele não tiver nenhum movimento válido para realizar, então aquele jogador é considerado perdedor. Considerando os jogadores _esquerda_ e _direita_, podemos representar suas jogadas da maneira descrita em \ref{eq:tjc_representacao_jogadas}, onde o jogador _esquerda_ possui as jogadas $\{a,b,c,\ldots\}$ e o jogador _direita_, as jogadas $\{f,g,h,\ldots\}$.

\begin{equation}
	\label{eq:tjc_representacao_jogadas}
	%\tag{eq. T.C.J. Representação das Jogadas}
	\begin{split}
		\{a,b,c,\ldots \vert f,g,h,\ldots\}
	\end{split}
\end{equation}



A Teoria dos Jogos pode ser definida como a teoria dos modelos matemáticos que estuda a escolha de decisões ótimas[^optimal_decision] sob condições de conflito[^conflict_condition].
Os elementos básicos de um jogo são o conjunto de **jogadores**, onde cada jogador possui um conjunto de **estratégias** e, a partir das escolhas de estratégias de cada jogador, temos uma **situação** ou **perfil**.
Para cada perfil do jogo, tem-se um resultado no final do jogo.
Em termos matemáticos é dito que um jogador tem uma **função utilidade**, que atribui um **_payoff_**, ou **ganho**, para cada situação do jogo.

Quando essa informação é inserida em uma matriz, tem-se uma **matriz de _payoff_**.
Em outras palavras, matriz de ganho é a representação matricial dos _payoffs_ dos jogadores, onde as estratégia de um jogador estão representadas por cada linha e as de seu oponente estão representadas pelas colunas como mostra a tabela +@tbl:21.
Além disso o ganho dos jogadores é representado como uma tupla (ou par) de valores, sendo que o primeiro é o ganho do primeiro jogador e o segundo valor, o do segundo jogador. 

[^optimal_decision]: É considerado que os jogadores são seres racionais e que possuem conhecimento completo das regras do jogo. Às vezes o jogador também possui informação completa sobre o estado atual e do histórico de jogadas do jogo.

[^conflict_condition]: Condições de conflito são aquelas no qual dois ou mais jogadores possuem o mesmo objetivo.

  $P_2$ \\ $P_1$ | $E_{11}$ | $E_{12}$
:---------------:|:--------:|:--------:
     $E_{21}$    |  (1,0)   |  (2,3)
     $E_{22}$    |  (3,4)   |  (0,2)

Table: Matriz de ganho. {#tbl:21}

Dessa forma, o primeiro jogador, que é representado por $P_1$, possui as estratégias $E_{11}$ e $E_{12}$.
Semelhante ao primeiro jogador, tem-se o segundo jogador sendo representado por $P_2$ e com as estratégias $E_{21}$ e $E_{22}$.
Os valores que se encontram na interseção da estratégia de $P_1$ e $P_2$ são os ganhos dos dois jogadores, dessa forma se as estratégias escolhidas forem $E_{12}$ e $E_{21}$, o primeiro jogador teria perdido com $3$ pontos e o segundo jogador venceria com $4$ pontos.

De uma forma matemática mais genérica, tem-se o jogador $i \in \{1,2\}$ onde sua estratégia é representada por $\sigma_i \forall \sigma \in S_i$. 

[^mixed_strategy]: Estratégia mista é um conjunto de estratégias puras associadas a uma distribuição de probabilidade \cite{figueiredo_conceitos}.

[^finite_game]: Jogos finitos são aqueles onde cada participante se depara com um conjunto finito de escolhas, ou seja, eles escolhem suas estratégias dentro de um conjunto finito de alternativas \cite{figueiredo_conceitos}.

[^zero_sum]: Um jogo soma zero é um jogo no qual a vitória de um jogador implica na derrota do outro.


## Minimax

Como o jogo não possui nenhum elemento dependente da sorte, não serão usados estratégias mistas. O \textit{winning move} não foi analizado devido à complexidade da implementação da análise atual.

e as estratégias $\sigma$ e $\tau$ para o primeiro e segundo jogador, respectivamente.
para cada jogador, as estratégias $e \in \{1,2,\cdots,n\}$.
Com isso, cada estratégia pode ser representada por $E_{je}$.
Para determinar a pontuação dos jogadores, temos uma função ultilidade $u(E_{1e},E_{2e})$ tal que retorne uma tupla $(a,b)$ onde $a$ representa o ganho do jogador $1$ e $b$ representa o ganho do jogador $2$.

## Soluções de um jogo

Uma solução de um jogo é uma prescrição ou previsão sobre o resultado do jogo. Dois métodos importantes para encontrar a solução de um estado do jogo são **dominância** e **equilíbrio de Nash**.

É dito que uma determinada estratégia é uma **estratégia dominante** quando esta é a única estratégia restante após aplicar a técnica de **dominância estrita iterada**.
O encontro das estratégias dos jogadores é chamado de **equilíbrio de estratégia dominante**.

**Dominância estrita iterada** nada mais é do que um processo onde se eliminam as estratégias que são estritamente dominadas.
Obs.: faltou explicar o que é uma estratégia dominada.

**Solução estratégica** ou **Equilíbrio de Nash** é um conjunto de estratégias para cada jogador onde cada um deles não tem incentivo de mudar sua estratégia se os demais jogadores não o fizerem.

**Zero-sum game**: a vitória de um jogador implica na derrota do outro.
No Big Points, o jogador com maior pontuação vence. Pode-se dar pontuação 1 caso o jogador em questão é o vencedor, e -1 para o jogador que perdeu. Caso haja mais de um jogador com a maior pontuação do jogo, é dado 0 para o payoff dos dois jogadores.

Outra maneira, mais refinada, de demonstrar a vitória e derrota entre os jogadores é calcular a difereça da pontuação entre eles. O jogador com a maior pontuação mantém sua pontuação, e o restante tem sua pontuação subtraída daquela maior pontuação do jogo (dando um resultado negativo).

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



Teoria dos jogos é o estudo do comportamento estratégico interdependente[^interdependent_strategy], não apenas o estudo de como vencer ou perder em um jogo, apesar de às vezes esses dois fatos coincidirem. Isso faz com que o escopo seja mais abranjente, desde comportamentos no qual as duas pessoas devem cooperar para ganhar, ou as duas tentam se ajudar para ganharem independente ou, por fim, comportamento de duas pessoas que tentam vencer individualmente \cite{spaniel_2011}.

[^interdependent_strategy]: Estratégia interdependente significa que as ações de uma pessoa interfere no resultado da outra, e vice-versa.

# Programação dinâmica

MIMIMIPROGRAM A SODIAMSDOUAHSDOIUG ADIFHGSDKJFHGSD FJGSkfdjgHSDfas
asdasd


# Regras do Big Points

_Big Points_ é um jogo abstrato e estratégico com uma mecânica de colecionar peças que pode ser jogado de dois a cinco jogadores. São cinco peões de cores distintas, que podem ser usadas por qualquer jogador, para percorrer um caminho de discos coloridos até chegar à escada. Durante o percurso, os jogadores coletam alguns destes discos e sua pontuação final é determinada a partir da ordem de chegada dos peões ao pódio e a quantidade de discos adquiridos daquela cor. Ganha o jogador com a maior pontuação.

\begin{figure}[htb]
	\centering
	\includegraphics[width=0.75\textwidth]{figuras/front}
	\caption{Caixa do jogo \textbf{Big Points}}
	\label{fig:front}
\end{figure}

O jogo é composto por cinco peões, como demonstrado na figura \ref{fig:front}, um de cada uma das seguintes cores, denominadas **cores comuns**: vermelha, verde, azul, amarela e violeta. Para cada cor de peão, tem-se dez discos, como mostrado na figura \ref{fig:content}, (totalizando cinquenta discos) denominados **discos comuns**, e cinco discos das cores branca e preta (totalizando dez discos) denominados **discos especiais**. Por fim, há um pódio (ou escada) com um lugar para cada peão. A escada determinará a pontuação equivalente a cada disco da cor do peão, de maneira que o peão que ocupar o espaço mais alto no pódio (o primeiro a subir) fará sua cor valer quatro[^pawn_score], o segundo peão, três pontos e assim por diante, até o último valer zero pontos.

[^pawn_score]: No caso de um jogo com menos de cinco peões, a seguinte fórmula se aplica: $Score = N_{c}-P_{pos}$, onde $Score$ é a pontuação daquela determinada cor, $N_{c}$ é o número de discos comuns e $P_{pos}$ é a posição do peão no pódio.

\begin{figure}
    \centering
    \begin{subfigure}[b]{0.48\textwidth}
    	\includegraphics[width=\textwidth]{figuras/content}
    	\caption{Conteúdo do jogo \textbf{Big Points}}
    	\label{fig:content}
    \end{subfigure}
    \begin{subfigure}[b]{0.48\textwidth}
    	\includegraphics[width=\textwidth]{figuras/setup}
    	\caption{Preparação do jogo \textbf{Big Points}}
    	\label{fig:setup}
    \end{subfigure}
    \caption{Organização do jogo \textbf{Big Points}}\label{fig:organization}
\end{figure}

No final da preparação, o jogo ficará parecido com as peças na figura \ref{fig:setup}. A preparação do jogo ocorre em algumas etapas envolvendo a posição dos peões, a aleatoriedade do tabuleiro e alguns discos ao lado da escada. A primeira coisa é retirar um disco de cada cor comum e posicioná-los ao lado da escada, estes serão os discos coletados pelo jogador que subir o peão da sua cor para a escada. Em seguida, deve-se embaralhar todos os 55 discos restantes[^discs_left] e formar uma fila até a escada, estes são os discos possíveis de serem coletados e onde os peões andam até chegar na escada. Por último, é preciso posicionar os peões no começo da fila de discos, de forma que fique oposto à escada.

[^discs_left]: 9 discos de cada uma das 5 cores comuns mais 5 discos de cada uma das 2 cores especiais resultando em $(n_{dc}-1) \cdot n_{cc} + n_{de} \cdot n_{ce} = (10-1) \cdot 5 + 5 \cdot 2 = 55\ discos$, onde $n_{dc}$ é o número de discos comuns, $n_{cc}$ é o número de cores comuns, $n_{de}$ é o número de discos especiais, e $n_{ce}$ é o número de cores especiais.

Após preparar o jogo, deve-se escolher o primeiro jogador de forma aleatória. Na sua vez, cada jogador deve escolher um peão, que não esteja na escada, para movê-lo até o disco à frente mais próximo de sua cor. Caso não haja um disco de sua cor para movê-lo, o peão sobe na escada para a posição mais alta que não esteja ocupada e coleta o disco daquela cor que está ao lado da escada. Em seguida, o jogador escolhe para pegar o primeiro disco disponível[^available_disc] à frente ou atrás da nova posição do peão. Caso o disco não esteja disponível, verifique o próximo disco até encontrar um que esteja disponível. Ao encontrar um disco que o jogador possa pegar, retire-o do tabuleiro e coloque-o na mão do jogador atual. A sua vez termina e passa para o próximo escolher um peão e pegar um disco. O jogo segue desta maneira até que todos os peões se encontrem na escada. No final do jogo, conta-se os pontos e ganha o jogador que tiver a maior pontuação.

[^available_disc]: É dito disponível aquele disco presente no tabuleiro que não possui um peão em cima.

A pontuação do jogo é dependente da ordem de chegada dos peões na escada e da quantidade de discos de cada cor que o jogador tiver. O primeiro peão que chegou na escada faz com que cada disco de sua cor valha quatro pontos. Os jogadores devem então multiplicar a quantidade de discos daquela cor pelo valor da ordem de chegada do peão da sua cor na escada. Exemplo: se o primeiro jogador tiver dois discos vermelhos, um disco verde e três azuis e a ordem de chegada deles for azul em primeiro lugar, verde logo em seguida e depois o vermelho, sua pontuação será descrita de acordo com a equação \label{eq:expontuacao}, onde $n_c$ é o número de cores do jogo, $n_r$, $n_g$ e $n_b$ são as quantidades de discos vermelhos, verdes e azuis, respectivamente, que o jogador possui e $p_r$, $p_g$ e $p_b$ são as posições dos peões vermelho, verde e azul, respectivamente, na escada.

\begin{equation}
	\label{eq:expontuacao}
	%\tag{eq. Exemplo de pontuação}
	\begin{split}
		P &= n_r \cdot (n_c - p_r) + n_g \cdot (n_c - p_g) + n_b \cdot (n_c - p_b)\\
		P &= 2 \cdot (3 - 3) + 1 \cdot (3 - 2) + 3 \cdot (3 - 1)\\
		P &= 7
	\end{split}
\end{equation}


<!--
Capítulo 3 - Metodologia
-->
\chapter{Metodologia}
\label{ch:metodologia}

# \textit{Fluxo de Trabalho}

O _framework_ _scrum_ é ideal para o desenvolvimento de projetos complexos no qual a produtividade e a criatividade são essenciais para a entrega de um produto de alto valor \cite{the_scrum_guide}.
Inicialmente, tal método de organização e gerenciamento do projeto foi aplicado para o desenvolvimento do sistema em questão.
O _kanban_ do \href{https://waffle.io/mfurquim/tcc}{waffle.io}[^waffleio] foi utilizado para registrar tarefas devido à sua integração com as _issues_ do github.
Reuniões com o orientador foram realizadas para discutir aspectos técnicos do jogo, como as estruturas de dados a serem utilizadas para reduzir os dados armazenados, e alguns métodos importantes para agilizar o processamento.

[^waffleio]:https://waffle.io/mfurquim/tcc

Porém, ao longo do tempo, o esforço para manter a rastreabilidade das tarefas tornou-se muito alto em relação à complexidade do projeto, e ao tamanho da equipe. As tarefas passaram a ser _branchs_ locais com nomes significativos, representando a funcionalidade a ser desenvolvida. Após a conclusão da tarefa, testes simples e manuais foram aplicados para então unir à _branch_ mestre[^git_merge]. Por fim, para trabalhar em outra _branch_, foi sempre necessário atualizá-la em relação à mestre[^git_rebase].

[^git_merge]: \texttt{\$ git checkout <to-branch>; git merge <from-branch>}
[^git_rebase]: \texttt{\$ git rebase <from-branch> <to-branch>}

# Análise do jogo \textit{Big Points}

Para analizar o jogo _Big Points_, é preciso realizar todas as jogadas de todos os jogos possíveis. Cada jogador, na sua vez, deve escolher uma jogada na qual lhe garanta a vitória, se houver mais de uma, escolha a que tiver a maior pontuação. Caso não tenha uma jogada para vencer, o jogador deve minimizar a pontuação do adversário. Após fazer isso para um jogo inicial, os resultados são escritos em um arquivo _csv_ para análise. Esse procedimento é repetido para _cada_ organização possível do tabuleiro inicial.

Exaurir todas as possibilidades de jogadas é um trabalho computacional imenso e cresce exponencialmente de acordo com o tamanho do jogo. Para um jogo pequeno com apenas dois discos e duas cores comuns (sem especiais) as jogadas possíveis são: mover o peão vermelho e pegar o disco da direita, ou da esquerda; e mover o peão verde e pegar o disco da direita ou da esquerda. Isso gera uma árvore onde cada nó possui quatro filhos e a altura média dessa árvore é quatro, totalizando uma quantidade de estados de aproximadamente $\sum_{h=0}^{4}4^{h} \approx 341$. Ao final do cálculo deste jogo reduzido, temos que o número de estados distintos varia entre 17 e 25, dependendo do estado inicial do tabuleiro. Devido a este grande número de estados repetidos, escrever o algoritmo fazendo uso de programação dinâmica economizou bastante tempo e processamento.

O jogo seria um jogo balanceado se ambos os jogadores ganharem aproximadamente metade das vezes. Se existem seis jogos diferentes (combinação de duas cores com dois discos cada), o jogo é considerado balanceado se cada jogador ganhar três jogos. Neste caso, temos os jogos $j_i \in \{1122, 1212, 1221, 2112, 2121, 2211\}$, e para cada $j_i$ temos a pontuação máxima e a quantidade de estados distintos, como demonstrado na tabela +@tbl:1.

 **Jogo** | **Pontuação** | **#Estados**
:--------:|:-------------:|:------------:
  1122    |     (2,1)     |      17
  1212    |     (2,0)     |      25
  1221    |     (2,1)     |      25
  2112    |     (2,1)     |      25
  2121    |     (2,1)     |      25
  2211    |     (2,0)     |      17

Table: Pontuação utilizando Minimax. {#tbl:1}

Em todos as possíveis combinações de tabuleiros iniciais, o primeiro jogador sempre ganha com dois pontos enquanto o segundo jogador consegue fazer no máximo um ponto, na maioria das vezes. Isso torna o jogo desequilibrado.

## Quantidade de partidas

\begin{equation}
	\label{eq:partidas}
	%\tag{eq. Quantidades de Partidas Distintas}
	\begin{split}
		Partidas\ &=\  (\#J-1) \cdot \binom{\#D_T}{\#D_W} \cdot \binom{\#D_{L1}}{\#D_K} \cdot \binom{\#D_{L2}}{\#D_R} \cdot \binom{\#D_{L3}}{\#D_G} \cdot \binom{\#D_{L4}}{\#D_B} \cdot \binom{\#D_{L5}}{\#D_Y} \cdot \binom{\#D_{L6}}{\#D_V}\\
		Partidas\ &=\  4\cdot \binom{55}{5} \cdot \binom{50}{5} \cdot \binom{45}{9} \cdot \binom{36}{9} \cdot \binom{27}{9} \cdot \binom{18}{9} \cdot \binom{9}{9}\\
		Partidas\ &=\ 560'483'776'167'774'018'942'304'261'616'685'408'000'000\\
		Partidas\ &\approx 5\times 10^{41}
	\end{split}
\end{equation}

# Estrutura de dados

Devido à enorme quantidade de estados de um jogo reduzido de _Big Points_, foi implementado duas funções para codificar e decodificar a _struct State_ para um _long long int_, de forme que ocupe apenas 64 _bits_ na memória. Após testar nos limites da capacidade da variável, percebeu-se um erro quando executado com quatro cores e cinco discos, o que levou à implementação por _bit fields_.

## Estado do jogo

Para escrever a programação dinâmica capaz de

## Bit fields

Dentro da estrutura \texttt{State} foi declarado duas estruturas anônimas[^anonymous_struct] utilizando _bit fields_. As duas estruturas servem para garantir a utilização correta dos _bits_ quando as variáveis chegarem próximo ao limite da sua capacidade. Essas estruturas possuem variáveis do tipo \texttt{unsigned long long int}, que ocupa  64 _bits_. Após a declaração da variável, é declarado a quantidade de _bits_ que será utilizado para ela, de modo que \texttt{ll \_tabuleiro :20} ocupe apenas 20 _bits_ da variável \texttt{unsigned long long int}, \texttt{ll \_peao :15} ocupe 15 _bits_, e assim por diante de forma que não ultrapsse os 64 _bits_ da variável. Como o comportamento do armazenamento é desconhecido quando a variável é ultrapassada, e para garantir consistência no armazenamento, foi utilizado duas _structs_ com, no máximo, uma variável \texttt{unsigned long long int} (64 _bits_).

[^anonymous_struct]: Estruturas anônimas permitem acesso às suas variáveis de forma direta, como por exemplo: \texttt{state.\_tabuleiro} acessa a variável \texttt{\_tabuleiro} dentro da estrutura anônima, que por sua vez se encontra dentro da estrutura \texttt{State}.

A estrutura \texttt{State} possui cinco variáveis:
\texttt{\_tabuleiro}, no qual pode armazenar informações sobre um tabuleiro até 20 discos[^tabuleiro];
\texttt{\_peao}, que representa a posição $p_i \in \{0, 1,...,n_d, n_d+1\}$, onde $n_d$ é o número de discos de cores comuns no jogo e $p_i$ é o peão da cor $i$[^cor_peao];
\texttt{\_escada}, que indica as posições dos peões na escada, sendo a $p_i$_-ésima_ posição de \texttt{\_escada} é a posição do peao $p_i$;
\texttt{\_jogadores}, possui informações sobre os discos coletados dos dois jogadores;
e por fim, a variável \texttt{\_atual} que representa o jogador que fará a jogada. 

[^tabuleiro]: Cinco cores e quatro discos.
[^cor_peao]: As cores de peão seguem a ordem RGBYP começando do $0$, onde $\textbf{R}ed = 0$, $\textbf{G}reen = 1$, $\textbf{B}lue = 2$, $\textbf{Y}ellow = 3$, e $\textbf{P}urple = 4$.

\lstinputlisting[language=C++, firstnumber=10, linerange={10-31}, caption=Definição da estrutura \texttt{State}]{../../pd/inc/state.h}

O cálculo para determinar os _bits_ necessários para armazenar as informações de cada variável foi realizado será explicado nas subseções seguintes.

### Cálculo de bits do atributo \texttt{tabuleiro}

\begin{equation}
	\label{eq:bitstabuleiro}
	%\tag{eq. \emph{bits} de \_tabuleiro}
	\begin{split}
		\texttt{\_tabuleiro} &= n_c \cdot n_d\\
		\texttt{\_tabuleiro} &= 5 \cdot 4\\
		\texttt{\_tabuleiro} &= 20\ \emph{bits}
	\end{split}
\end{equation}

Na equação \ref{eq:bitstabuleiro}, $n_c$ e $n_d$ são o número de cores e o número de discos do jogo, respectivamente. Seus valores são, no máximo $n_c = 5$ e $n_d = 4$.

### Cálculo de bits do atributo \texttt{peao}

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

Na segunda equação, \ref{eq:bitspeao}, o valor de $n_d$ é o número de discos e $n_p$ é o número de peões do jogo, que por sua vez é igual a $n_c$ (número de cores comuns). Cada peão pode estar: fora do tabuleiro, com $peao(p_i) = 0$; em cima de um disco da sua cor, com $peao(p_i) \in \{1, 2,..., n_d\}$ ; e na escada, com $peao(p_i) = n_d+1$.

### Cálculo de bits do atributo \texttt{escada}

\begin{equation}
	\label{eq:bitsescada}
	%\tag{eq. \emph{bits} de \_escada}
	\begin{split}
		\texttt{\_escada} &= \lceil \log_2(n_p+1) \rceil\cdot n_p\\
		\texttt{\_escada} &= \lceil \log_2(6) \rceil \cdot 5\\
		\texttt{\_escada} &= 15\ \emph{bits}
	\end{split}
\end{equation}

A equação \ref{eq:bitsescada} possui as variáveis $n_p$ e $n_c$ com $n_p, n_c \in \{2, 3, 4, 5\}$ e $n_p = n_c$. Cada peão tem um local na escada, que armazena a posição dele de forma que $0 \leqslant escada(p_i) \leqslant n_c$. As situações possíveis são: $escada(p_i) = 0$ quando o peão não estiver na escada; e $escada(p_i) \in \{1, 2, 3, 4, 5\}$ sendo a ordem de chegada do peão na escada[^chegada_escada].

[^chegada_escada]: O primeiro peão $p_i$ a chegar na escada é indicado com $escada(p_i) = 1$.

### Cálculo de bits do atributo \texttt{jogadores}

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

A capacidade da variável \texttt{\_jogadores} é de 30 \emph{bits}, como demonstrado na equação \label{eq:bitjogadores}. As variáveis utilizadas nessa equação são: $n_d$, o número de discos $n_d \in \{1, 2, 3, 4, 5\}$; $n_c$, o número de cores $n_c \in \{1, 2, 3, 4, 5\}$; e $n_j$, o número de jogadores $n_j = 2$. A informação armazenada na mão dos jogadores, para cada disco, vai até o número máximo de discos mais um, pois o jogador pode pegar todos os discos no tabuleiro e o disco adquirido ao mover o peão para a escada. Para armazenar o número seis, são necessários $\lceil \log_2(6) \rceil = 3 \emph{bits}$

### Cálculo de bits do atributo \texttt{atual}

\begin{equation}
	\label{eq:bitsatual}
	%\tag{eq. \emph{bits} de \_atual}
	\begin{split}
		\texttt{\_atual} &= \lceil \log_2(2) \rceil\\
		\texttt{\_atual} &= 1\ \emph{bit}
	\end{split}
\end{equation}

## Funções de acesso da estrutura \texttt{State}

A estrutura possui um construtor que atribui valores às variáveis através de RAII[^RAII], dessa forma não se faz necessário nenhuma extra implementação. Todas as variáveis possuem um valor padrão, verdadeiro para qualquer tamanho de tabuleiro $t_i$, onde $4 \leqslant t_i \leqslant 20$.

\lstinputlisting[language=C++, firstnumber=33, linerange={33-39}, caption=Construtor da estrutura \texttt{State}]{../../pd/inc/state.h}

[^RAII]: _Resource Aquisition Is Initialization_ é uma técnica de programação que vincula o ciclo de vida do recurso ao da estrutura \cite{cppreferenceraii}.

### Atributo \texttt{tabuleiro}
\lstinputlisting[language=C++, firstnumber=41, linerange={41-47}, caption=Funções de acesso ao atributo \texttt{tabuleiro}]{../../pd/inc/state.h}

### Atributo \texttt{peao}
\lstinputlisting[language=C++, firstnumber=50, linerange={50-60}, caption=Funções de acesso ao atributo \texttt{peão}]{../../pd/inc/state.h}

### Atributo \texttt{escada}
\lstinputlisting[language=C++, firstnumber=63, linerange={63-69}, caption=Funções de acesso ao atributo \texttt{escada}]{../../pd/inc/state.h}

### Atributo \texttt{jogador}
\lstinputlisting[language=C++, firstnumber=72, linerange={72-83}, caption=Funções de acesso ao atributo \texttt{jogador}]{../../pd/inc/state.h}

### Atributo \texttt{atual}
\lstinputlisting[language=C++, firstnumber=86, linerange={86-92}, caption=Funções de acesso ao atributo \texttt{atual}]{../../pd/inc/state.h}

## Comparador da estrutura \texttt{State}

\lstinputlisting[language=C++, firstnumber=95, linerange={95-102}, caption=Comparado da estrutura \texttt{State}]{../../pd/inc/state.h}

# Programação dinâmica

Programação dinâmica é um método para a construção de algoritmos no qual há uma memorização de cada estado distinto para evitar recálculo, caso este estado apareça novamente. A memorização dos estados do jogo _Big Points_ foi feita em uma _hash_, com a chave sendo o estado do jogo e o valor armazenado, a pontuação máxima dos dois jogadores a partir daquele nó.

a melhor jogada para ganhar maximizar seus pontos. Caso não Na vez de cadaCaso a quantidade de jogos vencidos pelo primeiro jogador seja aproximadamente $50\%$

Para analizar o jogo, é preciso exaurir todas as jogadas possíveis a partir de um jogo inicial. Como 

utilizando programação dinâmica[^dynamic_programing]
onde os estados são armazenados em uma _hash_, temos que o número de estados distintos varia entre 17 e 25.

Devido ao imenso número de jogadas possíveis ao longo do do jogo, decidiu-se utilizar a programação dinâmica para 
- Duas funções para melhor entendimento da DP e regras do jogo

## Função \texttt{dp}

A função \texttt{dp} possui os casos base para retornar a função, 

\lstinputlisting[language=C++, firstnumber=1, linerange={1-5}, caption=Construtor da estrutura \texttt{State}]{../../pd/src/dp.cpp}


## Função \texttt{play}

\lstinputlisting[language=C++, firstnumber=1, linerange={1-5}, caption=Construtor da estrutura \texttt{State}]{../../pd/src/dp.cpp}

- Explicação da DP e da função Play (função para realizar as jogadas)

# Verificação dos estados

Foi escrito os estados e suas transições em \textit{post-it}s para garantir que a _DP_ foi feita corretamente. Os estados


<!--
Capítulo 4 - Resultados
-->
\chapter{Resultados}
\label{ch:resultados}

# Análise Estatística

Estimar quantidade de Jogos que o jogador 1 consegue ganhar, empatar e perder.

o jogo é desbalanceado.


<!--
Capítulo 5 - Considerações Finais
-->
\chapter{Considerações Finais}
\label{ch:conclusao}

# Trabalhos futuros

Desenvolvimento de uma I.A. para competir contra um jogador humano.

<!--
Algorithms for games
G.M. Adelson-Velsky
V.L. Arlazarov
M.V. Donskoy


Lembrando a definição recursiva de uma árvore. Os elementos de uma árvore são _nós_ e _arestas_. Um nó incidente na aresta é chamado de _começo_ e o outro _final_.
A árvore pode ser: a) um único nó, ou b) possui um nó adicional e uma aresta começando por um nó já existente e terminando em um novo nó.
Se o nó antigo é representado por $A$ e o novo nó por $B$, a aresta saindo de $A$ para $B$ é representado por $(A,B)$ ou $B$
-->


