#pragma once
//class for a Card
#include <iostream>
#include <string>
//#include "Card.cpp"
using namespace std;

class Card
{

public:
	enum suit {HEART, DIAMOND, CLUB, SPADE};
	enum rank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
		EIGHT, NINE, TEN, JACK, QUENN, KING};
	friend ostream& operator<<(ostream& os, const Card& aCard);
	Card(rank aRank=ACE, suit aSuit=HEART, bool a=true) :mRank(aRank), mSuit(aSuit), mVisible(a)
	{}
	~Card() {}

	int GetValue() const;
	void Flip();
private:
	rank mRank;
	suit mSuit;
	bool mVisible;
};



