#include <iostream>
#include <unistd.h>

#include "dp.h"
#include "state.h"
#include "game.h"
#include "encode.h"

using ll = long long;
using namespace std;
using ii = pair<int, int>;

int main(int argc, char* argv[])
{
	short num_cores = 2;
	short num_discos = 2;
	short num_jogadores = 2;

	// Parse parameters
	int c;
	while ((c = getopt(argc, argv, "d:c:j:")) != -1) {
		switch (c) {
			case 'd':
			if (optarg) num_discos = (short) *optarg - '0';
			break;

			case 'c':
			if (optarg) num_cores = (short) *optarg - '0';
			break;

			case 'j':
			if (optarg) num_jogadores = (short) *optarg - '0';
			break;
		}
	}


	// cout << "Big Points" << endl;

	struct Game game(num_discos, num_cores, num_jogadores);
	cout << game;

	struct State state(num_discos, num_cores, num_jogadores);
	// cout << state << endl;

	// decode(encode(state, game), state, game);

	// Max score from states
	map<ll,ii> dp_states;

	clock_t start, end;
	start = clock();
	dp(dp_states, game, state);
	end = clock();

	cout << dp_states.size() << ":" << (((float)(end - start))/CLOCKS_PER_SEC) << endl;
	cout << "MAP (" << dp_states.size() << ") in " << (((float)(end - start))/CLOCKS_PER_SEC) << " seconds."<< endl;
	int i = 0;
	for (auto s: dp_states) {
		cout << "[" << i++ << "]\t";
		decode(s.first, state, game);
		update_board(game, state);
		print_game(cout, game, state);
		cout << "  = (" << s.second.first << "," << s.second.second << ")" << endl;
	}

	return 0;
}
