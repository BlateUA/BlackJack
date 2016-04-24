#include "Hand.h"

Hand::Hand()
{
	mCards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::AddCard(Card* aCard)
{
	mCards.push_back(aCard);
}

void Hand::Clear()
{
	vector<Card*>::iterator iter;
	for (iter = mCards.begin(); iter != mCards.end(); iter++)
	{
		delete *iter;
		*iter = 0;
	}
	mCards.clear();
}

int Hand::GetScore() const
{
	if (mCards.empty())
	{
		return 0;
	}
	if (mCards[0]->GetValue() == 0)
	{
		return 0;
	}

	int total = 0;
	bool aceHere = false;
	vector<Card*>::const_iterator c_iter;
	for (c_iter = mCards.begin(); c_iter != mCards.end(); c_iter++)
	{
		if ((*c_iter)->GetValue() == Card::ACE)
		{
			aceHere = true;
			
		}
		total += (*c_iter)->GetValue();
	}
	if (total < 12 && aceHere) total += 10;
	return total;
}