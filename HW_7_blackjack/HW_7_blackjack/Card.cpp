#include "Card.h"

Card::Card(CardFace cFace, CardSuit cSuit, bool cOpen)
    : cardFace(cFace),
    cardSuit(cSuit),
    isCardOpen(cOpen)
{

}

int Card::getValue() const
{
    int valueCard = 0;
    if (isCardOpen)
    {
        valueCard = (cardFace > 10) ? 10 : cardFace;
    }
    return valueCard;
}

void Card::FlipCard()
{
    isCardOpen = !(isCardOpen);
}

bool Card::getCardOpen()
{
    return isCardOpen;
}

std::string Card::getCardRank(const Card& card)
{
    const std::string sCardRank[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    return sCardRank[card.cardFace];
}

std::string Card::getCardSuit(const Card& card)
{
    const std::string sCardSuit[] = { "\005", "\004", "\003", "\006" };
    return sCardSuit[card.cardSuit];
}

Card::~Card()
{

}