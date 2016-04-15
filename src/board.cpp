#include "board.h"

#include <iostream>
#include <cstdio>
#include <random>

Board::Board(unsigned short int num_discs, unsigned short int num_pawns)
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

Disc*
Board::pick_disc(unsigned short int chosen_disc)
{
    Disc* disc_picked = this->_printable_board.at(number_pawns()+chosen_disc).first;
    this->_printable_board.at(number_pawns()+chosen_disc).first = NULL;

    return disc_picked;
}

std::vector<std::pair<Disc*, Pawn*> >::iterator
Board::move_pawn(unsigned short int chosen_pawn)
{
    fprintf(stderr, "\tmove_pawn(%d)\n", chosen_pawn);
    Pawn* pawn = pawns().at(chosen_pawn);
    unsigned short int moved = 0;

    std::vector<std::pair<Disc*, Pawn*> >::iterator it = find_pawn_index(pawn);
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
        else if (p_pawn == NULL && p_disc != NULL) {
            fprintf(stderr, "d: %d\t", p_disc->color());
            if (pawn->color() == p_disc->color()) {
                (*it).second = pawn;
                moved = 1;
                break;
            }
        }
        fprintf(stderr, "\n");
    }

    if (!stair()->contains(pawn) && !moved) {
        stair()->step_up(pawn);
    }

    return it;
}

std::pair<std::pair<unsigned short int, std::vector<std::pair<Disc*, Pawn*> >::iterator>, std::pair<unsigned short int, std::vector<std::pair<Disc*, Pawn*> >::iterator> >
Board::find_neighbors(std::vector<std::pair<Disc*, Pawn*> >::iterator pawn_index)
{
    std::pair<std::pair<unsigned short int, std::vector<std::pair<Disc*, Pawn*> >::iterator>, std::pair<unsigned short int, std::vector<std::pair<Disc*, Pawn*> >::iterator> > neighbors;

    unsigned short int index = 0;
    std::vector<std::pair<Disc*, Pawn*> >::iterator pawn_index_it = this->_printable_board.begin();
    for (; pawn_index_it != pawn_index; ++pawn_index_it) {
        ++index;
    }

    std::pair<unsigned short int, std::vector<std::pair<Disc*, Pawn*> >::iterator> prev_pair;

    unsigned short int prev_disc = index;
    std::vector<std::pair<Disc*, Pawn*> >::iterator prev_it = pawn_index_it;
    for (; prev_it != this->_printable_board.begin(); --prev_it) {
        std::pair<Disc*, Pawn*> disc_pawn = *prev_it;
        Disc* p_disc = disc_pawn.first;
        Pawn* p_pawn = disc_pawn.second;

        if (p_pawn == NULL &&
            p_disc != NULL) {
            p_disc = NULL;
            p_pawn = NULL;
            break;
        }
        p_disc = NULL;
        p_pawn = NULL;
        prev_disc--;
    }
    prev_pair

    std::vector<std::pair<Disc*, Pawn*> >::iterator next_it = pawn_index_it;
    unsigned short int next_disc = index;
    for (; next_it != this->_printable_board.end(); ++next_it) {
        std::pair<Disc*, Pawn*> disc_pawn = *next_it;
        Disc* p_disc = disc_pawn.first;
        Pawn* p_pawn = disc_pawn.second;

        if (p_pawn == NULL &&
            p_disc != NULL) {
            p_disc = NULL;
            p_pawn = NULL;
            break;
        }
        p_disc = NULL;
        p_pawn = NULL;
        next_disc++;
    }

    neighbors

    return neighbors;
}

unsigned short int
Board::invalid_move(unsigned short int chosen_pawn)
{
    fprintf(stderr, "\tintavlid_move(%d)\n", chosen_pawn);
    unsigned short int invalid = 0;

    if (chosen_pawn >= number_pawns()) {
        invalid = 1;
    }
    else {
        Pawn* pawn = pawns().at(chosen_pawn);

        std::vector<std::pair<Disc*, Pawn*> >::iterator it = find_pawn_index(pawn);

        for (; it != this->_printable_board.end(); ++it) {
            std::pair<Disc*, Pawn*> disc_pawn = *it;
            Disc* p_disc = disc_pawn.first;
            Pawn* p_pawn = disc_pawn.second;

            if (p_pawn == NULL && p_disc != NULL) {
                fprintf(stderr, "d: %d\t", p_disc->color());
                if (pawn->color() == p_disc->color()) {
                    break;
                }
            }
            fprintf(stderr, "\n");
        }

        if (stair()->contains(pawn) &&
            it == this->_printable_board.end())
        {
            invalid = 1;
        }
    }

    fprintf(stderr, "invalid [%d]\n", (int) invalid);
    return invalid;
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
    for (unsigned short int i = 0; i < number_discs(); i++) {
        if (this->_printable_board.at(number_pawns()+i).first != NULL) {
            discs().at(i)->paint();
            printf("%d ", i/10);
        }
        else {
            printf("  ");
        }
    }

    printf("\n");

    for (unsigned short int i = 0; i < number_pawns(); i++) {
        pawns().at(i)->paint();
        printf("%hu ", i);
    }

    printf(ANSI_COLOR_RESET);

    for (unsigned short int i = 0; i < number_discs(); i++) {
        if (this->_printable_board.at(number_pawns()+i).first != NULL) {
            discs().at(i)->paint();
            printf("%d ", i%10);
        }
        else {
            printf("  ");
        }
    }
    printf(ANSI_COLOR_RESET "\n");


    return ;
}

std::vector<std::pair<Disc*, Pawn*> >
Board::printable_board(void)
{
    return this->_printable_board;
}

/**
 * Private functions
 */

std::vector<std::pair<Disc*, Pawn*> >::iterator
Board::find_pawn_index(Pawn* pawn)
{
    std::vector<std::pair<Disc*, Pawn*> >::iterator it = this->_printable_board.begin();
    for (; it != this->_printable_board.end(); ++it) {
        std::pair<Disc*, Pawn*> disc_pawn = *it;
        Pawn* p_pawn = disc_pawn.second;

        if (p_pawn != NULL) {
            if (pawn->color() == p_pawn->color()) {
                p_pawn = NULL;
                break;
            }
        }

        p_pawn = NULL;
    }

    return it;
}

void
Board::init_discs(void)
{
    std::vector<unsigned int> disc_colors;
    disc_colors.assign(7,0);

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,6);

    for (unsigned short int disc_num = 0; disc_num < number_discs();) {
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
    for (unsigned short int pawn_color = 0; pawn_color < number_pawns(); pawn_color++) {
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

unsigned short int
Board::number_discs(void)
{
    return this->_num_discs;
}

void
Board::number_discs(unsigned short int num_discs)
{
    fprintf(stderr, "\tnumber_discs(%d)\n", (int) num_discs);

    this->_num_discs = num_discs;

    return ;
}

unsigned short int
Board::number_pawns(void)
{
    return this->_num_pawns;
}

void
Board::number_pawns(unsigned short int num_pawns)
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
