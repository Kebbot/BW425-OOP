#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <iterator>
#include <list>
//#include "Student.h"

using namespace std;

//dynamic_cast
class B
{
public:
    //виртуальная функция
    virtual void Test() {
        cout << "Test" << endl;
    }
};
class D : public B
{
public:
    //переопределение виртуальной функции
    void Test()
    {
        cout << "Test D" << endl;
    }
};

//const_cast - Снимает атрибут const (или ставит) (работает с const и volatile)
void test_pow(const int* v)
{
    int* tmp;
    tmp = const_cast<int*>(v);
    *tmp = *v * *v;
}

class FileOpen
{
    FILE* f;
public: 
    FileOpen(const char* fileName, const char* mode)
    {
        if (!(f = fopen(fileName, mode)))
        {
            exit(0);
        }
    }
    ~FileOpen()
    {
        fclose(f);
    }
};

void f() {
    FileOpen myFile("Test.txt", "r+");
}

template <class InIter, class Dist>
void advance(InIter& itr, Dist d);

template <class InIter>
ptrdiff_t distance(InIter& start, InIter end);

//template <class T, class Allocator = Allocator<T> >
//class List;

typedef list<int> ourList;
void ShowList(ourList& l1, ourList& l2)
{
    //создаем итератор
    ourList::iterator iter;
    cout << "List1: ";
    for (iter = l1.begin(); iter != l1.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl << "List2: ";
    for (iter = l2.begin(); iter != l2.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl << endl;
}


int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));


    list<int> list1, list2;
    for (size_t i = 0; i < 6; i++)
    {
        list1.push_back(i);
        list2.push_back(i+i);
    }
    ShowList(list1, list2);

    list2.splice(list2.end(), list2, list2.begin());
    ShowList(list1, list2);

    list1.reverse();
    ShowList(list1, list2);
  
    list1.sort();
    list2.sort();
    ShowList(list1, list2);

    list1.merge(list2);
    ShowList(list1, list2);

    list1.unique();
    ShowList(list1, list2);

    
    //const_cast - Снимает атрибут const (или ставит) (работает с const и volatile)

    //dynamic_cast
    //указатель на класс родитель
    //B* ptr_b, obj_b;
    ////указатель на класс потомок 
    //D* ptr_d, obj_d;
    ////приводим адрес объекта (D*) к указателю типа D*
    //ptr_d = dynamic_cast<D*> (&obj_d);
    ////если всё прошло успешно то вернется !0
 
    //reinterpret_cast
    //int x; //Целое число
    //const char* strT = { "This is string!!!" };
    //char* str = new char[30];
    //strcpy_s(str, 30, strT);
    //cout << str << endl;
    //x = reinterpret_cast<int>(str);
    //cout << x << endl;
    //str = reinterpret_cast<char*>(&x);
    //cout << str << endl;

    //static_cast - аналог (double)num;
    
    
    cout << "Конец программы" << endl;
    
}
//след. тема = работа с потоками в файлах.