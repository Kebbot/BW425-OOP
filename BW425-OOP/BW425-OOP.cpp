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


class Date
{
    int day;
    int month;
    int year;
public:
    Date(int day, int month, int year) :
        day{ day }, month{ month }, year{ year } 
    {cout << "Date конструктор из " << this << endl;}
    Date() : Date(1, 1, 1970) {}
    ~Date()
    {
        cout << "Date деструктор из " << this << endl;
    }

    void Print()
    {
        cout << day << '.' << month << '.' << year << endl;
    }
    void setDay1(int dayP) {day = dayP;}
    void setMonth1(int monthP) { month = monthP; }
    void setYear1(int yearP) { year = yearP; }

    Date& setDay2(int dayP) { day = dayP; return *this; }
    Date& setMonth2(int monthP) { month = monthP; return *this; }
    Date& setYear2(int yearP) { year = yearP; return *this; }
};

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

    Date date1{ 24,8,2024 };
    //date1.setDay2(29).setMonth2(2).setYear2(2024).Print();
    Date date2{ 19,07,2024 };
    date1.Print();
    date2.Print();
    
    

}