#include <bitset>
#include <iostream>
#include <vector>

#include "dp.h"
#include "game.h"
#include "turn.h"

using namespace std;
using ii = pair<int, int>;
using game_res = pair<bool, ii>;

game_res play(map<struct State,ii>& dp_states, struct Game game, struct State state, struct Turn turn)
{
	short player = turn.current_player;
	short pawn = turn.pawn_to_move;
	bool pick_right = turn.pick_right;
	short prev_pos = state.peao(pawn);

	// Cannot move pawn, it's already on the stair
	if (state.escada(pawn) != 0) {
		// cout << "Can't move. Pawn already on the stair" << endl;
		return game_res(false, ii(-1,-1));
	}

	// Remove discs from the board according to tabuleiro
	for (size_t i = 0; i < game.board.size(); i++) {
		if (state.tabuleiro(i) == 0) {
			game.board[i] = '0';
		}
	}

	// Moving Pawn
	bool available = false;
	bool in_range = false;
	do {
		if (state.peao(pawn) <= game.num_discos) {
			state.movepeao(pawn);
		}
		in_range = state.peao(pawn) <= game.num_discos;
		if (in_range) {
			available = game.board[game.color_index[pawn][state.peao(pawn)-1]] != '0';
		}
	} while (!available && in_range);

	// Step in the stair
	if (!in_range) {
		if (state.escada(pawn) == 0) {
			state.setescada(pawn, max_in_escada(game, state)+1);
			state.updatejogador(player, pawn);
			state.updateatual();
		}
	}

	// Update board: Discs under pawns are unavailable
	for (int color = 0; color < game.num_cores; color++) {
		// If pawn is in board
		if (state.peao(color) != 0 and state.peao(color) <= game.num_discos) {
			// Removing disc under pawns' current position
			game.board[game.color_index[color][state.peao(color)-1]] = '0';
		}
	}
	
	// If pawn is in board and was on the board before moving
	if (state.peao(pawn)-1 > 0 and prev_pos > 0) {
		// Replacing disc under pawn's previous position
		game.board[game.color_index[pawn][prev_pos-1]] = '1' + pawn;
	}

	// Pick a disc if the pawn has moved within the range of the board
	bool pick = false;
	if (in_range) {
		short pawn_pos = state.peao(pawn)-1;
		short disc_pos = -1;

		for (short i = 1;; i++) {
			// Pick right
			if (pick_right) {
				disc_pos = game.color_index[pawn][pawn_pos]+i;

				// Does not pick right (out of board)
				if (disc_pos >= (short) game.board.size()) {
					return game_res(false, ii(-1,-1));
				}
			}
			// Pick left
			else {
				disc_pos = game.color_index[pawn][pawn_pos]-i;

				// Does not pick left (out of board)
				if (disc_pos < 0) {
					return game_res(false, ii(-1,-1));
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
			state.settabuleiro(disc_pos, 0);

			// Add it to the player's hand
			state.updatejogador(player, pick_char-'1');

			// Calculate next player
			state.updateatual();
		}
	}

	auto max_score = dp(dp_states, game, state);

	return game_res(true, max_score);
}

ii dp(map<struct State,ii>& dp_states, struct Game game, struct State state)
{
	// If all pawns are in the stair
	if (is_pawns_stair(game, state)) {
		return calculate_score(game, state);
	}

	auto it = dp_states.find(state);
	if (it != dp_states.end()) {
		return dp_states[state];
	}

	vector<ii> results;
	for (short pawn = 0; pawn < game.num_cores; pawn++) {
		struct Turn right(state.atual(), pawn, true);
		struct Turn left(state.atual(), pawn, false);

		// DP após jogadas
		game_res result = play(dp_states, game, state, left);
		if (result.first) {
			results.push_back(result.second);
		}

		result = play(dp_states, game, state, right);
		if (result.first) {
			results.push_back(result.second);
		}
	}

	auto p1_order = [](const ii& a, const ii& b){
		if (a.first > a.second) {
			if (b.first > b.second) {
				return a.first > b.first ? true : false;
			}
			else {
				return true;
			}
		}
		else if (a.first == a.second) {
			if (b.first > b.second) {
				return false;
			}
			else if (b.first == b.second) {
				return a.first > b.first ? true : false;
			}
			else {
				return true;
			}
		}
		else {
			if (b.first >= b.second) {
				return false;
			}
			else {
				return a.second < b.second ? true : false;
			}
		}
	};

	auto p2_order = [](const ii& a, const ii& b){
		if (a.second > a.first) {
			if (b.second > b.first) {
				return a.second > b.second ? true : false;
			}
			else {
				return true;
			}
		}
		else if (a.second == a.first) {
			if (b.second > b.first) {
				return false;
			}
			else if (b.second == b.first) {
				return a.second > b.second ? true : false;
			}
			else {
				return true;
			}
		}
		else {
			if (b.second >= b.first) {
				return false;
			}
			else {
				return a.first < b.first ? true : false;
			}
		}
	};


	if (state.atual() == 0) {
		sort(results.begin(), results.end(), p1_order);
	}
	else {
		sort(results.begin(), results.end(), p2_order);
	}

	dp_states[state] = results.size() == 0 ? ii(-1, -1) : results.front();

	return dp_states[state];
}

bool is_pawns_stair(struct Game& game, struct State& state)
{
	for (int i = 0; i < game.num_cores; i++) {
		if (state.escada(i) == 0) {
			return false;
		}
	}

	return true;
}

ii calculate_score(struct Game& game, struct State& state)
{
	vector<short> score(game.num_jogadores, 0);
	for (int j = 0; j < game.num_jogadores; j++) {
		for (int disc = 0; disc < game.num_cores; disc++) {
			if (state.escada(disc) != 0) {
				score[j] += state.jogador(j,disc)*(game.num_cores - state.escada(disc));
			}
		}
	}

	return ii(score[0],score[1]);
}

short max_in_escada(struct Game& game, struct State& state)
{
	short highest = 0;

	for (size_t i = 0; i < game.num_cores; i++) {
		highest = max(highest, (short) state.escada(i));
	}

	return highest;
}

//void print_game(ostream& out, struct Game game, struct State& state)
//{
//	out << state.jogador_atual+1 << " - ";
//	if (state.peao[0] && state.peao[0] <= game.num_discos) {
//		game.board[game.color_index[0][state.peao[0]-1]] = 'R';
//	}
//	if (state.peao[1] && state.peao[1] <= game.num_discos) {
//		game.board[game.color_index[1][state.peao[1]-1]] = 'G';
//	}
//	out << game.board << "  (";
//	for (short c = 0; c < game.num_cores; c++) {
//		if (c) out << ",";
//		out << state.escada[c];
//	}
//	out << ")  ";
//	for (short j = 0; j < game.num_jogadores; j++) {
//		if (j) out << "  ";
//		out << j+1 << ": ";
//		for (short c = 0; c < game.num_cores; c++) {
//			if (c) out << ",";
//			out << state.jogadores[j][c];
//		}
//	}
//
//	return;
//}
