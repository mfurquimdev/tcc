#ifndef __TURN_H__
#define __TURN_H__

struct Turn
{
	short current_player;
	short pawn_to_move;
	bool pick_right;

	Turn (short j, short p, bool r) :
		current_player(j), pawn_to_move(p), pick_right(r)
	{
		// Nothing to do
	};

	friend ostream& operator<<(ostream& out, const struct Turn& turn)
	{
		out << endl;
		out << "Player " << turn.current_player + 1;
		out << " moves pawn " << turn.pawn_to_move + 1;
		out << " and picks " << (turn.pick_right ? "right" : "left");

		return out;
	};

};

#endif
