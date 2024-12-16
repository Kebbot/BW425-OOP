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

class Point
{
    double x;
    double y;
public:
    
    Point(double x, double y) : x{x},y{y} {}
    static const Point Sum(const Point& point1, const Point& point2)
    {
        return Point(point1.x + point2.x, point1.y + point2.y);
    }
    static const Point Subtract(const Point& point1, const Point& point2)
    {
        return Point(point1.x - point2.x, point1.y - point2.y);
    }
    static const Point Mult(const Point& point1, double value)
    {
        return Point(point1.x * value, point1.y * value);
    }
    static const Point Divide(const Point& point1, double value)
    {
        return Point(point1.x /  value, point1.y / value);
    }
    void Display() const
    {
        cout << "x = " << x << ' ' << "y = " << y << endl;
    }
    // перегрузка дружественной функцией
    friend Point operator+(const Point& point1, const Point& point2)
    {
        return Sum(point1, point2);
    }
    friend Point operator-(const Point& point1, const Point& point2)
    {
        return Subtract(point1, point2);
    }
    friend Point operator*(const Point& point1, double value)
    {
        return Mult(point1, value);
    }
    friend Point operator/(const Point& point1, double value)
    {
        return Divide(point1, value);
    }
    friend Point operator*(double value, const Point& point1)
    {
        return Mult(point1, value);
    }
    friend Point operator/(double value, const Point& point1)
    {
        return Divide(point1, value);
    }
    const Point operator-()
    {
        return Point(-x, -y);
    }
    Point& operator++()
    {
        ++x; ++y; return *this;
    }
    Point& operator--()
    {
        --x; --y; return *this;
    }
    const Point operator++(int)
    {
        Point point{ x,y };
        ++(*this);
        return point;
    }
    const Point operator--(int)
    {
        Point point{ x,y };
        --(*this);
        return point;
    }
};

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

    Point p1{ 1.1,1.5 };
    Point p2{ 2,2 };
    (p1++).Display();
    p1.Display();

}

//перегрузка операторов сравнения = след. тема