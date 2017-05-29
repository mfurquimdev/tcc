#include "game.h"
#include "menu.h"
#include "player.h"
#include <ncurses.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdio_ext.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include <map>

Game::Game(pair<int, int> screen_size)
{
	fprintf(stderr, "[%p]\tGame()\n", (void*) this);

	number_players(2);
	number_pawns(3);
	number_discs(5);
	number_special_discs(2);

	this->_player_turn = 0;
	this->_pawn_turn = 1;
	this->_picked = false;
	this->_screen_size = screen_size;

	this->_pawnmenu = new Menu(6, screen_size.second-12, screen_size.first-12, number_pawns()+2, ColorName, number_pawns());

	const char* disc_choices[2] = {"Pick left", "Pick right"};
	this->_discmenu = new Menu(6, screen_size.second-12, screen_size.first-12, 2+2, disc_choices, 2);

	const char* black_choices[2] = {"Use black disc", "Don't use black disc"};
	this->_blackmenu = new Menu(6, screen_size.second-12, screen_size.first-12, 2+2, black_choices, 2);

	init_stair();

	init_players();
	init_players_disc();
	init_board();
}

Game::~Game()
{
	fprintf(stderr, "[%p]\tgame destructor\n", (void*) this);

	if (this->_pawnmenu != NULL) {
		fprintf(stderr, "[%p]\tpawnmenu\n", (void*) this->_pawnmenu);
		delete(this->_pawnmenu);
		this->_pawnmenu = NULL;
	}
	
	if (this->_discmenu != NULL) {
		fprintf(stderr, "[%p]\tdiscmenu\n", (void*) this->_discmenu);
		delete(this->_discmenu);
		this->_discmenu = NULL;
	}
	
	if (this->_blackmenu != NULL) {
		fprintf(stderr, "[%p]\tblackmenu\n", (void*) this->_blackmenu);
		delete(this->_blackmenu);
		this->_blackmenu = NULL;
	}

	fprintf(stderr, "destroy players\n");
	if (this->_players != NULL) {
		fprintf(stderr, "players not null\n");
		for (int i = 0; i < number_players(); i++) {
			fprintf(stderr, "destroy player[%d]\n", i);
			if (this->_players[i] != NULL) {
				fprintf(stderr, "destroy player[%d] not null\n", i);
				delete(this->_players[i]);
				this->_players[i] = NULL;
			}
			else {
				fprintf(stderr, "destroy player[%d] null\n", i);
			}
		}
		fprintf(stderr, "free player\n");
		free(this->_players);
		this->_players = NULL;
	}
	fprintf(stderr, "[%p]\tend game destructor\n", (void*) this);
}

void
Game::init_stair()
{
	this->_stair_pos = 0;
	this->_skip_pick_disc = 0;
	int num_pawns = number_pawns();
	this->_stair = (char*) malloc(sizeof(char)*num_pawns+1);
	if (this->_stair != NULL) {
		for (size_t i = 0; i < num_pawns; i++) {
			this->_stair[i] = '_';
		}
		this->_stair[num_pawns] = '\0';
	}
	return ;
}

void
Game::init_players()
{
	fprintf(stderr, "init players\n");
	this->_players = NULL;
	this->_players = (Player**) malloc(sizeof(Player*)*number_players());
	if (this->_players != NULL) {
		fprintf(stderr, "players malloced\n");
		for (int i = 0; i < number_players(); i++) {
			this->_players[i] = new Player();
			fprintf(stderr, "[%p] players[%d]\n", (void*) this->_players[i], i);
		}
	}
	else {
		fprintf(stderr, "[%p] players variable is null\n", (void*) this->_players);
	}
}

