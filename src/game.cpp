#include "game.h"

#include <cstdio>
#include <stdio_ext.h>

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
    init_board();
}

Game::~Game()
{
    fprintf(stderr, "\n[%p]\tGame destructor\n", (void*) this);

    for (auto player: players()) {
        delete(player);
    }

    delete(board());
}

/**
 * Public functions
 */

void
Game::loop(void)
{
    fprintf(stderr, "Game loop(void)\n");
    unsigned char quit = 0;
    unsigned long long int turn = 0;

    while (!quit) {
        for (unsigned char id_player = 0;
                id_player < number_players();
                id_player++)
        {
            fprintf(stderr, "\nturn %llu\tid_player %d\n",
                turn,
                (int) id_player);

            draw(id_player);

            unsigned char chosen_pawn;
            chosen_pawn = choose_pawn();

            draw(id_player);

            unsigned char chosen_disc;
            chosen_disc = choose_disc(chosen_pawn);

            // Just a dummy way to quit
            quit = id_player;

            if (quit) {
                fprintf(stderr, "\nQuitting\n");
                break;
            }

            turn++;
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

    printf("Qual peao desejas mover?\n");
    unsigned short int chosen_pawn;
    scanf("%hu", &chosen_pawn);

    fprintf(stderr, "chosen_pawn [%hu]\n", chosen_pawn);
    return (unsigned char) chosen_pawn;
}

unsigned char
Game::choose_disc(unsigned char chosen_pawn)
{
    fprintf(stderr, "\tchoose_disc(%hu)\n", (unsigned short int) chosen_pawn);

    printf("Qual disco desejas pegar?\n");
    unsigned short int chosen_disc;

    scanf("%hu", &chosen_disc);

    fprintf(stderr, "chosen_disc [%hu]\n", chosen_disc);
    return (unsigned char) chosen_disc;
}

void
Game::draw(unsigned char current_player)
{
    fprintf(stderr, "\tdraw(%d)\n", (int) current_player);

    for (auto player: players()) {
        player->draw();
    }

    printf("\n");

    board()->draw();

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

void
Game::init_board(void)
{
    fprintf(stderr, "\tinit_board(void)\n");

    this->_board = new Board(number_discs(), number_pawns());

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

Board*
Game::board(void)
{
    return this->_board;
}
