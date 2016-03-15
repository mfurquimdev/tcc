#ifndef PAWN_H
#define PAWN_H

#include "colors.h"

struct Pawn {
    enum colors _color;
}Pawn;

struct Pawn* create_pawn(enum colors);
int destroy_pawn(struct Pawn*);
int pawn_set_color(struct Pawn*, enum colors);
int pawn_get_color_int(struct Pawn*);
char* pawn_get_color_char(struct Pawn*);
void print_pawn(struct Pawn*);

#endif
