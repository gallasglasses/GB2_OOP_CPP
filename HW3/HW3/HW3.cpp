// HW3.cpp 
#include <iostream>

//This is 1 exercise
#include "Figure.h"
#include "Circle.h"
#include "Parallelogram.h"
#include "Rectangle.h"
#include "Square.h"
#include "Rhombus.h"

//This is 2 exercise
#include "Car.h"
#include "Bus.h"
#include "PassengerCar.h"
#include "Minivan.h"

#pragma region funEX3
//This is 3 exercise
#include "Fraction.h"
void inputNumber(int& numerator, int& denominator);

Fraction operator+ (const Fraction& f1, const Fraction& f2)
{
    if (f1.m_denominator == f2.m_denominator)
        return Fraction((f1.m_numerator + f2.m_numerator), f1.m_denominator);
    if (f1.m_denominator != f2.m_denominator)
        return Fraction((f1.m_numerator * f2.m_denominator + f2.m_numerator * f1.m_denominator), f1.m_denominator * f2.m_denominator);
}

Fraction operator- (const Fraction& f1, const Fraction& f2)
{
    if (f1.m_denominator == f2.m_denominator)
        return Fraction((f1.m_numerator - f2.m_numerator), f1.m_denominator);
    if (f1.m_denominator != f2.m_denominator)
        return Fraction((f1.m_numerator * f2.m_denominator - f2.m_numerator * f1.m_denominator), f1.m_denominator * f2.m_denominator);
}

Fraction operator* (const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator/ (const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.m_numerator * f2.m_denominator, f1.m_denominator * f2.m_numerator);
}

bool operator== (const Fraction& f1, const Fraction& f2)
{
    return (f1.m_numerator * f2.m_denominator == f2.m_numerator * f1.m_denominator);
}

bool operator!= (const Fraction& f1, const Fraction& f2)
{
    return (f1.m_numerator * f2.m_denominator != f2.m_numerator * f1.m_denominator);
}

bool operator> (const Fraction& f1, const Fraction& f2)
{
    return ((f1.m_numerator * f2.m_denominator) > (f2.m_numerator * f1.m_denominator));
}

bool operator< (const Fraction& f1, const Fraction& f2)
{
    return ((f1.m_numerator * f2.m_denominator) < (f2.m_numerator * f1.m_denominator));
}

bool operator>= (const Fraction& f1, const Fraction& f2)
{
    return !(f1 < f2);
}

bool operator<= (const Fraction& f1, const Fraction& f2)
{
    return !(f1 > f2);
}
#pragma endregion

//This is 4 exercise

