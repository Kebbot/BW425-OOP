#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <io.h>
#include <vector>
//#include <fstream>
#include "Student.h"
using namespace std;
#define SQR(X) (X) * (X)
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
    int size;
    int* arr;
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
    static const double Length(const Point& point)
    {
        double sum = SQR(point.x) + SQR(point.y);
        return sqrt(sum);
    }
    void Display() const
    {
        cout << "x = " << x << ' ' << "y = " << y << endl;
    }
    // перегрузка дружественной функцией - Арифметические операторы
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

    //перегрузка операторов сравнения
    friend bool operator==(const Point& point1, const Point& point2)
    {
        return point1.x == point2.x && point1.y == point2.y;
    }
    friend bool operator!=(const Point& point1, const Point& point2)
    {
        return !(point1.x == point2.x && point1.y == point2.y);
    }
    friend bool operator>(const Point& point1, const Point& point2)
    {
        return Length(point1) > Length(point2);
    }
    
    //перегрузка левого побитового сдвига
    friend ostream& operator<<(ostream& output, const Point& point)
    {
        output << "(" << point.x << "," << point.y << ")";
        return output;
    }
    friend istream& operator>>(istream& input, Point& point)
    {
        input >> point.x;
        input.ignore(1);
        input >> point.y;
        return input;
    }
    double operator[](int value)
    {
        if (value == 0)
            return x;
        else if (value == 1)
            return y;
        else
            cout << " i can`t find the index..." << endl;
    }
};

//ДЗ от 18-12
class Name
{
    char* firstName = nullptr;
    char* secondName = nullptr;
    void setCharArray(char*& dest, const char* source, Name name);
    void remove();
public:
    void write();
   
};

class DynArray
{
    int* arr;
    int size;
public:
    explicit DynArray(int sizeP) : arr{ new int[sizeP] {} }, size{ sizeP } 
    {
        cout << "DynArray сконструировал массив на "
            << size << " элементов в объекте " << this << endl;
    }
    DynArray() :DynArray(5){}
    DynArray(const DynArray& object) :
        arr{ new int[object.size] {} }, size{ object.size }
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = object.arr[i];
        }
        cout << "Конструктор копирования с размером "
            << size << " элементов в объекте " << this << endl;
    }
    DynArray(DynArray&& object) : arr{ object.arr},size{ object.size}
    {
        object.arr = nullptr;
        object.size = 0;
        cout << "Конструктор перемещения с размером "
            << size << " элементов в объекте " << this << endl;
    }
    DynArray& operator=(const DynArray& object)
    {
        //Проверка на самоприсваивание
        if (!(this == &object))
        {
            /*проверка на невозможность "Переиспользовать"
            блок памяти, выделенный под имеющийся массив*/
            if (size != object.size)
            {
                delete[] arr;
                arr = new int[object.size];
            }
            size = object.size;

            //указатель на начало массива - назначения
            int* dest{ arr }; 

            //указатель на начало массива - источника
            int* src{ object.arr };

            //константный указатель на следующий 
            // за последним элементом в массиве-назначения
            //"Конец массива источника"
            int* const end{ arr + size };
            while (dest < end)
            {
                *dest++ = *src++;
            }
        }
        cout << "DynArray скопировал данные размером "
            << size << " элементов в объекте " << this << endl;
        return *this;
    }
   
    int getElem(int idx) const { return arr[idx]; }
    void setElem(int idx, int val) { arr[idx] = val; }
    void Print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    void Randomize()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 15;
        }
    }
    ~DynArray()
    {
        cout << "Очистка памяти объекта DynArray в указателе " <<
            arr << endl;
        delete[] arr;
        cout << "Сработал деструктор DynArray с размером "
            << size << " элементов в объекте " << this << endl;
    }
};

DynArray arrayFactory(int arrSize)
{
    DynArray arr{ arrSize };
    arr.Randomize();
    return arr; //можно move(arr) - для вызова конструктора перемещения
}

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

    DynArray ar1{ arrayFactory(10) };
    cout << "ar1 элементы: ";
    ar1.Print();
    DynArray ar2{ arrayFactory(10) };
    cout << "ar2 элементы: ";
    ar2.Print();
    /*DynArray* ar1 = new DynArray[5]
    {
        {arrayFactory(15)},
        {arrayFactory(5)},
        {arrayFactory(7)},
        {arrayFactory(3)},
        {arrayFactory(20)}
    };
    for (int i = 0; i < 5; i++)
    {
        ar1[i].Print();
    }
    ar1[3] = ar1[0];
    for (int i = 0; i < 5; i++)
    {
        ar1[i].Print();
    }
    delete[]ar1;*/
    
}

