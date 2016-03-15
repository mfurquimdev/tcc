#ifndef BOARD_H
#define BOARD_H

struct Board {
    struct Pawn** pawns;
    struct Disc** discs;

    unsigned int num_pawns;
    unsigned int num_discs;
}Board;

struct Board* create_board();
int destroy_board(struct Board*);
void print_board(struct Board*);
int board_move_pawn(struct Board*, int);

#endif
