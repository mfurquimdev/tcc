#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "disc.h"
#include "pawn.h"

#define DEBUG_ON 0

/*******************************************************************************
 * Main
 ******************************************************************************/

int main()
{
    if (DEBUG_ON) fprintf(stderr, "Main\n");

    struct Pawn* pawn_1 = NULL;
    struct Pawn* pawn_2 = NULL;
    struct Pawn* pawn_3 = NULL;
    struct Pawn* pawn_4 = NULL;
    struct Pawn* pawn_5 = NULL;

    struct Disc* disc_1 = NULL;
    struct Disc* disc_2 = NULL;
    struct Disc* disc_3 = NULL;
    struct Disc* disc_4 = NULL;
    struct Disc* disc_5 = NULL;
    struct Disc* disc_6 = NULL;
    struct Disc* disc_7 = NULL;

    pawn_1 = create_pawn(ENUM_RED);
    pawn_2 = create_pawn(ENUM_GREEN);
    pawn_3 = create_pawn(ENUM_BLUE);
    pawn_4 = create_pawn(ENUM_YELLOW);
    pawn_5 = create_pawn(ENUM_PURPLE);

    print_pawn(pawn_1);
    print_pawn(pawn_2);
    print_pawn(pawn_3);
    print_pawn(pawn_4);
    print_pawn(pawn_5);

    disc_1 = create_disc(ENUM_RED);
    disc_2 = create_disc(ENUM_GREEN);
    disc_3 = create_disc(ENUM_BLUE);
    disc_4 = create_disc(ENUM_YELLOW);
    disc_5 = create_disc(ENUM_PURPLE);
    disc_6 = create_disc(ENUM_WHITE);
    disc_7 = create_disc(ENUM_BLACK);

    print_disc(disc_1);
    print_disc(disc_2);
    print_disc(disc_3);
    print_disc(disc_4);
    print_disc(disc_5);
    print_disc(disc_6);
    print_disc(disc_7);

    destroy_disc(disc_7);
    destroy_disc(disc_6);
    destroy_disc(disc_5);
    destroy_disc(disc_4);
    destroy_disc(disc_3);
    destroy_disc(disc_2);
    destroy_disc(disc_1);

    destroy_pawn(pawn_5);
    destroy_pawn(pawn_4);
    destroy_pawn(pawn_3);
    destroy_pawn(pawn_2);
    destroy_pawn(pawn_1);

    return 0;
}
