#ifndef __STATE_H__
#define __STATE_H__

struct State{
	short estado_tabuleiro;
	vector<short> peao;
	vector<short> escada;
	vector<vector<short> > jogadores;
	short jogador_atual;

	State(short num_discos, short num_cores, short num_jogadores) {
		// Estado inicial do tabuleiro: todos os discos disponíveis
		estado_tabuleiro = ((1<<(num_discos*num_cores))-1);

		// Estado inicial dos peões:

	}
};

#endif
