#ifndef DISC_H
#define DISC_H

#include "colors.h"

class Disc
{
public:
    Disc(Colors);
    ~Disc();

    void color(Colors);
    Colors color();
    const char* color_str();

    void draw();

private:
    Colors _color;
};

#endif
