#ifndef BOARD_H
#define BOARD_H

#include "disc.h"
#include "pawn.h"

#include <vector>

class Board
{
public:
    Board(unsigned char, unsigned char);
    ~Board();

    /* Use pair to print.
    std::pair<Disc*, Pawn*>.
    if pair.second != NULL print pawn;
    else if pair.first != NULL print disc;
    else print blank space*/
    void draw();

private:

    void init_discs(void);
    void init_pawns(void);

    unsigned char number_discs(void);
    void number_discs(unsigned char);

    unsigned char number_pawns(void);
    void number_pawns(unsigned char);

    std::vector<Disc*> discs(void);
    std::vector<Pawn*> pawns(void);

    unsigned char _num_discs;
    std::vector<Disc*> _discs;

    unsigned char _num_pawns;
    std::vector<Pawn*> _pawns;
};

#endif
