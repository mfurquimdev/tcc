#ifndef PAWN_H
#define PAWN_H

#include "colors.h"

class Pawn
{
public:
    Pawn(Colors);
    ~Pawn();

    void color(Colors);
    Colors color();
    const char* color_str();

    void position(unsigned int);
    unsigned int position();

    void draw();

private:
    Colors _color;
    unsigned int _position;

    void reset_position();
};

#endif
