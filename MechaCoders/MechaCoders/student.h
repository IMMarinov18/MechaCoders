#pragma once
#include <string>
#include "team.h"
#include "SaveData.h"
#include <fstream>
#include <vector>
using namespace std;

struct STUDENT {
    string studentFName;
    string studentLName;
    string grade;
    char Class;
    string studentEmail;
    TEAM* studentsTeam;
};

std::vector<string> getAllStudentsByName(const std::string& inputName)
{
    vector<string> allFoundNames;
    //userFile.open("students.txt", ios::in | ios::out | ios::trunc);
    cout << students.is_open();
    if (!students.is_open()) return {};

    for (string line; getline(students, line); ) // Loops threw every line form the txt file
    {
        bool nameFound = false;
        for (int i = 0; nameFound == false and i < line.length(); i++)
        {
            string name = "";
            char symbol = line.at(i);
            if (symbol) {
                if (symbol == ';') {
                    for (int j = i + 1; j < line.length(); j++)
                    {
                        if (line[j] != ';')
                        {
                            name += line.at(i);
                        }
                        else
                        {
                            allFoundNames.push_back(name);
                        }

                    }
                }
            }
        }
    }
    return allFoundNames;
}
void AddStudent(const STUDENT& givenStudent)
{
    if (!students.is_open()) return;

    string saveLine = "{;" + givenStudent.studentFName + ";" + givenStudent.studentLName + ";}\n";
    cout << saveLine;
    students << saveLine;
}