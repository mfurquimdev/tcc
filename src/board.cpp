#include <stdlib.h>
#include <stdio.h>
#include <array>

#include "board.h"
#include "pawn.h"
#include "disc.h"
#include "util.h"

Board::Board()
{
    unsigned int position = 0;

    fprintf(stderr, "\n");
    for (auto it = pawns.begin(); it != pawns.end(); ++it) {
        unsigned int color = position;
        *it = new Pawn(color);
        position++;
    }


    std::array<unsigned int, 7> disc_colors;
    disc_colors.fill(0);

    fprintf(stderr, "\n");
    for (size_t i = 0; i < 55;) {
        uint32_t nonce = my_random();
        unsigned int nonce_color = nonce % 7;

        if (nonce_color < 5 &&
            disc_colors[nonce_color] < 9)
        {
            this->discs[i] = new Disc(nonce_color, position);
            disc_colors[nonce_color]++;
            position++;
            i++;
        }
        else if (disc_colors[nonce_color] < 5) {
            /* nonce_color == White || nonce_color == Black */
            this->discs[i] = new Disc(nonce_color, position);
            disc_colors[nonce_color]++;
            position++;
            i++;
        }
    }

    stair = new Stair();


}

Board::~Board()
{
    fprintf(stderr, "\n");
    for (auto it = discs.begin(); it != discs.end(); ++it) {
        if (*it != NULL) {
            delete(*it);
            *it = NULL;
        }
    }

    fprintf(stderr, "\n");
    for (auto it = pawns.begin(); it != pawns.end(); ++it) {
        if (*it != NULL) {
            delete(*it);
            *it = NULL;
        }
    }
}

void
Board::move_pawn(unsigned int color)
{
    unsigned int pawn_pos = pawns.at(color)->position();
    unsigned char moved = 0;

    fprintf(stderr, "\n[%p]\tMove pawn(%d)\t\n", (void*) pawns.at(color), pawn_pos);

    for (auto it = discs.begin(); it != discs.end(); ++it) {
        Disc* disc = *it;

        unsigned int disc_pos = disc->position();
        fprintf(stderr, "%d > %d && %d == %d?\n", disc_pos, pawn_pos, disc->color(), pawns.at(color)->color());

        if (disc_pos > pawn_pos &&
            disc->color() == pawns.at(color)->color()) {
                pawns.at(color)->position(disc_pos);
                fprintf(stderr, "%d\n", pawns.at(color)->position());
                moved = 1;
                break;
        }

        disc = NULL;
    }

    if (!moved) {
        stair->step_up(pawns.at(color));
    }

    return ;
}

void
Board::draw()
{
    fprintf(stderr, "\nDraw Board\n");

    stair->draw();

    for (unsigned int current_position = 0; current_position < 60;) {
        unsigned char drawn = 0;
        fprintf(stderr, "%d\t", current_position);

        for (auto it = pawns.begin(); it != pawns.end(); ++it) {
            Pawn* pawn = *it;

            if (pawn->position() == current_position) {
                fprintf(stderr, "Pawn(%d) %s\n", current_position, pawn->color_str());
                pawn->draw();
                fprintf(stdout, " ");
                drawn = 1;
                current_position++;
                break;
            }

            pawn = NULL;
        }

        if (drawn) {
            continue;
        }

        for (auto it = discs.begin(); it != discs.end(); ++it) {
            Disc* disc = *it;

            if (disc->position() == current_position) {
                fprintf(stderr, "Disc(%d) %s\n", current_position, disc->color_str());
                disc->draw();
                drawn = 1;
                current_position++;
                break;
            }

            disc = NULL;
        }

        if (!drawn) {
            fprintf(stdout, "  ");
            fprintf(stderr, "\n");
            current_position++;
        }
    }

    for (size_t i = 0; i < 12; i++) {
        fprintf(stdout, "\n");
    }

    return ;
}
