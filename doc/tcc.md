<!--
Capítulo 1 - Introdução
-->
\chapter{Introdução}
\label{ch:introducao}

Este trabalho propôs realizar uma análise em cima de um jogo de tabuleiro já existente chamado \textit{Big Points}. Fazendo uso de conceitos da teoria dos jogos, foi escrito um programa utilizando programação dinâmica para exaurir todas as possibilidades de jogos e de jogadas de um número reduzido de peças no jogo. Os resultados finais corroboram com a ideia de que o jogo é desbalanceado, dando ao primeiro jogador uma maior chance de vencer o jogo.

A estrutura do trabalho foi dividida em cinco capítulos, sendo que o primeiro é esta introdução. O capítulo seguinte, de fundamentação teórica, relata um pouco sobre a história da teoria dos jogos, esclarece alguns conceitos relevantes para o entendimento do trabalho, e explica as regras do próprio jogo. Em seguida, tem-se o capítulo \ref{ch:metodologia}, referente à análise e ao desenvolvimento do projeto, até sua conclusão, e no capítulo \ref{ch:resultados} os resultados da análise são mostrados. Por último, o capítulo \ref{ch:conclusao} onde é feita a conclusão do trabalho e são citados alguns possíveis trabalhos futuros em cima do trabalho atual.


<!--
Capítulo 2 - Fundamentação Teórica
-->
\chapter{Fundamentação Teórica}
\label{ch:fundamentacao_teorica}

Teoria dos jogos é o estudo do comportamento estratégico interdependente[^interdependent_strategy], não apenas o estudo de como vencer ou perder em um jogo, apesar de às vezes esses dois fatos coincidirem. Isso faz com que o escopo seja mais abranjente, desde comportamentos no qual as duas pessoas devem cooperar para ganhar, ou as duas tentam se ajudar para ganharem independente ou, por fim, comportamento de duas pessoas que tentam vencer individualmente \cite{spaniel_2011}.

[^interdependent_strategy]: Estratégia interdependente significa que as ações de uma pessoa interfere no resultado da outra, e vice-versa.

# Histórico da Teoria dos Jogos

Pode-se dizer que a análise de jogos é praticada desde o séculco XVIII tendo como evidência uma carta escrita por James Waldegrave ao analisar uma versão curta de um jogo de baralho chamado \emph{le Her} \cite[p.~2]{Prague_severalmilestones}. No século seguinte, o matemático e filósofo Augustin Cournot fez uso da teoria dos jogos para estudos relacionados à política. Mais recentemente, em 1913, Ernst Zermelo publicou o primeiro teorema matemático da teoria dos jogos \cite[p.~2]{sartini_IIbienaldasbm}.

Outros dois grandes matemáticos que se interessaram na teoria dos jogos foram Émile Borel e John von Neumann. Nas décadas de 1920 e 1930, Emile Borel publicou quatro artigos sobre jogos estratégicos \cite[p.~2]{Prague_severalmilestones}, introduzindo uma noção abstrada sobre jogo estratégico e estratégia mista[^mixed_strategy]. Em 1928, John von Neumann demonstrou que todo jogo finito[^finite_game] de soma zero[^zero_sum] com duas pessoas possui uma solução em estratégias mistas. Em 1944, Neumann publicou um trabalho junto a Oscar Morgenstern introduzindo a teoria dos jogos na área da economia e matemática aplicada \cite[p.~2--3]{sartini_IIbienaldasbm}.

[^mixed_strategy]: Estratégia mista é um conjunto de estratégias puras associadas a uma distribuição de probabilidade \cite{figueiredo_conceitos}.

[^finite_game]: Jogos finitos são aqueles onde cada participante se depara com um conjunto finito de escolhas, ou seja, eles escolhem suas estratégias dentro de um conjunto finito de alternativas \cite{figueiredo_conceitos}.

[^zero_sum]: Um jogo soma zero é um jogo no qual a vitória de um jogador implica na derrota do outro.

# Conceitos Relevantes

Alguns ceonceitos fundamentais para o entendimento da análise realizada em cima do jogo \textit{Big Points} são \textit{zero-sum game} e \textit{minimax}.

