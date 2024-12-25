#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <io.h>
#include <vector>
#include <fstream>
#include <cassert>
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

    int operator[](int idx)const // 1
    {
        //константная перегрузка, возвращающая эелемент по значению
        assert(idx >= 0 and idx < size and "Index is out of range!");
        return arr[idx];
    }
    int& operator[](int idx) // 2
    {
        // не константная перегрузка, возвращающая элемент по ссылке
        assert(idx >= 0 and idx < size and "Index is out of range!");
        return arr[idx];
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
    return move(arr); //можно move(arr) - для вызова конструктора перемещения
}

class Tochka
{
    double x;
    double y;
  
public:
    Tochka() = default;
    //Tochka(int pX, int pY) = delete; //Запрещаем использовать int в параметрах
    Tochka(double pX, double pY) : x{ pX }, y{ pY } {}
    Tochka& setX(int pX) = delete; /*{ x = pX; return *this; }*/
    Tochka& setY(int pY) = delete; /*{ y = pY; return *this; }*/
    void Pokaz() const
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

int maxX(int a, int b) { return a > b ? a : b; }
template <typename T1, typename T2> 
int maxX(T1 a, T2 b) = delete; // запретили использовать всё кроме int, int

class MedalRow
{
    char country[5];
    int medals[3];
public:
    /* определяем константы для удобного и однозначного
    доступа к элементам массива */
    static const int GOLD{ 0 };
    static const int SILVER{ 1 };
    static const int BRONZE{ 2 };
    MedalRow(const char* countryP, const int* medalsP)
    {
        strcpy_s(country, 5, countryP ? countryP : "NON");
        for (int i{ 0 }; i < 3; ++i)
        {
            medals[i] = medalsP ? medalsP[i] : 0;
        }
    }
    MedalRow() : MedalRow(nullptr, nullptr) {}
    MedalRow& setCountry(const char* countryP)
    {
        if (countryP)
        {
            strcpy_s(country, 5, countryP);
        }
        return *this;
    }
    const char* getCountry()const { return country; }
    int& operator[](int idx)
    {
        assert((idx >= 0 and idx < 3) and "Index out of range!");
        return medals[idx];
    }
    int operator[](int idx)const
    {
        assert((idx >= 0 and idx < 3) and "Index out of range!");
        return medals[idx];
    }
    void print()const
    {
        std::cout << '[' << country << "]-( ";
        for (int i{ 0 }; i < 3; ++i)
        {
            std::cout << medals[i];
            if (i < 2) { std::cout << '\t'; }
        }
        std::cout << " )\n";
    }
};

class MedalTable
{
public:
    static const int maxSize{ 10 };
private:
    MedalRow medalRows[MedalTable::maxSize];
    int size;
    int findCountry(const char* country) const
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(medalRows[i].getCountry(), country) == 0) { return i; }
        }
        return -1;
    }
public:
    MedalTable() : size{0}{}
    MedalRow& operator[](const char* country)
    {
        int idx{ findCountry(country) };
        if (idx == -1)
        {
            assert(size < MedalTable::maxSize and "Table is FULL!");
            idx = size++;
            medalRows[idx].setCountry(country);
        }
        return medalRows[idx];
    }
    const MedalRow& operator[](const char* country) const
    {
        int idx{ findCountry(country) };
        assert(idx != -1 and "Country not found on const table");
        return medalRows[idx];
    }
    void print()const
    {
        for (int i = 0; i < size; i++)
        {
            medalRows[i].print();
        }
    }
};

class Dyn2Array
{
    int sizeY;
    int sizeX;
public:
    int** data;
    Dyn2Array(int sizeYp, int sizeXp) : sizeY{ sizeYp },
        sizeX{ sizeXp }, data{ new int* [sizeYp] }
    {
        //стандартная версия
       /* for (int y = 0; y < sizeY; y++)
        {
            data[y] = new int[sizeX];
        }*/

        int* data_elements{ new int[sizeY * sizeX] };
        for (int y = 0; y < sizeY; y++)
        {
            data[y] = data_elements + y * sizeX;
        }
    }
    void Print()const
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x < sizeX; x++)
            {
                cout << data[y][x] << '\t';
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    
    ~Dyn2Array()
    {
        /* for (int y = 0; y < sizeY; y++)
         {
             delete[] data[y];
         }
         delete[] data;*/

        delete[] data[0];
        delete[] data;
    }
};

