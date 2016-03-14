#ifndef DISC_H
#define DISC_H

#include "colors.h"

struct Disc {
    enum colors _color;
}Disc;

struct Disc* create_disc(enum colors);
int destroy_disc(struct Disc*);
int set_color(struct Disc*, enum colors);
int get_color_int(struct Disc*);
char* get_color_char(struct Disc*);

#endif
