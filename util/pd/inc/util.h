#ifndef __UTIL_H__
#define __UTIL_H__

#include "game.h"
#include "state.h"
#include <string>

void step_in(struct State&, int);
void update_board(struct Game&, struct State&);
void pick_right(struct Game&, struct State&, int);
void pick_left(struct Game&, struct State&, int);
void normalize_tabuleiro(struct State&);
void move_pawn(struct Game&, struct State&, int);
bool is_pawns_stair(struct Game&, struct State&);
vector<short> calculate_score(struct Game&, struct State&);
short max_of_array(const vector<short>&);

#endif
