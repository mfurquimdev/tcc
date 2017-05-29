#ifndef __DP_H__
#define __DP_H__

#include "game.h"
#include "state.h"
#include "turn.h"
#include <string>

using ii = pair<int, int>;
using game_res = pair<bool, ii>;

ii dp(map<struct State, ii>&, struct Game, struct State);
game_res play(map<struct State, ii>&, struct Game, struct State, struct Turn);

bool is_pawns_stair(struct Game&, struct State&);
short max_in_escada(struct Game&, struct State&);
void print_game(ostream& out, struct Game, struct State&);
ii calculate_score(struct Game&, struct State&);

#endif
