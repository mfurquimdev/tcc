#include "player.h"

#include <cstdio>
#include <algorithm>

Player::Player(unsigned char id)
{
    fprintf(stderr, "[%p]\tPlayer(%d)\n", (void*) this, (int) id);

    player_id(id);
    init_discs();
}

Player::~Player()
{
    fprintf(stderr, "[%p]\tPlayer destructor\n", (void*) this);

    for (auto disc: disc_poll()) {
        delete(disc);
    }
}

/**
 * Public functions
 */

void
Player::draw(void)
{
    fprintf(stderr, "\t\tdraw(void)\n");

    printf("\nPlayer %d\n", player_id());
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
Player::player_id(unsigned char id)
{
    fprintf(stderr, "\tplayer_id(%d)\n", (int) id);
    this->_id = id;

    return ;
}

unsigned char
Player::player_id(void)
{
    return this->_id;
}

std::vector<Disc*>
Player::disc_poll(void)
{
    return this->_discs;
}

void
Player::init_discs(void)
{

    // Random discs
    for (unsigned char i = 0; i < 17; i++) {
        Disc* new_disc = new Disc(((player_id()+1)*i)%8);
        this->_discs.push_back(new_disc);
    }

// Seg Fault    std::sort(disc_poll().begin(), disc_poll().end(), sort_disc);

    return ;
}
