#include "game.h"

#include <cstdio>

Game::Game(unsigned char num_players,
            unsigned char num_pawns,
            unsigned char num_discs)
{
    fprintf(stderr, "[%p]\tGame(%d,%d,%2d)\n",
        (void*) this,
        (int) num_players,
        (int) num_pawns,
        (int) num_discs);

    number_players(num_players);
    number_pawns(num_pawns);
    number_discs(num_discs);
    init_players();
}

Game::~Game()
{
    fprintf(stderr, "[%p]\tGame destructor\n", (void*) this);

    for (auto player: players()) {
        delete(player);
    }
}

/**
 * Public functions
 */

void
Game::loop(void)
{
    fprintf(stderr, "Game loop(void)\n");
    unsigned char quit = 0;

    while (!quit) {
        fprintf(stderr, "Not quit\n");

        for (unsigned char id_player = 0;
                id_player < number_players();
                id_player++)
        {
            fprintf(stderr, "\nPlayer %d\n", (int) id_player);

            draw(id_player);

            unsigned char chosen_pawn = 0;
            chosen_pawn = choose_pawn();

            draw(id_player);

            choose_disc(chosen_pawn);

            quit = id_player;

            if (quit) {
                fprintf(stderr, "Quitting\n");
                break;
            }
        }
    }

    return ;
}

/**
 * Private functions
 */

unsigned char
Game::choose_pawn(void)
{
    fprintf(stderr, "\tchoose_pawn(void)\n");

    unsigned char chosen_pawn = 0;

    return chosen_pawn;
}

unsigned char
Game::choose_disc(unsigned char chosen_pawn)
{
    fprintf(stderr, "\tchoose_disc(%d)\n", (int) chosen_pawn);

    unsigned char chosen_disc = 0;

    // Dummy Attribution
    chosen_disc += chosen_pawn;

    return chosen_disc;
}

void
Game::draw(unsigned char current_player)
{
    fprintf(stderr, "\tDraw(%d)\n", (int) current_player);

    for (auto player: players()) {
        player->draw();
    }

    return ;
}

void
Game::init_players(void)
{
    fprintf(stderr, "\tinit_players(void)\n");

    for (unsigned char player_id = 0;
            player_id < number_players();
            player_id++)
    {
        Player* new_player = new Player(player_id);
        this->_players.push_back(new_player);
    }

    return ;
}

/**
 * Getters and Setters
 */

void
Game::number_players(unsigned char num_players)
{
    fprintf(stderr, "\tnumber_players(%d)\n", (int) num_players);
    this->_num_players = num_players;

    return ;
}

unsigned char
Game::number_players(void)
{
    return this->_num_players;
}

void
Game::number_pawns(unsigned char num_pawns)
{
    fprintf(stderr, "\tnumber_pawns(%d)\n", (int) num_pawns);
    this->_num_pawns = num_pawns;

    return ;
}

unsigned char
Game::number_pawns(void)
{
    return this->_num_pawns;
}

void
Game::number_discs(unsigned char num_discs)
{
    fprintf(stderr, "\tnumber_discs(%d)\n", (int) num_discs);
    this->_num_discs = num_discs;

    return ;
}

unsigned char
Game::number_discs(void)
{
    return this->_num_discs;
}

std::vector<Player*>
Game::players(void)
{
    return this->_players;
}
