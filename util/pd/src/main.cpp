#include <iostream>
#include <unistd.h>

#include "dp.h"
#include "state.h"
#include "game.h"

using ll = unsigned long long;
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

	if (num_discos > 5) {
		cout << "Essa versão suporta no máximo 5 discos!" << endl;
	}

	if (num_discos < 2) {
		cout << "A quantidade mínima de discos é 2!" << endl;
	}

	if (num_cores > 5) {
		cout << "A quantidade máxima de cores é 5!" << endl;
	}
	
	if (num_cores < 2) {
		cout << "A quantidade mínima de cores é 2!" << endl;
	}

	if (num_jogadores != 2) {
		cout << "Essa versão suporta apenas dois jogadores!" << endl;
	}
	
	if (num_discos < 2 or num_discos > 5 
		or num_cores < 2 or num_cores > 5
		or num_jogadores != 2)
	{
		return(1);
	}

	// Max score from states
	map<struct State, ii> dp_states;
	clock_t start, end;

	char* cboard = NULL;
	cboard = (char*) malloc(sizeof(char)*(num_discos*num_cores+1));
	for (int i = 0; i < num_cores*num_discos; i++) {
		cboard[i] = (i%num_cores) + '1';
	}
	cboard[num_discos*num_cores] = '\0';
	string board(cboard);
	free(cboard);
	sort(board.begin(),board.end());
	do
	{
		struct Game game(num_discos, num_cores, num_jogadores, board);
		struct State state;

		dp_states.clear();
		start = clock();
		auto max_score = dp(dp_states, game, state);
		end = clock();
		cout << (max_score.first < max_score.second ? "2 " : "1 ") << game.board << ": (" << max_score.first << "," << max_score.second << ") -> [" << dp_states.size() << "] states in " << (((float)(end - start))/CLOCKS_PER_SEC) << " seconds." << endl;
	} while(next_permutation(board.begin(),board.end()));

	return 0;
}
