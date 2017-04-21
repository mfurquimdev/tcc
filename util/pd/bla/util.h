#ifndef __UTIL_H__
#define __UTIL_H__

#include "game.h"
#include "state.h"
#include <string>

inline void step_in(struct State&, int);
inline void update_board(string&, struct State&);
inline void pick_right(string& , struct Game&, struct State&, int);
inline short pick_left(string& board, struct Game&, struct State&, int);
inline void normalize_tabuleiro(struct State&);
inline void move_pawn(string&, struct Game&, struct State&, int);
inline bool is_pawns_stair(struct Game&, struct State&);
inline vector<short> calculate_score(struct Game&, struct State&);
inline int max_of_array(const vector<short>&);

#endif
