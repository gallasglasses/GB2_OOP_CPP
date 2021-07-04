#pragma once
#include <iostream> 

const size_t SIZE = 10;

namespace EX3
{
    class Stack
    {
    private:
        int array[SIZE];
        size_t lengthStack;

    public:
        void reset();

        bool push(int value);

        int pop();

        void print();
    };
}