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