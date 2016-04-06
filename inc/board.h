#ifndef BOARD_H
#define BOARD_H

#include "disc.h"

#include <vector>

class Board
{
public:
    Board(unsigned char);
    ~Board();

    void draw();

private:

    void init_discs(void);

    unsigned char number_discs(void);
    void number_discs(unsigned char);

    std::vector<Disc*> discs(void);

    unsigned char _num_discs;
    std::vector<Disc*> _discs;
};

#endif
