#include "game.h"

#include <cstdlib>
#include <ncurses.h>

using namespace std;

pair<int,int> start_ncurses(void);
void end_ncurses(void);

/* Enum Colors */
enum Colors
{
	FW = 1, FR, FG, FY,	FB,	FM,	FC,
	BB,	BW,	BR,	BG,	BY,	BM,	BC
};

int main(int argc, char* argv[])
{
	pair<int, int> screen_size;
	screen_size = start_ncurses();

	Game* game = NULL;
	game = new Game();
	
	if (game == NULL) {
		fprintf(stdout, "Could not start game.");
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
			init_color(COLOR_CYAN   ,   0, 999, 999);
			init_color(COLOR_WHITE  , 999, 999, 999);
		}

		//init_pair(#color_pair, Foreground, Background);
		init_pair(FW, COLOR_WHITE  , COLOR_BLACK  );
		init_pair(FR, COLOR_RED    , COLOR_BLACK  );
		init_pair(FG, COLOR_GREEN  , COLOR_BLACK  );
		init_pair(FY, COLOR_YELLOW , COLOR_BLACK  );
		init_pair(FB, COLOR_BLUE   , COLOR_BLACK  );
		init_pair(FM, COLOR_MAGENTA, COLOR_BLACK  );
		init_pair(FC, COLOR_CYAN   , COLOR_BLACK  );
		init_pair(BB, COLOR_BLACK  , COLOR_BLACK  );
		init_pair(BW, COLOR_WHITE  , COLOR_WHITE  );
		init_pair(BR, COLOR_RED    , COLOR_RED    );
		init_pair(BG, COLOR_GREEN  , COLOR_GREEN  );
		init_pair(BY, COLOR_YELLOW , COLOR_YELLOW );
		init_pair(BB, COLOR_BLUE   , COLOR_BLUE   );
		init_pair(BM, COLOR_MAGENTA, COLOR_MAGENTA);
		init_pair(BC, COLOR_CYAN   , COLOR_CYAN   );
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

