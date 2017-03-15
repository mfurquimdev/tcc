#include "player.h"
#include <cstdio>

Player::Player()
{
	fprintf(stderr, "[%p] player constructor\n", (void*) this);
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
