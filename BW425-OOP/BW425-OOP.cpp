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




int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(NULL));

    vector<int> marks;
    for (int j = 0; j < 5; j++)
    {
        int tmp = 1 + rand() % (12 - 1);
        marks.push_back(tmp);
    }
    vector<Student> students{ 
        { "bob", 45, "bwp333", marks },
        {"pop", 35, "wwp357",marks}
    };
}