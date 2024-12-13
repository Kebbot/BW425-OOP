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
    /*explicit*/ Date(int year) : Date(1, 1, year){}
    Date() : Date(1, 1, 1970) {}
    ~Date()
    {
        cout << "Date деструктор из " << this << endl;
    }


    friend void Print(Date date);
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

void Print(Date date)
{
    cout << date.day << '.' << date.month << '.' << date.year << endl;
}

Date baseDate() { return 2000; }

class Array
{
    int size;
    int* array;
public:
    explicit Array(int size = 10) : size{ size }, array{ new int[size] {} } {}
    ~Array();
    int getSize() const;
    int getValue(int index) const;
    void setValue(int index, int value);
    void Display(int index) const;
};
Array::~Array() {delete[] array;}
int Array::getSize() const {return size;}
int Array::getValue(int index) const { return array[index]; }
void Array::setValue(int index, int value) { array[index] = value; }
void Array::Display(int index) const { cout << array[index] << ' '; }

void Display(const Array& array)
{
    for (int i = 0; i < array.getSize(); i++)
    {
        array.Display(i);
    }
    cout << endl;
}

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

    int size = 4;
    Array array(size);

    for (int i = 0; i < size; i++)
    {
        array.setValue(i, size - i);
    }
    Display(array);
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    Display(Array(3));
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    //Array array10 = 10; // так нельзя - ошибка компиляции 
    Array array10{ 10 };

    /*Print(2024);
    Date date = 2015;
    Print(date);
    Date date2000 = baseDate();
    Print(date2000);*/
 
}

//перегрузка операторов = след. тема