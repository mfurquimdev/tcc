 <p align=center>**_Big Points_<br>
Uma Análise Baseada na Teoria dos Jogos** </p>

Aluno: Mateus Medeiros Furquim Mendonça  
Orientador: Edson Alves da Costa Junior  
Co-orientador: Nilton Correia da Silva

# Resumo
A Teoria dos Jogos estuda as melhores estratégias dos jogadores em um
 determinado jogo. Aplicando suas teorias em um jogo de tabuleiro eletrônico,
 este trabalho propõe analisar o jogo _Big Points_ a partir de um determinado
 estado da partida e, como resultado, identificar as melhores heurísticas para
 os jogadores e uma possível inteligência artificial.

# Introdução
\label{sec:introducao}

- Motivação
- Contextualização
- Objetivo
	- Principal
	- Secundários
- Estrutura do trabalho

Por alguns anos a teoria dos jogos vem estudando o comportamento de indivíduos
 sob uma situação de conflito, como em jogos, balança de poder, leilões, e até
 mesmo evolução genética\cite{sartini_IIbienaldasbm}. Esta área possui duas
 frentes de estudo: (a) _teoria econômica dos jogos_, o qual possui motivações
 predominante econômicas, e (b) _teoria combinatória dos jogos_, que faz uso dos
 aspectos combinatórios de jogos de mesa e não permite elementos imprevisíveis.

Este trabalho faz uso de ambas abordagens, sendo que, a partir da primeira
 abordagem, é estabelecido um método para se maximizar o ganho (_payoff_) e, a
 partir da segunda, um método para identificar uma jogada que garantirá a
 vitória independente do resto do jogo.

O restante deste trabalho está organizado da seguinte maneira: Na seção
 \ref{sec:fundamentacao_teorica} é ~narrado~ uma breve história da teoria dos
 jogos e seus conceitos fundamentais, além de conter explicação para os temas
 de análise de complexidade, análise combinatória e programação dinâmica, e
 explicação das regras do jogo _Big Points_. A seção seguinte lista os
 equipamentos, _softwares_ e metodologia utilizados para o desenvolvimento do
 trabalho e, também, a maneira que a foi analisado o jogo. Os resultados, até o
 momento, são descritos na seção \ref{sec:resultados_parciais}, o cronograma de
 trabalho na seção \ref{sec:cronograma}, e as considerações finais na seção
 \ref{sec:consideracoes_finais}.


# Fundamentação Teórica
\label{sec:fundamentacao_teorica}

- Histórico da Teoria dos Jogos
- Conceitos Fundamentais da Teoria dos Jogos
- análise de complexidade
- análise combinátoria
- programação dinâmica
- _Big Points_

## Histórico da Teoria dos Jogos

Pode-se dizer que a análise de jogos é praticada desde o séculco XVIII tendo
 como evidência o trabalho de James Waldergrave ao analisar um jogo de cartas
 chamado _Le Her_\cite{Prague_severalmilestones}. No século seguinte, Augustin
 Cournot fez uso da teoria dos jogos para estudos relacionados à política
 \cite{cournot_1838}. Mais recentemente, em 1913, Ernst Zermelo publica o
 primeiro teorema matemático da teoria dos jogos \cite{zermelo_1913}.

Dois outros grandes matemáticos que se interessaram na teoria dos jogos foram
 Émile Borel e John von Neumann. Nas décadas de 1920 e 1930, Emile Borel
 publicou três artigos \cite{borel_1921} \cite{borel_1924} \cite{borel_1927} e
 um livro \cite{borel_1938} sobre jogos estratégicos, introduzindo uma noção
 abstrada sobre jogo estratégico e estratégia mista. Em 1928, John von Neumann
 demonstrou que todo jogo finito de soma zero\footnote{Um jogo soma zero é um
 jogo no qual a vitória de um jogador implica na derrota do outro.} com duas
 pessoas possui uma solução em estratégias mistas [18]. Em 1937, Neumann
 forneceu uma nova demonstração baseada em outro teorema (teorema do ponto fixo
 de Brouwer). Em 1944, Neumann publicou um trabalho, junto a Oscar Morgenstern
 [19], e com isso, a teoria dos jogos entrou na área da economia e matemática
 aplicada.

Outro matemático que contribuiu para a área foi John Forbes Nash Júnior, quea publicou quatro artigos importantes para teoria dos jogos não-cooperativos. Dois destes artigos [13, 16] provando a existência de um equilíbrio de estratégias mistas para jogos não-cooperativos, denominado **equilíbrio de Nash**, que será explicado na seção \ref{subsec:solucoes-de-um-jogo}. Nash recebeu o prêmio Nobel em 1994, junto com John Harsanyi e Reinhard Selten, por suas contribuições para a teoria dos jogos.



# Metodologia
\label{sec:metodologia}

- Listar os equipamentos e softwares utilizados
- Metodologia de desenvolvimento de software utilizada


- O jogo eletrônico está sendo implementado
- Foi feito uma análise para descobrir a possibilidade de computar a melhor
 jogada possível para um ou vários jogos. Nesta análise, levou-se em
 consideração:
	- A quantidade de memória necessária
	- O número de estados existentes
	- A complexidade assintótica do algoritmo (pois o número de entrada pro
 algorítimo é muito grande)
	- O tempo de processamento para um determinado número de estados

# Resultados Parciais
\label{sec:resultados_parciais}

# Cronograma
\label{sec:cronograma}

1/2016 Estudos de análise combinatória, programação dinâmica
Produto: simulador contando todos os estados de uma partida reduzida
2/2016 Intervalo para estudo e desenvolvimento.
1/2017

# Considerações Finais
\label{sec:consideracoes_finais}
