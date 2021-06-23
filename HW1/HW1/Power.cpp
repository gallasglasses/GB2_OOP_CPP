#include "Power.h"
#include <iostream> 

using namespace EX1;

void Power::setNumbers(int num1, int num2)
{
    x = num1;
    y = num2;
}
void Power::calculate()
{
    std::cout << "The result of raising the first number to the\n"
        "power of the second number: " << pow(x, y) << std::endl;
}
