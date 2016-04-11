#include "disc.h"

#include <cstdio>

Disc::Disc(unsigned short int colour)
{
    fprintf(stderr, "[%p]\tDisc(%d)\n", (void*) this, (int) colour);

    color(colour);
}


Disc::~Disc()
{
    fprintf(stderr, "[%p]\tDisc destructor\n", (void*) this);
}


/**
 * Public functions
 */

void
Disc::draw(void)
{
    switch (color()) {
        case 0:
        printf(ANSI_B_COLOR_RED " " ANSI_COLOR_RESET " ");
        break;

        case 1:
        printf(ANSI_B_COLOR_GREEN " " ANSI_COLOR_RESET " ");
        break;

        case 2:
        printf(ANSI_B_COLOR_BLUE " " ANSI_COLOR_RESET " ");
        break;

        case 3:
        printf(ANSI_B_COLOR_YELLOW " " ANSI_COLOR_RESET " ");
        break;

        case 4:
        printf(ANSI_B_COLOR_MAGENTA " " ANSI_COLOR_RESET " ");
        break;

        case 5:
        printf(ANSI_B_COLOR_WHITE " " ANSI_COLOR_RESET " ");
        break;

        case 6:
        printf(ANSI_B_COLOR_BLACK " " ANSI_COLOR_RESET " ");
        break;

        default:
        printf("  ");
        break;
    }

    return ;
}

void
Disc::paint(void)
{
    switch (color()) {
        case 0:
        printf(ANSI_F_COLOR_RED);
        break;

        case 1:
        printf(ANSI_F_COLOR_GREEN);
        break;

        case 2:
        printf(ANSI_F_COLOR_BLUE);
        break;

        case 3:
        printf(ANSI_F_COLOR_YELLOW);
        break;

        case 4:
        printf(ANSI_F_COLOR_MAGENTA);
        break;

        default:
        printf(ANSI_COLOR_RESET);
        break;
    }

    return ;
}

/**
 * Private functions
 */


/**
 * Getters and Setters
 */


unsigned short int
Disc::color(void)
{
    return this->_color;
}

void
Disc::color(unsigned short int color)
{
    fprintf(stderr, "\tcolor(%d)\n", (int) color);
    this->_color = color;

    return ;
}
