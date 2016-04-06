#include "disc.h"

#include <cstdio>


#define ANSI_B_COLOR_WHITE   "\x1b[47m"
#define ANSI_B_COLOR_BLACK   "\x1b[40m"
#define ANSI_B_COLOR_RED     "\x1b[41m"
#define ANSI_B_COLOR_GREEN   "\x1b[42m"
#define ANSI_B_COLOR_YELLOW  "\x1b[43m"
#define ANSI_B_COLOR_BLUE    "\x1b[44m"
#define ANSI_B_COLOR_MAGENTA "\x1b[45m"

#define ANSI_COLOR_RESET   "\x1b[0m"


Disc::Disc(unsigned char colour)
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


/**
 * Private functions
 */


/**
 * Getters and Setters
 */


unsigned char
Disc::color(void)
{
    return this->_color;
}

void
Disc::color(unsigned char color)
{
    fprintf(stderr, "\tcolor(%d)\n", (int) color);
    this->_color = color;

    return ;
}
