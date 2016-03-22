#include "player.h"
#include "disc.h"

#include <cstdlib>
#include <cassert>
#include <stdio_ext.h>

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
Player::pick_up(std::pair<Disc*, Disc*> adjacent)
{
    assert(adjacent.first != NULL || adjacent.second != NULL);


    if (adjacent.first != NULL &&
        adjacent.second != NULL) {
            fprintf(stdout, "Which do you wish to pick?\n\t%2d: 0\n\t%2d: 1",
            adjacent.first->position(), adjacent.second->position());

            unsigned int disc;
            scanf("%u", &disc);
            __fpurge(stdin);
            disc?this->collect_disc(adjacent.second):this->collect_disc(adjacent.first);
    }
    else if (adjacent.first != NULL) {
        this->collect_disc(adjacent.first);
    }
    else {
        this->collect_disc(adjacent.second);
    }



}

void
Player::collect_disc(Disc* disc)
{
    fprintf(stderr, "collect_disc (%p)\n", (void*) disc);
    disc->position(((this->_num_player+1)*100)+_num_discs);
    this->_disc_poll[this->_num_discs] = disc;
    this->_num_discs++;
}
