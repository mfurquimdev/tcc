#ifndef BOARD_H
#define BOARD_H

#include "pawn.h"
#include "disc.h"
#include "stair.h"

#include <array>

class Board
{
public:
    Board();
    ~Board();

    unsigned char move_pawn(unsigned int);
    void draw();
    std::array<std::pair<Colors, int>,5> retrieve_colors_worth();
    Stair* stair;
    std::pair<Disc*, Disc*> get_adjacent_discs(unsigned int);
    unsigned char is_avaliable(Disc*);

private:
    std::array<Pawn*,5> pawns;
    std::array<Disc*,55> discs;
};

#endif
