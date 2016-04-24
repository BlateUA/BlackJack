#include "Deck.h"

Deck::Deck()
{
	mCards.reserve(52);
	Populate();
}

void Deck::Populate()
{
	Clear();
	for (int s = Card::HEART; s <= Card::SPADE; s++)
	{
		for (int r = Card::ACE; r <= Card::KING; r++)
		{
			AddCard(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(mCards.begin(), mCards.end());
	cout << "Shuffled.\n";
}

void Deck::Deal(Hand & aHand)
{
	if (mCards.empty())
	{
		cout << "Out of cards. Unable to deal.";
	}
	else
	{
		aHand.AddCard(mCards.back());
		mCards.pop_back();
	}
}

void Deck::MoreCard(Player & aPlayer)
{
	cout << endl;
	while (!(aPlayer.IsBusted()) && aPlayer.IsHitting())
	{
		Deal(aPlayer);
		cout << aPlayer << endl;
	}
	if (aPlayer.IsBusted())
	{
		aPlayer.Bust();
	}

}

