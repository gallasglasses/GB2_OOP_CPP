#include <iostream>
#include <vector>
#include <sstream>
//#include <vld.h>
#include <windows.h>
#include <conio.h>

#include "Validation.h"
#include "Colours.h"
#include "Field.h"
#include "Game.h"

//#define CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE, LINE)
//#define new DEBUG_NEW

const int MAX_N_PLAYERS = 6;
Field field;

std::vector<std::string> vGetNamePlayers();
void sizeConsole();


int main()
{
    bool isContinue = true;
    char answer;
    
    sizeConsole();
    std::cout << Colours::Code::S_BRICHT_YELLOW << field.titleBJ() << Colours::Code::DEFAULT << "\n";
    std::cout << "Press any key to continue...\n";
    system("pause");
    //std::cout << "\x1B[2J\x1B[H";
    field.clearConsole();
    std::vector<std::string> vNames = vGetNamePlayers();
    isContinue = true;
    while (isContinue)
    {
        /*std::cout << Colours::Code::S_BRICHT_GREEN << field.titleMenu() << Colours::Code::DEFAULT << "\n";
        answer = Validation::getAnswerMenu();
        switch (answer)
        {
        case 1:
            std::cout << Colours::Code::S_BRICHT_GREEN << field.titlePlayer() << Colours::Code::DEFAULT << "\n";
            break;
        case 2:
            break;
        case 3:
            isContinue = !isContinue;
        }*/

        Game newGame(vNames);
        newGame.Play();
        std::cout << "\n";
        //std::cout << "\x1B[2J\x1B[H";
                
        std::cout << "Do you want play again?\nEnter 'Y' - Yes or 'N' - No : ";
        if ((answer = tolower(Validation::getAnswer())) == 'y')
        {
            if (answer == '\n')
                continue;
            field.clearConsole();
            //std::cout << "\x1B[2J\x1B[H";
        }
        if (answer == 'n')
        {
            std::cout << "New game?\nEnter 'Y' - Yes or 'N' - No : ";
            if ((answer = tolower(Validation::getAnswer())) == 'y')
            {
                field.clearConsole();
                //std::cout << "\x1B[2J\x1B[H";
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

    /*_CrtDumpMemoryLeaks();*/

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
            field.clearConsole();
            //std::cout << "\x1B[2J\x1B[H";
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
                field.clearConsole();
                //std::cout << "\x1B[2J\x1B[H";
                break;
            }
        }
    }
    return names;
}

void sizeConsole()
{
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) 
    { 
        MoveWindow(hwnd, 150, 150, 950, 600, TRUE); 
    }
}

