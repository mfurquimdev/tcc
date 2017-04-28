\chapter{Trabalho de Conclusão de Curso}

# Introdução

# Fundamentação Teórica

Teoria dos jogos é o estudo do comportamento estratégico interdependente[^interdependent_strategy] \cite{spaniel_2011}, não apenas o estudo de como vencer ou perder em um jogo, apesar de às vezes esses dois fatos coincidirem. Isso faz com que o escopo seja mais abranjente, desde comportamentos no qual as duas pessoas devem cooperar para ganhar, ou as duas tentam se ajudar para ganharem independente ou, por fim, comportamento de duas pessoas que tentam vencer individualmente.

[^interdependent_strategy]: Estratégia interdependente significa que as ações de uma pessoa interfere no resultado da outra, e vice-versa.

## Histórico da Teoria dos Jogos

Pode-se dizer que a análise de jogos é praticada desde o séculco XVIII tendo como evidência uma carta escrita por James Waldegrave ao analisar uma versão curta de um jogo de baralho chamado \emph{le Her} \cite[p.~2]{Prague_severalmilestones}. No século seguinte, o matemático e filósofo Augustin Cournot fez uso da teoria dos jogos para estudos relacionados à política. Mais recentemente, em 1913, Ernst Zermelo publicou o primeiro teorema matemático da teoria dos jogos \cite[p.~2]{sartini_IIbienaldasbm}.

Outros dois grandes matemáticos que se interessaram na teoria dos jogos foram Émile Borel e John von Neumann. Nas décadas de 1920 e 1930, Emile Borel publicou quatro artigos sobre jogos estratégicos \cite[p.~2]{Prague_severalmilestones}, introduzindo uma noção abstrada sobre jogo estratégico e **estratégia mista**[^mixed_strategy]. Em 1928, John von Neumann demonstrou que todo jogo finito[^finite_game] de **soma zero**[^zero_sum] com duas pessoas possui uma solução em estratégias mistas. Em 1944, Neumann publicou um trabalho junto a Oscar Morgenstern introduzindo a teoria dos jogos na área da economia e matemática aplicada \cite[p.~2--3]{sartini_IIbienaldasbm}.

[^mixed_strategy]: Estratégia mista é um conjunto de estratégias puras associadas a uma distribuição de probabilidade\cite{figueiredo_conceitos}.

[^finite_game]: Jogos finitos são aqueles onde cada participante se depara com um conjunto finito de escolhas, ou seja, eles escolhem suas estratégias dentro de um conjunto finito de alternativas\cite{figueiredo_conceitos}.

[^zero_sum]: Um jogo soma zero é um jogo no qual a vitória de um jogador implica na derrota do outro.


# Metodologia

## Scrum

O _framework_ _scrum_ é ideal para o desenvolvimento de projetos complexos no qual a produtividade e a criatividade são essenciais para a entrega de um produto de alto valor. Inicialmente, tal método de organização e gerenciamento do projeto foi aplicado para o desenvolvimento do sistema em questão \cite{the_scrum_guide}. O _kanban_ do \href{https://waffle.io/mfurquim/tcc}{waffle.io} foi utilizado para registrar tarefas devido à sua integração com as _issues_ do github. Reuniões com o orientador foram realizadas para discutir aspectos técnicos do jogo, como as estruturas de dados a serem utilizadas para reduzir os dados armazenados, e alguns métodos importantes para agilizar o processamento.

Porém, ao longo do tempo, o esforço para manter a rastreabilidade das tarefas tornou-se muito alto em relação à complexidade do projeto, e ao tamanho da equipe. As tarefas passaram a ser _branchs_ locais com nomes significativos, representando a funcionalidade a ser desenvolvida. Após a conclusão da tarefa, testes simples e manuais foram aplicados para então unir à _branch_ mestre[^git_merge]. Por fim, para trabalhar em outra _branch_, foi necessário atualizá-la em relação à mestre[^git_rebase].

[^git_merge]: `$ git merge`
[^git_rebase]: `$ git rebase`

## Regras do Big Points

_Big Points_ é um jogo abstrato e estratégico com uma mecânica de colecionar peças que pode ser jogado de dois a cinco jogadores. São cinco peões de cores distintas, que podem ser usadas por qualquer jogador, para percorrer um caminho de discos coloridos até chegar ao pódio. Durante o percurso, os jogadores coletam alguns destes discos e sua pontuação final é determinada a partir da ordem de chegada dos peões ao pódio e a quantidade de discos adquiridos daquela cor. Ganha o jogador com a maior pontuação.

O jogo é composto por cinco peões, um de cada uma das seguintes cores, denominadas **cores comuns**: vermelha, verde, azul, amarela e violeta. Para cada cor de peão, tem-se dez discos (totalizando cinquenta discos) denominados **discos comuns**, e cinco discos das cores branca e preta (totalizando dez discos) denominados **discos especiais**. Por fim, há um pódio (ou escada) com um lugar para cada peão. O pódio determinará a pontuação equivalente a cada disco da cor do peão, de maneira que o peão que ocupar o espaço mais alto no pódio (o primeiro a subir) fará sua cor valer quatro[^pawn_score], o segundo peão, três pontos e assim por diante, até o último valer zero pontos.

[^pawn_score]: No caso de um jogo com menos de cinco peões, a seguinte fórmula se aplica: $N_{c}-P_{pos}$, onde $N_{c}$ é o número de discos comuns e $P_{pos}$ é a posição do peão no pódio.

### Preparação



### Mecânica


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
