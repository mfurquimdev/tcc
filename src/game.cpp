#include "game.h"
#include "color.h"

#include <ncurses.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdio_ext.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <map>

Game::Game(WINDOW* menuwin)
{
	fprintf(stderr, "[%p]\tGame()\n", (void*) this);

	this->_menuwin = menuwin;
	strncpy(this->_choices[0], "Red", 4);
	strncpy(this->_choices[1], "Green", 6);
	strncpy(this->_choices[2], "Blue", 5);
	strncpy(this->_choices[3], "Press q to quit.", 17);

	this->_highlight = 0;

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
Game::print_color_board()
{
	printw("                                     ");

	bool first = 1;

	string board = this->board();
	for (unsigned int i = 0; i < board.length(); i++) {
		unsigned char disc = board.c_str()[i];
		switch(disc) {
			case '1':
			if (first) {
				attron(A_BOLD);
				attron(COLOR_PAIR(NcursesColor::FR));
				printw("%c", disc);
				attroff(COLOR_PAIR(NcursesColor::FR));
				attroff(A_BOLD);
				first = 0;
			}
			else {
				attron(COLOR_PAIR(NcursesColor::BR));
				printw("%c", disc);
				attroff(COLOR_PAIR(NcursesColor::BR));
			}
			break;

			case '2':
			attron(COLOR_PAIR(NcursesColor::BG));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColor::BG));
			break;

			case '3':
			attron(COLOR_PAIR(NcursesColor::BB));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColor::BB));
			break;

			case '4':
			attron(COLOR_PAIR(NcursesColor::BW));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColor::BW));
			break;

			case '5':
			attron(COLOR_PAIR(NcursesColor::BK));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColor::BK));
			break;

			case 'R':
			attron(COLOR_PAIR(NcursesColor::FR));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColor::FR));
			break;

			case 'G':
			attron(COLOR_PAIR(NcursesColor::FG));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColor::FG));
			break;

			case 'B':
			attron(COLOR_PAIR(NcursesColor::FB));
			printw("%c", disc);
			attroff(COLOR_PAIR(NcursesColor::FB));
			break;

			default:
			break;
		}
		printw(" ");
	}

	return ;
}

void
Game::print_color_pawn()
{
	printw("                                     ");
	attron(COLOR_PAIR(NcursesColor::FR));
	printw("R ");
	attroff(COLOR_PAIR(NcursesColor::FR));

	attron(COLOR_PAIR(NcursesColor::FG));
	printw("G ");
	attroff(COLOR_PAIR(NcursesColor::FG));

	attron(COLOR_PAIR(NcursesColor::FB));
	printw("B ");
	attroff(COLOR_PAIR(NcursesColor::FB));

	return ;
}

void
Game::print_color_players()
{
	printw("                                     ");
	attron(COLOR_PAIR(NcursesColor::FY));
	printw("P1: ");
	attroff(COLOR_PAIR(NcursesColor::FY));
	printw("\n");
	printw("\n");

	printw("                                     ");
	attron(COLOR_PAIR(NcursesColor::FM));
	printw("P2: ");
	attroff(COLOR_PAIR(NcursesColor::FM));
	printw("\n");

	return ;
}

void
Game::draw() {
	move(10,0);
	print_color_players();
	print_color_stair();
//	print_color_pawn();
	print_color_board();
	printw("\n");
	refresh();

	for (int i = 0; i < 4; ++i) {
		if (i == this->_highlight) {
			wattron(menuwin(), A_REVERSE);
		}
		mvwprintw(menuwin(), i+1, 1, this->_choices[i]);
		wattroff(menuwin(), A_REVERSE);
	}
	wrefresh(menuwin());

	return ;
}

void
Game::move_pawn(Color color)
{
	int pos = -1;
	switch (color) {
		case Color::R:
		pos = board().find_first_of('1');
		break;

		case Color::G:
		pos = board().find_first_of('2');
		break;

		case Color::B:
		pos = board().find_first_of('3');
		break;

		default:
		break;
	}

	move(0,0);
	printw("%d", pos);

	return ;
}

bool
Game::select_option()
{
	bool quit = 0;

	// Action depends on the highlight
	switch (this->_highlight) {

		case 0:
		move_pawn(Color::R);
		break;

		case 1:
		move_pawn(Color::G);
		break;

		case 2:
		move_pawn(Color::B);
		break;

		case 3:
		quit = 1;
		break;

		default:
		break;
	}

	return quit;
}

void
Game::loop(void)
{
	fprintf(stderr, "Game loop(void)\n");

	bool quit = 0;

	while (!quit) {
		draw();

		int c = wgetch(menuwin());
		switch (c) {
			// Press q to quit
			case 'q':
			quit = 1;
			break;

			// Move up on the menu
			case KEY_UP:
			this->_highlight--;
			if (this->_highlight < 0) {
				this->_highlight = 0;
			}
			break;

			// Move down on the menu
			case KEY_DOWN:
			this->_highlight++;
			if (this->_highlight > 3) {
				this->_highlight = 3;
			}
			break;

			// Press enter to choose action on menu
			case 10:
			quit = select_option();
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
	this->_board = "RGB1352233422145123113";
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
