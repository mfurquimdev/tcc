#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disc.h"

/*******************************************************************************
 * Disco
 ******************************************************************************/

struct Disc* create_disc(enum colors color)
{
    struct Disc* newDisc = NULL;
    newDisc = (struct Disc*) malloc(sizeof(struct Disc));

    set_color(newDisc, color);
    fprintf(stderr, "%p Disc color: %s\n", (void*) newDisc, get_color_char(newDisc));

    return newDisc;
}

int set_color(struct Disc* disc, enum colors color)
{
    disc->_color = color;

    return 0;
}

int get_color_int(struct Disc* disc)
{
    return disc->_color;
}

char* get_color_char(struct Disc* disc)
{
    switch (get_color_int(disc)) {
        case 0:
        return color_red;
        break;

        case 1:
        return color_green;
        break;

        case 2:
        return color_blue;
        break;

        case 3:
        return color_yellow;
        break;

        case 4:
        return color_purple;
        break;

        case 5:
        return color_white;
        break;

        case 6:
        return color_black;
        break;
    }

    return NULL;
}

int destroy_disc(struct Disc* disc)
{
    free(disc);

    return 0;
}
