#include "board.h"

#include <cstdio>
#include <random>

Board::Board(unsigned char num_discs)
{
    fprintf(stderr, "[%p]\tBoard(%d)\n", (void*) this, (int) num_discs);

    number_discs(num_discs);
    init_discs();
}

Board::~Board()
{
    fprintf(stderr, "[%p]\tBoard destructor\n", (void*) this);

    for (auto disc: discs()) {
        delete(disc);
    }
}

/**
 * Public functions
 */

void
Board::draw()
{
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

/**
 * Getters and Setters
 */

std::vector<Disc*>
Board::discs(void)
{
    return _discs;
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
