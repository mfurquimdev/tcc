#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdio_ext.h>
#include <array>

#include "colors.h"
#include "disc.h"
#include "pawn.h"
#include "board.h"
#include "util.h"
#include "player.h"

int main()
{
    Player* player = new Player(0);
    Board* board = new Board();

    clear_screen();
    board->draw();

    unsigned char quit = 0;
    while (!quit) {
        unsigned int pawn = get_instruction();
        clear_screen();
        if (pawn < 5) {
            unsigned char stepped_up = board->move_pawn(pawn);

            if (!stepped_up) {
                std::pair<Disc*, Disc*> adjacent = std::make_pair((Disc*) NULL,(Disc*) NULL);
                adjacent = board->get_adjacent_discs(pawn);
                if (adjacent.first != NULL) {
                    fprintf(stdout, "%2d ", adjacent.first->position());
                }
                else {
                    fprintf(stdout, "-1 ");
                }

                if (adjacent.second != NULL) {
                    fprintf(stdout, "%2d\n", adjacent.second->position());
                }
                else {
                    fprintf(stdout, "-1\n");
                }
            }
        }
        else {
            fprintf(stdout, "Quer fechar o jogo?\n\t0 - Nao\n\t1 - Sim\n");
            scanf("%c", &quit);
            __fpurge(stdin);
            clear_screen();
        }
        board->draw();
    }

    std::array<std::pair<Colors, int>,5> colors_worth;
    colors_worth = board->retrieve_colors_worth();

    for (size_t i = 0; i < 5; i++) {
        switch (colors_worth[i].first) {
            case ENUM_RED:
            fprintf(stdout, ANSI_F_COLOR_RED        "P" ANSI_COLOR_RESET);
            break;

            case ENUM_GREEN:
            fprintf(stdout, ANSI_F_COLOR_GREEN      "P" ANSI_COLOR_RESET);
            break;

            case ENUM_BLUE:
            fprintf(stdout, ANSI_F_COLOR_BLUE       "P" ANSI_COLOR_RESET);
            break;

            case ENUM_YELLOW:
            fprintf(stdout, ANSI_F_COLOR_YELLOW     "P" ANSI_COLOR_RESET);
            break;

            case ENUM_PURPLE:
            fprintf(stdout, ANSI_F_COLOR_MAGENTA    "P" ANSI_COLOR_RESET);
            break;

            default:
            break;
        }
        fprintf(stdout, "\t%d\n", colors_worth[i].second);
    }

    delete(board);


    return 0;
}
