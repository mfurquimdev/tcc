#ifndef BOARD_H
#define BOARD_H

#include "pawn.h"
#include "disc.h"

#include <array>

class Board
{
public:
    Board();
    ~Board();

    void move_pawn(unsigned int);
    void draw();

private:
    std::array<Pawn*,5> pawns;
    std::array<Disc*,55> discs;
};

#endif
