#include <sstream>
#include <vector>

using namespace std;

class Player
{
	private:
		vector<int> cards;
		
		string getCardString(int card);
	public:
		Player();
		
		vector<int> getCards();
		void setCards(vector<int> cards);
		
		void addCard(int card);
		int getCardSum();
		void printCards();
};
// Constructors
Player::Player() {}
// Methods
vector<int> Player::getCards()
{
	return this->cards;
}
void Player::setCards(vector<int> cards)
{
	this->cards = cards;
}
void Player::addCard(int card)
{
	this->cards.push_back(card);
}
int Player::getCardSum()
{
	int sum = 0;
	for (int i = 0; i < this->getCards().size(); i++)
	{
		int card = this->getCards().at(i);
		if (card == 14)
		{
			if (sum + 11 > 21)
			{
				sum++;
			}
			else
			{
				sum += 11;
			}
		}
		else if (card > 10)
		{
			sum += 10;
		}
		else
		{
			sum += card;
		}
	}
	return sum;
}
void Player::printCards()
{
	for (int i = 0; i < this->getCards().size(); i++)
	{
		int card = this->getCards().at(i);
		cout << getCardString(card) << "\n";
	}
}
string Player::getCardString(int card)
{
	if (card < 11)
	{
		stringstream ss;
		ss << card;
		return ss.str();
	}
	else
	{
		switch (card)
		{
			case 11:
				return "Jack";
			case 12:
				return "Queen";
			case 13:
				return "King";
			case 14:
				return "Ace";
			default:
				break;
		}
	}
}
