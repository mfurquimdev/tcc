\chapter{Trabalho de Conclusão de Curso}

# Introdução

As palavras _nó_ e _estado_ querem dizer a mesma coisa

# Fundamentação Teórica

Teoria dos jogos é o estudo do comportamento estratégico interdependente[^interdependent_strategy] \cite{spaniel_2011}, não apenas o estudo de como vencer ou perder em um jogo, apesar de às vezes esses dois fatos coincidirem. Isso faz com que o escopo seja mais abranjente, desde comportamentos no qual as duas pessoas devem cooperar para ganhar, ou as duas tentam se ajudar para ganharem independente ou, por fim, comportamento de duas pessoas que tentam vencer individualmente.

[^interdependent_strategy]: Estratégia interdependente significa que as ações de uma pessoa interfere no resultado da outra, e vice-versa.

## Histórico da Teoria dos Jogos

Pode-se dizer que a análise de jogos é praticada desde o séculco XVIII tendo como evidência uma carta escrita por James Waldegrave ao analisar uma versão curta de um jogo de baralho chamado \emph{le Her} \cite[p.~2]{Prague_severalmilestones}. No século seguinte, o matemático e filósofo Augustin Cournot fez uso da teoria dos jogos para estudos relacionados à política. Mais recentemente, em 1913, Ernst Zermelo publicou o primeiro teorema matemático da teoria dos jogos \cite[p.~2]{sartini_IIbienaldasbm}.

Outros dois grandes matemáticos que se interessaram na teoria dos jogos foram Émile Borel e John von Neumann. Nas décadas de 1920 e 1930, Emile Borel publicou quatro artigos sobre jogos estratégicos \cite[p.~2]{Prague_severalmilestones}, introduzindo uma noção abstrada sobre jogo estratégico e **estratégia mista**[^mixed_strategy]. Em 1928, John von Neumann demonstrou que todo jogo finito[^finite_game] de **soma zero**[^zero_sum] com duas pessoas possui uma solução em estratégias mistas. Em 1944, Neumann publicou um trabalho junto a Oscar Morgenstern introduzindo a teoria dos jogos na área da economia e matemática aplicada \cite[p.~2--3]{sartini_IIbienaldasbm}.

[^mixed_strategy]: Estratégia mista é um conjunto de estratégias puras associadas a uma distribuição de probabilidade\cite{figueiredo_conceitos}.

[^finite_game]: Jogos finitos são aqueles onde cada participante se depara com um conjunto finito de escolhas, ou seja, eles escolhem suas estratégias dentro de um conjunto finito de alternativas\cite{figueiredo_conceitos}.

[^zero_sum]: Um jogo soma zero é um jogo no qual a vitória de um jogador implica na derrota do outro.


## Regras do Big Points

_Big Points_ é um jogo abstrato e estratégico com uma mecânica de colecionar peças que pode ser jogado de dois a cinco jogadores. São cinco peões de cores distintas, que podem ser usadas por qualquer jogador, para percorrer um caminho de discos coloridos até chegar ao pódio. Durante o percurso, os jogadores coletam alguns destes discos e sua pontuação final é determinada a partir da ordem de chegada dos peões ao pódio e a quantidade de discos adquiridos daquela cor. Ganha o jogador com a maior pontuação.

O jogo é composto por cinco peões, um de cada uma das seguintes cores, denominadas **cores comuns**: vermelha, verde, azul, amarela e violeta. Para cada cor de peão, tem-se dez discos (totalizando cinquenta discos) denominados **discos comuns**, e cinco discos das cores branca e preta (totalizando dez discos) denominados **discos especiais**. Por fim, há um pódio (ou escada) com um lugar para cada peão. O pódio determinará a pontuação equivalente a cada disco da cor do peão, de maneira que o peão que ocupar o espaço mais alto no pódio (o primeiro a subir) fará sua cor valer quatro[^pawn_score], o segundo peão, três pontos e assim por diante, até o último valer zero pontos.

[^pawn_score]: No caso de um jogo com menos de cinco peões, a seguinte fórmula se aplica: $N_{c}-P_{pos}$, onde $N_{c}$ é o número de discos comuns e $P_{pos}$ é a posição do peão no pódio.

### Preparação


### Mecânica


# Metodologia

## Scrum

