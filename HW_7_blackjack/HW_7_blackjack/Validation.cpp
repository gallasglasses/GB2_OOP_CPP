#include "Validation.h"

namespace Validation
{
    char getAnswer()
    {
        char ch;
        ch = getchar();
        while (isspace(ch))
        {
            ch = getchar();
            continue;
        }
        while (isdigit(ch))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ch = getchar();
            continue;
        }
        while (ch != 'y' && ch != 'n' && ch != 'Y' && ch != 'N')
        {
            if (ch == '\n')
                ch = getchar();
            std::cout << "Enter 'Y' or 'N' : ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ch = getchar();
            continue;
        }
        while (getchar() != '\n')
            continue;
        return ch;
    }
}