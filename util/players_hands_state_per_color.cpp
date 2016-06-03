#include <iostream>
#include <string>
#include <bitset>
#include <type_traits>
#include <cstdio>
#include <map>

using namespace std;


map<string,short> ids;
map<short,string> masks;

void players_discs(bitset<8>);

int main()
{
	unsigned int counter_states = 0;
	for (size_t n = 0; n < 0x100; n++)
	{
		bitset<8> b(n);
		if (b.count() == 5)
		{
			ids[b.to_string()] = counter_states;
			masks[counter_states] = b.to_string();
			counter_states++;
//			fprintf(stderr, "\n%d\t%s\t%lu\n", counter_states, b.to_string().c_str(), n);
//			players_discs(b);
		}
	}

	for(auto p: ids)
	{
		cout << "Key: " << p.first << "\tValue: " << p.second << endl;
	}


//	printf("Estados: %d\n", counter_states);

	return 0;
}

void players_discs(bitset<8> disc_state)
{
	unsigned short counter = 0;
	unsigned short players[4];
	unsigned short n_players = 4;

	for (size_t i = 0; i < n_players; i++)
	{
		players[i] = 0;
	}

	unsigned short n = 0;
	for (size_t i = 0; i < 8; i++)
	{
		if (disc_state.test(i))
		{
			fprintf(stderr, "%lu: True\n", i);
			counter++;
		}
		else
		{
			fprintf(stderr, "%lu: False\n", i);
			players[n] = counter;
			counter = 0;
			n++;
		}

		if (i == 7)
		{
			players[n] = counter;
		}
	}

    if (players[1] == 1)
    {
        bool invalid = false;
        for (size_t i = 0; i < n_players; i++)
        {
            if (players[i] == 5)
            {
                invalid = true;
                break;
            }
        }

		if (!invalid)
        {
            printf("\n%s\t%lu\n", disc_state.to_string().c_str(), disc_state.to_ulong());
    
            for (size_t i = 0; i < n_players; i++)
	        {
	        	printf("player %hu\t%hu\n", i, players[i]);
	        }
        }
    }
}
