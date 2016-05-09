# Referencial Teórico


## Uma Introdução a Teoria dos Jogos

Autores: Brigida Alexandre Sartini, Gilmar Garbugio, Humberto José Bortolossi, Polyane Alves Santos e Larissa Santana Barreto
II Bienal da SBM, Universidade Federal da Bahia.
25 a 29 de outubro de 2004

### Introdução

A teoria dos jogos é uma teoria matemática criada para se modelar fenômenos que podem ser observados quando dois ou mais "agentes de decisão" interagem entre si.

Além de ser usada para estudar assuntos como eleições, leilões, balança de poder e evolução genética, a teoria dos jogos também pode ser estudada no campo de matemática pura.

Há uma diferença entre Teoria Econômica dos Jogos (motivações predominante econômicas) e Teoria Combinatória dos Jogos (aspectos combinatórios de jogos de mesa e não permite elementos imprevisíveis).

#### História

Século XVIII, James Waldergrave analisa um jogo de cartas chamado "_le Her_" e fornece uma solução que é um equilíbrio de estratégia mista, porém não estendeu sua abordagem a uma teoria geral.

Século XIX, Augustin Cournot escreve sobre duopólio [3]. Em 1913, Ernst Zermelo publicou o primeiro teorema matemático da teoria dos jogos [21], afirmando que o xadrez é um jogo estritamente determinado, ou seja, em cada estágio do jogo há pelo menos uma estratégia que garantirá a vitória de um dos jogadoresl, ou no mínimo conduzirá o jogo a um empate.

Emile Borel reinventou as soluções **minimax** e publicou quatro artigos sobre jogos estratégicos.

Em 1928, John von Neumann demonstrou que todo jogo finito de soma zero com duas pessoas possui uma solução em estratégias mistas [18], utilizando topologia e análise funcional.

Em 1937, Neumann forneceu uma nova demonstração baseada no teorema do ponto fixo de Brouwer.

Em 1944, publicou um trabalho na área da economia com Oscar Morgenstern [19]. Com isso, a teoria dos jogos invadiu a economia e a matemática aplicada.

Em 1950, John Forbes Nash Júnior publicou quatro artigos importantes para a teoria dos jogos não-cooperativos. Em "_Equilibrium Points in n-Person Games_" [14] <!--([13] ?)--> e "_Non-cooperative Games_" [16], Nash provou a existência de um equilíbrio de estratégias mistas para jogos não-cooperativos, denominado **equilíbrio de Nash**.

Em 1994, John Forbes Nash Jr., John Harsanyi e Reinhard Selten receberam o prêmio Nobel por suas contribuições para a Teoria dos Jogos.

#### O que é um jogo?

A teoria dos jogos pode ser definida como a teoria dos modelos matemáticos que estuda a escolha de decisões ótimas sob condições de conflito. Os elementos básicos de um jogo são: o conjunto de **jogadores**, onde cada jogadore possui um conjunto de **estratégias**. A partir das escolhas de estratégias de cada jogador, temos uma **situação** ou **perfil**.

Em termos matemáticos é dito que um jogador tem uma **função utilidade**, que atribui um **payoff** ou **ganho** para cada situação do jogo, quando este jogador tem um certo interesse ou preferência a uma situação.

**Matriz de _payoffs_** é uma representação matricial dos _payoffs_ dos jogadores, onde cada estratégia de um jogador estão representadas por cada linha e cada estratégias de seu oponente estão representadas por cada coluna.

#### Soluções de um jogo

Uma solução de um jogo é uma prescrição ou previsão sobre o resultado do jogo. **Dominância** e **equilíbrio de Nash** são dois conceitos importantes para encontrar uma solução de um estado do jogo.

É dito que uma determinada estratégia é uma **estratégia dominante** quando esta é a única estratégia restante após aplicar a técnica de **dominância estrita iterada**. O encontro das estratégias dos jogadores é chamado de **equilíbrio de estratégia dominante**.

**Dominância estrita iterada** nada mais é do que um processo onde se eliminam as estratégias que são estritamente dominadas.

**Solução estratégica** ou **equilíbrio de _Nash_** é um conjunto de estratégias para cada jogador onde cada um deles não tem incentivo de mudar sua estratégia se os demais jogadores não o fizerem.

#### Estratégias mistas

**Estratégias mistas** é uma alternativa quando não há equilíbrio de _Nash_. Neste caso, cada jogador escolhe uma **distribuição probabilística** sobre suas estratégias puras. Ou seja, há um valor probabilístico entre 0 e 1 para cada estratégia pura do jogador e a soma de todos estes valores é igual a 1.

O espaço de todos os perfis de estratégias mista é (dado pelo produto cartesiano) é denomidado **espaço de estratégia mista** e cada vetor pertencente a este espaço é denominado **perfil de estratégia mista**.

Cada perfil de estratégia mista determina um _payoff_ esperado. É feito uma média dos _payoffs_ ponderada pelas distribuições de probabilidades.

#### Soluções em estratégias mistas

Todos os critérios básicos para soluções de jogos em estratégia puras, tanto dominância estrita iterada quanto equilíbrio de nash, podem ser estendidas para estratégias mistas.

#### Existência de soluções

