#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "disc.h"
#include "pawn.h"
#include "board.h"

int main()
{
    Board* board = new Board();
    board->draw();
    delete(board);

    return 0;
}
