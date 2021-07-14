#pragma once
#include <iostream>
#include <string>

#include "Card.h"
#include "Hand.h"


class GenericPlayer : public Hand
{
protected:
	std::string playerName;
public:
	GenericPlayer(const std::string& name = "");

	virtual bool isHitting();
	bool isBoosted();
	void Bust();

	~GenericPlayer();

};