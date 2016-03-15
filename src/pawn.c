#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pawn.h"

/*******************************************************************************
 * Peões
 ******************************************************************************/

struct Pawn* create_pawn(enum colors color)
{
    struct Pawn* newPawn = NULL;

    if (color != ENUM_BLACK && color != ENUM_WHITE) {
        newPawn = (struct Pawn*) malloc(sizeof(struct Pawn));

        pawn_set_color(newPawn, color);
//      fprintf(stderr, "%p Pawn color: %s\n", (void*) newPawn, pawn_get_color_char(newPawn));
    }
    else {
        fprintf(stderr, "%p Cor do peao nao pode ser preta nem branca\n", (void*) newPawn);
    }

    return newPawn;
}

void print_pawn(struct Pawn* pawn)
{
    switch (pawn_get_color_int(pawn)) {
        case 0:
        fprintf(stderr, ANSI_F_COLOR_RED "P" ANSI_COLOR_RESET " ");
        break;

        case 1:
        fprintf(stderr, ANSI_F_COLOR_GREEN "P" ANSI_COLOR_RESET " ");
        break;

        case 2:
        fprintf(stderr, ANSI_F_COLOR_BLUE "P" ANSI_COLOR_RESET " ");
        break;

        case 3:
        fprintf(stderr, ANSI_F_COLOR_YELLOW "P" ANSI_COLOR_RESET " ");
        break;

        case 4:
        fprintf(stderr, ANSI_F_COLOR_MAGENTA "P" ANSI_COLOR_RESET " ");
        break;
    }

    return ;
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
        strncpy(char_color, COLOR_RED, sizeof(COLOR_RED));
        break;

        case 1:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_GREEN));
        strncpy(char_color, COLOR_GREEN, sizeof(COLOR_GREEN));
        break;

        case 2:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_BLUE));
        strncpy(char_color, COLOR_BLUE, sizeof(COLOR_BLUE));
        break;

        case 3:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_YELLOW));
        strncpy(char_color, COLOR_YELLOW, sizeof(COLOR_YELLOW));
        break;

        case 4:
        char_color = (char*) malloc(sizeof(char)*sizeof(COLOR_PURPLE));
        strncpy(char_color, COLOR_PURPLE, sizeof(COLOR_PURPLE));
        break;
    }

    return char_color;
}

int destroy_pawn(struct Pawn* pawn)
{
    free(pawn);

    return 0;
}
