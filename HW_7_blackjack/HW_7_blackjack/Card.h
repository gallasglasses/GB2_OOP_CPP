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

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        const std::string sCardRank[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
        const std::string sCardSuit[] = { "\005", "\004", "\003", "\006" };
        if (card.isCardOpen)
        {
            if (card.cardSuit == DIAMONDS || card.cardSuit == HEARTS)
                out << Colours::Code::S_BRICHT_RED << sCardRank[card.cardFace] << " " << sCardSuit[card.cardSuit] << Colours::Code::DEFAULT;
            else out << Colours::Code::S_BRICHT_BLACK << sCardRank[card.cardFace] << " " << sCardSuit[card.cardSuit] << Colours::Code::DEFAULT;
        }
        else out << " XX X";
        return out;
    }
};