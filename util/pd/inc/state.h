#ifndef __STATE_H__
#define __STATE_H__

#include <vector>

using namespace std;

struct State
{
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

	friend ostream& operator<<(ostream& out, const struct State& state)
	{
		short num_cores = 3;
		short num_jogadores = 2;

		out << endl;
		out << "Estado" << endl;
		out << "Tabuleiro: " << state.estado_tabuleiro << endl;

		out << "Peões: (";
		for (short c = 0; c < num_cores; c++) {
			if (c) out << ",";
			out << state.peao[c];
		}
		out << ")" << endl;

		out << "Escada: (";
		for (short c = 0; c < num_cores; c++) {
			if (c) out << ",";
			out << state.escada[c];
		}
		out << ")" << endl;

		out << "Jogadores: [";
		for (short j = 0; j < num_jogadores; j++) {
			if (j) out << ", ";
			out << j << ":(";
			for (short c = 0; c < num_cores; c++) {
				if (c) out << ",";
				out << state.jogadores[j][c];
			}
			out << ")";
		}
		out << "]" << endl;

		out << "Atual: " << state.jogador_atual << endl;

		out << endl;

		return out;
	};
};

#endif
