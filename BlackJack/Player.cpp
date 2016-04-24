#include "Player.h"

ostream & operator<<(ostream & os, const Player & player)
{

	os << player.mName << ":\t";
	vector<Card*>::const_iterator iter;
	if (!player.mCards.empty())
	{
		for (iter = player.mCards.begin(); iter != player.mCards.end(); iter++)
		{
			cout << *(*iter) << "\t";
		}
		if (player.GetScore() != 0)
		{
			cout << "(" << player.GetScore() << ")";
		}
	}
	else
	{
		os << "<empty>\n";
	}
	return os;

}

string Player::Name() const
{
	return mName;
}
