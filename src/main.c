#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "disc.h"
#include "pawn.h"
#include "board.h"

/*******************************************************************************
 * Main
 ******************************************************************************/

int main()
{
    struct Board* board = NULL;

    board = create_board();
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    board_move_pawn(board, 1);
    print_board(board);
    destroy_board(board);

    return 0;
}
