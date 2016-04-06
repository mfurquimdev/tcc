#include "stair.h"

#define ANSI_COLOR_RESET   "\x1b[0m"

#include <cstdio>

Stair::Stair()
{
    this->_current_position = 0;
}

Stair::~Stair()
{

}

void
Stair::step_up(Pawn* pawn)
{
    this->_steps.push_back(pawn);
    this->_current_position++;

    return ;
}

void
Stair::draw()
{
    int i = 0;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }
    if ((int) this->_current_position > i) {
        this->_steps[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "                 _");
    if ((int) this->_current_position > i) {
        this->_steps[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if ((int) this->_current_position > i) {
        this->_steps[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "             _");
    if ((int) this->_current_position > i) {
        this->_steps[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_");


    if ((int) this->_current_position > i-1) {
        this->_steps[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "|   |\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if ((int) this->_current_position > i) {
        this->_steps[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "         _");
    if ((int) this->_current_position > i) {
        this->_steps[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_");


    if ((int) this->_current_position > i-1) {
        this->_steps[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "|       |\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if ((int) this->_current_position > i) {
        this->_steps[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "     _");
    if ((int) this->_current_position > i) {
        this->_steps[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_");


    if ((int) this->_current_position > i-1) {
        this->_steps[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "|           |\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if ((int) this->_current_position > i) {
        this->_steps[i]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, " _");
    if ((int) this->_current_position > i) {
        this->_steps[i]->draw();
    }
    else {
        fprintf(stdout, "_");
    }
    fprintf(stdout, "_");

    if ((int) this->_current_position > i-1) {
        this->_steps[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    fprintf(stdout, "|               |\n");
    i++;

    for (size_t j = 0; j < 120; j++) {
        fprintf(stdout, " ");
    }

    if ((int) this->_current_position > i-1) {
        this->_steps[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }

    if ((int) this->_current_position > i-1) {
        this->_steps[i-1]->paint();
    }
    fprintf(stdout, "|");

    if ((int) this->_current_position > i-1) {
        this->_steps[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "_0_");

    if ((int) this->_current_position > i-2) {
        this->_steps[i-2]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "__1_");

    if ((int) this->_current_position > i-3) {
        this->_steps[i-3]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "__2_");

    if ((int) this->_current_position > i-4) {
        this->_steps[i-4]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "__3_");

    if ((int) this->_current_position > i-5) {
        this->_steps[i-5]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "__4_");

    if ((int) this->_current_position > i-1) {
        this->_steps[i-1]->paint();
    }
    else {
        fprintf(stdout, ANSI_COLOR_RESET);
    }
    fprintf(stdout, "|\n");

    fprintf(stdout, ANSI_COLOR_RESET "\n");

    return ;
}
