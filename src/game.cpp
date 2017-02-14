#include "game.h"
#include "color.h"

#include <ncurses.h>
#include <cstdio>
#include <stdio_ext.h>
#include <thread>
#include <chrono>

Game::Game(WINDOW* menuwin)
{
	fprintf(stderr, "[%p]\tGame()\n", (void*) this);

	this->_menuwin = menuwin;

	number_players(2);
	number_pawns(3);
	number_discs(5);
	number_special_discs(2);

	init_players_disc();
	init_board();
}

Game::~Game()
{
	fprintf(stderr, "[%p]\tGame destructor\n", (void*) this);
}

void
Game::print_color_stair()
{
	printw("                                     ");
	printw("                                            ");
	printw("    .");
	printw("_");
	printw(".\n");

	printw("                                     ");
	printw("                                            ");
	printw("  .");
	printw("_");
	printw("| |\n");

	printw("                                     ");
	printw("                                            ");
	printw(".");
	printw("_");
	printw("|   |\n");

	return ;
}

void
Game::print_color_disc()
{
	string board = this->board();
	for (unsigned int i = 0; i < board.length(); i++) {
		unsigned char disc = board.c_str()[i];
		switch(disc) {
			case 'R':
			attron(COLOR_PAIR(NcursesColors::BR));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColors::BR));
			break;

			case 'G':
			attron(COLOR_PAIR(NcursesColors::BG));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColors::BG));
			break;

			case 'B':
			attron(COLOR_PAIR(NcursesColors::BB));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColors::BB));
			break;

			case 'W':
			attron(COLOR_PAIR(NcursesColors::BW));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColors::BW));
			break;

			case 'K':
			attron(COLOR_PAIR(NcursesColors::BK));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColors::BK));
			break;

			case ' ':
			printw(" ");

			default:
			break;
		}
	}

	return ;
}

void
Game::print_color_pawn()
{
	printw("                                     ");
	attron(COLOR_PAIR(NcursesColors::FR));
	printw("R ");
	attroff(COLOR_PAIR(NcursesColors::FR));

	attron(COLOR_PAIR(NcursesColors::FG));
	printw("G ");
	attroff(COLOR_PAIR(NcursesColors::FG));

	attron(COLOR_PAIR(NcursesColors::FB));
	printw("B ");
	attroff(COLOR_PAIR(NcursesColors::FB));

	return ;
}

void
Game::print_color_players()
{
	printw("                                     ");
	attron(COLOR_PAIR(NcursesColors::FY));
	printw("P1: ");
	attroff(COLOR_PAIR(NcursesColors::FY));
	printw("\n");
	printw("\n");

	printw("                                     ");
	attron(COLOR_PAIR(NcursesColors::FM));
	printw("P2: ");
	attroff(COLOR_PAIR(NcursesColors::FM));
	printw("\n");

	return ;
}

void
Game::draw() {
	move(10,0);
	print_color_players();
	print_color_stair();
	print_color_pawn();
	print_color_disc();
	printw("\n");
	refresh();

	mvwprintw(menuwin(), 1, 1, "R");
	mvwprintw(menuwin(), 2, 1, "G");
	mvwprintw(menuwin(), 3, 1, "B");
	mvwprintw(menuwin(), 4, 1, "Press q to quit.");
	wrefresh(menuwin());

	return ;
}

void
Game::loop(void)
{
	fprintf(stderr, "Game loop(void)\n");

	bool quit = 0;

	while (!quit) {
		draw();

		int c = getch();
		switch (c) {
			case 'q':
				quit = 1;
				break;

			default:
				break;
		}
	}
}

void
Game::init_players_disc(void)
{
	fprintf(stderr, "init_players_disc(void)\n");
	this->_players_disc.clear();
	for (int n_pawns = 0; n_pawns < number_pawns(); n_pawns++) {
		string discs = "";
		for (int n_discs = 0; n_discs < number_discs(); n_discs++) {
			discs.push_back('+');
		}
		for (int n_players = 0; n_players < number_players(); n_players++) {
			discs.push_back('|');
		}
		this->_players_disc.push_back(discs);
	}

	return ;
}

void
Game::init_board(void)
{
	fprintf(stderr, "init_board(void)\n");
	this->_board = "R B K G G B B W G G R W K R G B R R B";
//	printw("%s", this->_board.c_str());
	return ;
}

/**
 * Getters and Setters
 */

void
Game::number_players(unsigned short int num_players)
{
	fprintf(stderr, "number_players(%d)\n", (int) num_players);
	this->_num_players = num_players;
	return ;
}

unsigned short int
Game::number_players(void)
{
	return this->_num_players;
}

void
Game::number_pawns(unsigned short int num_pawns)
{
	fprintf(stderr, "number_pawns(%d)\n", (int) num_pawns);
	this->_num_pawns = num_pawns;
	return ;
}

unsigned short int
Game::number_pawns(void)
{
	return this->_num_pawns;
}

void
Game::number_discs(unsigned short int num_discs)
{
	fprintf(stderr, "number_discs(%d)\n", (int) num_discs);
	this->_num_discs = num_discs;
	return ;
}

unsigned short int
Game::number_discs(void)
{
	return this->_num_discs;
}

void
Game::number_special_discs(unsigned short int num_special_discs)
{
	fprintf(stderr, "number_special_discs(%d)\n", (int) num_special_discs);
	this->_num_special_discs = num_special_discs;
	return ;
}

unsigned short int
Game::number_special_discs(void)
{
	return this->_num_discs;
}

vector<string>
Game::players_disc(void)
{
	return this->_players_disc;
}

string
Game::board(void)
{
	return this->_board;
}

WINDOW*
Game::menuwin(void)
{
	return this->_menuwin;
}
