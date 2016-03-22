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
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 4-i; j++) {
            fprintf(stdout, "    ");
        }

        if (i != 0) {
            fprintf(stdout, "|");
        }

        if (i < this->_current_position) {
            fprintf(stdout, "_");
            this->_stair[i]->draw();
            fprintf(stdout, "_");
        }
        else {
            fprintf(stdout, "___");
        }

        for (size_t j = 0; j < i*4; j++) {
            fprintf(stdout, " ");
        }

        if (i != 0) {
            fprintf(stdout, "|");
        }
        fprintf(stdout, "\n");
    }

/*


    for (size_t k = 0; k < 5; k++) {
        for (size_t i = 0; i < 5; i++) {
            fprintf(stdout, " ");
        }
        for (size_t i = 0; i < 60+(5-k); i++) {
            fprintf(stdout, "  ");
        }
        if (k < this->_current_position) {
            fprintf(stdout, "_");
            this->_stair[k]->draw();
            fprintf(stdout, "_");
        }
        else {
            fprintf(stdout, "___");
        }
        if (k != 0) {
            fprintf(stdout, "|");
        }
        fprintf(stdout, "\n");
    }
*/
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
