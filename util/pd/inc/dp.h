#ifndef __DP_H__
#define __DP_H__

#include "game.h"
#include "state.h"
#include "turn.h"
#include <string>

short dp(map<ll,int>&, struct Game, struct State);
short play(map<ll,int>&, struct Game, struct State, struct Turn);

bool is_pawns_stair(struct Game&, struct State&);
short max_of_array(const vector<short>&);
void print_game(ostream& out, struct Game&, struct State&);
void update_board(struct Game&, struct State&);
vector<short> calculate_score(struct Game&, struct State&);

#endif
