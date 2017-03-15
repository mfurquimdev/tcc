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

private:
	string _discs;
	int _score;
};

#endif
