#ifndef STAIR_H
#define STAIR_H

#include "pawn.h"
#include <vector>

class Stair
{
public:
    Stair();
    ~Stair();

    void step_up(Pawn*);
    void draw();

private:
    unsigned int _current_position;
    std::vector<Pawn*> _steps;
};


#endif
