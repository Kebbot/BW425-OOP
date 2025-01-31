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


void Start()
{
    bool choice = true;
    do {
        
        try {
            int a, b;
            cout << "Введите число 1: ";
            cin >> a;
            cout << "Введите число 2: ";
            cin >> b;

            if (b == 0)
                throw b;

            cout << "Результат:" << (a / b) << endl;
        }
        catch (...)
        {
            cout << "Какая-то Ошибка" << endl;
        }

        cout << "Начать заново?\n" << "0 - Выход\n" 
            << "Всё остальное продолжает программу" << endl;
        cin >> choice;
        _getch();
    } while (choice);
}

int Modulus(int iN, int iMod) {
    int iQ = (iN / iMod);
    return iN - (iQ * iMod);
}

char GetChar(int iGenerator, char cBase, int iRange) {
    return (cBase + Modulus(iGenerator, iRange));
}

//using namespace abot;
int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));
 
    enum LvlMap
    {
        lvl_1 = 0, lvl_2, lvl_3, lvl_4
    };
    

    
    vector<string> text = { "lvl1.txt","lvl2.txt","lvl3.txt","lvl4.txt" };
    string str;
    
    fstream filePath{ text[lvl_1], ios::in };
    if (!filePath.is_open())
    {
        cout << "Файл не открыт!!" << endl;
    }
    while (getline(filePath, str))
    {
        text.push_back(str);
    }
    filePath.close();
    fstream path{ "lvl2.txt", ios::out };
    for (int i = 0; i < text.size(); i++)
    {
        /*for (int j = 0; j < text[i].size(); j++)
        {
            cout << text[i][j];
            Sleep(0);
        }
        cout << endl;*/
        path << text[i] << endl;
    }


    //Start();
    cout << "Конец программы" << endl;
    
}
//след. тема = работа с потоками в файлах.