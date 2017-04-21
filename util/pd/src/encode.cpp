#include "encode.h"
#include <fstream>
#include <sstream>

#define MASK(x) ((1<<(x))-1)

using namespace std;

ll encode(struct State& st, struct Game& g)
{
	ll ll_st = 0;
	short shift = 0;

	ll_st = ((ll) st.estado_tabuleiro & MASK(9)) << shift;
	shift += 9;

	for (short i = 0; i < g.num_cores; i++) {
		ll_st |= ((ll) st.peao[i] & MASK(3)) << shift;
		shift += 3;
	}

	// Escada
	ostringstream os;

	for (short i = 0; i < g.num_cores; i++) {
		st.escada[i] ? os << st.escada[i] : os << '0';
	}

	short e = g.masks[os.str()];
	ll_st |= ((ll) e & MASK(4)) << shift;
	shift += 4;

	for (short j = 0; j < g.num_jogadores; j++) {
		for (short i = 0; i < g.num_cores; i++) {
			ll_st |= ((ll) st.jogadores[j][i] & MASK(3)) << shift;
			shift += 3;
		}
	}

	ll_st |= ((ll) st.jogador_atual & MASK(1)) << shift;
	shift += 1;

	return ll_st;
}

void decode(ll ll_st, struct State& st, struct Game& g)
{
	st.estado_tabuleiro = ll_st & MASK(9);
	ll_st >>= 9;

	for (short i = 0; i < g.num_cores; i++) {
		st.peao[i] = ll_st & MASK(3);
		ll_st >>= 3;
	}

	short e = ll_st & MASK(4);
	ll_st >>= 4;

	for (short i = 0; i < g.num_cores; i++) {
		st.escada[i] = g.ids[e][i] - '0';
	}

	for (short j = 0; j < g.num_jogadores; j++) {
		for (short i = 0; i < g.num_cores; i++) {
			st.jogadores[j][i] = ll_st  & MASK(3);
			ll_st >>= 3;
		}
	}

	st.jogador_atual = ll_st & MASK(1);
	ll_st >>= 1;

	return ;
}
