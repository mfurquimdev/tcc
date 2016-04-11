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
    Board(unsigned short int, unsigned short int);
    ~Board();

    void draw(void);
    unsigned short int invalid_move(unsigned short int);
    std::vector<std::pair<Disc*, Pawn*> >::iterator move_pawn(unsigned short int);
    Disc* pick_disc(unsigned short int);

private:

    std::vector<std::pair<Disc*, Pawn*> >::iterator find_pawn_index(Pawn*);

    void init_discs(void);
    void init_pawns(void);

    unsigned short int number_discs(void);
    void number_discs(unsigned short int);

    unsigned short int number_pawns(void);
    void number_pawns(unsigned short int);

    std::vector<Disc*> discs(void);
    std::vector<Pawn*> pawns(void);
    Stair* stair(void);

    std::vector<std::pair<Disc*, Pawn*> > _printable_board;

    unsigned short int _num_discs;
    std::vector<Disc*> _discs;

    unsigned short int _num_pawns;
    std::vector<Pawn*> _pawns;

    Stair* _stair;
};

#endif
