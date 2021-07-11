// HW4.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

//This is 1 exercise
class ArrayInt
{
    int m_length;
    int* m_data;

public:
    ArrayInt()
        : m_length(0),
        m_data(nullptr)
    {

    }
    ArrayInt(int length)
        : m_length(length)
    {
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase() // function clear 
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() const
    {
        return m_length;
    }

    int& operator[] (int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength) //increasing the size of the array
    {
        if (m_length == newLength)
            return;
        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];
        if (m_length > 0)
        {
            int elementsToCopy = newLength > m_length ? m_length : newLength;
            for (int i = 0; i < elementsToCopy; i++)
            {
                data[i] = m_data[i];
            }
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);
        int* data = new int[m_length + 1];
        for (int i = 0; i < index; ++i)
        {
            data[i] = m_data[i];
        }
        data[index] = value;
        for (int i = index; i < m_length; ++i)
        {
            data[i + 1] = m_data[i];
        }
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value)
    {
        insertBefore(value, m_length);
    }

    void deleteBefore(int index)
    {
        assert(index >= 0 && index < m_length);
        if (m_length == 1)
        {
            erase();
            return;
        }

        int* data = new int[m_length - 1];
        for (int i = 0; i < index; ++i)
        {
            data[i] = m_data[i];
        }
        
        for (int i = index + 1; i < m_length; ++i)
        {
            data[i - 1] = m_data[i];
        }
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    void pop_back()
    {
        deleteBefore(m_length - 1);
    }

    void pop_front()
    {
        deleteBefore(0);
    }

    void print()
    {
        std::cout << "array : ";
        for (int i = 0; i < m_length; i++)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    void sort()
    {
        for (int j = 0; j < m_length - 1; j++)
        {
            for (int i = 0; i < m_length - 1 - j; i++)
            {
                if (m_data[i] > m_data[i + 1])
                {
                    std::swap(m_data[i], m_data[i + 1]);
                }
            }
        }
    }
};

//This is 2 exercise
void printVector(const std::vector<int>& v);
void set_different_numbers(std::vector<int>& v);

//This is 3 exercise
#include "Card.h"
#include "Hand.h"

int main()
{

#pragma region EX1

    std::cout << "This is 1 exercise\n\n";
    /*
    =======================================================================================================================================
    1.	Добавить в контейнерный класс, который был написан в этом уроке, методы:
    ●	для удаления последнего элемента массива (аналог функции pop_back() в векторах)
    ●	для удаления первого элемента массива (аналог pop_front() в векторах)
    ●	для сортировки массива
    ●	для вывода на экран элементов.

    =======================================================================================================================================
    */
    
    ArrayInt array (8);
    for (int i = 0; i < array.getLength(); i++)
    {
        array[i] = rand() % 100 + 1;
    }
    std::cout << std::endl;
    array.print();

    array.insertBefore(19, 2);
    array.print();
    
    array.deleteBefore(2);
    array.print();
    
    array.pop_back();
    array.print();

    array.pop_front();
    array.print();

    array.sort();
    array.print();

    std::cout << "__________________________________________________________\n\n";

#pragma endregion

#pragma region EX2

    std::cout << "This is 2 exercise\n\n";
    /*
    =======================================================================================================================================
    2.	Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
    =======================================================================================================================================
    */

    std::vector<int> array2{ 2, 19, 32, 3, 10, 19, 10, 2, 1, 9, 2, 2 };
    printVector(array2);
    set_different_numbers(array2);
    std::cout << "__________________________________________________________\n\n";

#pragma endregion

#pragma region EX3

    std::cout << "This is 3 exercise\n\n";
    /*
    =======================================================================================================================================
    3.	Реализовать класс Hand, который представляет собой коллекцию карт. 
    В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив,
    а тип его элементов должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
    ●	метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
    ●	метод Clear, который очищает руку от карт
    ●	метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).

    =======================================================================================================================================
    */

    //watch files Hand.h & Hand.cpp

    std::cout << "___________watch files Hand.h & Hand.cpp___________________\n\n";

#pragma endregion


    return 0;

}

//This is 2 exercise
void printVector(const std::vector<int>& v)
{
    std::cout << "array2 : ";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

/*
void set_different_numbers(const std::vector<int>& v)
{
    std::vector<int>vSort = v;
    std::sort(vSort.begin(), vSort.end());
    printVector(vSort);
    int countDifferentNumber = 1;
    for (int i = 0; i < vSort.size() - 1; i++)
    {
        if (vSort[i] != vSort[i + 1])
            countDifferentNumber++;
    }
    std::cout << "Different numbers : " << countDifferentNumber << "\n";
}
*/

void set_different_numbers(std::vector<int>& v)
{
    std::vector<int>vSort = v;
    std::sort(vSort.begin(), vSort.end());
    auto last = std::unique(vSort.begin(), vSort.end());
    std::cout << "Different numbers : " << std::distance(vSort.begin(), last) << "\n";
}