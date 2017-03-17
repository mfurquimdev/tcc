#include "player.h"
#include <cstdio>

Player::Player()
{
	fprintf(stderr, "[%p] player constructor\n", (void*) this);
	this->_diff_colors = 0;
}

Player::~Player()
{
	fprintf(stderr, "[%p] player destructor\n", (void*) this);
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

	fprintf(stderr, "%c was found %d times in %s\n", char_disc, times, this->_discs.c_str());

	return times;
}

unsigned short int
Player::score(const char* stair, int stair_position, unsigned short int number_pawns)
{
	fprintf(stderr, "score(%s, %d, %d)\n", stair, stair_position, number_pawns);
	fprintf(stderr, "diff colors = %d\n", this->_diff_colors);
	unsigned short int score = 0;
	this->_diff_colors = 0;

	for (int i = 0; i < stair_position; i++) {
		fprintf(stderr, "%d\n", i);
		score += (number_pawns-i-1)*this->appearance(stair[i]);
	}

	fprintf(stderr, "Looking for discs, except white (6)\n");
	char * pch;

	for (size_t i = 0; i < count; i++) {
		/* code */
	}
	pch = strchr((char*) this->_discs.c_str(), '7');
	if (pch != NULL) {
		fprintf(stderr, "Black found\n");
		this->_diff_colors++;
	}

	for (auto char_disc: this->_discs.c_str()) {
		if (this->appearance(char_disc) > 0 && char_disc != '6') {
			this->_diff_colors++;
		}
	}

	fprintf(stderr, "diff colors = %d\n", this->_diff_colors);

	score += this->_diff_colors*this->appearance('W');
	fprintf(stderr, "diff colors = %d\n", this->_diff_colors);

	fprintf(stderr, "score = %d\n", score);

	return score;
}
