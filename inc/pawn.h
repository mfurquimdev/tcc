#ifndef PAWN_H
#define PAWN_H

#include "colors.h"

class Pawn
{
public:
    Pawn(unsigned int);
    ~Pawn();

    void color(unsigned int);
    Colors color();
    const char* color_str();

    void position(unsigned int);
    unsigned int position();

    void draw();

private:
    Colors _color;
    unsigned int _position;

    unsigned int color_int(Colors);
    Colors int_color(unsigned int);

    void reset_position();
};

#endif
