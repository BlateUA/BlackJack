#include "ComputerPlayer.h"

bool ComputerPlayer::IsHitting() const
{
	return (GetScore() < 17);
}

void ComputerPlayer::Flip1stCard()
{			
	if (mCards.empty())
	{
		cout << "No card to flip.\n";
	}
	else
	{
		mCards[0]->Flip();
	}
}
