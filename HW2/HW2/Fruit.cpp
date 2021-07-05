#include "Fruit.h"

Fruit::Fruit(std::string name, std::string colour)
	: m_name(name), m_colour(colour)
{

}

std::string Fruit::getName() const
{
	return m_name;
}

std::string Fruit::getColour() const
{
	return m_colour;
}