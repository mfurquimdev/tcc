
<!--

Às vezes o jogador também possui informação completa sobre o estado atual e do histórico de jogadas do jogo.

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


MIMIMIPROGRAM A SODIAMSDOUAHSDOIUG ADIFHGSDKJFHGSD FJGSkfdjgHSDfas
asdasd

-->
