// HW1.cpp 
#include <iostream>
#include <cmath>
#include <cstdint>

//This is 1 exercise
#include "Power.h"

//This is 2 exercise
#include "RGBA.h"

//This is 2 exercise
#include "Stack.h"

int main()
{
    std::cout << "This is 1 exercise\n\n";
    {
        EX1::Power value;
        value.setNumbers(2, 10);
        value.calculate();
    }
    std::cout << "__________________________________________________________\n\n";


    std::cout << "This is 2 exercise\n\n";
    {
        EX2::RGBA colour(153, 102, 204, 125);
        colour.printRGBA();
    }
    std::cout << "__________________________________________________________\n\n";
    
    std::cout << "This is 3 exercise\n\n";
    {
        EX3::Stack stack;
        stack.reset();
        stack.print();

        stack.push(3);
        stack.push(7);
        stack.push(5);
        stack.print();

        stack.pop();
        stack.print();

        stack.pop();
        stack.pop();
        stack.print();

        return 0;
    }
    std::cout << "__________________________________________________________\n\n";
    
    return 0;
}