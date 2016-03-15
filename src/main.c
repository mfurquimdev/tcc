#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "disc.h"
#include "pawn.h"
#include "board.h"

#define DEBUG_ON 0

/*******************************************************************************
 * Main
 ******************************************************************************/

int main()
{
    if (DEBUG_ON) fprintf(stderr, "Main\n");

    struct Board* board = NULL;

    board = create_board();
    print_board(board);
    destroy_board(board);

    return 0;
}
