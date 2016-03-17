#include <stdlib.h>
#include <stdio.h>

#include "board.h"
#include "pawn.h"
#include "disc.h"

struct Board* create_board()
{
    struct Board* newBoard = NULL;
    newBoard = (struct Board*) malloc(sizeof(struct Board));

    newBoard->pawns = (struct Pawn**) malloc(sizeof(struct Pawn*)*5);
    for (size_t i = 0; i < 5; i++)
        newBoard->pawns[i] = create_pawn(i);

    newBoard->discs = (struct Disc**) malloc(sizeof(struct Disc*)*60);
    for (size_t i = 0; i < 50; i++)
        newBoard->discs[i] = create_disc(i%5);

    for (size_t i = 0; i < 10; i++)
        newBoard->discs[50+i] = create_disc(5+(i%2));

    return newBoard;
}

int board_move_pawn(struct Board* board, int color)
{
    for (size_t i = pawn_get_position(board->pawns[color]); i < 60; i++) {
        if (disc_get_color_int(board->discs[i]) == color) {
            pawn_set_position(board->pawns[color], i);

            break;
        }
    }

    return 0;
}


void print_board(struct Board* board)
{
    for (size_t i = 0; i < 60; i++) {
        unsigned char drawn = 0;
        for (size_t j = 0; j < 5; j++) {
            if (pawn_get_position(board->pawns[j]) == i) {
                print_pawn(board->pawns[j]);
                drawn = 1;
                break;
            }
        }
        if (drawn) {
            continue;
        }
        else {
            if (board->discs[i] != NULL) {
                print_disc(board->discs[i]);
            }
            else {
                fprintf(stdout, "  ");
            }
        }
    }

    fprintf(stdout, "\n");

    return ;
}

int destroy_board(struct Board* board)
{
    if (board->discs != NULL)
        for (size_t i = 0; i < 60; i++)
            if (board->discs[i] != NULL)
                destroy_disc(board->discs[i]);
    free(board->discs);

    if (board->pawns != NULL)
        for (size_t i = 0; i < 5; i++)
            if (board->pawns[i] != NULL)
                destroy_pawn(board->pawns[i]);
    free(board->pawns);

    return 0;
}
