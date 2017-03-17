#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <ncurses.h>
#include "registering_enum.h"
#include "menu.h"
#include "player.h"

using namespace std;

class Game
{
public:
	Game(pair<int, int>);
	~Game();

	void loop(void);

private:

	/* Functions */
	void draw();
	unsigned short int choose_pawn(unsigned short int);
	unsigned short int choose_disc(unsigned short int);

	void init_players_disc(void);
	void init_board(void);
	void init_players(void);
	void init_stair(void);

	void print_color_stair();
	void print_color_pawn();
	void print_color_board();
	void print_color_players();
	void print_menu();

	void select_option();
	int move_pawn(Color);

	void pick_right();
	void pick_left();

	void player(const char*);

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

	void climb_stair(Color);
	void pawn_stair(int);
	int calculate_score(int);

	/* Variables */
	bool _picked;
	int _pawn_pos;
	int _pawn_turn;
	int _reachable;
	unsigned short int _num_players;
	unsigned short int _num_pawns;
	unsigned short int _num_discs;
	unsigned short int _num_special_discs;
	vector<string> _players_disc;
	string _board;
	Menu* _pawnmenu;
	Menu* _discmenu;
	Menu* _blackmenu;
	pair<int, int> _screen_size;
	Player** _players;
	int _player_turn;
	char* _stair;
	int _stair_pos;
	int _skip_pick_disc;

};

#endif
