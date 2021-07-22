#include <iostream>
#include <vector>

#include "Validation.h"
#include "Game.h"

const int MAX_N_PLAYERS = 6;

std::vector<std::string> vGetNamePlayers();

int main()
{
    bool isContinue = true;
    char answer;
    std::vector<std::string> vNames = vGetNamePlayers();
    isContinue = true;
    while (isContinue)
    {
        Game newGame(vNames);
        newGame.Play();
        std::cout << "Do wou want play again?\nEnter 'Y' - Yes or 'N' - No : ";
        if ((answer = tolower(Validation::getAnswer())) == 'y')
        {
            if (answer == '\n')
                continue;
            std::cout << "\x1B[2J\x1B[H";
        }
        if (answer == 'n')
        {
            std::cout << "New game?\nEnter 'Y' - Yes or 'N' - No : ";
            if ((answer = tolower(Validation::getAnswer())) == 'y')
            {
                std::cout << "\x1B[2J\x1B[H";
                newGame.~Game();
                vNames.clear();
                vNames = vGetNamePlayers();
            }
            if (answer == 'n')
            {
                if (answer == '\n')
                    continue;
            }
        }
        isContinue = (answer == 'y') ? true : false;
    }
    return 0;
}


std::vector<std::string> vGetNamePlayers()
{
    std::vector<std::string> names;
    int countPlayers = 0;
    bool isSetNames = true;
    char answer;
    while (isSetNames)
    {
        std::string name;
        std::cout << "Enter name for " << ++countPlayers << " player : ";
        std::cin >> name;
        if (names.size() == 0)
        {
            names.push_back(name);
        }
        else
        {
            auto it = std::find(names.begin(), names.end(), name);
            while (it != names.end())
            {
                std::cout << "Enter another name for " << countPlayers << " player : ";
                std::cin >> name;
                it = std::find(names.begin(), names.end(), name);
            }
                names.push_back(name);
        }

        if (countPlayers == MAX_N_PLAYERS)
        {
            std::cout << "\x1B[2J\x1B[H";
            isSetNames = false;
        }
        else if (countPlayers < MAX_N_PLAYERS)
        {
            std::cout << "Do you need another player?\nEnter 'Y' - Yes or 'N' - No : ";
            if ((answer = tolower(Validation::getAnswer())) != 'n')
            {
                if (answer == '\n')
                    continue;
            }
            isSetNames = (answer == 'y') ? true : false;
            if (countPlayers < MAX_N_PLAYERS && !isSetNames)
            {
                std::cout << "\x1B[2J\x1B[H";
                break;
            }
        }
    }
    return names;
}
