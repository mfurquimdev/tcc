#include "game.h"

#include <ncurses.h>
#include <cstdio>
#include <stdio_ext.h>
#include <thread>
#include <chrono>

Game::Game()
{
	fprintf(stderr, "[%p]\tGame()\n", (void*) this);
	
	number_players(2);
	number_pawns(5);
	number_discs(9);
	number_special_discs(5);

	init_players_disc();
	init_board();
}

Game::~Game()
{
	fprintf(stderr, "[%p]\tGame destructor\n", (void*) this);
}

void
Game::loop(void)
{
	fprintf(stderr, "Game loop(void)\n");

	bool quit = 0;

	while (!quit) {
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
	fprintf(stderr, "init_players(void)\n");
	this->_players_disc.clear();

	return ;
}

void
Game::init_board(void)
{
	fprintf(stderr, "init_board(void)\n");
	this->_board = "";
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
