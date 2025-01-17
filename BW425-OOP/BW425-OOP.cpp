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

class Stack
{
    // Нижняя и верхняя границы
    enum { EMPTY =-1, FULL=20};
    
    // Массив для хранения данных
    char st[FULL + 1];

    // Указатель на вершину
    int top;
public:
    //конструктор по умолчанию
    Stack()
    {
        //изначально стек пустой
        top = EMPTY;
    }

    //добавление элемента
    void Push(char c)
    {
        //Если в стеке есть место, то увеличиваем указатель на вершину
        // стека и вставляем новый элемент
        if (!isFull())
            st[++top] = c;
    }
    
    // Извлечение элемента
    char Pop()
    {
        //Если в стеке есть элементы, то возвращаем верхний
        //и уменьшаем указатель на вершину стека
        if (!isEmpty())
            return st[top--];
        else //если нет элементов
            return 0;
    }

    //очистка стека
    void Clear()
    {
        /*Эффективная "очистка" стека
        (данные в массиве все еще есть/существуют, 
        но фунции класса, ориентированные на работу с вершиной стека,
        будут их игнорировать)*/
        top = EMPTY;
    }

    //проверка на наличие элементов
    bool isEmpty()
    {
        //Стек пуст?
        return top == EMPTY;
    }

    //проверка на переполнение стека
    bool isFull()
    {
        //Стек полон?
        return top == FULL;
    }

    //Кол-во элементов в стеке
    int getCount()
    {
        return top;
    }

};

class A
{
public:
    int init(int);
private:
    class B;
    class Ref {
        // pli имеет тип A::B*
        B* pli;
    };
    class B {
    public:
        // pRef имеет тип A::Ref*
        Ref* pRef;
        int value;
        B* next; //указатель на собственный класс
        static int static_mem;

        B(int value = 0) /*: value{ value } {}*/;//Конструктор
        void mf( A&);
       
    };
    B* obj;
};

//class A::B {
//public:
//    int value;
//    B(int value = 0) /*: value{ value } {}*/;//Конструктор
//    B* next; //указатель на собственный класс
//    static int static_mem;
//};
void A::B::mf( A& i1)
{
    int memb = i1.init(5);
}
A::B::B(int value)
{
    
}

int A::B::static_mem = 1024;


class B
{
public:
    class A {};
    A* obj;
};

void Start()
{
    bool choice = true;
    do {
        


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