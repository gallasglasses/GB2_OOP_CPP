#pragma once
#include <iostream>
#include <string>

class Fruit
{
private:
	std::string m_name;
	std::string m_colour;
public:
	Fruit(std::string name, std::string colour);

	std::string getName() const;
	std::string getColour() const;
};

