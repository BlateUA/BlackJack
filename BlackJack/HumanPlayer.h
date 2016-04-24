#pragma once
#include "Player.h"



class HumanPlayer: public Player
{
public:
	static int players;
	HumanPlayer(const string& aName = ("Default player" + players), int aScore=500) :Player(aScore, aName) { players++; }
	~HumanPlayer() { players--; }
	
	virtual bool IsHitting() const;
	void Win();
	void Lose();
	void Push() const;
	

};

