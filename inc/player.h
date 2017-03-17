#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstring>
#include <string>

using namespace std;

class Player
{
public:
	Player();
	~Player();

	void discs(const char*);
	string discs(void);
	unsigned short int score(const char*, int, unsigned short int);
	int appearance(char);
	bool has_black();

private:
	string _discs;
	int _score;
	int _diff_colors;
};

#endif
