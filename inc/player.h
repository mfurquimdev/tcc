#ifndef PLAYER_H
#define PLAYER_H

#include <array>
#include "disc.h"

class Player
{
public:
    Player(unsigned int);
    ~Player();

    void collect_disc(Disc*);


private:
    std::array<Disc*,25> _disc_poll;
    unsigned int _num_discs;
    unsigned int _num_player;

};

#endif
