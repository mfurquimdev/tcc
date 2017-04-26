#include <bitset>
#include <iostream>

#include "encode.h"
#include "dp.h"
#include "game.h"
#include "turn.h"

using namespace std;

short play(map<ll,int>& dp_states, struct Game game, struct State state, struct Turn turn)
{
	short max_score = 0;

	short player = turn.current_player;
	short pawn = turn.pawn_to_move;
	bool pick_right = turn.pick_right;

	if (state.escada[pawn]) {
		max_score = max_of_array(calculate_score(game, state));
		return max_score;
	}

	// Remove discs from game.board according to state.tabuleiro
	update_board(game, state);

	// Moving Pawn
	bool available = false;
	bool in_range = false;
	do {
		if (state.peao[pawn] <= game.num_discos) {
			state.peao[pawn]++;
		}
		in_range = state.peao[pawn] <= game.num_discos;
		if (in_range) {
			available = game.board[game.color_index[pawn][state.peao[pawn]-1]] != '0';
		}
	} while (!available && in_range);

	// Step in the stair
	if (!in_range) {
		if (!state.escada[pawn]) {
			state.escada[pawn] = max_of_array(state.escada)+1;
			state.jogadores[player][pawn]++;
			state.jogador_atual = (player+1)%game.num_jogadores;
			game.board[game.color_index[pawn][state.peao[pawn]-2]] = '1' + pawn;
		}
		else {
			max_score = max_of_array(calculate_score(game, state));
			return max_score;
		}
	}
	// Move pawn in board
	else {
		for (int pawn = 0; pawn < game.num_cores; pawn++) {
			if (state.peao[pawn] && state.peao[pawn] < game.num_discos + 1) {
				int pawn_pos = state.peao[pawn]-1;
				game.board[game.color_index[pawn][pawn_pos]] = '0';

				if (pawn_pos > 0) {
					game.board[game.color_index[pawn][pawn_pos-1]] = '1' + pawn;
				}
			}
		}
	}

	// Remove disc from game.board according to state.peao
	update_board(game, state);

	// Pick a disc if the pawn has moved within the range of the board
	if (in_range) {
		short pawn_pos = state.peao[pawn]-1;
		bool pick = false;
		short disc_pos = -1;

		for (short i = 1;; i++) {
			// Pick right
			if (pick_right) {
				disc_pos = game.color_index[pawn][pawn_pos]+i;

				// Does not pick right (out of board)
				if (disc_pos >= (short) game.board.size()) {
					max_score = max_of_array(calculate_score(game, state));
					return max_score;
					break;
				}
			}
			// Pick left
			else {
				disc_pos = game.color_index[pawn][pawn_pos]-i;

				// Does not pick left (out of board)
				if (disc_pos < 0) {
					max_score = max_of_array(calculate_score(game, state));
					return max_score;
					break;
				}
			}

			// Does not pick if disc is 0, try again
			if (game.board[disc_pos] == '0') {
				continue;
			}

			// There is a disc to be picked
			pick = true;
			break;
		}

		// If There is a disc to be picked
		if (pick) {
			char pick_char = -1;

			// Disc's char to pick
			pick_char = game.board[disc_pos];

			// Remove it from the board
			state.estado_tabuleiro &= ~((1<<(game.board.size()-1))>>(disc_pos));

			// Add it to the player's hand
			state.jogadores[player][pick_char-'0'-1]++;

			// Calculate next player
			state.jogador_atual = (state.jogador_atual+1)%game.num_jogadores;
		}
	} // end if (in_range)

	update_board(game, state);

	max_score = dp(dp_states, game, state);

	return max_score;
}

short dp(map<ll,int>& dp_states, struct Game& game, struct State& state)
{
	short max_score = 0;

	// If all pawns are in the stair
	if (is_pawns_stair(game, state)) {
		// Calculate the max score
		max_score = max_of_array(calculate_score(game, state));

		ll st = encode(state, game);
		auto it = dp_states.find(st);
		if (it != dp_states.end()) {
			short score = dp_states[st];
			if (max_score < score) {
				max_score = score;
			}
			else {
				dp_states[st] = max_score;
			}
		}

		return max_score;
	}

	ll st = encode(state, game);
	auto it = dp_states.find(st);
	if (it != dp_states.end()) {
		max_score = dp_states[st];
		return max_score;
	}

	for (short pawn = 0; pawn < game.num_cores; pawn++) {
		struct Turn right(state.jogador_atual, pawn, true);
		struct Turn left(state.jogador_atual, pawn, false);

		max_score = max(
			play(dp_states, game, state, right),
			play(dp_states, game, state, left));

	}

	dp_states[st] = max_score;

	return max_score;
}

void update_board(struct Game& game, struct State& state)
{
	unsigned short estado_tabuleiro = state.estado_tabuleiro;

	int tab_mask = 1<<(game.board.size()-1);
	for (size_t i = 0; i < game.board.size(); i++) {
		if ((estado_tabuleiro & tab_mask) == 0) {
			game.board[i] = '0';
		}
		estado_tabuleiro <<= 1;
	}

	return ;
}

bool is_pawns_stair(struct Game& game, struct State& state)
{
	bool pawns_stair = true;

	for (int i = 0; i < game.num_cores; i++) {
		if (state.escada[i] == 0) {
			pawns_stair = false;
			break;
		}
	}

	return pawns_stair;
}

vector<short> calculate_score(struct Game& game, struct State& state)
{
	vector<short> score(game.num_jogadores, 0);
	for (int j = 0; j < game.num_jogadores; j++) {
		for (int disc = 0; disc < game.num_cores; disc++) {
			if (state.escada[disc]) {
				score[j] += state.jogadores[j][disc]*(game.num_cores - state.escada[disc]);
			}
		}
	}

	return score;
}

short max_of_array(const vector<short>& scores)
{
	short highest = 0;

	for (size_t i = 0; i < scores.size(); i++) {
		highest = max(highest, scores[i]);
	}

	return highest;
}

void print_game(ostream& out, struct Game& game, struct State& state)
{
	bitset<6> bit_st_tabuleiro(state.estado_tabuleiro);
	out << endl << "    " << bit_st_tabuleiro << endl;
	out << state.jogador_atual+1 << " - ";
	out << game.board << "  (";
	for (short c = 0; c < game.num_cores; c++) {
		if (c) out << ",";
		out << state.escada[c];
	}
	out << ")  ";
	for (short j = 0; j < game.num_jogadores; j++) {
		if (j) out << "  ";
		out << j+1 << ": ";
		for (short c = 0; c < game.num_cores; c++) {
			if (c) out << ",";
			out << state.jogadores[j][c];
		}
	}

	out << endl;

	return;
}