void
Game::pawn_stair(int pawn_position)
{
	char pawn = this->_stair[pawn_position];
	switch(pawn) {
		case 'R':
		attron(COLOR_PAIR(Color::Foreground_Red));
		printw("%c", pawn);
		attroff(COLOR_PAIR(Color::Foreground_Red));
		break;

		case 'G':
		attron(COLOR_PAIR(Color::Foreground_Green));
		printw("%c", pawn);
		attroff(COLOR_PAIR(Color::Foreground_Green));
		break;

		case 'B':
		attron(COLOR_PAIR(Color::Foreground_Blue));
		printw("%c", pawn);
		attroff(COLOR_PAIR(Color::Foreground_Blue));
		break;

		case 'Y':
		attron(COLOR_PAIR(Color::Foreground_Yellow));
		printw("%c", pawn);
		attroff(COLOR_PAIR(Color::Foreground_Yellow));
		break;

		case 'P':
		attron(COLOR_PAIR(Color::Foreground_Purple));
		printw("%c", pawn);
		attroff(COLOR_PAIR(Color::Foreground_Purple));
		break;

		default:
		printw("%c", pawn);
		break;
	}

	return ;
}

void
Game::print_color_stair()
{
	int num_pawns = number_pawns();
	for (int i = 0; i < number_pawns(); i++) {
		printw("                                                                                 ");
		for (int j = 0; j < (num_pawns-i-1)*2; j++) {
			printw(" ");
		}
		printw(".");
		pawn_stair(i);
		if (i == 0) {
			printw(".");
		}
		else {
			printw("|");
			for (int j = 0; j < (2*i-1); j++) {
				printw(" ");
			}
			printw("|");
		}
		printw("\n");
	}

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
			attron(COLOR_PAIR(Color::Background_Yellow));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Yellow));
			break;

			case '5':
			attron(COLOR_PAIR(Color::Background_Purple));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Purple));
			break;

			case '6':
			attron(COLOR_PAIR(Color::Background_White));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_White));
			break;

			case '7':
			attron(COLOR_PAIR(Color::Background_Black));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Black));
			break;

			case 'R':
			if (this->_pawnmenu->highlight() == Color::Red) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Red));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Red));
			attroff(A_BOLD);
			break;

			case 'G':
			if (this->_pawnmenu->highlight() == Color::Green) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Green));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Green));
			attroff(A_BOLD);
			break;

			case 'B':
			if (this->_pawnmenu->highlight() == Color::Blue) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Blue));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Blue));
			attroff(A_BOLD);
			break;

			case 'Y':
			if (this->_pawnmenu->highlight() == Color::Yellow) {
				attron(A_BOLD);
			}
			attron(COLOR_PAIR(Color::Foreground_Yellow));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Foreground_Yellow));
			attroff(A_BOLD);
			break;

			case 'P':
			if (this->_pawnmenu->highlight() == Color::Purple) {
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
		attroff(A_BOLD);
		printw(" ");
	}

	return ;
}

