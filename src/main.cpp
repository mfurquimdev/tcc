#include "game.h"

#include <cstdlib>

Game* initialize()
{
    Game* game = NULL;

    unsigned short int num_players = 2;
//    num_players = ask_num_players();

    unsigned short int num_pawns = 5;
//    num_pawns = ask_num_pawns();

    unsigned short int num_discs = 55;
//    num_discs = ask_num_discs();

    game = new Game(num_players, num_pawns, num_discs);

    return game;
}


int main()
{
    Game* game = NULL;
    game = initialize();
    game->loop();
    delete(game);

    return 0;
}
