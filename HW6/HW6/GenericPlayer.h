#pragma once
#include <iostream>
#include <string>

#include "Card.h"
#include "Hand.h"


class GenericPlayer : public Hand
{
protected:
	std::string playerName;

	friend std::ostream& operator<<(std::ostream& out, const GenericPlayer& player)
	{
		out << "Name : " << player.playerName << "\n";
		if (!player.vCardsOnHand.empty())
		{
			out << "Hand : ";
			for (std::vector<Card*>::iterator it = player.vCardsOnHand.begin(); it != player.vCardsOnHand.end(); it++)
			{
				out << *it << "   ";
			}
			out << "\nPoints : " << player.getValue() << "\n";
		}
		else
		{
			out << "No cards on hand.\n";
		}
		return out;
	}

public:
	GenericPlayer(const std::string& name = "");

	virtual bool isHitting();
	bool isBoosted();
	void Bust();

	~GenericPlayer();

};