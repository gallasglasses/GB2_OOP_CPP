#include "Hand.h"

Hand::Hand()
{
	vCardsOnHand.reserve(MAX_N_CARD);
}

size_t Hand::getValue() const
{
	if (vCardsOnHand.empty())
		return 0;
	size_t value = 0;
	std::vector<Card*>::iterator it;
	for (vCardsOnHand.begin(); it != vCardsOnHand.end(); it++)
	{
		value += (*it)->getValue();
		if ((*it)->getValue() == Card::Ace)
		{
			value += (value <= 11) ? 10 : 0;
		}
	}

	return value;
}

void Hand::add(Card* card)
{
	vCardsOnHand.push_back(card);
}

void Hand::clear()
{
	std::vector<Card*>::iterator it = vCardsOnHand.begin();
	for (; it != vCardsOnHand.end(); it++)
	{
		delete* it;
		*it = nullptr;
	}
	vCardsOnHand.clear();
}

Hand::~Hand()
{
	clear();
}