#include "menu.h"
#include <cstring>
#include <ncurses.h>

#define DEBUG 0

using namespace std;

Menu::Menu(int x, int y, int columns, int lines, const char** char_choices, int num_choices)
{
	 if(DEBUG) fprintf(stderr, "[%p] menu constructor\n", (void*) this);
	position(x,y);
	window_size(columns,lines);
	window(position(), window_size());
	choices(char_choices, num_choices);
	keypad(window(), true);
}

Menu::~Menu()
{
	 if(DEBUG) fprintf(stderr, "[%p] menu destructor\n", (void*) this);
	int num_choices = this->num_choices();
	if (this->_choices != NULL) {
		for (int i = 0; i < num_choices; i++) {
			 if(DEBUG) fprintf(stderr, "%i\n", i);
			if (this->_choices[i] != NULL) {
				free(this->_choices[i]);
				this->_choices[i] = NULL;
			}
		}
		 if(DEBUG) fprintf(stderr, "free_choices\n");
		free(this->_choices);
		this->_choices = NULL;
	}

	if (this->_window != NULL) {
		 if(DEBUG) fprintf(stderr, "del_win\n");
		delwin(this->_window);
		this->_window = NULL;
	}
	 if(DEBUG) fprintf(stderr, "[%p] end menu destructor\n");
}

void
Menu::draw()
{
	if(DEBUG) fprintf(stderr, "draw\n");
	WINDOW* window = this->window();
	const char** choices = this->choices();
	int num_choices = this->num_choices();
	int highlight = this->highlight();

	box(window, 0, 0);
	for (int i = 0; i < num_choices; ++i) {
		if (i == highlight) {
			wattron(window, A_REVERSE);
		}
		mvwprintw(window, i+1, 1, choices[i]);
		wattroff(window, A_REVERSE);
	}
	wrefresh(window);


	return ;
}

int
Menu::wait_choice()
{
	if(DEBUG) fprintf(stderr, "wait_choice\n");
	int c = 0;
	c = wgetch(window());
	switch (c) {
		// Move up on the menu
		case KEY_UP:
		highlight(-1);
		break;

		// Move down on the menu
		case KEY_DOWN:
		highlight(1);
		break;

		// Press q to quit
		case 'q':
		break;

		// Press enter to choose action on menu
		case 10:
		break;

		default:
		break;
	}

	return c;
}


void
Menu::choices(const char** char_choices, int num_choices)
{
	if(DEBUG) fprintf(stderr, "set choices\n");
	this->_num_choices = num_choices;
	this->_choices = NULL;
	this->_choices = (char**) malloc (sizeof(char)*num_choices);
	 if(DEBUG) fprintf(stderr, "[%p]%u\n", (void*) this->_choices, sizeof(char_choices));
	for (int i = 0; i < num_choices; ++i) {
		 if(DEBUG) fprintf(stderr, "%s[%d]", char_choices[i], strlen(char_choices[i]));
		this->_choices[i] = (char*) malloc(sizeof(char)*strlen(char_choices[i]));
		strncpy(this->_choices[i], char_choices[i], strlen(char_choices[i]));
		 if(DEBUG) fprintf(stderr, "\t%s\n", this->_choices[i]);
	}
	return ;
}

void
Menu::update()
{
	if(DEBUG) fprintf(stderr, "update\n");
	wrefresh(window());

	return ;
}

const char**
Menu::choices(void)
{
	if(DEBUG) fprintf(stderr, "get choices\n");
	return (const char**) this->_choices;
}

int
Menu::num_choices(void)
{
	if(DEBUG) fprintf(stderr, "get num_choices\n");
	return this->_num_choices;
}

void
Menu::window(pair<int, int> position, pair<int, int> window_size)
{
	if(DEBUG) fprintf(stderr, "set window\n");
	if(DEBUG) fprintf(stderr, "(x,y)\t(%d,%d)\n", position.first, position.second);
	if(DEBUG) fprintf(stderr, "(w,h)\t(%d,%d)\n", window_size.first, window_size.second);
	this->_window = newwin(window_size.second, window_size.first, position.second, position.first);
	return ;
}

WINDOW*
Menu::window(void)
{
	if(DEBUG) fprintf(stderr, "get window\n");
	return this->_window;
}

void
Menu::window_size(int columns, int lines)
{
	if(DEBUG) fprintf(stderr, "set window_size\n");
	this->_window_size = make_pair(columns, lines);
	return ;
}

pair<int, int>
Menu::window_size(void)
{
	if(DEBUG) fprintf(stderr, "get window_size\n");
	return this->_window_size;
}

void
Menu::position(int x, int y)
{
	if(DEBUG) fprintf(stderr, "set position\n");
	this->_position = make_pair(x, y);
	return ;
}

pair<int, int>
Menu::position(void)
{
	if(DEBUG) fprintf(stderr, "get position\n");
	return this->_position;
}

int
Menu::highlight(void)
{
	return this->_highlight;
}

void
Menu::highlight(int increment)
{
	int num_choices = this->num_choices();
	this->_highlight += increment;
	if (this->_highlight > num_choices-1) {
		this->_highlight = num_choices-1;
	}
	else if (this->_highlight < 0) {
		this->_highlight = 0;
	}
	return ;
}
