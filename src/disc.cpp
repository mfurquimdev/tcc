#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disc.h"
#include "colors.h"


Disc::Disc(Colors color)
{
    this->color(color);
    fprintf(stderr, "[%p]\tDisc\t%s\n", (void*) this, this->color_str());
}

Disc::~Disc()
{
    fprintf(stderr, "[%p] destroy disc\n", (void*) this);
}

void
Disc::color(Colors color)
{
    this->_color = color;
}

Colors
Disc::color()
{
    return this->_color;
}

const char*
Disc::color_str()
{
    const char* char_color = NULL;

    switch (this->color()) {
        case ENUM_RED:
        char_color = COLOR_RED;
        break;

        case ENUM_GREEN:
        char_color = COLOR_GREEN;
        break;

        case ENUM_BLUE:
        char_color = COLOR_BLUE;
        break;

        case ENUM_YELLOW:
        char_color = COLOR_YELLOW;
        break;

        case ENUM_PURPLE:
        char_color = COLOR_PURPLE;
        break;

        case ENUM_WHITE:
        char_color = COLOR_WHITE;
        break;

        case ENUM_BLACK:
        char_color = COLOR_BLACK;
        break;
    }

    return char_color;
}

void
Disc::draw()
{
    switch (this->color()) {
        case ENUM_RED:
        fprintf(stdout, ANSI_B_COLOR_RED " " ANSI_COLOR_RESET " ");
        break;

        case ENUM_GREEN:
        fprintf(stdout, ANSI_B_COLOR_GREEN " " ANSI_COLOR_RESET " ");
        break;

        case ENUM_BLUE:
        fprintf(stdout, ANSI_B_COLOR_BLUE " " ANSI_COLOR_RESET " ");
        break;

        case ENUM_YELLOW:
        fprintf(stdout, ANSI_B_COLOR_YELLOW " " ANSI_COLOR_RESET " ");
        break;

        case ENUM_PURPLE:
        fprintf(stdout, ANSI_B_COLOR_MAGENTA " " ANSI_COLOR_RESET " ");
        break;

        case ENUM_WHITE:
        fprintf(stdout, ANSI_B_COLOR_WHITE " " ANSI_COLOR_RESET " ");
        break;

        case ENUM_BLACK:
        fprintf(stdout, ANSI_B_COLOR_BLACK " " ANSI_COLOR_RESET " ");
        break;
    }

    return ;
}
