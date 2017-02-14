#include "game.h"
#include "color.h"

#include <cstdlib>
#include <ncurses.h>

using namespace std;

pair<int,int> start_ncurses(void);
void end_ncurses(void);

int main(int argc, char* argv[])
{
	pair<int, int> screen_size;
	screen_size = start_ncurses();

	WINDOW* menuwin = newwin(6, screen_size.second-12, screen_size.first-8, 5);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);

	// Using arrow keys
	keypad(menuwin, true);

	Game* game = NULL;
	game = new Game(menuwin);

	if (game == NULL) {
		printw("Could not start game.");
		fprintf(stderr, "[%p] game variable is null.", (void*) game);
	}
	else {
		game->loop();
		delete(game);
		game = NULL;
	}

	end_ncurses();

	return 0;
}

pair<int, int> start_ncurses(void)
{
	initscr();
	cbreak();
	noecho();

	// Get screen size
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	if (has_colors()) {
		start_color();

		if (can_change_color()) {

			//init_color(color, 0~999, 0~999, 0~999);
			init_color(COLOR_BLACK  ,   0,   0,   0);
			init_color(COLOR_RED    , 999,   0,   0);
			init_color(COLOR_GREEN  ,   0, 999,   0);
			init_color(COLOR_YELLOW , 999, 999,   0);
			init_color(COLOR_BLUE   ,   0,   0, 999);
			init_color(COLOR_MAGENTA, 999,   0, 999);
			init_color(COLOR_CYAN   , 500, 500, 500);
			init_color(COLOR_WHITE  , 999, 999, 999);
		}

		//init_pair(#color_pair, Foreground, Background);
		init_pair((short int)NcursesColors::FW, COLOR_WHITE  , COLOR_BLACK  );
		init_pair((short int)NcursesColors::FR, COLOR_RED    , COLOR_BLACK  );
		init_pair((short int)NcursesColors::FG, COLOR_GREEN  , COLOR_BLACK  );
		init_pair((short int)NcursesColors::FB, COLOR_BLUE   , COLOR_BLACK  );
		init_pair((short int)NcursesColors::FY, COLOR_YELLOW , COLOR_BLACK  );
		init_pair((short int)NcursesColors::FM, COLOR_MAGENTA, COLOR_BLACK  );
		init_pair((short int)NcursesColors::FC, COLOR_CYAN   , COLOR_BLACK  );
		init_pair((short int)NcursesColors::BK, COLOR_CYAN   , COLOR_CYAN   );
		init_pair((short int)NcursesColors::BW, COLOR_WHITE  , COLOR_WHITE  );
		init_pair((short int)NcursesColors::BR, COLOR_RED    , COLOR_RED    );
		init_pair((short int)NcursesColors::BG, COLOR_GREEN  , COLOR_GREEN  );
		init_pair((short int)NcursesColors::BY, COLOR_YELLOW , COLOR_YELLOW );
		init_pair((short int)NcursesColors::BB, COLOR_BLUE   , COLOR_BLUE   );
		init_pair((short int)NcursesColors::BM, COLOR_MAGENTA, COLOR_MAGENTA);
		init_pair((short int)NcursesColors::BC, COLOR_CYAN   , COLOR_CYAN   );
	}
	else {
		printw("Terminal does not support color");
		getch();
	}

	return make_pair(yMax, xMax);
}

void end_ncurses()
{
	endwin();

	return ;
}
