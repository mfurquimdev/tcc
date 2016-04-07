#ifndef BOARD_H
#define BOARD_H

#include "disc.h"
#include "pawn.h"
#include "stair.h"

#include <vector>

#define ANSI_COLOR_RESET   "\x1b[0m"

class Board
{
public:
    Board(unsigned char, unsigned char);
    ~Board();

    void draw(void);

private:

    void init_discs(void);
    void init_pawns(void);

    unsigned char number_discs(void);
    void number_discs(unsigned char);

    unsigned char number_pawns(void);
    void number_pawns(unsigned char);

    std::vector<Disc*> discs(void);
    std::vector<Pawn*> pawns(void);
    Stair* stair(void);

    std::vector<std::pair<Disc*, Pawn*> > _printable_board;

    unsigned char _num_discs;
    std::vector<Disc*> _discs;

    unsigned char _num_pawns;
    std::vector<Pawn*> _pawns;

    Stair* _stair;
};

#endif
