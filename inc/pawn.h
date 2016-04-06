#ifndef PAWN_H
#define PAWN_H


class Pawn
{
public:
    Pawn(unsigned char);
    ~Pawn();

    void draw(void);
    void paint();

    unsigned char color(void);

private:

    void color(unsigned char);

    unsigned char _color;
};

#endif
