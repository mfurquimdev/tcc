#include "util.h"
#include "colors.h"

#include <cstdio>
#include <cstdlib>
#include <stdio_ext.h>

#include <stdarg.h>
#include <linux/random.h>
#include <fcntl.h>
#include <unistd.h>

void clear_screen()
{
    for (size_t i = 0; i < 60; i++) printf("\n");
}

unsigned int get_instruction()
{
    unsigned int pawn_color = 0;

    fprintf(stdout, "Selecione uma cor de peao para andar:\n");
    fprintf(stdout, ANSI_F_COLOR_RED        "Peao " ANSI_COLOR_RESET "0\n");
    fprintf(stdout, ANSI_F_COLOR_GREEN      "Peao " ANSI_COLOR_RESET "1\n");
    fprintf(stdout, ANSI_F_COLOR_BLUE       "Peao " ANSI_COLOR_RESET "2\n");
    fprintf(stdout, ANSI_F_COLOR_YELLOW     "Peao " ANSI_COLOR_RESET "3\n");
    fprintf(stdout, ANSI_F_COLOR_MAGENTA    "Peao " ANSI_COLOR_RESET "4\n");
    scanf("%u", &pawn_color);
//    __fpurge(stdin);

    return pawn_color;
}


unsigned int my_random()
{
    unsigned int val;
    int hRandom = open("/dev/urandom", O_RDONLY);

    if (hRandom == 0) {
        printf("Could not open random device\n");
        exit(1);
    }

    if (read(hRandom,&val,sizeof(val)) != sizeof(val)) {
        perror("reading random value");
        exit(1);
    }
    close(hRandom);

    return val;
}

/* Example of pair

std::pair<int, int> p;
p = std::make_pair(9,2);

fprintf(stdout, "%d %d\n", p.first, p.second);

*/
