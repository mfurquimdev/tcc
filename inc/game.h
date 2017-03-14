#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <ncurses.h>
#include "registering_enum.h"
#include "menu.h"

using namespace std;

class Game
{
public:
	Game(WINDOW*, pair<int, int>);
	~Game();

	void loop(void);

private:

	/* Functions */
	void draw();
	unsigned short int choose_pawn(unsigned short int);
	unsigned short int choose_disc(unsigned short int);

	void init_players_disc(void);
	void init_board(void);

	void print_color_stair();
	void print_color_pawn();
	void print_color_board();
	void print_color_players();
	void print_menu();

	bool select_option();
	int move_pawn(Color);

	bool pick_right(int);
	bool pick_left(int);

	/* Getters and Setters */
	void number_players(unsigned short int);
	unsigned short int number_players(void);

	void number_pawns(unsigned short int);
	unsigned short int number_pawns(void);

	void number_discs(unsigned short int);
	unsigned short int number_discs(void);

	void number_special_discs(unsigned short int);
	unsigned short int number_special_discs(void);

	vector<string> players_disc(void);
	string board(void);
	Menu* discwin(void);
	Menu* pawnwin(void);

	/* Variables */
	int _pawn_turn;
	int _reachable;
	int _highlight;
	char _choices[4][20];
	unsigned short int _num_players;
	unsigned short int _num_pawns;
	unsigned short int _num_discs;
	unsigned short int _num_special_discs;
	vector<string> _players_disc;
	string _board;
	Menu* _pawnwin;
	Menu* _discwin;
	pair<int, int> _screen_size;
};

#endif
