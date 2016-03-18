#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "disc.h"
#include "pawn.h"
#include "board.h"
#include "util.h"

int main()
{
    Board* board = new Board();
    for (size_t i = 0; i < 9; i++) {
        board->draw();
        board->move_pawn(0);
        board->draw();
        board->move_pawn(1);
        board->draw();
        board->move_pawn(2);
        board->draw();
        board->move_pawn(3);
        board->draw();
        board->move_pawn(4);
        board->draw();
    }
    delete(board);


    return 0;
}
