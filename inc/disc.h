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

    Colors int_color(unsigned int);

    void draw();

private:
    Colors _color;
    unsigned int _position;
};

#endif
