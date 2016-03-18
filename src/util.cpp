#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <linux/random.h>
#include <fcntl.h>
#include <unistd.h>

void clear_screen()
{
    for (size_t i = 0; i < 60; i++) printf("\n");
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
