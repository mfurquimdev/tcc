#include "dp.h"
#include "encode.h"
#include <iostream>

short dp(struct Game& game, struct State& state)
{
	short max_score = 0;

	if (is_pawns_stair(game, state)) {
		max_score = max_of_array(calculate_score(game, state));
		return max_score;
	}

	ll st = encode(state, game);
	auto it = game.dp_states.find(st);
	if (it != game.dp_states.end()) {
		return game.dp_states[st];
	}

	normalize_tabuleiro(state);
	update_board(game, state);
	for (short pawn = 0; pawn < game.num_cores; pawn++) {
		move_pawn(game, state, pawn);
		update_board(game, state);
		max_score = max(pick_right(game, state, pawn), pick_left(game, state, pawn));
	}

	return max_score;
}
