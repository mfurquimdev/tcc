#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"

#include <vector>

class Game
{
public:
    Game(unsigned char, unsigned char, unsigned char);
    ~Game();

    void loop(void);

private:

    /* Functions */
    void draw(unsigned char);
    unsigned char choose_pawn(void);
    unsigned char choose_disc(unsigned char);

    void init_players(void);
    void init_board(void);

    /* Getters and Setters */
    void number_players(unsigned char);
    unsigned char number_players(void);

    void number_pawns(unsigned char);
    unsigned char number_pawns(void);

    void number_discs(unsigned char);
    unsigned char number_discs(void);

    std::vector<Player*> players(void);

    Board* board(void);

    /* Variables */
    unsigned char _num_players;
    unsigned char _num_pawns;
    unsigned char _num_discs;
    std::vector<Player*> _players;
    Board* _board;
};

#endif
