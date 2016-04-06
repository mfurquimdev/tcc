#ifndef DISC_H
#define DISC_H

class Disc
{
public:
    Disc(unsigned char, unsigned char);
    ~Disc();

    void draw();

private:
    unsigned char _color;
    unsigned char _position;
};

#endif
