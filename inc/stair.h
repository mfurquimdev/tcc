#ifndef STAIR_H
#define STAIR_H

#include "pawn.h"
#include <array>

class Stair
{
public:
    Stair();
    ~Stair();

    void step_up(Pawn*);
    void draw();

    std::array<std::pair<Colors, int>,5> retrieve_colors_worth();

private:
    unsigned int _current_position;
    std::array<Pawn*, 5> _stair;
};


#endif
