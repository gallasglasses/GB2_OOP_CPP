#pragma once
#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Field.h"

#include <algorithm>
#include <random>

class Deck : public Hand
{
private:
	Field field;
public:
	const int MAX_CARD_DECK = 52;

	Deck();

	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);

	virtual ~Deck();
};