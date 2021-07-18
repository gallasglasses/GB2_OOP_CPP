// HW6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <iomanip>

long numericValidation(void);

std::ostream& endll(std::ostream& stream)
{
    stream.put(stream.widen('\n'));
    stream.put(stream.widen('\n'));
    stream.flush();
    return stream;
}

//bonus

#include "ParsingExchangeRates.h"

int main()
{

#pragma region EX1

    std::cout << "This is 1 exercise\n\n";
    /*
    =======================================================================================================================================
    1.	Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: если пользователь вводит что-то кроме 
    одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз. 
    Пример неправильных введенных строк:

        rbtrb
        nj34njkn
        1n

    =======================================================================================================================================
    */
    
    long yourNumber;
    std::cout << "Enter the integer number ('#' to terminate): ";

    yourNumber = numericValidation();
    while (yourNumber != 0)
    {
        std::cout << "Your number is " << yourNumber << std::endl;
        std::cout << "Enter the next number ('#' to terminate):\n";
        yourNumber = numericValidation();
    }

    std::cout << "\nProgram completed!\n";

    std::cout << "__________________________________________________________" << endll;

#pragma endregion

#pragma region EX2

    std::cout << "This is 2 exercise\n\n";
    /*
    =======================================================================================================================================
    2.	Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.

    =======================================================================================================================================
    */

    std::cout << "Wazzup!" << endll;

    std::cout << "__________________________________________________________" << endll;

#pragma endregion

#pragma region EX3

    std::cout << "This is 3 exercise\n\n";
    /*
    =======================================================================================================================================
    3.	Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
    ●	virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. 
    Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false. 
    ●	void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
    ●	void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
    ●	void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.

    =======================================================================================================================================
    */

    //watch files Player.h & Player.cpp

    std::cout << "___________watch files Player.h & Player.cpp______________" << endll;

#pragma endregion

#pragma region EX4

    std::cout << "This is 4 exercise\n\n";
    /*
    =======================================================================================================================================
    4.	Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
    ●	virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, 
    то он берет еще одну карту.
    ●	void FlipFirstCard() - метод переворачивает первую карту дилера.

    =======================================================================================================================================
    */

    //watch files House.h & House.cpp

    std::cout << "____________watch files House.h & House.cpp_______________" << endll;

#pragma endregion

#pragma region EX5

    std::cout << "This is 5 exercise" << endll;
    /*
    =======================================================================================================================================
    5.	Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим), 
    вывести ХХ, если мы ее видим, вывести масть и номинал карты. Также для класса GenericPlayer написать перегрузку оператора вывода, 
    который должен отображать имя игрока и его карты, а также общую сумму очков его карт.
    =======================================================================================================================================
    */

    //watch files Card.h & GenericPlayer.h

    std::cout << "__________watch files Card.h & GenericPlayer.h____________" << endll;

#pragma endregion

#pragma region BONUS

    //bonus ex: Parsing of Exchange Rates

    parsing();

    // USD 1
    // =
    // RUB 74,07 
    // EUR 1 
    // =
    // RUB 87,49

#pragma endregion
    return 0;
}


long numericValidation(void)
{
    std::string userInput = "";

    int numCount = 0;
    long userConvertedNum;

    bool isIntNumber = false;
    bool isFloatNumber = false;
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
                    isFloatNumber = true;
                    numCount = 0;
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
            }
        }
        if (numCount == userInput.size())
        {
            std::stringstream ssInput(userInput);
            ssInput >> userConvertedNum;
        }
        else
        {
            if (isFloatNumber == true)
                std::cout << "It's float-point number!\nEnter the integer number: ";
            else if (isIntNumber == false && numCount == 0)
                std::cout << "It's not a number!\nEnter the number (only digits without letters, symbols): ";
            else if (isExit == true)
                break;
           
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            numCount = 0;
            isIntNumber = false;
            isFloatNumber = false;
        }

    } while (isIntNumber == false && isExit == false);

    if (isExit == true)
        userConvertedNum = 0;

    return userConvertedNum;

}