#pragma once

#include "Hand.h"
#include "Player.h"
#include <algorithm>
class Deck: public Hand
{
public:
	Deck();
	virtual ~Deck() {}
	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void MoreCard(Player& aPlayer);

};