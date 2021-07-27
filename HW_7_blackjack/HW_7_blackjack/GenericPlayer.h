#pragma once
#include <iostream>
#include <string>
#include <iomanip>

#include "Colours.h"
#include "Card.h"
#include "Hand.h"

class GenericPlayer : public Hand
{
protected:
	std::string playerName;

	friend std::ostream& operator<<(std::ostream& out, const GenericPlayer& player)
	{
		out << "     " << Colours::Code::S_BRICHT_GREEN << player.playerName << "     " << Colours::Code::S_BRICHT_YELLOW << "     " << player.getTotal() << Colours::Code::DEFAULT << "\n";
		if (!player.vCardsOnHand.empty())
		{
            for (size_t i = 0; i < 6; i++)
            {
                for (std::vector<Card*>::const_iterator it = player.vCardsOnHand.begin(); it != player.vCardsOnHand.end(); ++it)
                {
                    if ((*it)->getCardOpen())
                    {
                        switch (i)
                        {
                        case 0:
                            out << "  " << "         " << "  ";
                            break;
                        case 1:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK <<"         " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 2:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << " ";
                            if ((*it)->getCardSuit(*(*it)) == "\004" || (*it)->getCardSuit(*(*it)) == "\003")
                                out << Colours::Code::S_RED << std::setw(4) << std::setfill(' ') << (*it)->getCardSuit(*(*it));
                            else out << Colours::Code::S_BLACK << std::setw(4) << std::setfill(' ') << (*it)->getCardSuit(*(*it));
                            out << "    " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 3:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << " ";
                            if ((*it)->getCardSuit(*(*it)) == "\004" || (*it)->getCardSuit(*(*it)) == "\003")
                                out << Colours::Code::S_RED << std::setw(4) << std::setfill(' ') << (*it)->getCardRank(*(*it));
                            else out << Colours::Code::S_BLACK << std::setw(4) << std::setfill(' ') << (*it)->getCardRank(*(*it));
                            out << "    " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 4:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << " ";
                            if ((*it)->getCardSuit(*(*it)) == "\004" || (*it)->getCardSuit(*(*it)) == "\003")
                                out << Colours::Code::S_RED << std::setw(4) << std::setfill(' ') << (*it)->getCardSuit(*(*it));
                            else out << Colours::Code::S_BLACK << std::setw(4) << std::setfill(' ') << (*it)->getCardSuit(*(*it));
                            out << "    " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 5:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << "         " << Colours::Code::DEFAULT << "  ";
                            break;
                        }
                    }
                    else
                    {
                        switch (i)
                        {
                        case 0:
                            out << "  " << "         " << "  ";
                            break;
                        case 1:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << "         " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 2:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << Colours::Code::S_BRICHT_BLUE << " XXXXXXX " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 3:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << Colours::Code::S_BRICHT_BLUE << " X<<+>>X " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 4:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << Colours::Code::S_BRICHT_BLUE << " XXXXXXX " << Colours::Code::DEFAULT << "  ";
                            break;
                        case 5:
                            out << "  " << Colours::Code::BG_BRICHT_BLACK << "         " << Colours::Code::DEFAULT << "  ";
                            break;
                        }

                    }
                }
                out << std::endl;
                
            }

			if (player.isBoosted())
				std::cout << "\n" << player.playerName << " busts with " << player.getTotal() << " points!\n";
		}
		else
		{
			out << "No cards on hand.\n\n\n\n\n\n";
		}
		return out;
	}

public:
	GenericPlayer(const std::string& name = "");

	virtual bool isHitting() const = 0;
	bool isBoosted() const;

	virtual ~GenericPlayer();

};