#include "pawn.h"

#include <cstdio>

Pawn::Pawn(unsigned char colour)
{
    fprintf(stderr, "[%p]\tPawn(%d)\n", (void*) this, (int) colour);

    color(colour);
}


Pawn::~Pawn()
{
    fprintf(stderr, "[%p]\tPawn destructor\n", (void*) this);
}


/**
 * Public functions
 */

void
Pawn::draw(void)
{
    switch (color()) {
        case 0:
        printf(ANSI_F_COLOR_RED "P" ANSI_COLOR_RESET " ");
        break;

        case 1:
        printf(ANSI_F_COLOR_GREEN "P" ANSI_COLOR_RESET " ");
        break;

        case 2:
        printf(ANSI_F_COLOR_BLUE "P" ANSI_COLOR_RESET " ");
        break;

        case 3:
        printf(ANSI_F_COLOR_YELLOW "P" ANSI_COLOR_RESET " ");
        break;

        case 4:
        printf(ANSI_F_COLOR_MAGENTA "P" ANSI_COLOR_RESET " ");
        break;

        default:
        printf(ANSI_COLOR_RESET "  ");
        break;
    }

    return ;
}

void
Pawn::paint(void)
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


unsigned char
Pawn::color(void)
{
    return this->_color;
}

void
Pawn::color(unsigned char color)
{
    fprintf(stderr, "\tcolor(%d)\n", (int) color);
    this->_color = color;

    return ;
}
