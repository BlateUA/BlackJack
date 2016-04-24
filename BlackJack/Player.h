#pragma once
#include "Hand.h"
const int RoundPoints = 100;
class Player : public Hand
{

	friend ostream& operator<<(ostream& os, const Player& player);
public:
	Player( int aScore, const string& aName = "Default player") :mName(aName),mScore(aScore) {}
	virtual ~Player() {}
	virtual bool IsHitting() const = 0;
	virtual bool IsBusted() const
	{
		return (GetScore() > 21);
	}
	void Bust()
	{
		cout << mName << " wasted.\n";
		mScore -= RoundPoints;
	}
	inline int Score() const
	{
		return mScore;
	}
	string Name() const;
protected:
	string mName;
	int mScore;
};


