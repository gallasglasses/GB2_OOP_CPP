﻿// HW8.cpp

#include <iostream>


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
    std::cin >> num1;
    std::cout << "Enter second number : \n";
    std::cin >> num2;
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
    int n;
    Bar bar;
    
    try
    {
        do
        {
            std::cout << "Enter number : ";
            std::cin >> n;
            bar.setBar(static_cast<float>(n));
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