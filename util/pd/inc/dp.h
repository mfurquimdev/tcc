#ifndef __DP_H__
#define __DP_H__

#include "game.h"
#include "state.h"
#include "turn.h"
#include <string>


short play(map<ll,int>&, struct Game, struct State, struct Turn);
void print_game(ostream& out, struct Game&, struct State&);
// void step_in(struct Game&, struct State&, int);
void update_board(struct Game&, struct State&);
// short pick_right(map<ll,int>&, struct Game&, struct State&, int);
// short pick_left(map<ll,int>&, struct Game&, struct State&, int);
// void normalize_tabuleiro(struct State&);
// void move_pawn(struct Game&, struct State&, int);
bool is_pawns_stair(struct Game&, struct State&);
vector<short> calculate_score(struct Game&, struct State&);
short max_of_array(const vector<short>&);

short dp(map<ll,int>&, struct Game&, struct State&);

#endif
