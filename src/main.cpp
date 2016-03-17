#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "disc.h"
#include "pawn.h"
//#include "board.h"

int main()
{
    Disc* disc = new Disc(ENUM_RED);
    Pawn* pawn = new Pawn(ENUM_RED);

    disc->draw();
    pawn->draw();

    delete(disc);
    delete(pawn);

    return 0;
}