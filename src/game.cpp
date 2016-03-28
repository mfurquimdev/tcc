#include "game.h"
#include "board.h"
#include "player.h"

using namespace std;

Game::Game(
    unsigned char number_players,
    unsigned char number_pawns,
    unsigned char number_discs)
{
    board = new Board(number_pawns, number_discs);

    for (unsigned char i = 0; i < number_players; i++) {
        Player* player = new Player(i);
        players.push_back(player)
    }
}

Game::~Game()
{
    if (players != NULL) {
        vector<Player>::reverse_iterator rit = players.rbegin();
        while (rit != players.rend()) {
            if ((*rit) != NULL) {
                destroy((*rit));
            }
            ++rit;
        }
    }

    if (board != NULL) {
        delete(board);
    }
}

void
Game::loop()
{
    unsigned char quit = 0;

    while (!quit) {
        for (unsigned char i = 0; i < (unsigned char) players.size(); i++) {

            draw(i+1);

            pawn_to_move = moving_pawn(board);

            draw(i+1);

            picking_disc(board, pawn_to_move);

            if (quit) {
                break;
            }
        }
    }

    return ;
}

unsigned char
Game::moving_pawn(Board* board)
{
    /* Run AI (instead of input)
    if(ai) {
        run_ai(board);
    }
    else {
    */

    // Input
    unsigned char pawn_to_move = 0;
    pawn_to_move = ask_pawn_to_move(board);

    // Update game entities
    board->move_pawn(pawn_to_move);

    return pawn_to_move;
}

unsigned char
Game::ask_pawn_to_move(Board* board)
{
    unsigned char pawn_to_move = 0;
    


    return pawn_to_move;
}

void
Game::picking_disc()
{
    /* Run AI (instead of input)
    if(ai) {
        run_ai(board);
    }
    else {
    */

    // Input
    unsigned char disc_to_pick = 0;
    disc_to_pick = ask_disc_to_pick(board, pawn_to_move);

    // Update game entities
    Disc* disc_picked = (Disc*) NULL;
    disc_picked = board->pick_disc(disc_to_pick);
    players.at(i)->pick_disc(disc_picked);

    return ;
}

void
Game::draw(unsigned char current_player)
{
    printf("Player %d\n", (int) current_player);

    for (vector<Player> it = players.begin(); it != players.end(); ++it) {
        (*it)->draw();
    }

    board->draw();

    return ;
}
