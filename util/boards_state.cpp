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

int main()
{
	string board = "1212";
	add_board(board);

	for (int p = 1; p <= 2; p++) {
		move(board,p);
	}

	for(auto p: boards)
		cout << "\nKey: " << p.first << "\tValue: " << p.second << endl;

	return 0;
}

void move(string board, int pawn)
{
	printf("%s\n", board.c_str());

	add_board(board);
	char c_pawn;
	char n_char[1] = '';

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

	sprintf(n_char, "%d", pawn);
	board.replace(
		board.find_first_of(n_char, position+1), 1, c_pawn);

	printf("%s\n", board.c_str());

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