int main()
{

#pragma region EX1
    std::cout << "This is 1 exercise\n\n";
    /*
    =======================================================================================================================================

    1.	Создать абстрактный класс Figure (фигура). 
    Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
    Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
    Для всех классов создать конструкторы. 
    Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
    Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

    =======================================================================================================================================
    */

    Figure* figure1 = new Circle();
    figure1->area();
    delete figure1;

    Figure* figure2 = new Parallelogram();
    figure2->area();
    delete figure2;

    Figure* figure3 = new Rectangle();
    figure3->area();
    delete figure3;

    Figure* figure4 = new Square();
    figure4->area();
    delete figure4;

    Figure* figure5 = new Rhombus();
    figure5->area();
    delete figure5;

    std::cout << "__________________________________________________________\n\n";

#pragma endregion

#pragma region EX2
    std::cout << "This is 2 exercise\n\n";
    /*
    =======================================================================================================================================

    2.	Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
    Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
    От этих классов наследует класс Minivan (минивэн). 
    Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
    Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
    Обратить внимание на проблему «алмаз смерти».
    Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.

    =======================================================================================================================================
    */

    Car car("Tesla", "Model X");
    std::cout << "_____\n";
    PassengerCar passengerCar("KIA", "Soul 2014");
    std::cout << "_____\n";
    Bus bus("Mercedes-Benz", "Tourismo Euro V");
    std::cout << "_____\n";
    Minivan minivan("KIA", "Carnival 2021");

    std::cout << "__________________________________________________________\n\n";

#pragma endregion

#pragma region EX3
    std::cout << "This is 3 exercise\n\n";
    /*
    =======================================================================================================================================

    3.	Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
    Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
    ●	математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
    ●	унарный оператор (-)
    ●	логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
    Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
    Продемонстрировать использование перегруженных операторов.

    =======================================================================================================================================
    */

    int numerator,
        denominator;
    inputNumber(numerator, denominator);
    Fraction fraction1(numerator, denominator);
    std::cout << "First fraction : ";
    fraction1.printFraction();
    std::cout << "\n\n";

    inputNumber(numerator, denominator);
    Fraction fraction2(numerator, denominator);
    std::cout << "Second fraction : ";
    fraction2.printFraction();
    std::cout << "\n\n";

    Fraction fractionSum = fraction1 + fraction2;
    std::cout << "Sum of fractions : ";
    fractionSum.printFraction();
    std::cout << "\n";

    Fraction fractionSubtraction = fraction1 - fraction2;
    std::cout << "Subtraction of fractions : ";
    fractionSubtraction.printFraction();
    std::cout << "\n";

    Fraction fractionMultiplication = fraction1 * fraction2;
    std::cout << "Multiplication of fractions : ";
    fractionMultiplication.printFraction();
    std::cout << "\n";

    Fraction fractionDivision = fraction1 / fraction2;
    std::cout << "Division of fractions : ";
    fractionDivision.printFraction();
    std::cout << "\n";

    Fraction fractionNegation = -fraction1;
    std::cout << "Negative fraction : ";
    fractionNegation.printFraction();
    std::cout << "\n";

    if (fraction1 == fraction2)
    {
        fraction1.printFraction();
        std::cout << " is equal to ";
        fraction2.printFraction();
        std::cout << "\n";
    }
    if (fraction1 != fraction2)
    {
        fraction1.printFraction();
        std::cout << " is not equal to ";
        fraction2.printFraction();
        std::cout << "\n";
    }
    if (fraction1 > fraction2)
    {
        fraction1.printFraction();
        std::cout << " is greater than ";
        fraction2.printFraction();
        std::cout << "\n";
    }
    if (fraction1 < fraction2)
    {
        fraction1.printFraction();
        std::cout << " is less than ";
        fraction2.printFraction();
        std::cout << "\n";
    }
    if (fraction1 >= fraction2)
    {
        fraction1.printFraction();
        std::cout << " is greater than or equal to ";
        fraction2.printFraction();
        std::cout << "\n";
    }
    if (fraction1 <= fraction2)
    {
        fraction1.printFraction();
        std::cout << " is less than or equal to ";
        fraction2.printFraction();
        std::cout << "\n";
    }
        

    std::cout << "__________________________________________________________\n\n";

#pragma endregion

#pragma region EX4
    std::cout << "This is 4 exercise\n\n";
    /*
    =======================================================================================================================================

    4.	Создать класс Card, описывающий карту в игре БлэкДжек. 
    У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). 
    Сделать поля масть и значение карты типом перечисления (enum). 
    Положение карты - тип bool. Также в этом классе должно быть два метода:
    ●	метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
    ●	метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

    =======================================================================================================================================
    */

   //watch files Card.h & Card.cpp

    std::cout << "___________watch files Card.h & Card.cpp___________________\n\n";

#pragma endregion
    
    return 0;
}

void inputNumber(int &numerator, int &denominator)
{
    std::cout << "Enter numerator : ";
    std::cin >> numerator;
    do
    {
        std::cout << "Enter denominator : ";
        std::cin >> denominator;
        if (denominator == 0)
            std::cout << "The denominator cannot be zero!" << std::endl;
    } while (denominator == 0);
}