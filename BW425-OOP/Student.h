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
    string name; // Имя
    int age; // Возраст
    string nameGroup; //Имя группы
    vector<int> marks;  
    int* mass;
public:
    Student();
    Student(string name, int age, string nameGroup, vector<int> marks);
    Student(string name, int age, string nameGroup, int* mass);
    ~Student();
    double getAver();
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    void setNameGroup(string nameGroup);
    string getNameGroup();

};
