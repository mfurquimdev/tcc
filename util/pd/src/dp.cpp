#include "dp.h"
#include "encode.h"
#include "util.h"

inline int dp(struct Game& game, struct State& st)
{
	//ofsDp << "DP" << endl;
	//ofsDp << endl << endl << st << endl;
	normalize_tabuleiro(st);
	short max_score = 0;

	// Todos os peões na escada
