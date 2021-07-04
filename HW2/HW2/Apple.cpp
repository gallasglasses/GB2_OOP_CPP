#include "Apple.h"

Apple::Apple(std::string colour, std::string name)
	: Fruit(name, colour)
{
	
}

Apple::Apple(std::string colour = "yellow")
	: Fruit("apple", colour)
{

}