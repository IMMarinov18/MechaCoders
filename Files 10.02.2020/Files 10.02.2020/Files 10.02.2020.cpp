// Files 10.02.2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct STUDENT
{
    string firstName;
    string lastName;
    int age;

    string getFullName()
    {
        return firstName + " " + lastName;
    }
    string toString()
    {
        string result;
        result += firstName;
        result += "," + lastName;
        result += "," + std::to_string(age);
        return result;
    }
};



int main()
{
    STUDENT student1 = { "Vasil", "Stanchev", 16 };
    STUDENT student2 = { "Vasil", "Petrov", 17 };
    cout << student1.getFullName()<<endl;
    cout << student2.getFullName() << endl;
    cout << student1.toString() << endl;
    cout << student2.toString() << endl;

    ofstream studentsFile;
    studentsFile.open("students.txt", ios::out | ios::trunc);
    if (studentsFile.is_open())
    {
        studentsFile << "test" << " " << 56;
        studentsFile.close();
    }
}

