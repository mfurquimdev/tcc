#include "board.h"

#include <iostream>
#include <cstdio>
#include <random>

Board::Board(unsigned char num_discs, unsigned char num_pawns)
{
    fprintf(stderr, "[%p]\tBoard(%d,%d)\n", (void*) this, (int) num_discs, (int) num_pawns);

    number_discs(num_discs);
    number_pawns(num_pawns);
    init_discs();
    init_pawns();

    for (auto pawn: pawns()) {
        std::pair<Disc*, Pawn*> disc_pawn = std::make_pair((Disc*) NULL, pawn);
        this->_printable_board.push_back(disc_pawn);
    }

    for (auto disc: discs()) {
        std::pair<Disc*, Pawn*> disc_pawn = std::make_pair(disc, (Pawn*) NULL);
        this->_printable_board.push_back(disc_pawn);
    }

    this->_stair = new Stair();
}

Board::~Board()
{
    fprintf(stderr, "\n[%p]\tBoard destructor\n", (void*) this);

    for (auto disc: discs()) {
        delete(disc);
    }

    for (auto pawn: pawns()) {
        delete(pawn);
    }

    delete(this->_stair);
}

/**
 * Public functions
 */

void
Board::draw()
{
    stair()->draw();

    for (auto pair: this->_printable_board) {
        if (pair.second != NULL) {
            pair.second->draw();
        }
        else if (pair.first != NULL) {
            pair.first->draw();
        }
        else {
            printf("  ");
        }
    }
    printf("\n");

    return ;
}

/**
 * Private functions
 */

void
Board::init_discs(void)
{
    std::vector<unsigned int> disc_colors;
    disc_colors.assign(7,0);

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,6);

    for (unsigned char disc_num = 0; disc_num < number_discs();) {
        int nonce = distribution(generator);

        if (/* nonce_color != White && nonce_color != Black && qte < 9 */
            (nonce < 5 && disc_colors[nonce] < 9) ||

            /* nonce_color == White || nonce_color == Black && qte < 5*/
            (disc_colors[nonce] < 5))
        {
            Disc* new_disc = new Disc(nonce);
            this->_discs.push_back(new_disc);
            disc_colors[nonce]++;
            disc_num++;
        }
    }

    return ;
}

void
Board::init_pawns(void)
{
    for (unsigned char pawn_color = 0; pawn_color < number_pawns(); pawn_color++) {
        Pawn* new_pawn = new Pawn(pawn_color);
        this->_pawns.push_back(new_pawn);
    }
    return ;
}

/**
 * Getters and Setters
 */

std::vector<Disc*>
Board::discs(void)
{
    return this->_discs;
}

std::vector<Pawn*>
Board::pawns(void)
{
    return this->_pawns;
}

unsigned char
Board::number_discs(void)
{
    return this->_num_discs;
}

void
Board::number_discs(unsigned char num_discs)
{
    fprintf(stderr, "\tnumber_discs(%d)\n", (int) num_discs);

    this->_num_discs = num_discs;

    return ;
}

unsigned char
Board::number_pawns(void)
{
    return this->_num_pawns;
}

void
Board::number_pawns(unsigned char num_pawns)
{
    fprintf(stderr, "\tnumber_pawns(%d)\n", (int) num_pawns);

    this->_num_pawns = num_pawns;

    return ;
}

Stair*
Board::stair(void)
{
    return this->_stair;
}
