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

//Виртуальный базовый класс
class A
{
public:
    int val;
};

class B : public virtual A { public: }; //виртуализация базового класса
class C : public virtual A {public:}; //виртуализация базового класса

class D : public B, public C
{
public:
    int Get_val() {
        return val; //результат (нет ошибки)
    }
};

// Виртуальный деструктор
class Base
{
private:
    char* str;
    int size;
public:
    Base(const char* Str, int s) {
        size = s;
        str = new char[size];
        strcpy_s(str, size, Str);
    }
    virtual ~Base()
    {
        cout << "Деструктор Base" << endl;
        delete[] str;
    }
};

class Derived : public Base
{
private:
    char* str2;
    int size2;
public:
    Derived(const char* Str1, int s1, const char* Str2, int s2 ) : Base(Str1,s1){
        size2 = s2;
        str2 = new char[size2];
        strcpy_s(str2, size2, Str2);
    }
     ~Derived()
    {
        cout << "Деструктор Derived" << endl;
        delete[] str2;
    }

};

//"Чисто" виртуальный деструктор
class Something
{
public:
    virtual ~Something() = 0; //Объявление
};
Something::~Something() {}; //описание

void Test(int tool)
{
    cout << "Начало" << endl;
    if (tool == 2)
        throw "\nОшибка - tool = 2\n";
    else if(tool == 5)
        throw "\nОшибка - tool = 5\n";
}
void Test2(int tool)
{
    try {
        throw "\nHello\n";
    }
    catch (const char* str)
    {
        cout << "Ошибка в функции!" << endl;
        throw;
    }
}

void Start()
{
    bool choice = true;
    do {
        
        try {
            int a, b;
            cout << "Введите число 1: ";
            cin >> a;
            cout << "Введите число 2: ";
            cin >> b;

            if (b == 0)
                throw b;

            cout << "Результат:" << (a / b) << endl;
        }
        catch (...)
        {
            cout << "Какая-то Ошибка" << endl;
        }

        cout << "Начать заново?\n" << "0 - Выход\n" 
            << "Всё остальное продолжает программу" << endl;
        cin >> choice;
        _getch();
    } while (choice);
}
namespace combat
{
    void fire() {
        cout << "ВЫСТРЕЕЕЛ!";
    }
}
namespace exploration 
{
    void fire() {
        cout << "Зажечь факел";
    }
}
namespace combat
{
    void scope() {
        cout << "ВЫСТРЕЕЕЛ!";
    }
}
//using combat::fire;
namespace //abot
{
    //элементы данной видимости
    int pro;
}
//using namespace abot;
int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));
    /*
    * ostream - использует << для вывода (операция помещения в поток)
    * istream - использует >> для ввода (операция извлечение из потока)
    * cout - объект класса ostream
    * cin - объект класса istream
    * cerr - объект класса ostream (не буфер)
    * clog - объект класса ostream (буфер)
    */
  
    ofstream filePath{ "Test1.", ios::app };
    string text;
    getline(cin, text);

    if (!filePath.is_open())
    {
        cout << "Файл не открыт!!" << endl;
    }
    filePath << text;
    filePath.close();


    //Start();
    cout << "Конец программы" << endl;
    
}
//след. тема = работа с потоками в файлах.