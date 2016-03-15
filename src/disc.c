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

    disc_set_color(newDisc, color);
//  fprintf(stderr, "%p Disc color: %s\n", (void*) newDisc, disc_get_color_char(newDisc));

    return newDisc;
}

void print_disc(struct Disc* disc)
{
    switch (disc_get_color_int(disc)) {
        case 0:
        fprintf(stderr, ANSI_B_COLOR_RED " " ANSI_COLOR_RESET " ");
        break;

        case 1:
        fprintf(stderr, ANSI_B_COLOR_GREEN " " ANSI_COLOR_RESET " ");
        break;

        case 2:
        fprintf(stderr, ANSI_B_COLOR_BLUE " " ANSI_COLOR_RESET " ");
        break;

        case 3:
        fprintf(stderr, ANSI_B_COLOR_YELLOW " " ANSI_COLOR_RESET " ");
        break;

        case 4:
        fprintf(stderr, ANSI_B_COLOR_MAGENTA " " ANSI_COLOR_RESET " ");
        break;

        case 5:
        fprintf(stderr, ANSI_B_COLOR_WHITE " " ANSI_COLOR_RESET " ");
        break;

        case 6:
        fprintf(stderr, ANSI_B_COLOR_BLACK " " ANSI_COLOR_RESET " ");
        break;
    }

    return ;
}


int disc_set_color(struct Disc* disc, enum colors color)
{
    disc->_color = color;

    return 0;
}

int disc_get_color_int(struct Disc* disc)
{
    return disc->_color;
}

char* disc_get_color_char(struct Disc* disc)
{
    char* char_color = NULL;

    switch (disc_get_color_int(disc)) {
        case 0:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_RED));
        strncpy(char_color, COLOR_RED, strlen(COLOR_RED));
        break;

        case 1:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_GREEN));
        strncpy(char_color, COLOR_GREEN, strlen(COLOR_GREEN));
        break;

        case 2:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_BLUE));
        strncpy(char_color, COLOR_BLUE, strlen(COLOR_BLUE));
        break;

        case 3:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_YELLOW));
        strncpy(char_color, COLOR_YELLOW, strlen(COLOR_YELLOW));
        break;

        case 4:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_PURPLE));
        strncpy(char_color, COLOR_PURPLE, strlen(COLOR_PURPLE));
        break;

        case 5:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_WHITE));
        strncpy(char_color, COLOR_WHITE, strlen(COLOR_WHITE));
        break;

        case 6:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_BLACK));
        strncpy(char_color, COLOR_BLACK, strlen(COLOR_BLACK));
        break;
    }

    return char_color;
}

int destroy_disc(struct Disc* disc)
{
    free(disc);

    return 0;
}
