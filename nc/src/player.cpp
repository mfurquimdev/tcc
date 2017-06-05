#include "player.h"
#include <cstdio>

#define DEBUG 0

Player::Player()
{
	 if(DEBUG) fprintf(stderr, "[%p] player constructor\n", (void*) this);
	this->_diff_colors = 0;
}

Player::~Player()
{
	 if(DEBUG) fprintf(stderr, "[%p] player destructor\n", (void*) this);
}

void
Player::discs(const char* disc)
{
	this->_discs.append(disc,1);
	return ;
}

string
Player::discs(void)
{
	return this->_discs;
}

bool
Player::has_black()
{
	bool has_black = false;

	return has_black;
}

int
Player::appearance(char pawn)
{
	char char_disc = '0';

	switch (pawn) {
		case 'R':
		char_disc = '1';
		break;

		case 'G':
		char_disc = '2';
		break;

		case 'B':
		char_disc = '3';
		break;

		case 'Y':
		char_disc = '4';
		break;

		case 'P':
		char_disc = '5';
		break;

		case 'W':
		char_disc = '6';
		break;

		default:
		break;
	}

	char * pch;
	int times = 0;
	pch = strchr((char*) this->_discs.c_str(), char_disc);
	while (pch != NULL) {
		times++;
		pch = strchr(pch+1,char_disc);
	}

	 if(DEBUG) fprintf(stderr, "%c was found %d times in %s\n", char_disc, times, this->_discs.c_str());

	return times;
}

unsigned short int
Player::score(const char* stair, int stair_position, unsigned short int number_pawns)
{
	 if(DEBUG) fprintf(stderr, "score(%s, %d, %d)\n", stair, stair_position, number_pawns);
	 if(DEBUG) fprintf(stderr, "diff colors = %d\n", this->_diff_colors);
	unsigned short int score = 0;
	this->_diff_colors = 0;

	for (int i = 0; i < stair_position; i++) {
		 if(DEBUG) fprintf(stderr, "%d\n", i);
		score += (number_pawns-i-1)*this->appearance(stair[i]);
	}

	 if(DEBUG) fprintf(stderr, "Looking for discs, except white (6)\n");
	char * pch;
	pch = strchr((char*) this->_discs.c_str(), '7');
	if (pch != NULL) {
		 if(DEBUG) fprintf(stderr, "Black found\n");
		this->_diff_colors++;
	}

	for (auto char_disc: this->_discs) {
		if (this->appearance(char_disc) > 0 && char_disc != '6') {
			this->_diff_colors++;
		}
	}

	 if(DEBUG) fprintf(stderr, "diff colors = %d\n", this->_diff_colors);

	score += this->_diff_colors*this->appearance('W');
	 if(DEBUG) fprintf(stderr, "diff colors = %d\n", this->_diff_colors);

	 if(DEBUG) fprintf(stderr, "score = %d\n", score);

	return score;
}
