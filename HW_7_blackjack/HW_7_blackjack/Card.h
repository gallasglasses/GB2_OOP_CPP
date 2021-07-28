#pragma once
#include <iostream>
#include <string>

#include "Colours.h"

class Card
{
public:
    enum CardFace
    {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    };

    enum CardSuit
    {
        CLUBS, DIAMONDS, HEARTS, SPADES
    };

    Card(CardFace cFace = ACE, CardSuit cSuit = CLUBS, bool cOpen = true);

    int getValue() const;
    void FlipCard();
    bool getCardOpen();
    std::string getCardRank(const Card& card);
    std::string getCardSuit(const Card& card);

    ~Card();

private:
    bool isCardOpen;

    CardFace cardFace;
    CardSuit cardSuit;

};