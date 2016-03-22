#ifndef COLORS_H
#define COLORS_H

/*******************************************************************************
 * Cores
 ******************************************************************************/
#define ANSI_B_COLOR_WHITE   "\x1b[47m"
#define ANSI_B_COLOR_BLACK   "\x1b[40m"
#define ANSI_B_COLOR_RED     "\x1b[41m"
#define ANSI_B_COLOR_GREEN   "\x1b[42m"
#define ANSI_B_COLOR_YELLOW  "\x1b[43m"
#define ANSI_B_COLOR_BLUE    "\x1b[44m"
#define ANSI_B_COLOR_MAGENTA "\x1b[45m"

#define ANSI_F_COLOR_RED     "\x1b[31;1m"
#define ANSI_F_COLOR_GREEN   "\x1b[32;1m"
#define ANSI_F_COLOR_BLUE    "\x1b[34;1m"
#define ANSI_F_COLOR_YELLOW  "\x1b[33;1m"
#define ANSI_F_COLOR_MAGENTA "\x1b[35;1m"

#define ANSI_COLOR_RESET   "\x1b[0m"

static const char COLOR_RED[]       = "vermelho";
static const char COLOR_GREEN[]     = "verde";
static const char COLOR_BLUE[]      = "azul";
static const char COLOR_YELLOW[]    = "amarelo";
static const char COLOR_PURPLE[]    = "roxo";
static const char COLOR_WHITE[]     = "branco";
static const char COLOR_BLACK[]     = "preto";

enum Colors
{
    ENUM_RED,
    ENUM_GREEN,
    ENUM_BLUE,
    ENUM_YELLOW,
    ENUM_PURPLE,
    ENUM_WHITE,
    ENUM_BLACK
};

const char* color_str(unsigned int);
const char* color_str(Colors);
unsigned int color_int(Colors);
Colors int_color(unsigned int);

#endif
