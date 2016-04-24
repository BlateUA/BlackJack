#pragma once
#include "Card.h"
#include <vector>
class Hand
{
public:
	Hand();
	virtual ~Hand();

	void AddCard(Card* aCard);
	void Clear();
	int GetScore() const;

protected:
	vector<Card*> mCards;
	
};