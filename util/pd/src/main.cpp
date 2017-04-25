#include "dp.h"
#include <iostream>
#include "state.h"
#include "game.h"
#include "encode.h"

using ll = long long;
using namespace std;

int main()
{
	short num_cores = 3;
	short num_discos = 2;
	short num_jogadores = 2;

	cout << "Big Points" << endl;

	struct Game game(num_discos, num_cores, num_jogadores);
	cout << game << endl;

	struct State state(num_discos, num_cores, num_jogadores);
	cout << state << endl;

	// decode(encode(state, game), state, game);

	// Max score from states
	map<ll,int> dp_states;

   	clock_t start, end;
   	start = clock();
   	dp(dp_states, game, state);
   	end = clock();

   	cout << "MAP (" << dp_states.size() << ") in " << (((float)(end - start))/CLOCKS_PER_SEC) << " seconds."<< endl;
   	for (auto s: dp_states) {
   		cout << s.first << " -> " << s.second << endl;
   	}

   	return 0;
}
