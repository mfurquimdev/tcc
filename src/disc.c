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
    char* char_color = NULL;
    
    switch (get_color_int(disc)) {
        case 0:
        char_color = (char*) malloc(sizeof(char)*sizeof(color_red));
        strncpy(char_color, color_red, sizeof(color_red));
        break;

        case 1:
        char_color = (char*) malloc(sizeof(char)*sizeof(color_green));
        strncpy(char_color, color_green, sizeof(color_green));
        break;

        case 2:
        char_color = (char*) malloc(sizeof(char)*sizeof(color_blue));
        strncpy(char_color, color_blue, sizeof(color_blue));
        break;

        case 3:
        char_color = (char*) malloc(sizeof(char)*sizeof(color_yellow));
        strncpy(char_color, color_yellow, sizeof(color_yellow));
        break;

        case 4:
        char_color = (char*) malloc(sizeof(char)*sizeof(color_purple));
        strncpy(char_color, color_purple, sizeof(color_purple));
        break;

        case 5:
        char_color = (char*) malloc(sizeof(char)*sizeof(color_white));
        strncpy(char_color, color_white, sizeof(color_white));
        break;

        case 6:
        char_color = (char*) malloc(sizeof(char)*sizeof(color_black));
        strncpy(char_color, color_black, sizeof(color_black));
        break;
    }

    return char_color;
}

int destroy_disc(struct Disc* disc)
{
    free(disc);

    return 0;
}
