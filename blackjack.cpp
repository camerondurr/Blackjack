#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Player.cpp"
#include "random.h"

int main()
{
	string userInput;
	while (true)
	{
		while (true)
		{
			cout << "Type 'Start' to start the game.\n";
			cin >> userInput;
			if (userInput == "Start")
			{
				break;
			}
		}
		
		Player player;
		srand(time(NULL));
		player.addCard(getNumberInRange(2, 14));
		player.addCard(getNumberInRange(2, 14));
		
		while (true)
		{
			cout << "\nYour cards:\n";
			player.printCards();
			cout << "Total: " << player.getCardSum() << "\n";
			
			cout << "Type 'Hit' to get another card. Type 'Stay' to end the game.\n";
			cin >> userInput;
			if (userInput == "Hit")
			{
				player.addCard(getNumberInRange(2, 14));
				
				if (player.getCardSum() > 21)
				{
					cout << "You lose.\n";
					cout << "You busted at " << player.getCardSum() << ".\n";
					break;
				}
			}
			else if (userInput == "Stay")
			{
				int playerCards = player.getCardSum();
				int dealerCards = getNumberInRange(15, 25);
				
				if (dealerCards > 21 || playerCards > dealerCards)
				{
					cout << "You win!\n";
					cout << "Dealer had: " << dealerCards << "\n";
					break;
				}
				else if (dealerCards == playerCards)
				{
					cout << "You tie!\n";
					break;
				}
				else
				{
					cout << "You lose.\n";
					cout << "Dealer had: " << dealerCards << "\n";
					break;
				}
			}
		}
		
		cout << "Do you want to play again? ('Yes' or 'No')\n";
		cin >> userInput;
		if (userInput == "No")
		{
			cout << "Goodbye!\n";
			break;
		}
	}
	
	return 0;
}
