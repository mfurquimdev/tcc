#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "colors.h"
#include "disc.h"
#include "pawn.h"
#include "board.h"
#include "util.h"

int main()
{

    Board* board = new Board();
    clear_screen();
    board->draw();

    for (size_t i = 0; i < 50; i++) {
        unsigned int pawn = get_instruction();
        clear_screen();
        if (pawn >= 0 && pawn < 5) {
            board->move_pawn(pawn);
        }
        board->draw();
        /*
        switch (pawn) {
            case 0:
            fprintf(stdout, "Moved Pawn Red\n");
            break;

            case 1:
            fprintf(stdout, "Moved Pawn Green\n");
            break;

            case 2:
            fprintf(stdout, "Moved Pawn Blue\n");
            break;

            case 3:
            fprintf(stdout, "Moved Pawn Yellow\n");
            break;

            case 4:
            fprintf(stdout, "Moved Pawn Purple\n");
            break;

        }
        */
    }
    delete(board);


    return 0;
}
