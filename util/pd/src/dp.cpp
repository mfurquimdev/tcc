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

	cout << endl << "Player " << player+1 << endl;
	cout << "Move pawn " << pawn+1 << endl;
	if (pick_right) {
		cout << "Pick right" << endl;
	}
	else {
		cout << "Pick left" << endl;
	}

	if (state.escada[pawn]) {
		cout << "Pawn " << pawn+1 << " already in stair" << endl;
		print_game(cout, game, state);
		max_score = max_of_array(calculate_score(game, state));
		return max_score;
	}

	// Remove discs from game.board according to state.tabuleiro
	cout << "Update board according to state.tabuleiro" << endl;
	update_board(game, state);

	// Moving Pawn
	cout << "Moving pawn" << endl;
	bool available = false;
	bool in_range = false;
	do {
		if (state.peao[pawn] <= game.num_discos) {
			cout << "Incrementing" << endl;
			state.peao[pawn]++;
		}
		in_range = state.peao[pawn] <= game.num_discos;
		if (in_range) {
			cout << "In Range" << endl;
			available = game.board[game.color_index[pawn][state.peao[pawn]-1]] != '0';

			if (available) {
				cout << "Available (" << game.board[game.color_index[pawn][state.peao[pawn]-1]] << ")" << endl;
			}
			else {
				cout << "Not Available (" << game.board[game.color_index[pawn][state.peao[pawn]-1]] << ")" << endl;
			}
		}
		else {
			cout << "Not In Range" << endl;
		}
	} while (!available && in_range);

	// Step in the stair
	if (!in_range) {
		cout << "Steping in Stair" << endl;
		if (!state.escada[pawn]) {
			state.escada[pawn] = max_of_array(state.escada)+1;
			state.jogadores[player][pawn]++;
			state.jogador_atual = (player+1)%game.num_jogadores;
			cout << "Replacing disc under previous Pawn position at " << game.color_index[pawn][state.peao[pawn]-2] << endl;
			game.board[game.color_index[pawn][state.peao[pawn]-2]] = '1' + pawn;
			print_game(cout, game, state);
		}
		else {
			cout << "Pawn " << pawn+1 << " already in stair" << endl;
			print_game(cout, game, state);
			max_score = max_of_array(calculate_score(game, state));
			return max_score;
		}
	}
	// Move pawn in board
	else {
		for (int pawn = 0; pawn < game.num_cores; pawn++) {
			if (state.peao[pawn] && state.peao[pawn] < game.num_discos + 1) {
				int pawn_pos = state.peao[pawn]-1;
				cout << "Moving Pawn " << pawn+1 << " to position " << game.color_index[pawn][pawn_pos] << endl;
				game.board[game.color_index[pawn][pawn_pos]] = '0';
				print_game(cout, game, state);

				if (pawn_pos > 0) {
					cout << "Replacing disc under previous Pawn position at " << game.color_index[pawn][pawn_pos-1] << endl;
					game.board[game.color_index[pawn][pawn_pos-1]] = '1' + pawn;
					print_game(cout, game, state);
				}
			}
		}
	}

	// Remove disc from game.board according to state.peao
	update_board(game, state);

	// Pick a disc if the pawn has moved within the range of the board
	if (in_range) {
		cout << "Picking disc" << endl;
		short pawn_pos = state.peao[pawn]-1;
		bool pick = false;
		short disc_pos = -1;

		for (short i = 1;; i++) {
			// Pick right
			if (pick_right) {
				disc_pos = game.color_index[pawn][pawn_pos]+i;
				cout << "Picking right (" << disc_pos << ")"<< endl;

				// Does not pick right (out of board)
				if (disc_pos >= (short) game.board.size()) {
					cout << "Does not pick disc on the right"<< endl;
					break;
				}
			}
			// Pick left
			else {
				disc_pos = game.color_index[pawn][pawn_pos]-i;
				cout << "Picking left (" << disc_pos << ")"<< endl;

				// Does not pick left (out of board)
				if (disc_pos < 0) {
					cout << "Does not pick disc on the left"<< endl;
					break;
				}
			}

			// Does not pick if disc is 0, try again
			if (game.board[disc_pos] == '0') {
				cout << "Disc 0 at position " << disc_pos << endl;
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

			cout << "Disc " << pick_char << " at position " << disc_pos << endl;

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

	cout << endl << "Test all pawns in stair" << endl;
	if (is_pawns_stair(game, state)) {
		cout << "All pawns in stair true" << endl;
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

		cout << "Max Score = " << max_score << endl;
	}

	dp_states[(ll) encode(state, game)] = max_score;
	// cout << "Dp States (" << dp_states.size() << ")" << endl;
	// for (auto s: dp_states) {
	// 	cout << s.first << " -> " << s.second << endl;
	// }

	return max_score;
}

void update_board(struct Game& game, struct State& state)
{
	unsigned short estado_tabuleiro = state.estado_tabuleiro;
	// bitset<9> bit_st_tabuleiro(state.estado_tabuleiro);

	int tab_mask = 1<<(game.board.size()-1);
	for (size_t i = 0; i < game.board.size(); i++) {
		if ((estado_tabuleiro & tab_mask) == 0) {
			game.board[i] = '0';
		}
		estado_tabuleiro <<= 1;
	}

	print_game(cout, game, state);

	return ;
}

// short pick_right(map<ll,int>& dp_states, struct Game& game, struct State& state, int pawn)
// {
// 	short max_score = 0;
// 	return max_score;
// }
//
// short pick_left(map<ll,int>& dp_states, struct Game& game, struct State& state, int pawn)
// {
// 	// cerr << "Picking left" << endl;
// 	short max_score = 0;
//
// 	int pawn_pos = state.peao[pawn]-1;
// 	int pawn_index = pawn;
//
// 	if (game.num_discos < pawn_pos) {
// 		return 0;
// 	}
//
// 	int disc_pos_left = -1;
// 	char pick_left = -1;
// 	for (int i = 1;; i++) {
// 		// cerr << i << game << state << endl;
// 		disc_pos_left = game.color_index[pawn_index][pawn_pos]-i;
// 		// cerr << disc_pos_left << endl;
//
// 		// Does not pick left
// 		if (disc_pos_left < 0) {
// 			// cerr << "Does not pick left" << endl;
// 			break;
// 		}
//
// 		// Trying to pick 0
// 		if (game.board[disc_pos_left] == '0') {
// 			// cerr << "Trying to pick 0" << endl;
// 			continue;
// 		}
//
// 		// Which disc to pick?
// 		pick_left = game.board[disc_pos_left];
//
// 		// Remove it from the board
// 		state.estado_tabuleiro &= ~((1<<(game.board.size()-1))>>(disc_pos_left));
//
// 		// Add it to the player's hand
// 		state.jogadores[state.jogador_atual][pick_left-'0'-1]++;
// 		// cerr << "Jogador " << state.jogador_atual << ": " << state.jogadores[state.jogador_atual][pick_left-'0'-1] << endl;
//
// 		// // Store the player who's playing
// 		// short prev_player = state.jogador_atual;
// 		//
// 		// Calculate next player
// 		state.jogador_atual = (state.jogador_atual+1)%game.num_jogadores;
//
// 		// Encode game state and hash it
// 		// ll ll_st = encode(state, game);
//
// 		// Get max score from this node's child
// 		max_score = dp(dp_states, game, state);
//
// 		// // Store max score from this node's child
// 		// dp_states[ll_st] = max_score;
//
// 		// // Recover player who's playing
// 		// state.jogador_atual = prev_player;
// 		//
// 		// // Remove the disc from player's hand
// 		// state.jogadores[state.jogador_atual][pick_left-'0'-1]--;
// 		//
// 		// // Put disc back to the board
// 		// state.estado_tabuleiro |= ~((1<<(game.board.size()-1))>>(disc_pos_left));
// 		break;
// 	}
//
// 	return max_score;
// }

// void normalize_tabuleiro(struct State& state)
// {
// 	// Normalize tabuleiro
// 	bitset<9> bit_st_tabuleiro(state.estado_tabuleiro);
// 	state.estado_tabuleiro = (short) bit_st_tabuleiro.to_ulong();
//
// 	return ;
// }

// void move_pawn(struct Game& game, struct State& state, int pawn)
// {
// 	// Moving Pawn
// 	bool available = false;
// 	bool in_range = false;
// 	do {
// 		if (state.peao[pawn] <= game.num_discos) {
// 			state.peao[pawn]++;
// 		}
// 		// cerr << "Pawn" << pawn << ": " << state.peao[pawn] << endl;
// 		in_range = state.peao[pawn] <= game.num_discos;
// 		if (in_range) {
// 			// cerr << "In Range" << endl;
// 			// cerr << "game.board[game.color_index[pawn][state.peao[pawn]]]: " << game.board[game.color_index[pawn][state.peao[pawn]-1]] << endl;
// 			// cerr << "game.color_index[pawn][state.peao[pawn]]: " << game.color_index[pawn][state.peao[pawn]-1] << endl;
// 			// cerr << "state.peao[pawn]: " << state.peao[pawn]-1 << endl;
// 			// cerr << "pawn: " << pawn << endl;
// 			available = game.board[game.color_index[pawn][state.peao[pawn]-1]] != '0';
// 			if (available) {
// 				// cerr << "Available" << endl;
// 			}
// 			else {
// 				// cerr << "Not Available" << endl;
// 			}
// 		}
// 		else {
// 			// cerr << "Not In Range" << endl;
// 		}
// 	} while (!available && in_range);
//
// 	if (!in_range) {
// 		// cerr << "Not In Range, Climb Stair" << endl;
// 		step_in(game, state, pawn);
// 		return;
// 	}
//
// 	for (int i = 0; i < game.num_cores; i++) {
// 		int pawn = i;
// 		// cerr << "pawn: " << pawn << endl;
// 		if (state.peao[i] && state.peao[i] < game.num_discos + 1) {
// 			int pawn_pos = state.peao[i]-1;
// 			// cerr << "pawn_pos: " << pawn_pos << endl;
// 			game.board[game.color_index[pawn][pawn_pos]] = '0';
// 			if (pawn_pos > 0) {
// 				// cerr << "pawn_pos > 0" << endl;
// 				game.board[game.color_index[pawn][pawn_pos-1]] = '1' + pawn;
// 			}
// 		}
// 	}
//
// 	update_board(game, state);
//
// 	return ;
// }

// void step_in(struct Game& game, struct State& state, int pawn)
// {
// 	if (!state.escada[pawn]) {
// 		state.escada[pawn] = max_of_array(state.escada)+1;
// 		state.jogadores[state.jogador_atual][pawn]++;
// 		state.jogador_atual = (state.jogador_atual+1)%game.num_jogadores;
// 	}
//
// 	return ;
// }

bool is_pawns_stair(struct Game& game, struct State& state)
{
	cout << "Testing all pawns in stair" << endl;
	bool pawns_stair = true;

	for (int i = 0; i < game.num_cores; i++) {
		cout << "Pawn " << i+1 << endl;
		if (state.escada[i] == 0) {
			cout << "Not in stair" << endl;
			pawns_stair = false;
			break;
		}
		else {
			cout << "In stair" << endl;
		}
	}

	return pawns_stair;
}

vector<short> calculate_score(struct Game& game, struct State& state)
{
	cout << "Calculating Scores" << endl;

	vector<short> score(game.num_jogadores, 0);
	for (int j = 0; j < game.num_jogadores; j++) {
		cout << "Player " << j << endl;
		for (int disc = 0; disc < game.num_cores; disc++) {
			if (disc) cout << " + ";
			if (state.escada[disc]) {
				cout << state.jogadores[j][disc] << "*" << game.num_cores - state.escada[disc];
				score[j] += state.jogadores[j][disc]*(game.num_cores - state.escada[disc]);
			}
			else {
				cout << state.jogadores[j][disc] << "*" << state.escada[disc];
			}
		}
		cout << ": " << score[j] << endl;
	}

	return score;
}

short max_of_array(const vector<short>& scores)
{
	short highest = 0;

	for (size_t i = 0; i < scores.size(); i++) {
		highest = max(highest, scores[i]);
		// if (highest < scores[i]) {
		// 	highest = scores[i];
		// }
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
