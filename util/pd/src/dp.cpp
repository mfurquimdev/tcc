#include <bitset>
#include <iostream>
#include <vector>

#include "encode.h"
#include "dp.h"
#include "game.h"
#include "turn.h"

using namespace std;
using ii = pair<int, int>;
using game_res = pair<bool, ii>;

game_res play(map<ll,ii>& dp_states, struct Game game, struct State state, struct Turn turn)
{
	ll st = encode(state, game);
	auto it = dp_states.find(st);
	if (it != dp_states.end()) {
		return game_res(true, dp_states[st]);
	}

	cout << turn << endl;
	update_board(game, state);
	print_game(cout, game, state);
	cout << endl;

	short player = turn.current_player;
	short pawn = turn.pawn_to_move;
	bool pick_right = turn.pick_right;
	short prev_pos = state.peao[pawn];

	// Cannot move pawn, it's already on the stair
	if (state.escada[pawn]) {
		cout << "Can't move. Pawn already on the stair" << endl;
		return game_res(false, ii(-1,-1));
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
			cout << "Stepping in the stair" << endl;
			state.escada[pawn] = max_of_array(state.escada)+1;
			state.jogadores[player][pawn]++;
			state.jogador_atual = (player+1)%game.num_jogadores;
		}
	}
	// Move pawn in board
	else {
		for (int pawn = 0; pawn < game.num_cores; pawn++) {
			if (state.peao[pawn] && state.peao[pawn] < game.num_discos + 1) {
				// Replacing next disc under pawn's current position
				short pawn_pos = state.peao[pawn]-1;
				game.board[game.color_index[pawn][pawn_pos]] = '0';
			}
		}
	}
	// Replacing disc under pawn's previous position
	short pawn_pos = state.peao[pawn]-1;
	if (pawn_pos > 0 && prev_pos > 0) {
		game.board[game.color_index[pawn][prev_pos-1]] = '1' + pawn;
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
					cout << "Does not pick right" << endl;
					return game_res(false, ii(-1,-1));
				}
			}
			// Pick left
			else {
				disc_pos = game.color_index[pawn][pawn_pos]-i;

				// Does not pick left (out of board)
				if (disc_pos < 0) {
					cout << "Does not pick left" << endl;
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
			state.estado_tabuleiro &= ~((1<<(game.board.size()-1))>>(disc_pos));

			// Add it to the player's hand
			state.jogadores[player][pick_char-'0'-1]++;

			// Calculate next player
			state.jogador_atual = (state.jogador_atual+1)%game.num_jogadores;
		}
	} // end "Pick a disc if the pawn has moved within the range of the board"

	update_board(game, state);
	print_game(cout, game, state);
	cout << endl;

	auto max_score = dp(dp_states, game, state);
	cout << "====state" << st << " : (" << max_score.first << "," << max_score.second << ")" << endl;

	return game_res(true, max_score);
}

ii dp(map<ll,ii>& dp_states, struct Game game, struct State state)
{
	// If all pawns are in the stair
	if (is_pawns_stair(game, state)) {
		return calculate_score(game, state);
	}

	ll st = encode(state, game);
	auto it = dp_states.find(st);
	if (it != dp_states.end()) {
		return dp_states[st];
	}

	vector<ii> results;
	for (short pawn = 0; pawn < game.num_cores; pawn++) {
		struct Turn right(state.jogador_atual, pawn, true);
		struct Turn left(state.jogador_atual, pawn, false);

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


	if (!state.jogador_atual) {
		sort(results.begin(), results.end(), p1_order);
	}
	else {
		sort(results.begin(), results.end(), p2_order);
	}

	dp_states[st] = results.size() == 0 ? ii(-1, -1) : results.front();

	return dp_states[st];
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

ii calculate_score(struct Game& game, struct State& state)
{
	vector<short> score(game.num_jogadores, 0);
	for (int j = 0; j < game.num_jogadores; j++) {
		for (int disc = 0; disc < game.num_cores; disc++) {
			if (state.escada[disc]) {
				score[j] += state.jogadores[j][disc]*(game.num_cores - state.escada[disc]);
			}
		}
	}

	return ii(score[0],score[1]);
}

short max_of_array(const vector<short>& scores)
{
	short highest = 0;

	for (size_t i = 0; i < scores.size(); i++) {
		highest = max(highest, scores[i]);
	}

	return highest;
}

void print_game(ostream& out, struct Game game, struct State& state)
{
	// bitset<4> bit_st_tabuleiro(state.estado_tabuleiro);
	// out << "    " << bit_st_tabuleiro << endl;
	out << state.jogador_atual+1 << " - ";
	if (state.peao[0] && state.peao[0] <= game.num_discos) {
		game.board[game.color_index[0][state.peao[0]-1]] = 'R';
	}
	if (state.peao[1] && state.peao[1] <= game.num_discos) {
		game.board[game.color_index[1][state.peao[1]-1]] = 'G';
	}
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

	return;
}
