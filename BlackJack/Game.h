#pragma once
#include "Deck.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Game
{
public:
	Game(const vector<string> names);
	~Game();
	void Play();
	void Scoreboard();
private:
	Deck mDeck;
	ComputerPlayer mHost;
	vector<HumanPlayer> mPlayers;
};