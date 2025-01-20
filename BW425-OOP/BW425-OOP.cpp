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

void Start()
{
    bool choice = true;
    do {
        
        MyWindow A(10, 10);
        A.Show();

        A.getX() = 5;
        A.getY() = 3;
        A.getWidth() = 40;
        A.getHeight() = 50;
        A.Show();

        A.moveX(2);
        A.moveY(7);
        A.Show();

        

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