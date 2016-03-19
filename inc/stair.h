#ifndef STAIR_H
#define STAIR_H

class Stair
{
public:
    Stair();
    ~Stair();

    void step_up(Pawn*);

private:
    unsigned int current_position;
    std::array<Pawn*, 5> _stair;
}


#endif
