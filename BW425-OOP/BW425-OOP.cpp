#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <iterator>
#include <list>
#include <map>
//#include "Student.h
using namespace std;

class Other
{
public:
    int num;
    string name;
    void print();
};

int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

    map<string, string> our_map;
    vector<int> our_vector;
    cout << "Max size vector: " << our_vector.max_size() / sizeof(int) << endl;
    cout << "Max size map: \t" << our_map.max_size() / sizeof(int) << endl;
    
    string val;
    string key;

    cout << "Введи значение: ";
    cin >> val;
    cout << "Введи ключ: ";
    cin >> key;

    // создаем "Пару" на основании двух значений
    pair<string, string> element(key, val);

    our_map.insert(element); //втсавляем пару в отображение
    cout << "Size map: \t" << our_map.size() << endl;

    cout << "Введи значение: ";
    cin >> val;
    cout << "Введи ключ: ";
    cin >> key;

    pair<map<string, string>::iterator, bool>
        err = our_map.insert(make_pair(key, val));

    if (err.second == false)
    {
        cout << "Errore" << endl;
    }
    cout << "Current element: \t" << our_map.size() << endl;

    map<string, string>:: iterator iter = our_map.begin();
    for (; iter != our_map.end();iter++)
    {
        cout << "Key: " << iter->first << "\t Value: " << iter->second <<endl;
    }
    
    cout << "Конец программы" << endl;
    
}
//след. тема = работа с потоками в файлах.