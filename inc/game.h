#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(unsigned char, unsigned char, unsigned char);
    ~Game();

    void loop();
    void draw(unsigned char);

private:

    void number_players(unsigned char);
    unsigned char number_players(void);

    void number_pawns(unsigned char);
    unsigned char number_pawns(void);

    void number_discs(unsigned char);
    unsigned char number_discs(void);

    unsigned char _num_players;
    unsigned char _num_pawns;
    unsigned char _num_discs;
};

#endif
