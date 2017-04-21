#include "dp.h"
#include <iostream>
#include "state.h"
#include "game.h"
#include "encode.h"

using ll = long long;
using namespace std;

int main()
{
	short num_cores = 3;
	short num_discos = 3;
	short num_jogadores = 2;

	cout << "Big Points" << endl;

	cout << endl;

	struct Game game(num_discos, num_cores, num_jogadores);

	cout << "#Discos: " << game.num_discos << endl;
	cout << "#Cores: " << game.num_cores << endl;
	cout << "#Jogadores: " << game.num_jogadores << endl;
	cout << "Board: " << game.board << endl;
	cout << "Index" << endl;
	for (short c = 0; c < game.num_cores; c++) {
		cout << c+1 << ":(";
		for (short d = 0; d < game.num_discos; d++) {
			if (d) cout << ",";
			cout << game.color_index[c][d];
		}
		cout << ")" << endl;
	}

	cout << endl;

	struct State state(num_discos, num_cores, num_jogadores);

	cout << "Tabuleiro: " << state.estado_tabuleiro << endl;

	cout << "Peões: (";
	for (short c = 0; c < num_cores; c++) {
		if (c) cout <<",";
		cout << state.peao[c];
	}
	cout << ")" << endl;

	cout << "Escada: (";
	for (short c = 0; c < num_cores; c++) {
		if (c) cout <<",";
		cout << state.escada[c];
	}
	cout << ")" << endl;

	cout << "Jogadores: [";
	for (short j = 0; j < num_jogadores; j++) {
		if (j) cout << ", ";
		cout << j << ":(";
		for (short c = 0; c < num_cores; c++) {
			if (c) cout << ",";
			cout << state.jogadores[j][c];
		}
		cout << ")";
	}
	cout << "]" << endl;

	cout << "Atual: " << state.jogador_atual << endl;

	cout << endl;

	// decode(encode(state, game), state, game);

   	clock_t start, end;
   	start = clock();
   	dp(game, state);
   	end = clock();

   	cout << "MAP (" << game.dp_states.size() << ")"  << endl;
   	for (auto s: game.dp_states) {
   		cout << s.first << " -> " << s.second << endl;
   	}

   	cout << game.dp_states.size() << " " << (((float)(end - start))/CLOCKS_PER_SEC) << endl;

   	return 0;
}
