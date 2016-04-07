#ifndef PAWN_H
#define PAWN_H

#define ANSI_F_COLOR_RED     "\x1b[31;1m"
#define ANSI_F_COLOR_GREEN   "\x1b[32;1m"
#define ANSI_F_COLOR_BLUE    "\x1b[34;1m"
#define ANSI_F_COLOR_YELLOW  "\x1b[33;1m"
#define ANSI_F_COLOR_MAGENTA "\x1b[35;1m"

#define ANSI_COLOR_RESET   "\x1b[0m"

class Pawn
{
public:
    Pawn(unsigned char);
    ~Pawn();

    void draw(void);
    void paint(void);

    unsigned char color(void);

private:

    void color(unsigned char);

    unsigned char _color;
};

#endif
