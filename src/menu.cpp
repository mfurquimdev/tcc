#include "menu.h"
#include <cstring>
#include <ncurses.h>

using namespace std;

Menu::Menu(int x, int y, int columns, int lines, const char** char_choices, int num_choices)
{
	fprintf(stderr, "constructor\n");
	position(x,y);
	window_size(columns,lines);
	window(position(), window_size());
	choices(char_choices, num_choices);
	keypad(this->_window, true);
	box(this->_window, 0, 0);
}

int
Menu::wait_choice()
{
	fprintf(stderr, "wait_choice\n");
	int c = 0;
	c = wgetch(this->_window);
	switch (c) {
		// Press q to quit
		case 'q':
		c = 0xFFFF;
		break;

		// Move up on the menu
		case KEY_UP:
		// this->_highlight--;
		// if (this->_highlight < 0) {
		// 	this->_highlight = 0;
		// }
		break;

		// Move down on the menu
		case KEY_DOWN:
		// this->_highlight++;
		// if (this->_highlight > 3) {
		// 	this->_highlight = 3;
		// }
		break;

		// Press enter to choose action on menu
		case 10:
		// quit = select_option();
		break;

		default:
		break;
	}

	return c;
}


void
Menu::choices(const char** char_choices, int num_choices)
{
	fprintf(stderr, "set choices\n");
	this->_num_choices = num_choices;
	this->_choices = NULL;
	this->_choices = (char**) malloc (sizeof(char)*num_choices);
	fprintf(stderr, "[%p]%u\n", (void*) this->_choices, sizeof(char_choices));
	for (int i = 0; i < num_choices; ++i) {
		fprintf(stderr, "%s[%d]", char_choices[i], strlen(char_choices[i]));
		this->_choices[i] = (char*) malloc(sizeof(char)*strlen(char_choices[i]));
		strncpy(this->_choices[i], char_choices[i], strlen(char_choices[i]));
		fprintf(stderr, "\t%s\n", this->_choices[i]);
	}
	return ;
}

void
Menu::update()
{
	fprintf(stderr, "update\n");
	wrefresh(this->_window);

	return ;
}

const char**
Menu::choices(void)
{
	fprintf(stderr, "get choices\n");
	return (const char**) this->_choices;
}

void
Menu::window(pair<int, int> position, pair<int, int> window_size)
{
	fprintf(stderr, "set window\n");
	fprintf(stderr, "(x,y)\t(%d,%d)\n", position.first, position.second);
	fprintf(stderr, "(w,h)\t(%d,%d)\n", window_size.first, window_size.second);
	this->_window = newwin(window_size.second, window_size.first, position.second, position.first);
	return ;
}

WINDOW*
Menu::window(void)
{
	fprintf(stderr, "getupdate\n");
	return this->_window;
}

void
Menu::window_size(int columns, int lines)
{
	fprintf(stderr, "set window_size\n");
	this->_window_size = make_pair(columns, lines);
	return ;
}

pair<int, int>
Menu::window_size(void)
{
	fprintf(stderr, "get window_size\n");
	return this->_window_size;
}

void
Menu::position(int x, int y)
{
	fprintf(stderr, "set position\n");
	this->_position = make_pair(x, y);
	return ;
}

pair<int, int>
Menu::position(void)
{
	fprintf(stderr, "get position\n");
	return this->_position;
}
