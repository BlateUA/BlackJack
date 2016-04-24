#include "Card.h"

int Card::GetValue() const
{
	int value=0;
	if (mVisible)
	{
		value = mRank;
		if (value > 10) value = 10;
	}
	return value;
}

void Card::Flip()
{
	mVisible = !(mVisible);
	
}


ostream& operator<<(ostream & os, const Card & aCard)
{
	const string RANKS[]{ "0", "A", "2","3","4","5","6","7","8","9","10",
						  "J","Q","K" };
	const string SUIT[]{ "H","D","C","S" };


	if (aCard.mVisible)
	{
		os << RANKS[aCard.mRank] << SUIT[aCard.mSuit];
	}
	else
	{
		os << "XX";
	}
	return os;
}
