#include <iostream>
#include <vector>
#include <sstream>
//#include <vld.h>
#include <windows.h>
#include <conio.h>


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
    Console::sizeConsole();
    std::cout << Colours::Code::S_BRICHT_YELLOW << "\n" << field.titleBJ() << Colours::Code::DEFAULT << "\n";
    std::cout << "Press any key to continue...\n";
    system("pause");
    Console::clearConsole();
    field.menuMain();
    while (field.getContinue())
    {
        if (!field.getMenu() && !field.getContinue())
        {
            break;
        }

        Game newGame(field.names);
        newGame.Play();
        std::cout << "\n";
                
        std::cout << "Do you want play again?\nEnter 'Y' - Yes or 'N' - No : \n";
        switch (_getch())
        {
        case 'y':
            Console::clearConsole();
            continue;
        case 'Y':
            Console::clearConsole();
            continue;
        case 'n':
            newGame.~Game();
            field.names.clear();
            Console::clearConsole();
            field.setMenu();
            field.menuMain();
            break;
        case 'N':
            newGame.~Game();
            field.names.clear();
            Console::clearConsole();
            field.setMenu();
            field.menuMain();
            break;
        default:
            continue;
        }
    }
    field.~Field();

    /*_CrtDumpMemoryLeaks();*/

    return 0;
}