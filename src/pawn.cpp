#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pawn.h"
#include "colors.h"


Pawn::Pawn(Colors color)
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
Pawn::color(Colors color)
{
    this->_color = color;
}

Colors
Pawn::color()
{
    return this->_color;
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

void
Pawn::reset_position()
{
    switch (this->color()) {
        case ENUM_RED:
        this->position(0);
        break;

        case ENUM_GREEN:
        this->position(1);
        break;

        case ENUM_BLUE:
        this->position(2);
        break;

        case ENUM_YELLOW:
        this->position(3);
        break;

        case ENUM_PURPLE:
        this->position(4);
        break;

        default:
        break;
    }

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

void Pawn::draw()
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
