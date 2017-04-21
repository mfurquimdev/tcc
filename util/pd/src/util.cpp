#include "util.h"
#include "encode.h"
#include <bitset>
#include "dp.h"
#include "game.h"

void step_in(struct State& state, int pawn)
{
	if (!state.escada[pawn]) {
		state.escada[pawn] = max_of_array(state.escada)+1;
	}

	return ;
}

void update_board(struct Game& game, struct State& state)
{
	unsigned short estado_tabuleiro = state.estado_tabuleiro;
	bitset<9> bit_st_tabuleiro(state.estado_tabuleiro);

	int tab_mask = 1<<(game.board.size()-1);
	for (size_t i = 0; i < game.board.size(); i++) {
		if ((estado_tabuleiro & tab_mask) == 0) {
			game.board[i] = '0';
		}
		estado_tabuleiro <<= 1;
	}

	return ;
}

void pick_right(struct Game& game, struct State& state, int pawn)
{
	short pawn_pos = state.peao[pawn]-1;
	short pawn_index = pawn+1;

	short disc_pos_right = -1;
	char pick_right = -1;
	for (short i = 1;; i++) {
		disc_pos_right = game.color_index[pawn_index][pawn_pos]+i;

		// Does not pick right
		if (disc_pos_right >= (short) game.board.size()) {
			break;
		}

		// Trying to pick 0
		if (game.board[disc_pos_right] == '0') {
			continue;
		}

		// Which disc to pick?
		pick_right = game.board[disc_pos_right];

		// Remove it from the board
		state.estado_tabuleiro &= ~((1<<(game.board.size()-1))>>(disc_pos_right));

		// Add it to the player's hand
		state.jogadores[state.jogador_atual][pick_right-'0'-1]++;

		// Store the player who's playing
		short prev_player = state.jogador_atual;

		// Calculate next player
		state.jogador_atual = (state.jogador_atual+1)%game.num_jogadores;

		// Encode game state and hash it
		ll ll_st = encode(state, game);

		// Store max score from this node's child
		game.dp_states[ll_st] = dp(game, state);

		// Recover player who's playing
		state.jogador_atual = prev_player;

		// Remove the disc from player's hand
		state.jogadores[state.jogador_atual][pick_right-'0'-1]--;

		// Put disc back to the board
		state.estado_tabuleiro |= ~((1<<(game.board.size()-1))>>(disc_pos_right));
		break;
	}

	return ;
}

void pick_left(struct Game& game, struct State& state, int pawn)
{
	int pawn_pos = state.peao[pawn]-1;
	int pawn_index = pawn+1;

	int disc_pos_left = -1;
	char pick_left = -1;
	for (int i = 1;; i++) {
		disc_pos_left = game.color_index[pawn_index][pawn_pos]-i;

		// Does not pick left
		if (disc_pos_left < 0) {
			break;
		}

		// Trying to pick 0
		if (game.board[disc_pos_left] == '0') {
			continue;
		}

		// Which disc to pick?
		pick_left = game.board[disc_pos_left];

		// Remove it from the board
		state.estado_tabuleiro &= ~((1<<(game.board.size()-1))>>(disc_pos_left));

		// Add it to the player's hand
		state.jogadores[state.jogador_atual][pick_left-'0'-1]++;

		// Store the player who's playing
		short prev_player = state.jogador_atual;

		// Calculate next player
		state.jogador_atual = (state.jogador_atual+1)%game.num_jogadores;

		// Encode game state and hash it
		ll ll_st = encode(state, game);

		// Store max score from this node's child
		game.dp_states[ll_st] = dp(game ,state);

		// Recover player who's playing
		state.jogador_atual = prev_player;

		// Remove the disc from player's hand
		state.jogadores[state.jogador_atual][pick_left-'0'-1]--;

		// Put disc back to the board
		state.estado_tabuleiro |= ~((1<<(game.board.size()-1))>>(disc_pos_left));
		break;
	}

	return ;
}

void normalize_tabuleiro(struct State& state)
{
	// Normalize tabuleiro
	bitset<9> bit_st_tabuleiro(state.estado_tabuleiro);
	state.estado_tabuleiro = (short) bit_st_tabuleiro.to_ulong();

	return ;
}

void move_pawn(struct Game& game, struct State& state, int pawn)
{
	// Moving Pawn
	do {
		state.peao[pawn]++;
		if (state.peao[pawn] > game.num_cores) {
			break;
		}
	} while (game.board[game.color_index[pawn+1][state.peao[pawn]-1]] == '0');

	if (state.peao[pawn] > game.num_cores) {
		return;
	}

	for (int i = 0; i < game.num_cores; i++) {
		int pawn = i+1;
		if (state.peao[i] && state.peao[i] < game.num_discos + 1) {
			int pawn_pos = state.peao[i]-1;
			game.board[game.color_index[pawn][pawn_pos]] = '0';
		}
	}

	update_board(game, state);

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
			score[j] += state.jogadores[j][disc]*(game.num_cores - state.escada[disc]);
		}
	}

	return score;
}

short max_of_array(const vector<short>& scores)
{
	short max = 0;
	for (size_t i = 0; i < scores.size(); i++) {
		if (max < scores[i]) {
			max = scores[i];
		}
	}

	return max;
}
