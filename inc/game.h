#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"

#include <vector>

class Game
{
public:
    Game(unsigned short int, unsigned short int, unsigned short int);
    ~Game();

    void loop(void);

private:

    /* Functions */
    void draw(unsigned short int);
    unsigned short int choose_pawn(unsigned short int);
    unsigned short int choose_disc(unsigned short int, std::vector<std::pair<Disc*, Pawn*> >::iterator);

    void init_players(void);
    void init_board(void);

    /* Getters and Setters */
    void number_players(unsigned short int);
    unsigned short int number_players(void);

    void number_pawns(unsigned short int);
    unsigned short int number_pawns(void);

    void number_discs(unsigned short int);
    unsigned short int number_discs(void);

    std::vector<Player*> players(void);

    Board* board(void);

    /* Variables */
    unsigned short int _num_players;
    unsigned short int _num_pawns;
    unsigned short int _num_discs;
    std::vector<Player*> _players;
    Board* _board;
};

#endif
