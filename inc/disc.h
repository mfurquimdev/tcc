#ifndef DISC_H
#define DISC_H

#include "colors.h"

struct Disc {
    enum colors _color;
}Disc;

struct Disc* create_disc(enum colors);
int destroy_disc(struct Disc*);
int disc_set_color(struct Disc*, enum colors);
int disc_get_color_int(struct Disc*);
char* disc_get_color_char(struct Disc*);
void print_disc(struct Disc*);

#endif
