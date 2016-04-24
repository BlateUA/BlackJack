#pragma once
#include "Player.h"

class ComputerPlayer :public Player
{
public:
	ComputerPlayer(const string& aName = "Host"): Player(0,aName) {}
	virtual ~ComputerPlayer() {}
	virtual bool IsHitting() const;
	void Flip1stCard();

};
