#include "encode.h"
#include <fstream>
#include <sstream>
#include <cmath>

#define MASK(x) ((1<<(x))-1)

using namespace std;

ll encode(struct State& st, struct Game& g)
{
	ll ll_st = 0;
	short shift = 0;
	int field_size = 0;

	field_size = g.num_cores*g.num_discos;
	ll_st = ((ll) st.estado_tabuleiro & MASK(field_size)) << shift;
	shift += field_size;
	if (shift >= 64) {
		cerr << "Estourou a variável de 64 bits." << endl;
	}

	field_size = (int) ((log(g.num_discos+2)/log(2))+1);
	for (short i = 0; i < g.num_cores; i++) {
		ll_st |= ((ll) st.peao[i] & MASK(field_size)) << shift;
		shift += field_size;
		if (shift >= 64) {
			cerr << "Estourou a variável de 64 bits." << endl;
		}
	}

	// Escada
	ostringstream os;

	for (short i = 0; i < g.num_cores; i++) {
		st.escada[i] ? os << st.escada[i] : os << '0';
	}

	short e = g.masks[os.str()];
	field_size = (int) ((log(g.num_cores+2)/log(2))+1);

	ll_st |= ((ll) e & MASK(field_size)) << shift;
	shift += field_size;
	if (shift >= 64) {
		cerr << "Estourou a variável de 64 bits." << endl;
	}

	field_size = (int) ((log(g.num_discos+2)/log(2))+1);
	for (short j = 0; j < g.num_jogadores; j++) {
		for (short i = 0; i < g.num_cores; i++) {
			ll_st |= ((ll) st.jogadores[j][i] & MASK(field_size)) << shift;
			shift += field_size;
			if (shift >= 64) {
				cerr << "Estourou a variável de 64 bits." << endl;
			}
		}
	}

	ll_st |= ((ll) st.jogador_atual & MASK(1)) << shift;
	shift += 1;
	if (shift >= 64) {
		cerr << "Estourou a variável de 64 bits." << endl;
	}

	return ll_st;
}

void decode(ll ll_st, struct State& st, struct Game& g)
{
	int field_size = g.num_cores*g.num_discos;
	st.estado_tabuleiro = ll_st & MASK(field_size);
	ll_st >>= field_size;

	field_size = (int) ((log(g.num_discos+2)/log(2))+1);
	for (short i = 0; i < g.num_cores; i++) {
		st.peao[i] = ll_st & MASK(field_size);
		ll_st >>= field_size;
	}

	field_size = (int) ((log(g.num_cores+2)/log(2))+1);
	short e = ll_st & MASK(field_size);
	ll_st >>= field_size;

	for (short i = 0; i < g.num_cores; i++) {
		st.escada[i] = g.ids[e][i] - '0';
	}

	field_size = (int) ((log(g.num_discos+2)/log(2))+1);
	for (short j = 0; j < g.num_jogadores; j++) {
		for (short i = 0; i < g.num_cores; i++) {
			st.jogadores[j][i] = ll_st  & MASK(field_size);
			ll_st >>= field_size;
		}
	}

	st.jogador_atual = ll_st & MASK(1);
	ll_st >>= 1;

	return ;
}
