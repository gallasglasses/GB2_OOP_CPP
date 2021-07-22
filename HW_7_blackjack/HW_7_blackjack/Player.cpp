#include "Player.h"

Player::Player(const std::string& name)
	: GenericPlayer(name)
{

}

bool Player::isHitting() const
{
	char answer;
	bool isSetAnswer = true;
	std::cout << "Player " << playerName << ", do you need another card?\nEnter 'Y' - Yes or 'N' - No : ";
	while (isSetAnswer)
	{
		if ((answer = tolower(Validation::getAnswer())) != 'n')
		{
			if (answer == '\n')
				continue;
		}
		return isSetAnswer = (answer == 'y') ? true : false;
	}
}

void Player::Win() const
{
	std::cout << "Player " << playerName << "! Winner winner chicken dinner! Congrats!\n";
}

void Player::Lose() const
{
	std::cout << "Player " << playerName << " loses.\n";
}

void Player::Push() const
{
	std::cout << "Player " << playerName << " pushs.\n";
}

Player::~Player()
{

}