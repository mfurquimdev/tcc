#include "menu.h"
#include <ncurses.h>

pair<int, int> start_ncurses(void);
void end_ncurses(void);


int main()
{
	fprintf(stderr, "main\n");
	start_ncurses();

	const char* disc_choices[2] = {"Pick left\0", "Pick right\0"};
	Menu* disc_menu = new Menu(1, 1, 30, 6, disc_choices, 2);
	refresh();
	disc_menu->update();
	disc_menu->wait_choice();


	end_ncurses();
	return 0;
}

pair<int, int> start_ncurses(void)
{
	fprintf(stderr, "start_ncurses\n");
	initscr();
	cbreak();
	noecho();

	// Get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	return make_pair(yMax, xMax);
}

void end_ncurses(void)
{
	fprintf(stderr, "end_ncurses\n");
	endwin();

	return ;
}
