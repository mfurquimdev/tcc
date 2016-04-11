#include "player.h"

#include <cstdio>
#include <algorithm>

Player::Player(unsigned short int id)
{
    fprintf(stderr, "[%p]\tPlayer(%d)\n", (void*) this, (int) id);

    player_id(id);
}

Player::~Player()
{
    fprintf(stderr, "\n[%p]\tPlayer destructor\n", (void*) this);
}

/**
 * Public functions
 */

void
Player::gather_disc(Disc* disc_picked)
{
    this->_discs.push_back(disc_picked);
// Seg Fault    std::sort(disc_poll().begin(), disc_poll().end(), sort_disc);

    return ;
}


void
Player::draw(void)
{
    fprintf(stderr, "\t\tdraw(void)\n");

    printf("\nPlayer %d\nDisc Poll:\t", player_id()+1);
    for (auto disc: disc_poll()) {
        disc->draw();
    }
    printf("\n");

    return ;
}

/**
 * Private functions
 */

bool sort_disc (Disc* d1, Disc* d2)
{
    return (d1->color() < d2->color());
}

/**
 * Getters and Setters
 */

void
Player::player_id(unsigned short int id)
{
    fprintf(stderr, "\tplayer_id(%d)\n", (int) id);
    this->_id = id;

    return ;
}

unsigned short int
Player::player_id(void)
{
    return this->_id;
}

std::vector<Disc*>
Player::disc_poll(void)
{
    return this->_discs;
}