Como o jogo não possui nenhum elemento dependente da sorte, não serão usados estratégias mistas. O \textit{winning move} não foi analizado devido à complexidade da implementação da análise atual.

## Minimax


## Programação dinâmica

# Regras do Big Points

_Big Points_ é um jogo abstrato e estratégico com uma mecânica de colecionar peças que pode ser jogado de dois a cinco jogadores. São cinco peões de cores distintas, que podem ser usadas por qualquer jogador, para percorrer um caminho de discos coloridos até chegar à escada. Durante o percurso, os jogadores coletam alguns destes discos e sua pontuação final é determinada a partir da ordem de chegada dos peões ao pódio e a quantidade de discos adquiridos daquela cor. Ganha o jogador com a maior pontuação.

\begin{figure}[htb]
	\centering
	\includegraphics[width=0.7\textwidth]{img/front}
	\caption{Caixa do jogo \textbf{Big Points}}
	\label{fig:front}
\end{figure}

O jogo é composto por cinco peões, como demonstrado na figura \ref{fig:front}, um de cada uma das seguintes cores, denominadas **cores comuns**: vermelha, verde, azul, amarela e violeta. Para cada cor de peão, tem-se dez discos, como mostrado na figura \ref{fig:content}, (totalizando cinquenta discos) denominados **discos comuns**, e cinco discos das cores branca e preta (totalizando dez discos) denominados **discos especiais**. Por fim, há um pódio (ou escada) com um lugar para cada peão. A escada determinará a pontuação equivalente a cada disco da cor do peão, de maneira que o peão que ocupar o espaço mais alto no pódio (o primeiro a subir) fará sua cor valer quatro[^pawn_score], o segundo peão, três pontos e assim por diante, até o último valer zero pontos.

[^pawn_score]: No caso de um jogo com menos de cinco peões, a seguinte fórmula se aplica: $Score = N_{c}-P_{pos}$, onde $Score$ é a pontuação daquela determinada cor, $N_{c}$ é o número de discos comuns e $P_{pos}$ é a posição do peão no pódio.

\begin{figure}
    \centering
    \begin{subfigure}[b]{0.48\textwidth}
    	\includegraphics[width=\textwidth]{img/content}
    	\caption{Conteúdo do jogo \textbf{Big Points}}
    	\label{fig:content}
    \end{subfigure}
    \begin{subfigure}[b]{0.48\textwidth}
    	\includegraphics[width=\textwidth]{img/setup}
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
	\tag{e.q. Exemplo de pontuação}
	\begin{split}
		Pontuacao &= n_r \cdot (n_c - p_r) + n_g \cdot (n_c - p_g) + n_b \cdot (n_c - p_b)\\
		Pontuacao &= 2 \cdot (3 - 3) + 1 \cdot (3 - 2) + 3 \cdot (3 - 1)\\
		Pontuacao &= 7
	\end{split}
\end{equation}


<!--
Capítulo 3 - Metodologia
-->
\chapter{Metodologia}
\label{ch:metodologia}

# Scrum

