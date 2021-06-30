#include "Stack.h"

using namespace EX3;

void Stack::reset()
{
    for (size_t i = 0; i < SIZE; i++)
    {
        array[i] = 0;
    }
    lengthStack = 0;
}

bool Stack::push(int value)
{
    if (lengthStack > 0 || lengthStack < SIZE)
    {
        array[lengthStack] = value;
        lengthStack++;
        return true;
    }
    else return false;
}

int Stack::pop()
{
    if (lengthStack > 0)
    {
        lengthStack--;
        for (size_t i = 0; i < lengthStack; i++)
        {
            return array[i];
        }
    }
    else
    {
        std::cout << "Stack is empty!\n";
        return 0;
    }
}

void Stack::print()
{
    std::cout << "( ";
    for (size_t i = 0; i < lengthStack; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << ")\n";
}