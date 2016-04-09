#ifndef PLAYER_H
#define PLAYER_H

#include "disc.h"

#include <vector>


bool sort_disc (Disc*, Disc*);

class Player
{
public:
    Player(unsigned short int);
    ~Player();

    void draw(void);

private:

    std::vector<Disc*> disc_poll(void);
    void init_discs(void);

    void player_id(unsigned short int);
    unsigned short int player_id(void);

    unsigned short int _id;
    std::vector<Disc*> _discs;
};

#endif
