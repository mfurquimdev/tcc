# _Big Points_: Uma Análise Baseada na Teoria dos Jogos
## Resumo
A área de Teoria dos Jogos estuda as melhores estratégias dos jogadores em um determinado jogo. Aplicando suas teorias em um jogo de tabuleiro eletrônico, este trabalho propõe analisar o jogo _Big Points_ a partir de um determinado estado e, como resultado, identificar as melhores heurísticas para os jogadores e uma possível inteligência artificial.

## Introdução
- História da teoria dos jogos
- Definição de teoria dos jogos
- Jogo a ser analisado
- Regra do jogo

## Materiais e Métodos
- O jogo eletrônico está sendo implementado
- Foi feito uma análise combinatória inicial para descobrir a possibilidade de computar todas as possíveis jogadas de um ou de vários jogos. Chegou-se na conclusão que não era factível

### Análise combinatória
O jobo _Big Points_ possui cinco peões de cores distintas, pode ser jogado de dois a cinco jogadores, e dos 55 discos totais, cinco são brancos, cinco são pretos e nove de cada um das cinco cores restantes. Os peões podem estar em cima de um disco ou em uma das cinco posições da escada.
Cada partida diferente pode ser representado pela quantidade de jogadores e pela posição inicial dos discos, compondo o tabuleiro. Desta forma temos que o número de jogos distintos é 10^{41} < \#Jogos Distintos < 10^{42}

<!--
\#Partidas\ &=\  (\#J-1) * \binom{55}{5} * \binom{50}{5} * \binom{45}{9} * \binom{36}{9} * \binom{27}{9} * \binom{18}{9} * \binom{9}{9}\\
\#Partidas\ &=\ \cfrac{4 * 55!}{2^{27} * 3^{36} * 5^7 * 7^5}\\
\#Partidas\ &=\ \cfrac{2^{52} * 3^{26} * 5^{13} * 7^{8} * 11^{5} * 13^{4} * 17^{3} * 19^{2} * 23^{2} * 29 * 31 * 37 * 41 * 43 * 47 * 53}{2^{27} * 3^{36} * 5^7 * 7^5}\\
\#Partidas\ &=\ \cfrac{2^{25} * 5^{6} * 7^{3} * 11^{5} * 13^{4} * 17^{3} * 19^{2} * 23^{2} * 29 * 31 * 37 * 41 * 43 * 47 * 53}{3^{10}}\\
\#Partidas\ &=\ 560'483'776'167'774'018'942'304'261'616'685'408'000'000
	\end{split}
\end{equation}
$10^{41}$ \textless\ \#Partidas \textless\ $10^{42}$
-->

## Resultados
?

## Discussão e Conclusões
?
