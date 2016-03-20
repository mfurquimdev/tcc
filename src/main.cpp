#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdio_ext.h>

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

    unsigned char quit = 0;
    while (!quit) {
        unsigned int pawn = get_instruction();
        clear_screen();
        if (pawn >= 0 && pawn < 5) {
            board->move_pawn(pawn);
        }
        else {
            fprintf(stdout, "Quer fechar o jogo?\n\t0 - Nao\n\t1 - Sim\n");
            scanf("%d", &quit);
            __fpurge(stdin);
            clear_screen();
        }
        board->draw();
    }
    delete(board);


    return 0;
}
