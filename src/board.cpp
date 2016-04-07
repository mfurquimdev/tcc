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

unsigned char
Board::move_pawn(unsigned char chosen_pawn)
{
    fprintf(stderr, "\tmove_pawn(%d)\n", chosen_pawn);
    Pawn* pawn = pawns().at(chosen_pawn);
    unsigned char pawn_index = 0;

    std::vector<std::pair<Disc*, Pawn*> >::iterator it = this->_printable_board.begin();
    for (; it != this->_printable_board.end(); ++it) {
        std::pair<Disc*, Pawn*> disc_pawn = *it;
        Disc* p_disc = disc_pawn.first;
        Pawn* p_pawn = disc_pawn.second;

        if (p_pawn != NULL) {
            fprintf(stderr, "p: %d", p_pawn->color());
            if (pawn->color() == p_pawn->color()) {
                (*it).second = NULL;
            }
        }
        else if (p_disc != NULL) {
            fprintf(stderr, "d: %d\t", p_disc->color());
            if (pawn->color() == p_disc->color()) {
                (*it).second = pawn;
                break;
            }
        }
        fprintf(stderr, "\n");
    }
/*
    unsigned char found = 0;
    for (auto disc_pawn: this->_printable_board) {
        fprintf(stderr, "pawn_index %d\n", pawn_index);
        if (!found &&
            disc_pawn.second != NULL &&
            disc_pawn.second->color() == pawn->color())
        {
            disc_pawn.second = (Pawn*) NULL;
            found = 1;
        }

        if (found &&
            disc_pawn.first != NULL &&
            disc_pawn.first->color() == pawn->color())
        {
            disc_pawn.second = pawn;
            break;
        }
        pawn_index++;
    }

    pawn = (Pawn*) NULL;

    fprintf(stderr, "pawn_index %d\n", pawn_index);
*/
    return pawn_index;
}

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

    printf("\n          ");
    for (unsigned char i = 0; i < number_discs(); i++) {
        discs().at(i)->paint();
        printf("%d ", (int) (i/10));
    }

    printf("\n");

    for (unsigned char i = 0; i < number_pawns(); i++) {
        pawns().at(i)->paint();
        printf("%d ", (int) i);
    }

    printf(ANSI_COLOR_RESET);

    for (unsigned char i = 0; i < number_discs(); i++) {
        discs().at(i)->paint();
        printf("%d ", (int) (i%10));
    }
    printf(ANSI_COLOR_RESET "\n");


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
