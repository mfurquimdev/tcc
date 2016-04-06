#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    Player(unsigned char);
    ~Player();

    void draw();

private:

    void player_id(unsigned char);
    unsigned char player_id(void);

    unsigned char _id;
};

#endif
