#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <io.h>
#include <conio.h>
#include <vector>
#include <fstream>
#include <cassert>
#include <initializer_list>
#include "Student.h"
using namespace std;

//шалон класса
template <class T>
class Array1
{
    T* array;
    size_t size;
public:
    T getItem(size_t index) const;
    void setItem(size_t index, T value);
};

// Функция принимаюя N количество параметров
int getSum1(int count, int first, ...)
{
    int sum = 0;
    int* p = &first;
    while (count--)
    {
        sum += *p;
        cout << p << endl;
        p++;
        cout << p << endl;
        p++;
        cout << p << endl;
    }
    return sum;
}

//double getSum(double x)
//{
//    return x;
//}
//
//template <class... Args>
//double getSum(double x, Args... args)
//{
//    return x + getSum(args...);
//}

template <class T>
class DynArray
{
private:
    int length;
    T* data;
public:
    DynArray() : length(0), data(nullptr){}
    DynArray(int length) : length{ length }
    {
        data = new T[length];
    }
    DynArray(const initializer_list<T>& list) : DynArray(list.size())
    {
        int i = 0;
        for (auto& element : list )
        {
            data[i] = element;
            i++;
        }
    }
    ~DynArray()
    {
        delete[] data;
    }
    T& operator[](int index)
    {
        return data[index];
    }
    int getLength()const
    {
        return length;
    }
};

struct Point
{
    int x;
    int y;
    friend ostream& operator<<(ostream& output, const Point& p)
    {
        output << "(" << p.x << "," << p.y << ")";
        return output;
    }
};
void Start()
{
    bool choice = true;
    do {

        DynArray<int> array{ 7,8,9,6,5,1,0 };
        for (int i = 0; i < array.getLength(); i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;

        DynArray<Point> pointArray{ Point{1,1},Point{5,5}, Point{9,9} };
        for (int i = 0; i < pointArray.getLength(); i++)
        {
            cout << pointArray[i] << " ";
        }
        cout << endl;



        cout << "Начать заново?\n" << "0 - Выход\n" 
            << "Всё остальное продолжает программу" << endl;
        cin >> choice;
        _getch();
    } while (choice);
}
int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));


    Start();
    cout << "Конец программы" << endl;
}


