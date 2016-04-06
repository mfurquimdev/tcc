#ifndef DISC_H
#define DISC_H

class Disc
{
public:
    Disc(unsigned char);
    ~Disc();

    void draw(void);
    unsigned char color(void);

private:

    void color(unsigned char);

    unsigned char _color;
};

#endif
