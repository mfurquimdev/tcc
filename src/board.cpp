#include <stdlib.h>
#include <stdio.h>

#include "board.h"
#include "pawn.h"
#include "disc.h"

Board::Board()
{
    unsigned int color = 0;
    for (auto it = pawns.begin(); it != pawns.end(); ++it) {
        *it = new Pawn(color);
        color++;
    }
/*
    this->discs = (Disc**) malloc(sizeof(Disc*)*this->_num_discs);
    for (size_t i = 0; i < this->_num_discs; i++) {
        this->discs[i] = new Disc(i%5);
    }
*/
}

Board::~Board()
{
/*
    if (this->discs != NULL) {
        for (size_t i = this->_num_discs; i >= 0; i--) {
            if (this->discs[i] != NULL) {
                delete(this->discs[i]);
            }
        }
        delete(this->pawns);
    }

    if (this->pawns != NULL) {
        for (size_t i = this->_num_pawns; i >= 0; i--) {
            if (this->pawns[i] != NULL) {
                delete(this->pawns[i]);
            }
        }
        delete(this->pawns);
    }
*/
}

/*
void
Board::move_pawn(unsigned int color)
{
    for (size_t i = this->pawns[color]); i < 60; i++) {
        if (this->board->discs[i].color() == color) {
            this->pawns[color].position(i);

            break;
        }
    }
}

void
Board::draw()
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
*/
