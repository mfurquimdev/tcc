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

	// Max score from states
	map<ll,ii> dp_states;
	clock_t start, end;
	ii max_score;

	char* cboard = NULL;
	cboard = (char*) malloc(sizeof(char)*(num_discos*num_cores+1));
	for (int i = 0; i < num_cores*num_discos; i++) {
		// cout << (i%(num_cores)) + '1' << endl;
		cboard[i] = (i%num_cores) + '1';
	}
	cboard[num_discos*num_cores] = '\0';
	string board(cboard);
	free(cboard);
	sort(board.begin(),board.end());
	bool doesPlayer2Win = false;
	do
	{
		struct Game game(num_discos, num_cores, num_jogadores, board);
		struct State state(num_discos, num_cores, num_jogadores);

		dp_states.clear();
		start = clock();
		max_score = dp(dp_states, game, state);
		end = clock();
		doesPlayer2Win = max_score.first < max_score.second;
		cout << (doesPlayer2Win ? "2 " : "1 ") << game.board << ": (" << max_score.first << "," << max_score.second << ") -> [" << dp_states.size() << "] states in " << (((float)(end - start))/CLOCKS_PER_SEC) << " seconds." << endl;
		// if (doesPlayer2Win) {
		// 	break;
		// }
	} while(next_permutation(board.begin(),board.end()));

	// if (doesPlayer2Win) {
	// 	cout << endl << "Player 2 won" << endl;
	// }

	return 0;
}
