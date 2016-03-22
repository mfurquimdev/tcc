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
    int i = 0;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }
    if (this->_current_position > i) {
        this->_stair[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "                 _");
    if (this->_current_position > i) {
        this->_stair[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if (this->_current_position > i) {
        this->_stair[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "             _");
    if (this->_current_position > i) {
        this->_stair[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_");


    if (this->_current_position > i-1) {
        this->_stair[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "|   |\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if (this->_current_position > i) {
        this->_stair[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "         _");
    if (this->_current_position > i) {
        this->_stair[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_");


    if (this->_current_position > i-1) {
        this->_stair[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "|       |\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if (this->_current_position > i) {
        this->_stair[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "     _");
    if (this->_current_position > i) {
        this->_stair[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_");


    if (this->_current_position > i-1) {
        this->_stair[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "|           |\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if (this->_current_position > i) {
        this->_stair[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, " _");
    if (this->_current_position > i) {
        this->_stair[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_");

    if (this->_current_position > i-1) {
        this->_stair[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "|               |\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if (this->_current_position > i-1) {
        this->_stair[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    if (this->_current_position > i-1) {
        this->_stair[i-1]->paint();
    }
    fprintf(stdout, "|");

    if (this->_current_position > i-1) {
        this->_stair[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "_0_");

    if (this->_current_position > i-2) {
        this->_stair[i-2]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "__1_");

    if (this->_current_position > i-3) {
        this->_stair[i-3]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "__2_");

    if (this->_current_position > i-4) {
        this->_stair[i-4]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "__3_");

    if (this->_current_position > i-5) {
        this->_stair[i-5]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "__4_");

    if (this->_current_position > i-1) {
        this->_stair[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "|\n");

    fprintf(stdout, ANSI_COLOR_RESET "\n");

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
