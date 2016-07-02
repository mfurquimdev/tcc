#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

static map<string,int> boards;
static map<int,string> masks;
static int counter = 0;

void add_board(string);
void move(string,int);
int move_pawn(string&, int);
void pick_right(string, int);
void pick_left(string, int);

static int num_discs = 2;
static int num_pawns = 2;

int main(int argc, char* argv[])
{
	string board = "";

	boards.clear();
	masks.clear();
	counter = 0;

	int c;
	while((c = getopt(argc, argv, "d:p:")) != -1) {
		switch (c) {
			case 'd':
			if(optarg) num_discs = atoi(optarg);
			break;

			case 'p':
			if(optarg) num_pawns = atoi(optarg);
			break;
		}
	}

	for (int disc = 0; disc < num_discs; disc++) {
		for (char pawn = 1; pawn <= (char) num_pawns; pawn++) {
			board.push_back(pawn+48);
		}
	}
	add_board(board);

	for (int p = 1; p <= num_pawns; p++) {
		move(board,p);
	}

	fprintf(stderr,"P: %d\tD: %d\tTotal: %d\n", num_pawns, num_discs, boards.size());
	printf("%d\n", boards.size());

	return 0;
}

int move_pawn(string& board, int pawn)
{
	// Move Pawn
	char c_pawn;
	char n_char = ' ';
	n_char = (char) pawn+48;

	switch (pawn) {
		// Red
		case 1:
		c_pawn = 'R';
		break;

		// Green
		case 2:
		c_pawn = 'G';
		break;

		// Blue
		case 3:
		c_pawn = 'B';
		break;

		// Yellow
		case 4:
		c_pawn = 'Y';
		break;

		// Violet
		case 5:
		c_pawn = 'V';
		break;

		default:
		break;
	}

	int position = 0;
	position = board.find_first_of(c_pawn);

	if (position == (int) string::npos) {
		position = -1;
	}
	else {
		board.replace(position, 1, 1, n_char);
	}

	int pawn_pos = board.find_first_of(n_char, position+1);

	if (pawn_pos == (int) string::npos) {
		return -1;
	}

	board.replace(pawn_pos, 1, 1, c_pawn);

	return pawn_pos;
}

void pick_right(string board, int pawn_pos)
{
	int position = board.find_first_not_of("RGBYV0", pawn_pos);
	if (position != string::npos) {
		board.replace(position, 1, 1, '0');
	}

	for (int p = 1; p <= num_pawns; p++) {
		move(board,p);
	}

	return ;
}

void pick_left(string board, int pawn_pos)
{
	int position = board.find_last_not_of("RGBYV0", pawn_pos);
	if (position != string::npos) {
		board.replace(position, 1, 1, '0');
	}

	for (int p = 1; p <= num_pawns; p++) {
		move(board,p);
	}

	return ;
}

void move(string board, int pawn)
{
	add_board(board);
	int pawn_pos = move_pawn(board, pawn);
	if (pawn_pos < 0) {
		return ;
	}

	// Picking discs
	pick_right(board, pawn_pos);
	pick_left(board, pawn_pos);

	return ;
}

void add_board(string board)
{
	if (boards.count(board) <= 0)
	{
		boards[board.c_str()] = counter;
		masks[counter] = board.c_str();
		counter++;
	}

	return ;
}
