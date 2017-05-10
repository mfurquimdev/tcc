#ifndef __DP_H__
#define __DP_H__

#include "game.h"
#include "state.h"
#include "turn.h"
#include <string>

using ii = pair<int, int>;
using game_res = pair<bool, ii>;

ii dp(map<ll,ii>&, struct Game, struct State);
game_res play(map<ll,ii>&, struct Game, struct State, struct Turn);

bool is_pawns_stair(struct Game&, struct State&);
short max_of_array(const vector<short>&);
void print_game(ostream& out, struct Game, struct State&);
void update_board(struct Game&, struct State&);
ii calculate_score(struct Game&, struct State&);

#endif
