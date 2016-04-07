#ifndef DISC_H
#define DISC_H

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

class Disc
{
public:
    Disc(unsigned char);
    ~Disc();

    void draw(void);
    unsigned char color(void);
    void paint(void);

private:

    void color(unsigned char);

    unsigned char _color;
};

#endif
