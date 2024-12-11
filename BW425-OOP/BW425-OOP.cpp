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
public:
    int day;
    int month;
    int year;
    const int baseYear;
//public:
    Date(int day, int month, int year) :
        day{ day }, month{ month }, year{ year }, baseYear{2000}
    {cout << "Date конструктор из " << this << endl;}
    Date() : Date(1, 1, 1970) {}
    ~Date()
    {
        cout << "Date деструктор из " << this << endl;
    }

    void Print() const
    {
        cout << day << '.' << month << '.' << year << endl;
    }
    void setDay1(int dayP) {day = dayP;}
    void setMonth1(int monthP) { month = monthP; }
    void setYear1(int yearP) { year = yearP; }
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }

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

    Date dayP{ 11,03,2024 };
    int yearP = dayP.getYear();
    dayP.setYear1(10);
    cout << dayP.getYear() << endl;
 
}