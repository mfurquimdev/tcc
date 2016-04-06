#include "board.h"

#include <cstdio>
#include <random>

Board::Board(unsigned char num_discs, unsigned char num_pawns)
{
    fprintf(stderr, "[%p]\tBoard(%d,%d)\n", (void*) this, (int) num_discs, (int) num_pawns);

    number_discs(num_discs);
    number_pawns(num_pawns);
    init_discs();
    init_pawns();

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

    for (auto pawn: pawns()) {
        pawn->draw();
    }

    for (auto disc: discs()) {
        disc->draw();
    }

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
