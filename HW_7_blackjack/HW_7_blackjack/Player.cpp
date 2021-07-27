#include "Player.h"

Player::Player(const std::string& name)
	: GenericPlayer(name)
{

}

bool Player::isHitting() const
{
	bool isSetAnswer = true;
	std::cout << "Player " << playerName << ", do you need another card?\nEnter 'Y' - Yes or 'N' - No\n";
	while (isSetAnswer)
	{
        switch (_getch())
        {
        case 'y':
            return isSetAnswer;
        case 'Y':
            return isSetAnswer;
        case 'n':
            return !isSetAnswer;
        case 'N':
            return !isSetAnswer;
        }
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