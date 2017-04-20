#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Game
{
	short num_discos;
	short num_cores;
	short num_jogadores;
	string board;

	Game(short ndiscos, short ncores, short njogadores)
	{
		num_cores = ncores;
		num_discos = ndiscos;
		num_jogadores = njogadores;

		board = random_game(num_discos, num_cores);
	};

	string random_game(short num_discos, short num_cores)
	{
		string board(num_cores*num_discos, '0');

		for (short c = 0; c < num_cores; c++) {
			for (short d = 0; d < num_discos; d++) {
				board[c*num_discos+d] = '1' + c;
			}
		}

		srand(time(NULL));
		random_shuffle(board.begin(), board.end());

		return board;
	};

};

#endif
