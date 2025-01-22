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

// Описание наследования
/*
class имя_класса : спецификатор_доступа имя_родительского_класса
{ описание_класса; };

*/

class Point
{
protected:
    int x;
    int y;
public:
    Point() { x = 0; y = 0; }

    int& getX() {
        return x;
    }
    int& getY() {
        return y;
    }
};

class Figura
{
protected:
    int Fx;
    int Fy;
public:
    Figura() { Fx = 0; Fy = 0; }

    int& FgetX() {
        return Fx;
    }
    int& FgetY() {
        return Fy;
    }
};

class MyWindow : public Point, public Figura
{
    int width;
    int height;
public:
    MyWindow() { width = 0; height = 0; }
    MyWindow(int W, int H) : width{ W }, height{ H } {}
    int& getWidth() {
        return width;
    }
    int& getHeight() {
        return height;
    }
    void moveX(int DX) { x = DX;}
    void moveY(int DY) { y = DY; }
    void Show() const {
        cout << "----------------------------" << endl;
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
        cout << "W = " << width << endl;
        cout << "H = " << height << endl << endl;
    }
};

//Наследование шаблона класса
template <class T>
class Pair
{
    T a;
    T b;
public:
    Pair(T t1, T t2) : a{ t1 }, b{ t2 } {}
};
template <class T>
class Trio : public Pair<T>
{
    T c;
public:
    Trio(T t1, T t2, T t3) : Pair<T>(t1, t2), c{ t3 } {}
};

class A {
public: 
    virtual void v_function() = 0; //"Чисто" виртуальная функция
};
class B : public A
{
    virtual void v_function() { cout << "ПлюхПаф" << endl; }
};
class C : public B
{
    virtual void v_function() { cout << "ПлюхПафБац" << endl; }
};

// Абстрактный базовай класс
class Animal
{
public:
    string Title;
    Animal(string Title) : Title{Title }{}
    virtual void speak() = 0;
};

class Frog : public Animal
{
public:
    Frog(string Title) : Animal(Title){}
    virtual void speak() { cout << Title << " Говорит " << "Ква-Ква" << endl; }
};
class Dog : public Animal
{
public:
    Dog(string Title) : Animal(Title) {}
    virtual void speak() { cout << Title << " Говорит " << "Гав-Гав" << endl; }
};
class Cat : public Animal
{
public:
    Cat(string Title) : Animal(Title) {}
    virtual void speak() { cout << Title << " Говорит " << "Мур-Мур" << endl; }
};

class Lion : public Cat
{
public:
    Lion(string Title) : Cat(Title) {}
    virtual void speak() { cout << Title << " Говорит " << "RRRRRRR" << endl; }
    virtual void speak(int when) { cout << Title << " Говорит " << "RRRRRRR" << endl; }
};

void Start()
{
    bool choice = true;
    do {
        
       //след тема = Виртуальный базовый класс
        Animal* animals[4] = {
            new Dog("Чаппи"),
            new Cat("Мурка"),
            new Frog("Юлий"),
            new Lion("Санек")
        };
        for (int i = 0; i < 4; i++)
        {
            animals[i]->speak();
        }
       /* Lion f{ "Санек" };
        f.speak();
        f.speak(4);*/
       /* B* point_to_obj_B;
        point_to_obj_B = &object_A;

        A* point = new C;*/

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