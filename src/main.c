#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "disc.h"

#define DEBUG_ON 0

/*******************************************************************************
 * Main
 ******************************************************************************/

int main()
{
    if (DEBUG_ON) fprintf(stderr, "Main\n");

    struct Disc* disc_1 = NULL;
    struct Disc* disc_2 = NULL;
    struct Disc* disc_3 = NULL;
    struct Disc* disc_4 = NULL;
    struct Disc* disc_5 = NULL;

    if (DEBUG_ON) fprintf(stderr, "\nDisco 1\n");
    disc_1 = create_disc(red);

    if (DEBUG_ON) fprintf(stderr, "\nDisco 2\n");
    disc_2 = create_disc(green);

    if (DEBUG_ON) fprintf(stderr, "\nDisco 3\n");
    disc_3 = create_disc(blue);

    if (DEBUG_ON) fprintf(stderr, "\nDisco 4\n");
    disc_4 = create_disc(yellow);

    if (DEBUG_ON) fprintf(stderr, "\nDisco 5\n");
    disc_5 = create_disc(purple);

    destroy_disc(disc_1);
    destroy_disc(disc_2);
    destroy_disc(disc_3);
    destroy_disc(disc_4);
    destroy_disc(disc_5);

    return 0;
}