void
Game::print_color_players()
{
	string player_discs;
	printw("                                     ");
	attron(COLOR_PAIR(Color::Foreground_White));
	printw("(%d) ", calculate_score(0));
	if (this->_player_turn == 0 ) {
		attron(A_BOLD);
		if (this->_pawn_turn == 1) {
			switch (this->_pawnmenu->highlight()) {
				case 0:
				attron(COLOR_PAIR(Color::Foreground_Red));
				break;

				case 1:
				attron(COLOR_PAIR(Color::Foreground_Green));
				break;

				case 2:
				attron(COLOR_PAIR(Color::Foreground_Blue));
				break;

				case 3:
				attron(COLOR_PAIR(Color::Foreground_Yellow));
				break;

				case 4:
				attron(COLOR_PAIR(Color::Foreground_Purple));
				break;

				default:
				break;
			}
		}
	}
	printw("P1: ");
	attroff(COLOR_PAIR(Color::Foreground_Red));
	attroff(COLOR_PAIR(Color::Foreground_Green));
	attroff(COLOR_PAIR(Color::Foreground_Blue));
	attroff(COLOR_PAIR(Color::Foreground_Yellow));
	attroff(COLOR_PAIR(Color::Foreground_Purple));
	attroff(A_BOLD);
	attroff(COLOR_PAIR(Color::Foreground_White));

	player_discs = this->_players[0]->discs();
	for (unsigned int i = 0; i < player_discs.length(); i++) {
		unsigned char disc = player_discs.c_str()[i];

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

			case '6':
			attron(COLOR_PAIR(Color::Background_White));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_White));
			break;

			case '7':
			attron(COLOR_PAIR(Color::Background_Black));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Black));
			break;

			default:
			break;
		}
		printw(" ");
	}

	printw("\n");
	printw("\n");

	printw("                                     ");
	attron(COLOR_PAIR(Color::Foreground_White));
	printw("(%d) ", calculate_score(1));
	if (this->_player_turn == 1 ) {
		attron(A_BOLD);
		if (this->_pawn_turn == 1) {
			switch (this->_pawnmenu->highlight()) {
				case 0:
				attron(COLOR_PAIR(Color::Foreground_Red));
				break;

				case 1:
				attron(COLOR_PAIR(Color::Foreground_Green));
				break;

				case 2:
				attron(COLOR_PAIR(Color::Foreground_Blue));
				break;

				case 3:
				attron(COLOR_PAIR(Color::Foreground_Yellow));
				break;

				case 4:
				attron(COLOR_PAIR(Color::Foreground_Purple));
				break;

				default:
				break;
			}
		}
	}
	printw("P2: ");
	attroff(COLOR_PAIR(Color::Foreground_Red));
	attroff(COLOR_PAIR(Color::Foreground_Green));
	attroff(COLOR_PAIR(Color::Foreground_Blue));
	attroff(COLOR_PAIR(Color::Foreground_Yellow));
	attroff(COLOR_PAIR(Color::Foreground_Purple));
	attroff(A_BOLD);
	attroff(COLOR_PAIR(Color::Foreground_White));
	player_discs = this->_players[1]->discs();
	for (unsigned int i = 0; i < player_discs.length(); i++) {
		unsigned char disc = player_discs.c_str()[i];

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

			case '6':
			attron(COLOR_PAIR(Color::Background_White));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_White));
			break;

			case '7':
			attron(COLOR_PAIR(Color::Background_Black));
			printw("%c", disc);
			attroff(COLOR_PAIR(Color::Background_Black));
			break;

			default:
			break;
		}
		printw(" ");
	}

	printw("\n");

	return ;
}

void
Game::print_menu()
{
	if (this->_pawn_turn == 1) {
		this->_pawnmenu->draw();
	}
	else {
		this->_discmenu->draw();
	}

	return ;
}

void
Game::draw() {
	clear();
	move(10,0);
	print_color_players();
	print_color_stair();
//	print_color_pawn();
	print_color_board();
	printw("\n");
	refresh();

	print_menu();

	return ;
}

void
Game::climb_stair(Color color)
{
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

	if (strchr(this->_stair, char_pawn) == NULL) {
		this->_stair[this->_stair_pos] = char_pawn;
		this->_stair_pos++;
		player((const char*) &char_disc);
		this->_picked = 0;
		this->_player_turn++;
		this->_player_turn %= number_players();
	}

	return ;
}


int
Game::move_pawn(Color color)
{
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
			this->_skip_pick_disc = 0;
		}
		// Move to stair
		else {
			climb_stair(color);
			this->_skip_pick_disc = 1;
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
	fprintf(stderr,"Pawn: %d\tDisc: %d\n", pawn_pos, disc_pos);
	this->_pawn_pos = disc_pos;

	return pawn_pos;
}

void
Game::player(const char* disc)
{
	fprintf(stderr, "player(%c)\n", disc[0]);
	this->_players[this->_player_turn]->discs(disc);
	return ;
}

