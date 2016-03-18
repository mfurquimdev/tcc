#ifndef DISC_H
#define DISC_H

#include "colors.h"

class Disc
{
public:
    Disc(unsigned int);
    ~Disc();

    void color(unsigned int);
    Colors color();
    const char* color_str();

    void draw();

private:
    Colors int_color(unsigned int);
    Colors _color;
};

#endif
