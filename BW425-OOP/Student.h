#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <io.h>
#include <vector>
#include <fstream>
using namespace std;

class Student 
{
    string name{"unName"}; // Имя
    int age{18}; // Возраст
    string nameGroup{"unnameGroup"}; //Имя группы
    int* mass{nullptr};
public:
    Student();
    Student(string name, int age, string nameGroup);
    Student(string name, int age);
    Student(string name);
    Student(const Student& object);
    ~Student();



    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    void setNameGroup(string nameGroup);
    string getNameGroup();
    void Print();
};
