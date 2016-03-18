#ifndef DISC_H
#define DISC_H

#include "colors.h"

class Disc
{
public:
    Disc(unsigned int, unsigned int);
    ~Disc();

    void color(unsigned int);
    Colors color();
    const char* color_str();

    void position(unsigned int);
    unsigned int position();

    void draw();

private:
    Colors int_color(unsigned int);
    Colors _color;
    unsigned int _position;
};

#endif