void
Game::pick_right()
{
	fprintf(stderr, "pick_right\n");
	bool success = true;
	int position = this->_board.find_first_not_of("RGBYP0", this->_pawn_pos);
	if (position == (int) string::npos) {
		success = false;
	}
	else {
		player((const char*) &this->_board.at(position));
		this->_board.at(position) = '0';
	}

	fprintf(stderr, "disc_position\t%d\n", position);
	fprintf(stderr, "success\t%d\n", success);
	this->_picked = success;
	return ;
}

void
Game::pick_left()
{
	fprintf(stderr, "pick_left\n");
	bool success = true;
	int position = this->_board.find_last_not_of("RGBYP0", this->_pawn_pos);
	if (position == (int) string::npos) {
		success = false;
	}
	else {
		player((const char*) &this->_board.at(position));
		this->_board.at(position) = '0';
	}

	fprintf(stderr, "pawn_position\t%d\n", this->_pawn_pos);
	fprintf(stderr, "disc_position\t%d\n", position);
	fprintf(stderr, "success\t%d\n", success);
	this->_picked = success;
	return ;
}

void
Game::select_option()
{
	// Choose pawn to move
	if (this->_pawn_turn == 1) {
		fprintf(stderr, "Choose pawn\n");
		// Action depends on the highlight
		switch (this->_pawnmenu->highlight()) {
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
			move_pawn(Color::Yellow);
			break;

			case 4:
			move_pawn(Color::Purple);
			break;

			default:
			break;
		}
	}
	else {
		if (this->_skip_pick_disc == 0) {
			fprintf(stderr, "Choose disc\n");
			// Action depends on the highlight
			switch (this->_discmenu->highlight()) {
				case 0:
				pick_left();
				break;

				case 1:
				pick_right();
				break;

				default:
				break;
			}
		}
	}

	return ;
}

void
Game::loop(void)
{
	fprintf(stderr, "Game loop(void)\n");

	bool quit = 0;

	while (!quit) {
		draw();
		if (this->_stair_pos == number_pawns()) {
			quit = 1;
			break;
		}
		else {
			int c = 0;
			// Choose pawn to move
			if (this->_pawn_turn == 1) {
				c = this->_pawnmenu->wait_choice();
				fprintf(stderr, "Option\t%d\n", c);
				switch (c) {
					// Press q to quit
					case 'q':
					quit = 1;
					break;

					// Press enter to choose action on menu
					case 10:
					select_option();
					if (this->_skip_pick_disc == 1) {
						this->_pawn_turn = 1;
					}
					else {
						this->_pawn_turn = 0;
					}
					break;

					default:
					break;
				}
			}
			// Choose disc to pick
			else {
				c = this->_discmenu->wait_choice();
				fprintf(stderr, "Option\t%d\n", c);
				switch (c) {
					// Press q to quit
					case 'q':
					quit = 1;
					break;

					// Press enter to choose action on menu
					case 10:
					select_option();
					break;

					default:
					break;
				}
				if (this->_picked == true) {
					this->_pawn_turn = 1;
					this->_picked = false;
					if (this->_players[this->_player_turn]->has_black() == true) {
						this->_pawn_turn = 3;
					}
					this->_player_turn++;
					this->_player_turn %= number_players();
				}
			}
		}
	}

	move(8,37);
	if (calculate_score(0) > calculate_score(1)) {
		printw("Player 1 wins!");
	}
	else if (calculate_score(0) < calculate_score(1)) {
		printw("Player 2 wins!");
	}
	else {
		printw("Player 1 and Player 2 draws!");
	}

	getch();

	return ;
}

int
Game::calculate_score(int player_id)
{
	return this->_players[player_id]->score((const char*) this->_stair, this->_stair_pos, number_pawns());
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
	this->_board = "RGB1372233622167123113";
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

Menu*
Game::discwin(void)
{
	return this->_discmenu;
}

Menu*
Game::pawnwin(void)
{
	return this->_pawnmenu;
}
