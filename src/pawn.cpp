#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pawn.h"
#include "colors.h"


Pawn::Pawn(Colors color)
{
    this->color(color);
    this->reset_position();
    fprintf(stderr, "[%p]\t%d - Pawn\t%s\n", (void*) this, this->position(), this->color_str());
}

Pawn::~Pawn()
{

}

void
Pawn::color(Colors color)
{

}

Colors
Pawn::color()
{

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
    }

    return char_color;
}

void
Pawn::reset_position()
{
    switch (this->color()) {
        case ENUM_RED:
        _position = 0;
        break;

        case ENUM_GREEN:
        _position = 1;
        break;

        case ENUM_BLUE:
        _position = 2;
        break;

        case ENUM_YELLOW:
        _position = 3;
        break;

        case ENUM_PURPLE:
        _position = 4;
        break;
    }
}

void
Pawn::position(unsigned int)
{

}

unsigned int
Pawn::position()
{

}

void Pawn::draw()
{

}


struct Pawn* create_pawn(enum colors color)
{
    struct Pawn* newPawn = NULL;

    if (color != ENUM_BLACK && color != ENUM_WHITE) {
        newPawn = (struct Pawn*) malloc(sizeof(struct Pawn));
        pawn_set_color(newPawn, color);
        pawn_set_position(newPawn, color);
        fprintf(stderr, "[%p] Pawn color: %s\n", (void*) newPawn, pawn_get_color_char(newPawn));
    }
    else {
        fprintf(stderr, "[%p] Cor do peao nao pode ser preta nem branca\n", (void*) newPawn);
    }

    return newPawn;
}

void print_pawn(struct Pawn* pawn)
{
    switch (pawn_get_color_int(pawn)) {
        case 0:
        fprintf(stdout, ANSI_F_COLOR_RED "P" ANSI_COLOR_RESET " ");
        break;

        case 1:
        fprintf(stdout, ANSI_F_COLOR_GREEN "P" ANSI_COLOR_RESET " ");
        break;

        case 2:
        fprintf(stdout, ANSI_F_COLOR_BLUE "P" ANSI_COLOR_RESET " ");
        break;

        case 3:
        fprintf(stdout, ANSI_F_COLOR_YELLOW "P" ANSI_COLOR_RESET " ");
        break;

        case 4:
        fprintf(stdout, ANSI_F_COLOR_MAGENTA "P" ANSI_COLOR_RESET " ");
        break;
    }

    return ;
}

int pawn_set_position(struct Pawn* pawn, int position)
{
    pawn->_position = position;
    return 0;
}

int pawn_get_position(struct Pawn* pawn)
{
    return pawn->_position;
}

int pawn_set_color(struct Pawn* pawn, enum colors color)
{
    pawn->_color = color;

    return 0;
}

int pawn_get_color_int(struct Pawn* pawn)
{
    return pawn->_color;
}

char* pawn_get_color_char(struct Pawn* pawn)
{
    char* char_color = NULL;

    switch (pawn_get_color_int(pawn)) {
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
    }

    return char_color;
}

int destroy_pawn(struct Pawn* pawn)
{
    fprintf(stderr, "[%p] destroy pawn\n", (void*) pawn);

    free(pawn);

    return 0;
}