class Matrix
{
    int sizeY;
    int sizeX;
    int* data;
    int index2d(int y,int x)
        const { return y * sizeX + x; }

    int index2d(int y, int x, int sizeXp)
        const { return y * sizeXp + x; }
public:
    Matrix(int sizeYp, int sizeXp) :
        sizeY{ sizeYp }, sizeX{ sizeXp },
        data{ new int[sizeYp * sizeXp] {} } {}

    int operator()(int y, int x) const
    { return *(data + index2d(y, x)); }

    int& operator()(int y, int x)
    { return *(data + index2d(y, x));}

    void deleteColumn(int colunPos)
    {
        --sizeX;
        int* newData{ new int[sizeY * sizeX] };
        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x < sizeX; x++)
            {
                *(newData + index2d(y, x)) =
                    *(data + index2d(y, x + (x >= colunPos)));
            }
        }
        delete[] data;
        data = newData;
    }
    void addColumn(int colunPos, int* newCol = nullptr)
    {
        int* newData{ new int[sizeY * (sizeX+1)] };
        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x < sizeX; x++)
            {
                *(newData + index2d(y, x +(x >= colunPos),sizeX +1)) =
                    *(data + index2d(y, x));
            }
            *(newData + index2d(y, colunPos, sizeX + 1))
                = newCol ? *(newCol + y) : 0;
        }
        delete[] data;
        data = newData;
        ++sizeX;
    }

    void deleteRow(int rowPos)
    {
        --sizeY;
        int* newData{ new int[sizeY * sizeX] };
        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x < sizeX; x++)
            {
                *(newData + index2d(y, x)) =
                    *(data + index2d(y+(y>= rowPos), x));
            }
        }
        delete[] data;
        data = newData;
    }
    void addRow(int rowPos, int* newRow = nullptr)
    {
        int* newData{ new int[(sizeY+1) * sizeX] };
        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x < sizeX; x++)
            {
                *(newData + index2d(y + (y >= rowPos), x)) =
                    *(data + index2d(y, x));
            }
        }
        for (int x = 0; x < sizeX; x++)
        {
            *(newData + index2d(rowPos, x))
                = newRow ? *(newRow + x) : 0;
        }
        delete[] data;
        data = newData;
        ++sizeY;
    }

    void print()const
    {
        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x < sizeX; x++)
            {
                cout << (*this)(y, x) << '\t';
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    ~Matrix() { delete[] data; }
};


int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

    /*MedalTable mt1;
    mt1["USSR"][MedalRow::GOLD] = 14;
    mt1["USSR"][MedalRow::SILVER] = 5;
    mt1["USA"][MedalRow::BRONZE] = 4;
    mt1["USA"][MedalRow::SILVER] = 6;
    mt1["CH"][MedalRow::GOLD] = 5;
    mt1["CH"][MedalRow::SILVER] = 2;

    mt1.print();

    const MedalTable mt2{ mt1 };
    mt2.print();*/
//#define USER_INPUT 0;
//
//    int rows{ 3 };
//    int columns{ 3 };
//    int counter{ 1 };
//#if USER_INPUT == 1
//    cout << "Введите кол-во строк матрицы" << endl;
//    cin >> rows;
//    cout << "Введите кол-во столбцов матрицы" << endl;
//    cin >> columns;
//#endif 
//
//    Matrix matrix{ rows, columns };
//    for (int y = 0; y < rows; y++)
//    {
//        for (int x = 0; x < columns; x++)
//        {
//            matrix (y,x) = counter++;
//        }
//    }
//    matrix.print();
//    cout << matrix(1, 1) <<endl;
//    matrix.deleteColumn(2);
//    matrix.print();
//
//    int* newColumns{ new int[columns] {11,22,33} };
//    matrix.addColumn(0, newColumns);
//    matrix.print();
//
//    matrix.deleteRow(2);
//    matrix.print();
//
//    int* newRow{ new int[rows] {111,222,333} };
//    matrix.addRow(2, newRow);
//    matrix.print();
//
//    delete[] newRow;
//    delete[] newColumns;

   
  
}

