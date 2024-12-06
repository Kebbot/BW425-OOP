#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <io.h>
#include <vector>
#include <fstream>
#include "Student.h"
using namespace std;

class poof
{
    Student students;
    string nameFacultet;
    string number;
public:
    poof() : poof{"Null","Null","Null","Null",0}
    {
        cout << "poof Сработал конструктор по умолчанию" << endl;
    }
    poof(string number, string nameFacultet, string NameGroup,
        string Name, int Age) :
        number{ number }, nameFacultet{ nameFacultet },
        students{ Name,Age, NameGroup }
    {
        cout << "poof Сработал конструктор с параметрами" << endl;
    }

};

class Human
{
    char* name;
public:
    Human(char* name) : name{ name }{}
    void Print()
    {
        cout << name << endl;
    }
};


int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));


    char* p = new char[255];
    cin.getline(p, 255);
    Human num{ p };
    num.Print();

  
    
}