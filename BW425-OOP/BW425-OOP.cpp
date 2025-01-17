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

//Вроженные классы
class A
{
public:
    void print()
    {
        obj->poo(*this);
    }
private:
    int i = 10;
    class B;
    class Ref {
        // pli имеет тип A::B*
        B* pli;
    };
    class B {
    public:
        // pRef имеет тип A::Ref*
        Ref* pRef;
        int value = 5;
        B* next; //указатель на собственный класс

        static int static_mem;

        B(int value = 0) /*: value{ value } {}*/;//Конструктор
        void mf( A&);
        int sum(A& ptr)
        {
            int sum = ptr.i + value + ptr.obj->value;
            return sum;
        }
        void poo(A& ptr)
        {
            cout << ptr.i + value << endl;
            cout << ptr.obj->value << endl;
        }

    };
    B* obj = new B;
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

//Агрегирование
class Point
{
    int X;
    int Y;
public:
    Point() {
        X = Y = 0;
    }
    void setPoint(int iX, int iY) {
        X = iX;
        Y = iY;
    }
    void Show() {
        cout << "------------------------------" << endl << endl;
        cout << X << "\t" << Y << endl << endl;
        cout << "------------------------------" << endl << endl;
    }
};

class Figura {
    //Агрегация точки - 
    // (внутри одного класса (отдельного) находятся объект(ы) другого класса
    Point* obj; 

    int count; 
    int color; 
public:
    Figura() {
        count = color = 0;
        obj = nullptr;
    }
    // Создание фигуры
    void createFigura(int cr, int ct) {
        //если углов меньше 3 - это не фигура
        if (ct < 3) exit(0);
        // инициализация света и кол-ва углов
        count = ct;
        color = cr;
        //выделение памяти под массив точек
        obj = new Point[count];

        if(!obj)exit(0);

        //установка координат точек
        int tempX, tempY;
        for (int i = 0; i < count; i++)
        {
            cout << "Set X\n";
            cin >> tempX;
            cout << "Set Y\n";
            cin >> tempY;
            obj[i].setPoint(tempX, tempY);
        }
    }
    //показ фигуры
    void ShowFigura() {
        cout << "------------------------------" << endl << endl;
        cout <<"Color - " << color << endl << endl;
        cout << "Points - " << count << endl << endl;
        for (int i = 0; i < count; i++)
        {
            obj[i].Show();
        }
        cout << "------------------------------" << endl << endl;
    }

    //Если фигура была, то очистить память
    ~Figura(){
        if (obj != nullptr) delete[] obj;
    }
};

void Start()
{
    bool choice = true;
    do {
        
        Figura f;
        f.createFigura(255, 3);
        f.ShowFigura();

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