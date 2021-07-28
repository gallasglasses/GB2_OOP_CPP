// HW8.cpp

#include <iostream>
#include <sstream>

double numericValidation();

template < typename T >
const double& div(const T& num1,const T& num2)
{
    if (num2 == 0)
        throw "Division by zero!";
    return (num1 / num2);
}

#include "Ex.h"
#include "Bar.h"

#include "Robot.h"

int main()
{
#pragma region EX1

    std::cout << "This is 1 exercise\n\n";
    /*
    =======================================================================================================================================
    1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, 
    если второй параметр равен 0. В функции main выводить результат вызова функции div в консоль, а также ловить исключения. 
    =======================================================================================================================================
    */
    double num1 = 0;
    double num2 = 0;
    double valueDiv = 0;

    std::cout << "Enter first number : \n";
    num1 = numericValidation();
    std::cout << "Enter second number : \n";
    num2 = numericValidation();
    try
    {
        valueDiv = div(num1, num2);
        std::cout << "Division : " << valueDiv << std::endl;
    }
    catch (const char* message)
    {
        std::cout << message << std::endl;
    }

    std::cout << "__________________________________________________________" << std::endl;

#pragma endregion

#pragma region EX2

    std::cout << "This is 2 exercise\n\n";
    /*
    =======================================================================================================================================
    2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра. 
    Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем) и имеющий метод set 
    с единственным вещественным параметром a. Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится 
    значение a. В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n. Использовать его в 
    качестве параметра метода set до тех пор, пока не будет введено 0. В обработчике исключения выводить сообщение об ошибке,
    содержащее данные объекта исключения.
    =======================================================================================================================================
    */
    double n;
    Bar bar;
    
    try
    {
        do
        {
            std::cout << "Enter number : ";
            n = numericValidation();
            bar.setBar(n);
            std::cout << "y = " << bar.getBar() << "\n";
        } 
        while (n != 0);
        
    }
    catch (Ex ex)
    {
        std::cout << "Error!\n";
        std::cout << bar.getBar() << " + " << n << " > 100 , so " << bar.getBar() << " * " << n << " = " << ex.getEx() << "\n";
    }

    std::cout << "__________________________________________________________" << std::endl;

#pragma endregion

#pragma region EX3

    std::cout << "This is 3 exercise\n\n";
    /*
    =======================================================================================================================================
    3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на 
    соседнюю позицию. Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, 
    если подана неверная команда (направление не находится в нужном диапазоне). Объект исключения должен содержать всю необходимую 
    информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения 
    от его методов, а также выводящую подробную информацию о всех возникающих ошибках.
    =======================================================================================================================================
    */

    Robot robot;
    robot.robotMovement();

    std::cout << "__________________________________________________________" << std::endl;

#pragma endregion

    return 0;
}

double numericValidation()
{
    std::string userInput = "";

    int numCount = 0,
        floatCount = 0;
    double userConvertedNum;

    bool isIntNumber = false;
    bool isExit = false;

    do
    {
        std::cin >> userInput;
        if (userInput[0] == '#')
        {
            isExit = true;
            numCount = 0;
            break;
        }
        else
        {
            for (size_t i = 0; i < userInput.size(); i++)
            {
                if (isdigit(userInput[i]))
                {
                    numCount++;
                    isIntNumber = true;
                }
                else if (isalnum(userInput[i]))
                {
                    isIntNumber = false;
                    numCount = 0;
                    break;
                }
                if (userInput[i] == '.')
                {
                    numCount++;
                    floatCount++;
                    isIntNumber = true;
                }
            }
        }
        if (userInput[0] == '-')
        {
            numCount++;
            for (size_t i = numCount; i < userInput.size(); i++)
            {
                if (isdigit(userInput[i]))
                {
                    numCount++;
                    isIntNumber = true;
                }
                else if (isalnum(userInput[i]))
                {
                    isIntNumber = false;
                    numCount = 0;
                    break;
                }
                if (userInput[i] == '.')
                {
                    numCount++;
                    floatCount++;
                    isIntNumber = true;
                }
            }
        }
        if (floatCount > 1)
        {
            isIntNumber = false;
            numCount = 0;
            break;
        }
        if (numCount == userInput.size())
        {
            std::stringstream ssInput(userInput);
            ssInput >> userConvertedNum;
        }
        else
        {
            if (isIntNumber == false && numCount == 0)
                std::cout << "It's not a number!\nEnter the number (only digits without letters, symbols): ";
            else if (isExit == true)
                break;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            numCount = 0;
            isIntNumber = false;
        }

    } while (isIntNumber == false && isExit == false);

    if (isExit == true)
        userConvertedNum = 0;

    return static_cast<double>(userConvertedNum);
}