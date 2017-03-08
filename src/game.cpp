#include "game.h"
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

	string board = this->board();
	for (unsigned int i = 0; i < board.length(); i++) {
		unsigned char disc = board.c_str()[i];
		switch(disc) {
			case '0':
			attron(A_INVIS);
			printw("%c", disc);
			attroff(A_INVIS);
			break;

			case '1':
			// if (first) {
			// 	attron(A_BOLD);
			// 	attron(COLOR_PAIR(Color::Foreground_Red));
			// 	printw("%c", disc);
			// 	attroff(COLOR_PAIR(Color::Foreground_Red));
			// 	attroff(A_BOLD);
			// 	first = 0;
			// }
			attron(COLOR_PAIR(Color::Background_Red));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Red));
			break;

			case '2':
			attron(COLOR_PAIR(Color::Background_Green));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Green));
			break;

			case '3':
			attron(COLOR_PAIR(Color::Background_Blue));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Blue));
			break;

			case '4':
			attron(COLOR_PAIR(Color::Background_White));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_White));
			break;

			case '5':
			attron(COLOR_PAIR(Color::Background_Black));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Black));
			break;

			case 'R':
			if (this->_highlight == 0) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Red));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Red));
			attroff(A_BOLD);
			break;

			case 'G':
			if (this->_highlight == 1) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Green));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Green));
			attroff(A_BOLD);
			break;

			case 'B':
			if (this->_highlight == 2) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Blue));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Blue));
			attroff(A_BOLD);
			break;

			case 'Y':
			if (this->_highlight == 3) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Yellow));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Yellow));
			attroff(A_BOLD);
			break;

			case 'P':
			if (this->_highlight == 4) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Purple));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Purple));
			attroff(A_BOLD);
			break;

			default:
			break;
		}
		printw(" ");
	}

	return ;
}

// void
// Game::print_color_pawn()
// {
// 	printw("                                     ");
// 	attron(COLOR_PAIR(Color::Foreground_Red));
// 	printw("R ");
// 	attroff(COLOR_PAIR(Color::Foreground_Red));
//
// 	attron(COLOR_PAIR(Color::Foreground_Green));
// 	printw("G ");
// 	attroff(COLOR_PAIR(Color::Foreground_Green));
//
// 	attron(COLOR_PAIR(Color::Foreground_Blue));
// 	printw("B ");
// 	attroff(COLOR_PAIR(Color::Foreground_Blue));
//
// 	return ;
// }
//
void
Game::print_color_players()
{
	printw("                                     ");
	attron(COLOR_PAIR(Color::Foreground_White));
	printw("P1: ");
	attroff(COLOR_PAIR(Color::Foreground_White));
	printw("\n");
	printw("\n");

	printw("                                     ");
	attron(COLOR_PAIR(Color::Foreground_White));
	printw("P2: ");
	attroff(COLOR_PAIR(Color::Foreground_White));
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
	int d = 3;
	int disc_pos = -1;
	int pawn_pos = -1;
	char char_pawn = ' ';
	char char_disc = '0';
	
	switch (color) {
		case Color::Red:
		char_pawn = 'R';
		char_disc = '1';
		break;

		case Color::Green:
		char_pawn = 'G';
		char_disc = '2';
		break;

		case Color::Blue:
		char_pawn = 'B';
		char_disc = '3';
		break;

		case Color::Yellow:
		char_pawn = 'Y';
		char_disc = '4';
		break;

		case Color::Purple:
		char_pawn = 'P';
		char_disc = '5';
		break;

		default:
		char_pawn = ' ';
		char_disc = '0';
		break;
	}
	
	// The color is correct
	if (char_pawn != ' ' && char_disc != '0') {
	
		// Locate pawn position and next disc position
		pawn_pos = board().find_first_of(char_pawn);
		if (pawn_pos != (int) string::npos) {
			disc_pos = board().find_first_of(char_disc, pawn_pos);
		}
		
		// Pawn not trying to move out of board range
		if (disc_pos != (int) string::npos) {
			this->_board.at(disc_pos) = char_pawn;
		}
			
		// There is always a disc underneath a pawn (except the first movement)
		if (pawn_pos != (int) string::npos) {
			if (pawn_pos < number_pawns()) {
				this->_board.at(pawn_pos) = '0';
			}
			else {
				this->_board.at(pawn_pos) = char_disc;
			}
		}
	}

	move(0,0);
	printw("Pawn: %d\nDisc: %d", pawn_pos, disc_pos);

	return ;
}

bool
Game::select_option()
{
	bool quit = 0;

	// Action depends on the highlight
	switch (this->_highlight) {

		case 0:
		move_pawn(Color::Red);
		break;

		case 1:
		move_pawn(Color::Green);
		break;

		case 2:
		move_pawn(Color::Blue);
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
