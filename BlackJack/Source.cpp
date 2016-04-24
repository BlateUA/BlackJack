#include "Game.h"

int HumanPlayer::players = 0;

void main()
{
	cout << "Welcome to the blackjack game! \n\n";
	int numPlayers=0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players want to play? (1-7): ";
		cin >> numPlayers;
	}
	vector<string> playersNames;
	string name;
	for (int i=0; i < numPlayers;i++)
	{
		cout << "\nEnter player name: ";
		cin >> name;
		playersNames.push_back(name);
	}
	cout << endl;
	Game theGame(playersNames);
	char again='y';
	while (again != 'n' && again != 'N')
	{
		theGame.Play();
		theGame.Scoreboard();
		cout << "Do you want to play again? (Y/N): ";
		cin >> again;
	}
}