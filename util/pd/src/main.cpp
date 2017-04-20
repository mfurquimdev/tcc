// #include "encode.h"
// #include "dp.h"
#include <iostream>
#include "state.h"
// #include "util.h"
#include "game.h"

using ll = long long;
using namespace std;

// Fazer map de ll pro valor da pontuação máxima
// map<ll,int> g_dp_st;

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

   	//ofstream ofsStair("stair.txt", ofstream::out);
   	//ofsStair << "Stair_states {" << endl;
   	//for (unsigned int i = 0; i < g_ids.size(); i++) {
   	//	ofsStair << "\t" << i << "->" << g_ids[i] << endl;
   	//}
   	//ofsStair << "}" << endl;
   	//ofsStair.close();

	// st.escada[0] = 1;
	// st.escada[1] = 2;
	// st.escada[2] = 3;

	// st.peao[0] = 1;
	// st.peao[1] = 0;
	// st.peao[2] = 0;

	// st.jogadores[0][0] = 0;
	// st.jogadores[0][1] = 1;
	// st.jogadores[0][2] = 2;

	// st.jogadores[1][0] = 3;
	// st.jogadores[1][1] = 0;
	// st.jogadores[1][2] = 1;

	// ll ll_st = encode(st);
	//
	// decode(ll_st, st);

   //	cerr << "BEGIN" << endl;
   // 	clock_t start, end;
   // 	start = clock();
   // 	dp(game, st);
   // 	end = clock();
   //
   // //	cerr << "END" << endl;
   //
   // 	ofsDp << endl << "MAP (" << g_dp_st.size() << ")"  << endl;
   // 	for (auto s: g_dp_st) {
   // 		ofsDp << s.first << " -> " << s.second << endl;
   // 	}
   //
   // 	ofsDp.close();
   //
   // 	cout << g_dp_st.size() << " " << (((float)(end - start))/CLOCKS_PER_SEC) << endl;

   	return 0;
}