O _framework_ _scrum_ é ideal para o desenvolvimento de projetos complexos no qual a produtividade e a criatividade são essenciais para a entrega de um produto de alto valor. Inicialmente, tal método de organização e gerenciamento do projeto foi aplicado para o desenvolvimento do sistema em questão \cite{the_scrum_guide}. O _kanban_ do \href{https://waffle.io/mfurquim/tcc}{waffle.io} foi utilizado para registrar tarefas devido à sua integração com as _issues_ do github. Reuniões com o orientador foram realizadas para discutir aspectos técnicos do jogo, como as estruturas de dados a serem utilizadas para reduzir os dados armazenados, e alguns métodos importantes para agilizar o processamento.

Porém, ao longo do tempo, o esforço para manter a rastreabilidade das tarefas tornou-se muito alto em relação à complexidade do projeto, e ao tamanho da equipe. As tarefas passaram a ser _branchs_ locais com nomes significativos, representando a funcionalidade a ser desenvolvida. Após a conclusão da tarefa, testes simples e manuais foram aplicados para então unir à _branch_ mestre[^git_merge]. Por fim, para trabalhar em outra _branch_, foi sempre necessário atualizá-la em relação à mestre[^git_rebase].

[^git_merge]: `$ git merge`
[^git_rebase]: `$ git rebase`





Quantidade de partidas

\begin{equation}
	\label{eq:partidas}
	\tag{e.q. Quantidades de Partidas Distintas}
	\begin{split}
		Partidas\ &=\  (\#J-1) \cdot \binom{\#D_T}{\#D_W} \cdot \binom{\#D_{L1}}{\#D_K} \cdot \binom{\#D_{L2}}{\#D_R} \cdot \binom{\#D_{L3}}{\#D_G} \cdot \binom{\#D_{L4}}{\#D_B} \cdot \binom{\#D_{L5}}{\#D_Y} \cdot \binom{\#D_{L6}}{\#D_V}\\
		Partidas\ &=\  4\cdot \binom{55}{5} \cdot \binom{50}{5} \cdot \binom{45}{9} \cdot \binom{36}{9} \cdot \binom{27}{9} \cdot \binom{18}{9} \cdot \binom{9}{9}\\
		Partidas\ &=\ 560'483'776'167'774'018'942'304'261'616'685'408'000'000\\
		Partidas\ &\approx 5\times 10^{41}
	\end{split}
\end{equation}













## Análise do jogo

Para analizar o jogo _Big Points_, é preciso realizar todas as jogadas de todos os jogos possíveis. Cada jogador, na sua vez, deve escolher uma jogada na qual lhe garanta a vitória, se houver mais de uma, escolha a que tiver a maior pontuação. Caso não tenha uma jogada para vencer, o jogador deve minimizar a pontuação do adversário. Após fazer isso para um jogo inicial, os resultados são escritos em um arquivo _csv_ para análise. Esse procedimento é repetidos para _cada_ organização possível do tabuleiro inicial.

Exaurir todas as possibilidades de jogadas é um trabalho computacional imenso e cresce exponencialmente de acordo com o tamanho do jogo. Para um jogo pequeno com apenas dois discos e duas cores comuns (sem especiais) as jogadas possíveis são: mover o peão vermelho e pegar o disco da direita, ou da esquerda; e mover o peão verde e pegar o disco da direita ou da esquerda. Isso gera uma árvore onde cada nó possui quatro filhos e a altura média dessa árvore é quatro, totalizando uma quantidade de estados de aproximadamente $\sum_{h=0}^{4}4^{h} \approx 341$. Ao final do cálculo deste jogo reduzido, temos que o número de estados distintos varia entre 17 e 25, dependendo do estado inicial do tabuleiro. Devido a este grande número de estados repetidos, escrever o algoritmo fazendo uso de programação dinâmica economizou bastante tempo e processamento.

**Remover esta linha!**_

O jogo seria um jogo balanceado se ambos os jogadores ganharem aproximadamente metade das vezes. Se existem seis jogos diferentes (combinação de duas cores com dois discos cada), o jogo é considerado balanceado se cada jogador ganhar três jogos. Neste caso, temos os jogos $j_i \in {1122, 1212, 1221, 2112, 2121, 2211}$, e para cada $j_i$ temos a pontuação máxima e a quantidade de estados distintos, como demonstrado na tabela @tab:pontuacao.


Tabela: Pontuação utilizando Minimax {#tab:pontuacao}

**Jogo** | **Pontuação** | **#Estados**
:-------:|:-------------:|:-----------:
  1122   |     (2,1)     |      17
  1212   |     (2,0)     |      25
  1221   |     (2,1)     |      25
  2112   |     (2,1)     |      25
  2121   |     (2,1)     |      25
  2211   |     (2,0)     |      17


## Programação Dinâmica

Programação dinâmica é um método para a construção de algoritmos no qual há uma memorização de cada estado distinto para evitar recálculo, caso este estado apareça novamente. A memorização dos estados do jogo _Big Points_ foi feita em uma _hash_, com a chave sendo o estado do jogo e o valor armazenado, a pontuação máxima dos dois jogadores a partir daquele nó.

a melhor jogada para ganhar maximizar seus pontos. Caso não Na vez de cadaCaso a quantidade de jogos vencidos pelo primeiro jogador seja aproximadamente $50\%$

Para analizar o jogo, é preciso exaurir todas as jogadas possíveis a partir de um jogo inicial. Como 

utilizando programação dinâmica[^dynamic_programing]
onde os estados são armazenados em uma _hash_, temos que o número de estados distintos varia entre 17 e 25.



### Estado do jogo

Para escrever a programação dinâmica capaz de
