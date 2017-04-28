#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

using ll = long long;
using namespace std;

struct Game
{
	short num_discos;
	short num_cores;
	short num_jogadores;
	string board;
	map<string,short> masks;
	map<short,string> ids;
	vector<vector<short> > color_index;

	Game(short ndiscos, short ncores, short njogadores)
	{
		num_cores = ncores;
		num_discos = ndiscos;
		num_jogadores = njogadores;

		board = random_game(num_discos, num_cores);
		color_index = calculate_color_index(board, num_cores);
		generate_stair_states(masks, ids, num_cores);
	};

	vector<vector<short> > calculate_color_index(const string& board, const short& num_cores)
	{
		vector<vector<short> > index;

		for (short c = 0; c < num_cores; c++) {
			vector<short> pawn;
			for (size_t i = 0; i < board.size(); i++) {
				if (board[i] == (c+1) + '0') {
					pawn.push_back(i);
				}
			}
			index.push_back(pawn);
		}

		return index;
	}

	string random_game(const short& num_discos, const short& num_cores)
	{
		string board(num_cores*num_discos, '0');

		for (short c = 0; c < num_cores; c++) {
			for (short d = 0; d < num_discos; d++) {
				board[d*num_discos+c] = '1' + c;
			}
		}

		// srand(time(NULL));
		// random_shuffle(board.begin(), board.end());

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

	friend ostream& operator<<(ostream& out, const struct Game& game)
	{
		out << endl;
		out << "Game" << endl;
		out << "#Discos: " << game.num_discos << endl;
		out << "#Cores: " << game.num_cores << endl;
		out << "#Jogadores: " << game.num_jogadores << endl;
		out << "Board: " << game.board << endl;
		out << "Index {" << endl;
		for (short c = 0; c < game.num_cores; c++) {
			out << "  " << c+1 << ":(";
			for (short d = 0; d < game.num_discos; d++) {
				if (d) out << ",";
				out << game.color_index[c][d];
			}
			out << ")" << endl;
		}
		out << "}" << endl;

		cout << endl;
		return out;
	};
};

#endif
