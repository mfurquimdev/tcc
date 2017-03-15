#ifndef MENU_H
#define MENU_H

#include "registering_enum.h"
#include <ncurses.h>
#include <algorithm>

using namespace std;

class Menu
{
public:
	Menu(int, int, int, int, const char**, int);
	~Menu();

	void draw();
	int wait_choice();
	int highlight(void);

private:
	void update();
	WINDOW* window(void);

	void position(int, int);
	pair<int, int> position(void);

	void window_size(int, int);
	pair<int, int> window_size(void);

	void window(pair<int, int>, pair<int, int>);

	void choices(const char**, int);
	const char** choices(void);

	int num_choices(void);

	void highlight(int);

	int _highlight;
	char** _choices;
	int _num_choices;
	pair<int, int> _position;
	pair<int, int> _window_size;
	WINDOW* _window;
};
#endif
