#include "player.h"
#include "disc.h"

#include <cstdlib>

Player::Player(unsigned int num_player)
{
    this->_num_player = num_player;
    this->_num_discs = 0;
    this->_disc_poll.fill(NULL);
}

Player::~Player()
{
}

void
Player::collect_disc(Disc* disc)
{
    fprintf(stderr, "collect_disc (%p)\n", (void*) disc);
    disc->position(((this->_num_player+1)*100)+_num_discs);
    this->_disc_poll[this->_num_discs] = disc;
    this->_num_discs++;
}
