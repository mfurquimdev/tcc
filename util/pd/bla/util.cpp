#include "util.h"

inline void step_in(struct State& cst, int pawn)
{
	if (!cst.escada[pawn]) {
		cst.escada[pawn] = max_of_array(cst.escada)+1;
	}

	return ;
}

inline void update_board(string& board, struct State& st)
{
	unsigned short estado_tabuleiro = st.estado_tabuleiro;
	bitset<9> bit_st_tabuleiro(st.estado_tabuleiro);

	int tab_mask = 1<<(board.size()-1);
	for (size_t i = 0; i < board.size(); i++) {
		if ((estado_tabuleiro & tab_mask) == 0) {
			board[i] = '0';
		}
		estado_tabuleiro <<= 1;
	}

	return ;
}

inline void pick_right(string& board, struct Game& g, struct State& cst, int p)
{
	int pawn_pos = cst.peao[p]-1;
	int pawn_index = p+1;

	int disc_pos_right = -1;
	char pick_right = -1;
	for (int i = 1;; i++) {
		disc_pos_right = g.color_index[pawn_index][pawn_pos]+i;

		// Does not pick right
		if (disc_pos_right >= (int) board.size()) {
			break;
		}

		// Trying to pick 0
		if (board[disc_pos_right] == '0') {
			continue;
		}

		// Pick right
		pick_right = board[disc_pos_right];
		cst.estado_tabuleiro &= ~((1<<(board.size()-1))>>(disc_pos_right));
		cst.jogadores[cst.jogador_atual][pick_right-'0'-1]++;
		short prev_player = cst.jogador_atual;
		cst.jogador_atual = (cst.jogador_atual+1)%g.num_jogadores;
		ll ll_st = encode(cst);
		g_dp_st[ll_st] = dp(g,cst);
		cst.jogador_atual = prev_player;
		cst.jogadores[cst.jogador_atual][pick_right-'0'-1]--;
		cst.estado_tabuleiro |= ~((1<<(board.size()-1))>>(disc_pos_right));
		break;
	}

	return ;
}

inline short pick_left(string& board, struct Game& g, struct State& cst, int p)
{
	int pawn_pos = cst.peao[p]-1;
	int pawn_index = p+1;

	int disc_pos_left = -1;
	char pick_left = -1;
	for (int i = 1;; i++) {
		disc_pos_left = g.color_index[pawn_index][pawn_pos]-i;

		// Does not pick left
		if (disc_pos_left < 0) {
			break;
		}

		// Trying to pick 0
		if (board[disc_pos_left] == '0') {
			continue;
		}

		// Pick left
		pick_left = board[disc_pos_left];
		cst.estado_tabuleiro &= ~((1<<(board.size()-1))>>(disc_pos_left));
		cst.jogadores[cst.jogador_atual][pick_left-'0'-1]++;
		cst.jogador_atual = (cst.jogador_atual+1)%g.num_jogadores;
		short prev_player = cst.jogador_atual;
		ll ll_st = encode(cst);
		score = dp(g,cst);
		g_dp_st[ll_st] = score;
		cst.jogador_atual = prev_player;
		cst.jogador_atual = (g.num_jogadores-1)%g.num_jogadores;
		cst.jogadores[cst.jogador_atual][pick_left-'0'-1]--;
		cst.estado_tabuleiro |= ~((1<<(board.size()-1))>>(disc_pos_left));
		break;
	}

	return score;
}

inline void normalize_tabuleiro(struct State& st)
{
	// Normalize tabuleiro
	bitset<9> bit_st_tabuleiro(st.estado_tabuleiro);
	st.estado_tabuleiro = (short) bit_st_tabuleiro.to_ulong();

	return ;
}

inline void move_pawn(string& board, struct Game& g, struct State& cst, int p)
{
	// Moving Pawn
	do {
		cst.peao[p]++;
		if (cst.peao[p] > g.num_cores) {
			break;
		}
	} while (board[g.color_index[p+1][cst.peao[p]-1]] == '0');

	if (cst.peao[p] > g.num_cores) {
		return;
	}

	for (int i = 0; i < g.num_cores; i++) {
		int pawn = i+1;
		if (cst.peao[i] && cst.peao[i] < g.num_discos + 1) {
			int pawn_pos = cst.peao[i]-1;
			board[g.color_index[pawn][pawn_pos]] = '0';
		}
	}

	update_board(board,cst);

	return ;
}

inline bool is_pawns_stair(struct Game& g, struct State& st)
{
	bool pawns_stair = true;
	for (int i = 0; i < g.num_cores; i++) {
		if (st.escada[i] == 0) {
			pawns_stair = false;
			break;
		}
	}
	return pawns_stair;
}

inline vector<short> calculate_score(struct Game& g, struct State& st)
{
	vector<short> score(g.num_jogadores, 0);
	for (int j = 0; j < g.num_jogadores; j++) {
		for (int disc = 0; disc < g.num_cores; disc++) {
			score[j] += st.jogadores[j][disc]*(g.num_cores - st.escada[disc]);
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