O _framework_ _scrum_ é ideal para o desenvolvimento de projetos complexos no qual a produtividade e a criatividade são essenciais para a entrega de um produto de alto valor. Inicialmente, tal método de organização e gerenciamento do projeto foi aplicado para o desenvolvimento do sistema em questão \cite{the_scrum_guide}. O _kanban_ do \href{https://waffle.io/mfurquim/tcc}{waffle.io} foi utilizado para registrar tarefas devido à sua integração com as _issues_ do github. Reuniões com o orientador foram realizadas para discutir aspectos técnicos do jogo, como as estruturas de dados a serem utilizadas para reduzir os dados armazenados, e alguns métodos importantes para agilizar o processamento.

Porém, ao longo do tempo, o esforço para manter a rastreabilidade das tarefas tornou-se muito alto em relação à complexidade do projeto, e ao tamanho da equipe. As tarefas passaram a ser _branchs_ locais com nomes significativos, representando a funcionalidade a ser desenvolvida. Após a conclusão da tarefa, testes simples e manuais foram aplicados para então unir à _branch_ mestre[^git_merge]. Por fim, para trabalhar em outra _branch_, foi sempre necessário atualizá-la em relação à mestre[^git_rebase].

[^git_merge]: \texttt{\$ git merge}
[^git_rebase]: \texttt{\$ git rebase <from-branch> <to-branch>}

# Análise do jogo \textit{Big Points}

Para analizar o jogo _Big Points_, é preciso realizar todas as jogadas de todos os jogos possíveis. Cada jogador, na sua vez, deve escolher uma jogada na qual lhe garanta a vitória, se houver mais de uma, escolha a que tiver a maior pontuação. Caso não tenha uma jogada para vencer, o jogador deve minimizar a pontuação do adversário. Após fazer isso para um jogo inicial, os resultados são escritos em um arquivo _csv_ para análise. Esse procedimento é repetidos para _cada_ organização possível do tabuleiro inicial.

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
	\tag{e.q. Quantidades de Partidas Distintas}
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

[^tabuleiro]: Cinco cores e quatro discos ou quatro cores e cinco discos.
[^cor_peao]: As cores de peão seguem a ordem RGBYP, onde $\textbf{R}ed = 0$, $\textbf{G}reen = 1$, $\textbf{B}lue = 2$, $\textbf{Y}ellow = 3$, e $\textbf{P}urple = 4$.

\lstinputlisting[language=C++, firstnumber=10, linerange={10-31}]{../../pd/inc/state.h}

O cálculo para determinar os _bits_ necessários para armazenar as informações de cada variável foi realizado da seguinte forma:

\begin{equation}
	\label{eq:bitstabuleiro}
	\tag{e.q. \emph{bits} de \_tabuleiro}
	\begin{split}
		\texttt{\_tabuleiro} &= n_c \cdot n_d\\
		\texttt{\_tabuleiro} &= \max(4 \cdot 5,\ 5 \cdot 4)\\
		\texttt{\_tabuleiro} &= 20\ \emph{bits}
	\end{split}
\end{equation}

Na equação \ref{eq:bitstabuleiro}, $n_c$ e $n_d$ são o número de cores e o número de discos do jogo, respectivamente. Seus valores são, no máximo, $n_c = 4$ quando $n_d = 5$ e $n_c = 5$ quando $n_d = 4$.

\begin{equation}
	\label{eq:bitspeao}
	\tag{e.q. \emph{bits} de \_peao}
	\begin{split}
		\texttt{\_peao} &= \lceil \log_2(n_d+1) \rceil \cdot n_p\\
		\texttt{\_peao} &= \max\left(\lceil \log_2(4 + 1) \rceil \cdot 5,\ \lceil \log_2(5 + 1)\rceil \cdot 4 \right)\\
		\texttt{\_peao} &= \max\left(3 \cdot 5,\ 3 \cdot 4 \right)\\
		\texttt{\_peao} &= 15\ \emph{bits}
	\end{split}
\end{equation}

Na segunda equação, \ref{eq:bitspeao}, o valor de $n_d$ é o número de discos e $n_p$ é o número de peões do jogo, que por sua vez é igual a $n_c$ (número de cores comuns). Cada peão pode estar: fora do tabuleiro, com $peao(p_i) = 0$; em cima de um disco da sua cor, com $peao(p_i) \in \{1, 2,..., n_d\}$ ; e na escada, com $peao(p_i) = n_d+1$.

\begin{equation}
	\label{eq:bitsescada}
	\tag{e.q. \emph{bits} de \_escada}
	\begin{split}
		\texttt{\_escada} &= \lceil \log_2(n_c+1) \rceil\cdot n_p\\
		\texttt{\_escada} &= \lceil \log_2(6) \rceil \cdot 5\\
		\texttt{\_escada} &= 15\ \emph{bits}
	\end{split}
\end{equation}

A equação \ref{eq:bitsescada} possui as variáveis $n_p$ e $n_c$ com $n_p, n_c \in \{2, 3, 4, 5\}$ e $n_p = n_c$. Cada peão tem um local na escada, que armazena a posição dele de forma que $0 \leqslant escada(p_i) \leqslant n_c$. As situações possíveis são: $escada(p_i) = 0$ quando o peão não estiver na escada; e $escada(p_i) \in \{1, 2, 3, 4, 5\}$ sendo a ordem de chegada do peão na escada[^chegada_escada].

[^chegada_escada]: O primeiro peão $p_i$ a chegar na escada é indicado com $escada(p_i) = 1$.

\begin{equation}
	label{eq:bitsjogadores}
	\tag{e.q. \emph{bits} de \_jogadores}
	\begin{split}
		\texttt{\_jogadores} &= \lceil \log_2(n_d+1) \rceil \cdot n_c \cdot n_j\\
		\texttt{\_jogadores} &= \max(\lceil \log_2(5+1) \rceil \cdot 4 \cdot 2,\ \lceil \log_2(4+1) \rceil \cdot 5 \cdot 2)\\
		\texttt{\_jogadores} &= \max(3 \cdot 4 \cdot 2,\ 3 \cdot 5 \cdot 2)\\
		\texttt{\_jogadores} &= 30\ \emph{bits}
	\end{split}
\end{equation}

A capacidade da variável \texttt{\_jogadores} é de 30 \emph{bits}, como demonstrado na equação \label{eq:bitjogadores}. As variáveis utilizadas nessa equação são: $n_d$, o número de discos $n_d \in \{1, 2, 3, 4, 5\}$; $n_c$, o número de cores $n_c \in \{1, 2, 3, 4, 5\}$; e $n_j$, o número de jogadores $n_j = 2$. A informação armazenada na mão dos jogadores, para cada disco, vai até o número máximo de discos mais um, pois o jogador pode pegar todos os discos no tabuleiro e o disco adquirido ao mover o peão para a escada. Para armazenar o número seis, são necessários $\lceil \log_2(6) \rceil = 3 \emph{bits}$

\begin{equation}
	\label{eq:bitsatual}
	\tag{e.q. \emph{bits} de \_atual}
	\begin{split}
		\texttt{\_atual} &= \lceil \log_2(2) \rceil\\
		\texttt{\_atual} &= 1\ \emph{bit}
	\end{split}
\end{equation}

## Funções de acesso

A estrutura possui um construtor que atribui valores às variáveis através de RAII[^RAII], dessa forma não se faz necessário nenhuma extra implementação. Todas as variáveis possuem um valor padrão, verdadeiro para qualquer tamanho de tabuleiro $t_i$, onde $4 \leqslant t_i \leqslant 20$.

\lstinputlisting[language=C++, firstnumber=34, linerange={34-39}]{../../pd/inc/state.h}

[^RAII]: _Resource Aquisition Is Initialization_ é uma técnica de programação que vincula o ciclo de vida do recurso ao da estrutura \cite{cppreferenceraii}.

\lstinputlisting[language=C++, firstnumber=42, linerange={42-48}]{../../pd/inc/state.h}

## Comparador




# Programação dinâmica

Programação dinâmica é um método para a construção de algoritmos no qual há uma memorização de cada estado distinto para evitar recálculo, caso este estado apareça novamente. A memorização dos estados do jogo _Big Points_ foi feita em uma _hash_, com a chave sendo o estado do jogo e o valor armazenado, a pontuação máxima dos dois jogadores a partir daquele nó.

a melhor jogada para ganhar maximizar seus pontos. Caso não Na vez de cadaCaso a quantidade de jogos vencidos pelo primeiro jogador seja aproximadamente $50\%$

Para analizar o jogo, é preciso exaurir todas as jogadas possíveis a partir de um jogo inicial. Como 

utilizando programação dinâmica[^dynamic_programing]
onde os estados são armazenados em uma _hash_, temos que o número de estados distintos varia entre 17 e 25.

Devido ao imenso número de jogadas possíveis ao longo do do jogo, decidiu-se utilizar a programação dinâmica para 
- Duas funções para melhor entendimento da DP e regras do jogo

## Função \textbf{dp}

## Função \textbf{play}


- Explicação da DP e da função Play (função para realizar as jogadas)

# Verificação dos estados

Foi escrito os estados e suas transições em _post-it_s para garantir que a _DP_ foi feita corretamente. Os estados


<!--
Capítulo 4 - Resultados
-->
\chapter{Resultados}
\label{ch:resultados}

# Trabalhos futuros


<!--
Capítulo 5 - Conclusão
-->
\chapter{Conclusão}
\label{ch:conclusao}

# Trabalhos futuros
