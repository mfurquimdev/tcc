#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_ON 0

/*******************************************************************************
 * Cores
 ******************************************************************************/

enum colors
{
    red,
    green,
    blue,
    yellow,
    purple,
    white,
    black
};

static char color_red[] = "vermelho";
static char color_green[] = "verde";
static char color_blue[] = "azul";
static char color_yellow[] = "amarelo";
static char color_purple[] = "roxo";
static char color_white[] = "branco";
static char color_black[] = "preto";

/*******************************************************************************
 * Disco
 ******************************************************************************/

struct Disc {
    enum colors _color;
}Disc;

struct Disc* create_disc(enum colors);
int destroy_disc(struct Disc*);
int set_color(struct Disc*, enum colors);
int get_color_int(struct Disc*);
char* get_color_char(struct Disc*);

struct Disc* create_disc(enum colors color)
{
    if (DEBUG_ON) printf(stderr, "create_disc(%u)\n", color);

    struct Disc* newDisc = NULL;
    newDisc = (struct Disc*) malloc(sizeof(struct Disc));
    if (DEBUG_ON) fprintf(stderr, "%p (%lu)\n", (void*) newDisc, sizeof(struct Disc));

    set_color(newDisc, color);
    fprintf(stderr, "%p Disc color: %s\n", (void*) newDisc, get_color_char(newDisc));

    return newDisc;
}

int set_color(struct Disc* disc, enum colors color)
{
    if (DEBUG_ON) fprintf(stderr, "set_color(%p,%u)\n", (void*) disc, color);

    disc->_color = color;

    return 0;
}

int get_color_int(struct Disc* disc)
{
    if (DEBUG_ON) fprintf(stderr, "get_color_int(%p)\n", (void*) disc);

    return disc->_color;
}

char* get_color_char(struct Disc* disc)
{
    if (DEBUG_ON) fprintf(stderr, "get_color_char(%p)\n", (void*) disc);

    switch (get_color_int(disc)) {
        case 0:
        return color_red;
        break;

        case 1:
        return color_green;
        break;

        case 2:
        return color_blue;
        break;

        case 3:
        return color_yellow;
        break;

        case 4:
        return color_purple;
        break;

        case 5:
        return color_white;
        break;

        case 6:
        return color_black;
        break;
    }

    return NULL;
}

int destroy_disc(struct Disc* disc)
{
    if (DEBUG_ON) fprintf(stderr, "destroy_disc(%p)\n", (void*) disc);

    free(disc);

    return 0;
}

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
