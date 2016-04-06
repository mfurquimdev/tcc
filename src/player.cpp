#include "player.h"

#include <cstdio>

Player::Player(unsigned char id)
{
    fprintf(stderr, "[%p]\tPlayer(%d)\n", (void*) this, (int) id);

    player_id(id);
}

Player::~Player()
{
    fprintf(stderr, "[%p]\tPlayer destructor\n", (void*) this);
}

/**
 * Public functions
 */

void
Player::draw(void)
{
    fprintf(stderr, "\t\tdraw(void)\n");

    printf("Player %d\n", player_id());

    return ;
}

/**
 * Private functions
 */


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
