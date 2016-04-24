#include "HumanPlayer.h"

bool HumanPlayer::IsHitting() const
{
	cout << mName <<", do you want to take additional card? (Y/N): ";
	char k;
	cin >> k;
	return (k == 'Y' || k == 'y');
}

void HumanPlayer::Win()
{
	cout << mName << ", win!\n";
	mScore += RoundPoints;
	cout << "Score: " << Score() << ".\n";
}

void HumanPlayer::Lose()
{
	cout << mName << ", lost.\n";
	mScore -= RoundPoints;
	cout << "Score: " << Score() << ".\n";
}

void HumanPlayer::Push() const
{
	cout << mName << ", pushes.\n";
	cout << "Score: " << Score() << ".\n";
}

