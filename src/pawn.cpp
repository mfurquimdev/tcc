#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pawn.h"
#include "colors.h"


Pawn::Pawn(unsigned int color)
{
    this->color(color);
    this->reset_position();
    fprintf(stderr, "[%p]\tPawn(%d)\t%s\n", (void*) this, this->position(), this->color_str());
}

Pawn::~Pawn()
{
    fprintf(stderr, "[%p] destroy pawn\n", (void*) this);
}

void
Pawn::color(unsigned int color)
{
    if (color < 5) {
        this->_color = this->int_color(color);
    }
    else {
        fprintf(stderr, "[%p]\tPawn cannot be of colors white or black\n", (void*) this);
    }
}

Colors
Pawn::color()
{
    return this->_color;
}

void
Pawn::reset_position()
{
    unsigned int color_position = this->color_int(this->color());
    this->position(color_position);
    return ;
}

void
Pawn::position(unsigned int position)
{
    this->_position = position;

    return ;
}

unsigned int
Pawn::position()
{
    return this->_position;
}

void
Pawn::draw()
{
    switch (this->color()) {
        case ENUM_RED:
        fprintf(stdout, ANSI_F_COLOR_RED "P" ANSI_COLOR_RESET " ");
        break;

        case ENUM_GREEN:
        fprintf(stdout, ANSI_F_COLOR_GREEN "P" ANSI_COLOR_RESET " ");
        break;

        case ENUM_BLUE:
        fprintf(stdout, ANSI_F_COLOR_BLUE "P" ANSI_COLOR_RESET " ");
        break;

        case ENUM_YELLOW:
        fprintf(stdout, ANSI_F_COLOR_YELLOW "P" ANSI_COLOR_RESET " ");
        break;

        case ENUM_PURPLE:
        fprintf(stdout, ANSI_F_COLOR_MAGENTA "P" ANSI_COLOR_RESET " ");
        break;

        default:
        break;
    }

    return ;
}


const char*
Pawn::color_str()
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

        default:
        break;
    }

    return char_color;
}

unsigned int
Pawn::color_int(Colors color)
{
    unsigned int int_color = -1;
    switch (color) {
        case ENUM_RED:
        int_color = 0;
        break;

        case ENUM_GREEN:
        int_color = 1;
        break;

        case ENUM_BLUE:
        int_color = 2;
        break;

        case ENUM_YELLOW:
        int_color = 3;
        break;

        case ENUM_PURPLE:
        int_color = 4;
        break;

        default:
        break;
    }

    return int_color;
}


Colors
Pawn::int_color(unsigned int int_color)
{
    Colors color;
    switch (int_color) {
        case 0:
        color = ENUM_RED;
        break;

        case 1:
        color = ENUM_GREEN;
        break;

        case 2:
        color = ENUM_BLUE;
        break;

        case 3:
        color = ENUM_YELLOW;
        break;

        case 4:
        color = ENUM_PURPLE;
        break;
    }

    return color;
}
