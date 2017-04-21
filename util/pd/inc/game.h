#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct Game
{
	short num_discos;
	short num_cores;
	short num_jogadores;
	string board;
	map<string,short> masks;
	map<short,string> ids;

	Game(short ndiscos, short ncores, short njogadores)
	{
		num_cores = ncores;
		num_discos = ndiscos;
		num_jogadores = njogadores;

		board = random_game(num_discos, num_cores);
		generate_stair_states(masks, ids, num_cores);
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

	void generate_stair_states(map<string,short>& masks, map<short,string>& ids, short num_cores)
	{
		short counter = 0;

		char* cstair = NULL;
		cstair = (char*) malloc(sizeof(char)*(num_cores+1));
		for (int i = 0; i < num_cores; i++) {
			cstair[i] = '0';
		}
		cstair[num_cores] = '\0';

		for (int i = 0; i <= num_cores; i++) {
			cstair[i%num_cores] = i + 48;
			string stair(cstair);
			sort(stair.begin(),stair.end());
			do
			{
				auto it = masks.find(stair.c_str());
				if (it == masks.end()) {
					masks[stair.c_str()] = counter;
					ids[counter] = stair.c_str();
					counter++;
				}
			} while(next_permutation(stair.begin(),stair.end()));
		}

		free(cstair);
		return ;
	};

};

#endif
