// HW7.cpp 

#include <iostream>
#include <memory>
#include <typeinfo>
#include "Date.h"

std::unique_ptr<Date>& BackToTheFuture(std::unique_ptr<Date>& d1, std::unique_ptr<Date>& d2);
void BackToTheFuture2(std::unique_ptr<Date>& d1, std::unique_ptr<Date>& d2);

int main()
{
#pragma region EX1

    std::cout << "This is 1 exercise\n\n";
    /*
    =======================================================================================================================================
    1.  Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. Перегрузите оператор вывода для данного класса. 
    Создайте два "умных" указателя today и date. Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы 
    доступа к полям класса Date, а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. 
    Затем переместите ресурс, которым владеет указатель today в указатель date. Проверьте, являются ли нулевыми указатели today и date
    и выведите соответствующую информацию об этом в консоль.
    =======================================================================================================================================
    */

    std::unique_ptr<Date> today = std::make_unique<Date>(21,07,2021);
    std::cout << "Day : " << today->getDay() << "\n";
    std::cout << "Month : " << today->getMonth() << "\n";
    std::cout << "Year : " << today->getYear() << "\n";
    if (today)
        std::cout << "1.Smart pointer \"today\" : \n" << *today;
    std::unique_ptr<Date> date;
    date = move(today);
    if (today)
        std::cout << "2.Smart pointer \"today\" : \n" << *today;
    else if (date)
        std::cout << "2.Smart pointer \"date\" : \n" << *date;

    std::cout << "__________________________________________________________" << std::endl;

#pragma endregion

#pragma region EX2

    std::cout << "This is 2 exercise\n\n";
    /*
    =======================================================================================================================================
    2. По условию предыдущей задачи создайте два умных указателя date1 и date2. 
        ●	Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой 
            (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
        ●	Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
    Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.

    =======================================================================================================================================
    */

    std::unique_ptr<Date> date1 = std::make_unique<Date>(26, 10, 1985);

    std::unique_ptr<Date> date2 = std::make_unique<Date>(05, 11, 1955);
    std::cout << *BackToTheFuture(date1, date2);
    
    std::cout << "\n";
    //date1.swap(date2);
    BackToTheFuture2(date1, date2);
    std::cout << "date1 is date2 : \n" << *date1;
    std::cout << "date2 is date1 : \n" << *date2;

    std::cout << "__________________________________________________________" << std::endl;

#pragma endregion

    return 0;
}


std::unique_ptr<Date>& BackToTheFuture(std::unique_ptr<Date>& d1, std::unique_ptr<Date>& d2)
{
    if (d1->getYear() > d2->getYear())
    {
        std::cout << "If my calculations are correct, when this baby hits 88 miles per hour you're going to see some serious shit.\n";
        return d1;
    }
    else if (d2->getYear() > d1->getYear())
    {
        std::cout << "My pine! Why you... You space bastard! You killed our pine!\n";
        return d2;
    }
    else if (d1->getMonth() > d2->getMonth())
    {
        return d1;
    }
    else if (d2->getMonth() > d1->getMonth())
    {
        return d2;
    }
    else if (d1->getDay() > d2->getDay())
    {
        return d1;
    }
    else if (d2->getDay() > d1->getDay())
    {
        return d2;
    }
    else std::cout << "Do you know what this means ? It means that this damn thing doesn't work at all!\n";
    return d1;
}


void BackToTheFuture2(std::unique_ptr<Date>& d1, std::unique_ptr<Date>& d2)
{
    std::unique_ptr<Date> swap = move(d1);
    d1 = move(d2);
    d2 = move(swap);
}