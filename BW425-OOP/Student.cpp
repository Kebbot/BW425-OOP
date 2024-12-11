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
    
    cout << "Сработал конструктор по умолчанию " << this << endl;
}

Student::Student(string name, int age, string nameGroup) : 
    name{ name }, age{ age }, nameGroup{ nameGroup }, 
    mass{ new int[age] {} }
{
    cout << "Сработал конструктор с параметрами " << this << endl;
}

Student::Student(string name, int age) : Student{ name,age,"Null" } {}

Student::Student(string name) : Student{ name,0,"Null" } {}

Student::Student(const Student& object) : 
    name{ object.name }, age{ object.age }, 
    nameGroup{ object.nameGroup }, mass{ new int[object.age] {} } 
{
    cout << "Сработал конструктор копирования " << this << endl;
}

Student::~Student()
{
        cout << "Сработал Деструктор " << this << endl;
        if(mass != nullptr)
            delete[] mass;
}
void Student::Print()
{
    cout <<"Name: " << name << " - " << "age: " << age << endl;
}