Há jogos que não possuem equilíbrio de Nash em estratégias puras, mas todos os exemplos descritos na seção _Exemplos_ possuem pelo menos um equilíbrio de Nash em estratégias mistas. Existem dois teoremas de que comprovam a existência de solução para jogos em geral: o **teorema minimax de von Newmann** para jogos de soma zero com dois jogadores e o **teorema de equilíbrios de Nash** para jogos gerais.

### O teorema de minimax de von Neumann
#### Jogos de soma constante com dois jogadores

Um jogo de _soma constante com dois jogadores_ é um jogo com dois jogadores, no qual o _payoff_ de suas estratégias na matriz somam a uma constante, i.e. $a_{ij} + b_{ij} = c$. No caso particular em que a constante _c_ é zero, o jogo é dito ter _soma zero_.

### Exemplos

1. Dilema do prisioneiro
1. A batalha dos sexos
1. _Matching pennies_
1. Chefe e empregado
1. A tragédia dos comuns
<!-- 1. Troll na estrada ? -->

### Teoremas

1. Teorema Minimax
    - Para jogos de soma zero com dois jogadores
1. Equlíbrio de Nash
    - Para jogos gerais

### Bibliografia

[3] A. A. Cournot, _Recherches sur les Principes Mathématiques de la Théorie des Richesses_, 1838. Traduzido por N. T. Bacon em _Reserches into the Mathematical Principles of the Theory of Wealth_, McMillan, New York, 1927.

[13] J. F. Nash Jr., _Equilibrium Points in n-person Games_. Proceedings of the National Academy of Sciences of the United States of America, pp. 48-49, 1950.

[14] J. F. Nash Jr., _Non-Cooperative Games_. PhD. Thesis. Princeton University Press, 1950.

[16] J. F. Nash Jr., _Non-Cooperative Games_. Annals of Mathematics, pp. 286-295, 1951.

[18] J. von Neumann. _Zur Theorie der Gesellschaftsspiele_. Mathematische Annalen, vol. 100, pp 295-320. Traduzido por S. Bargmann: _On the Theory of Games of Strategy_ em _Contributions to the Theory of Games_, vol. 4, pp. 13-42, A. W. Tucker e R. D. Luce (editores), Princeton University Press, 1959. <!--(1928 ?)-->

[19] J. von Neumann e O. Morgenstern, _Theory of Games and Economic Behavior_. Princeton University Press, 1944.

[21] E. Zermelo, _Über eine Anwendung der Mengdenlehre auf die theories des Schachspiels_. Atas do _Décimo Quinto Congresso Internacional de Matemáticos_, vol. 2, pp. 501-504, 1913.

### Notas/Extras

- "O Duopólio é uma falha de mercado e tipo específico de oligopólio em que apenas dois produtores existem em um mercado. Esta definição é geralmente usada apenas quando duas empresas têm o controle dominante do mercado." - <!-- [Wikipedia](https://pt.wikipedia.org/wiki/Duop%C3%B3lio) -->

- Procurar os quatro artigos de Emile Borel sobre jogos estratégicos e teoria **minimax**.

- Pesquisar sobre ponto fixo de Brouwer.


## Stanford

### Notas

Impartial game means the rules for both players are the same. The inverse of this game, is itself.

Reversible moves are moves which the other player can make to bring the game to a previous state, similar to undoing that player's move.

Canonical form, which is a simplified game form, and it is unique.


## MindYourDecisions (YouTube)
### Avoiding The Troll

Everyday you walk from A to B, which distance 2km. 50% of the time, there is no obstruction. The other half of the time, there is a Troll in the middle of the way who creates an invisible barrier 1km north and 1km south to block your trip, forcing you to go around it. You cannot neither detect nor predict the barrier until you reach it, so you cannot plan in advance whether you need to walk around it. But you do know the troll appears randomly 50% at the time.

If you can walk in a two straight lines from any points between A and B, what is the best strategy to walk the least distance on average? What is the distance?

1. **Walk arround the barrier every time**

- Walk the hypothenuse twice.
Distance = 2*sqrt(2) = 2.83km

2. **Try to walk straight, then walk around if needed**

- 50% of the time, there is no troll, and you walk 2km.
- 50% of the time, there is a troll, and you walk 1km+1km+sqrt(2).
Distance = 0.5(2km) + 0.5(2+sqrt(2)) = 2.71km.

3. **Walk a distance _x_ above the halfway point**

- 50% of the time, there is no troll, and you walk the hypothenuse twice = 2*sqrt(1+pow(x,2))
- 50% of the time, there is a troll, and you walk the hypothenuse once, plus the rest up of the barrier and the hypothenuse of the entire triangle.

Distance = 0.5(2*sqrt(1+pow(x,2))) + 0.5(sqrt(1+pow(x,2))+(1-x)+sqrt(2)) = 2.62km
with _x_ = 1/(2*sqrt(2))

4. **Walk angle theta from starting point**

the hypothenuse given angle theta = 1/cos(theta)
- 50% of the time, there is no troll, and you walk twice the hypothenuse = 2/cos(theta)
- 50% of the time, there is a troll, and you walk the hypothenuse, walk around it and complete the trip. The hypothenuse (1/cos(theta)) + the other leg of the triangle which is the tangent, so you walk 1-tan(theta) + sqrt(2)

Distance = 1.5/cos(theta) + 0.5(1-tan(theta) + sqrt(2)) = 2.62km
with _theta_ = sin-1(1/3) = 0.34 = 19.5o
