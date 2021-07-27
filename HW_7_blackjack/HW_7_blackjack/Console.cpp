#include "Console.h"

namespace Console
{
    void sizeConsole()
    {
        HWND hwnd = GetConsoleWindow();
        if (hwnd != NULL)
        {
            MoveWindow(hwnd, 150, 150, 950, 600, TRUE);
        }
    }

    void clearConsole() 
    {
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
}