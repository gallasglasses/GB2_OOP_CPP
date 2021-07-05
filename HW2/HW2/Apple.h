#pragma once
#include "Fruit.h"

class Apple : public Fruit
{
protected:
	Apple(std::string name, std::string colour)
		: Fruit(name, colour)
	{
	}
public:
	Apple(std::string colour = "yellow");

};

