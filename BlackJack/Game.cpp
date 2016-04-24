#include "Game.h"
#include <ctime>
Game::Game(const vector<string> names)
{
	vector<string>::const_iterator iter;
	for (iter = names.begin(); iter != names.end(); iter++)
	{
		mPlayers.push_back(HumanPlayer(*iter));
	}
	srand(static_cast<unsigned int>(time(0)));
	mDeck.Populate();
	mDeck.Shuffle();
}

Game::~Game() {}

void Game::Play()
{
	vector<HumanPlayer>::iterator pPlayer;
	for (int i = 0; i < 2; i++)
	{
		for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); pPlayer++)
		{
			mDeck.Deal(*pPlayer);
		}
		mDeck.Deal(mHost);
	}
	mHost.Flip1stCard();
	for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); pPlayer++)
	{
		cout << *pPlayer << endl;
	}
	cout << mHost << endl;
	for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); pPlayer++)
	{
		mDeck.MoreCard(*pPlayer);
	}
	mHost.Flip1stCard();
	cout << endl << mHost << endl;
	mDeck.MoreCard(mHost);
	if (mHost.IsBusted())
	{
		for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); pPlayer++)
			if (!(pPlayer->IsBusted()))
				pPlayer->Win();
	}
	else
	{
		for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); pPlayer++)
			if (!(pPlayer->IsBusted()))
			{
				if (pPlayer->GetScore() > mHost.GetScore())
					pPlayer->Win();
				else if (pPlayer->GetScore() < mHost.GetScore())
					pPlayer->Lose();
				else pPlayer->Push();

			}
	}
	for (pPlayer = mPlayers.begin(); pPlayer != mPlayers.end(); pPlayer++)
		pPlayer->Clear();
	mHost.Clear();
}

void Game::Scoreboard()
{
	cout << "\n----====The scoreboard:====----\n";
	vector<HumanPlayer>::const_iterator iter;
	for (iter = mPlayers.begin(); iter != mPlayers.end();iter++)
	{
		cout << endl << (*iter).Name() << ":\t" << iter->Score() << ".\n";
	}
	cout << endl;
}
