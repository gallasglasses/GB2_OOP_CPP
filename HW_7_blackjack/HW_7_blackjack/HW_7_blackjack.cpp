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


Field field;

int main()
{
    bool isContinue = true;
    
    field.sizeConsole();
    std::cout << Colours::Code::S_BRICHT_YELLOW << field.titleBJ() << Colours::Code::DEFAULT << "\n";
    std::cout << "Press any key to continue...\n";
    system("pause");
    //std::cout << "\x1B[2J\x1B[H";
    field.clearConsole();
    while (field.getContinue())
    {
        field.menu();

        if (!field.getMenu() && !field.getContinue())
        {
            break;
        }

        Game newGame(field.names);
        newGame.Play();
        std::cout << "\n";
        //std::cout << "\x1B[2J\x1B[H";
                
        std::cout << "Do you want play again?\nEnter 'Y' - Yes or 'N' - No : \n";
        switch (_getch())
        {
        case 'y':
            field.clearConsole();
            continue;
        case 'Y':
            field.clearConsole();
            continue;
        case 'n':
            newGame.~Game();
            field.names.clear();
            field.clearConsole();
            field.setMenu();
            field.menu();
            break;
        case 'N':
            newGame.~Game();
            field.names.clear();
            field.clearConsole();
            field.setMenu();
            field.menu();
            break;
        default:
            continue;
        }
    }
    field.~Field();

    /*_CrtDumpMemoryLeaks();*/

    return 0;
}