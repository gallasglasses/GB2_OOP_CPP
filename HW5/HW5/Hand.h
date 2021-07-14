#pragma once
#include <iostream>
#include <vector>

#include "Card.h"



class Hand
{
public:
	Hand();

	size_t getValue() const;
	void add(Card* card);
	void clear();

	~Hand();

protected:
	std::vector<Card*>& vCardsOnHand;
	const size_t MAX_N_CARD = 9; // 2 * 4, 3 * 4 + 1
};
