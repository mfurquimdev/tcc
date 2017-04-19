
Game::Game(short num_discos, short num_cores, short num_jogadores, string board)
{

}

inline struct Game
Game::random_game(short num_discos, short num_cores, short num_jogadores)
{
	string board(num_cores*num_discos, '0');

	for (size_t c = 0; c < num_cores; c++) {
		for (size_t d = 0; d < num_discos; d++) {
			board[c*num_discos+d] = '1' + i;
		}
	}

	srand(time(NULL));
	random_shuffle(board.begin(), board.end());

	return Game(num_discos, num_cores, num_jogadores, board);
}
