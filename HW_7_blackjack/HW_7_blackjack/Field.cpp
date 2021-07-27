#include "Field.h"

Field::Field()
{

}

std::string Field::titleBJ()
{
    std::ostringstream titleReturn;
    titleReturn << tBJ;
    return titleReturn.str();
}

std::string Field::titleMenu()
{
    std::ostringstream titleReturn;
    titleReturn << tMenu;
    return titleReturn.str();
}

std::string Field::titlePlayer()
{
    std::ostringstream titleReturn;
    titleReturn << tPlayer;
    return titleReturn.str();
}

void Field::setContinue()
{
    isContinue = !isContinue;
}

void Field::setSingle()
{
    isSinglePlayer = !isSinglePlayer;
}

void Field::setMulti()
{
    isMultiPlayer = !isMultiPlayer;
}

void Field::setMenu()
{
    isMenu = !isMenu;
}

bool Field::getContinue() const
{
    return isContinue;
}

bool Field::getSingle() const
{
    return isSinglePlayer;
}

bool Field::getMulti() const
{
    return isMultiPlayer;
}

bool Field::getMenu() const
{
    return isMenu;
}


int Field::getMaxSPlayers() const
{
    return MAX_N_SPLAYERS;
}

int Field::getMaxMPlayers() const
{
    return MAX_N_MPLAYERS;
}

void Field::menuMain()
{
    do
    {
        clearConsole();
        std::cout << Colours::Code::S_BRICHT_GREEN << titleMenu() << Colours::Code::DEFAULT << "\n";
        switch (_getch())
        {
        case '1':
            menuPlayer();
            break;
        case '2':
            break;
        case '3':
            //clearConsole();
            setMenu();
            setContinue();
            break;
        default:
            break;
        }
        if (!getMenu())
            break;
    } while (isMenu);
}

void Field::menuPlayer()
{
    do
    {
        clearConsole();
        std::cout << Colours::Code::S_BRICHT_GREEN << titlePlayer() << Colours::Code::DEFAULT << "\n";

        switch (_getch())
        {
        case '1':
            setSingle();
            maxPlayers = getMaxSPlayers();
            names = vGetNamePlayers();
            clearConsole();
            setMenu();
            break;
        case '2':
            setMulti();
            maxPlayers = getMaxMPlayers();
            names = vGetNamePlayers();
            clearConsole();
            setMenu();
            break;
        case '3':
            clearConsole();
            menuMain();
            break;
        default:
            break;
        }
    } while (isMenu);
}

std::vector<std::string> Field::vGetNamePlayers()
{
    std::vector<std::string> names;
    int countPlayers = 0;
    bool isSetNames = true;
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

        if (countPlayers == maxPlayers)
        {
            clearConsole();
            //std::cout << "\x1B[2J\x1B[H";
            isSetNames = false;
        }
        else if (countPlayers < maxPlayers)
        {
            std::cout << "Do you need another player?\nEnter 'Y' - Yes or 'N' - No : \n";
            switch (_getch())
            {
            case 'y':
                isSetNames = true;
                continue;
            case 'Y':
                isSetNames = true;
                continue;
            case 'n':
                isSetNames = false;
                break;
            case 'N':
                isSetNames = false;
                break;
            default:
                continue;
            }
            if (countPlayers < maxPlayers && !isSetNames)
            {
                clearConsole();
                //std::cout << "\x1B[2J\x1B[H";
                break;
            }
        }
    }
    return names;
}

void Field::sizeConsole()
{
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL)
    {
        MoveWindow(hwnd, 150, 150, 950, 600, TRUE);
    }
}

void Field::clearConsole() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

Field::~Field()
{

}