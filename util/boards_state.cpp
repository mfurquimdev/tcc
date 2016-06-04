#include <iostream>
#include <cstdio>
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

int main()
{
	string board = "1212";
	add_board(board);

	for (int p = 1; p <= 2; p++) {
		move(board,p);
	}

	for(auto p: boards) {
		cout << "\nKey: " << p.first << "\tValue: " << p.second << endl;
	}

	for (size_t i = 0; i < counter; i++) {
		cout << "\nKey: " << i << "\tValue: " << masks[i] << endl;
	}

	return 0;
}

int move_pawn(string& board, int pawn)
{
	// Move Pawn
	char c_pawn;
	char n_char = ' ';
	char buffer[2];

	sprintf(buffer, "%d", pawn);
	n_char = buffer[0];

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

void pick_right(string& board, int pawn)
{
//	board.replace(pawn_pos, 1, 1, '0');

	return ;
}

void pick_left()
{
//	board.replace(pawn_pos, 1, 1, '0');

	return ;
}

void move(string board, int pawn)
{
	printf("%s\n", board.c_str());

	add_board(board);
	int pawn_pos = move_pawn(board, pawn);
	if (pawn_pos < 0) {
		return ;
	}

	// Picking discs
/*
	position = board.find_first_not_of("RGBYV", pawn_pos);
	if (position != string::npos) {
		pick_left(board, position);
	}

	position = board.find_last_not_of("RGBYV", pawn_pos);

	if (position != string::npos) {
		pick_right(board, position);
	}
*/
	printf("%s\n", board.c_str());

	for (int p = 1; p <= 2; p++) {
		move(board,p);
	}

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
