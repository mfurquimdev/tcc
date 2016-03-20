#include "stair.h"

#include <cstdlib>

Stair::Stair()
{
    this->_current_position = 0;
}

Stair::~Stair()
{
}

void
Stair::draw()
{
    for (size_t i = 0; i < 60; i++) {
        fprintf(stdout, "  ");
    }

    for (unsigned int i = 0; i < this->_current_position; i++) {
        this->_stair[i]->draw();
    }

    fprintf(stdout, "\n");

    return ;
}

void
Stair::step_up(Pawn* pawn)
{
    unsigned char contain = 0;

    for (size_t i = 0; i < this->_current_position; i++) {
        if (this->_stair[i] == pawn) {
            contain = 1;
            break;
        }
    }

    if (!contain) {
        this->_stair[this->_current_position] = pawn;
        pawn->position(65 + this->_current_position);
        this->_current_position++;
    }

}
