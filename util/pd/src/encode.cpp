#include "encode.h"
#include <fstream>
#include <sstream>

#define MASK(x) ((1<<(x))-1)

using namespace std;

ll encode(struct State& st, struct Game& g)
{
	ofstream ofsEncode("encode.txt", ofstream::out);
	ofsEncode << "Encode" << endl;

	ll ll_st = 0;
	short shift = 0;

	ofsEncode << "estado_tabuleiro = " << st.estado_tabuleiro << endl;
	ll_st = ((ll) st.estado_tabuleiro & MASK(9)) << shift;
	shift += 9;

	ofsEncode << "\t(R,G,B)" << endl << "Peoes\t" << "(";
	for (short i = 0; i < g.num_cores; i++) {
		if (i) ofsEncode << ",";
		ofsEncode << st.peao[i];
		ll_st |= ((ll) st.peao[i] & MASK(3)) << shift;
		shift += 3;
	}
	ofsEncode << ")" << endl;

	// Escada
	ostringstream os;

	ofsEncode << "\t(R,G,B)" << endl << "Escada\t" << "(";
	for (short i = 0; i < g.num_cores; i++) {
		if (i) ofsEncode << ",";
		ofsEncode << st.escada[i];
		st.escada[i] ? os << st.escada[i] : os << '0';
	}
	ofsEncode << ")" << endl;

	short e = g.masks[os.str()];
	ofsEncode << "e = " << e << endl;
	ll_st |= ((ll) e & MASK(4)) << shift;
	shift += 4;

	ofsEncode << "\t(R,G,B)" << endl;
	for (short j = 0; j < g.num_jogadores; j++) {
		ofsEncode << "Player" << j << "\t(";
		for (short i = 0; i < g.num_cores; i++) {
			if (i) ofsEncode << ",";
			ofsEncode << st.jogadores[j][i];
			ll_st |= ((ll) st.jogadores[j][i] & MASK(3)) << shift;
			shift += 3;
		}
		ofsEncode << ")" << endl;
	}

	ofsEncode << "jogador_atual = " << st.jogador_atual << endl;
	ll_st |= ((ll) st.jogador_atual & MASK(1)) << shift;
	shift += 1;

	ofsEncode << "ll_st = " << ll_st << endl;
	ofsEncode.close();

	return ll_st;
}

void decode(ll ll_st, struct State& st, struct Game& g)
{
	ofstream ofsDecode("decode.txt", ofstream::out);

	ofsDecode << "Decode" << endl;

	st.estado_tabuleiro = ll_st & MASK(9);
	ll_st >>= 9;
	ofsDecode << "estado_tabuleiro = " << st.estado_tabuleiro << endl;

	ofsDecode << "\t(R,G,B)" << endl << "Peoes\t" << "(";
	for (short i = 0; i < g.num_cores; i++) {
		if (i) ofsDecode << ",";
		st.peao[i] = ll_st & MASK(3);
		ll_st >>= 3;
		ofsDecode << st.peao[i];
	}
	ofsDecode << ")" << endl;

	short e = ll_st & MASK(4);
	ll_st >>= 4;
	ofsDecode << "e = " << e << endl;

	ofsDecode << "\t(R,G,B)" << endl << "Escada\t" << "(";
	for (short i = 0; i < g.num_cores; i++) {
		if (i) ofsDecode << ",";
		st.escada[i] = g.ids[e][i] - '0';
		ofsDecode << st.escada[i];
	}
	ofsDecode << ")" << endl;

	ofsDecode << "\t(R,G,B)" << endl;
	for (short j = 0; j < g.num_jogadores; j++) {
		ofsDecode << "Player" << j << "\t(";
		for (short i = 0; i < g.num_cores; i++) {
			if (i) ofsDecode << ",";
			st.jogadores[j][i] = ll_st  & MASK(3);
			ll_st >>= 3;
			ofsDecode << st.jogadores[j][i];
		}
		ofsDecode << ")" << endl;
	}

	st.jogador_atual = ll_st & MASK(1);
	ll_st >>= 1;
	ofsDecode << "jogador_atual = " << st.jogador_atual << endl;

	ofsDecode << "ll_st = " << ll_st << endl;

	ofsDecode.close();

	return ;
}
