#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colors.h"
#include "disc.h"
//#include "pawn.h"
//#include "board.h"

int main()
{
/*    ,
    ENUM_GREEN,
    ENUM_BLUE,
    ENUM_YELLOW,
    ENUM_PURPLE,
    ENUM_WHITE,
    ENUM_BLACK
*/
    Disc* disc = new Disc(ENUM_RED);
    disc->draw();
    delete(disc);

    return 0;
}
