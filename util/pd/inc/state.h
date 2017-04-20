#ifndef __STATE_H__
#define __STATE_H__

#include <vector>

using namespace std;

struct State{
	short estado_tabuleiro;
	vector<short> peao;
	vector<short> escada;
	vector<vector<short> > jogadores;
	short jogador_atual;

	State(short num_discos, short num_cores, short num_jogadores)
	{
		// Estado inicial do tabuleiro: todos os discos disponíveis
		estado_tabuleiro = ((1<<(num_discos*num_cores))-1);

		// Estado inicial dos peões: todos no começo do tabuleiro
		for (short i = 0; i < num_cores; i++) {
			peao.push_back(0);
		}

		// Estado inicial da escada: todas as posições vazias.
		for (short i = 0; i < num_cores; i++) {
			escada.push_back(0);
		}

		// Estado inicial dos jogadores: mãos vazias
		for (short j = 0; j < num_jogadores; j++) {
			vector<short> jogador(num_cores, 0);
			jogadores.push_back(jogador);
		}

		// Estado do jogador atual: primeiro jogador
		jogador_atual = 0;
	};
};

#endif
