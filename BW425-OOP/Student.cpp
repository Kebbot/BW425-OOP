#include "Student.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <io.h>
#include <vector>
#include <fstream>
using namespace std;
double Student::getAver()
{
    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }
    return sum / 5;
}

void Student::setName(string name) { this->name = name; }
string Student::getName() { return name; }
void Student::setAge(int age) { this->age = age; }
int Student::getAge() { return age; }
void Student::setNameGroup(string nameGroup) { this->nameGroup = nameGroup;}
string Student::getNameGroup() { return nameGroup; }
Student::Student(string name, int age, string nameGroup, vector<int> marks)
{
    setName(name);
    setAge(age);
    setNameGroup(nameGroup);
    this->marks = marks;
    mass = new int[5];
    cout << "Сработал конструктор." << &mass << endl;
}
Student::Student(string name, int age, string nameGroup, int* mass)
{
    setName(name);
    setAge(age);
    setNameGroup(nameGroup);
    cout << "Сработал конструктор." << &mass << endl;
}
Student::Student()
{
    
    mass = new int[5];
    cout << "Сработал конструктор." << &mass << endl;
}
Student::~Student()
{
        cout << "Сработал Деструктор." << &mass << endl;
        delete[] mass;
}
