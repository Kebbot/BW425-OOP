#include "Student.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <io.h>
#include <vector>
#include <fstream>
using namespace std;

void Student::setName(string name) { this->name = name; }
string Student::getName() { return name; }
void Student::setAge(int age) { this->age = age; }
int Student::getAge() { return age; }
void Student::setNameGroup(string nameGroup) { this->nameGroup = nameGroup;}
string Student::getNameGroup() { return nameGroup; }

Student::Student() : Student{"Null",0,"Null"}
{
    //mass = new int[5];
    cout << "Сработал конструктор по умолчанию " << &mass << endl;
}

Student::Student(string name, int age, string nameGroup) : 
    name{name}, age{age}, nameGroup{ nameGroup }
{
    cout << "Сработал конструктор с параметрами " << &mass << endl;
}

Student::Student(string name, int age) : Student{ name,age,"Null" } {}

Student::Student(string name) : Student{ name,0,"Null" } {}

Student::~Student()
{
        cout << "Сработал Деструктор " << &mass << endl;
        /*delete[] mass;*/   
}
