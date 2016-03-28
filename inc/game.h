#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(unsigned char, unsigned char, unsigned char);
    ~Game();

    void loop();

private:
    Board* board;
    std::vector<Player> players;

    unsigned char moving_pawn(Board*);
    unsigned char ask_pawn_to_move(Board*);

    void picking_disc();

    void draw(unsigned char);
};

#endif
