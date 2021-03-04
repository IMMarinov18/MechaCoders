#pragma once
#include <string>
#include "team.h"
#include "SaveData.h"
#include <fstream>
#include <vector>
using namespace std;

struct STUDENT {
    int id;
    string studentFName;
    string studentLName;
    string grade;
    char Class;
    string studentEmail;
    TEAM studentsTeam;
};

int getLinesFromFile()
{
    string text;
    const char newLine = '.';
    int numLines = 0;
    while (getline(students, text, '\n'))
    {
        for (size_t i = 0; i < text.length(); i++)
        {
            if (text.at(i) == newLine)
            {
                numLines++;
            }
        }
    }
    return numLines;
}

std::vector<string> getAllStudentsByFName(const std::string& inputName)
{
    vector<string> allFoundNames;
    if (!students.is_open()) return {};

    for (string line; getline(students, line); ) // Loops threw every line from the txt file
    {
        bool nameFound = false;
        for (int i = 0; nameFound == false and i < line.length(); i++)
        {
            string name = "";
            char symbol = line.at(i);
            if (symbol) {
                if (symbol == ' ') {
                    for (int j = i - 1; j < line.length(); j++)
                    {
                        if (line[j] != ';')
                        {
                            name += line.at(i);
                        } else {
                            allFoundNames.push_back(name);
                        }
                    }
                }
            }
        }
    }
    return allFoundNames;
}
void addStudent(const STUDENT& givenStudent)
{
    try {
        if (!students.is_open()) throw "1";
        string saveLine = givenStudent.studentFName + " " + givenStudent.studentLName + " " + givenStudent.grade + " " + givenStudent.Class + " " + givenStudent.studentEmail + " " + givenStudent.studentsTeam.teamName + ";";
        cout << saveLine;
        students << saveLine;
    }
    catch (string val) {
        if (val == "1") {cout << "Couldn't open file.";}
    }
}

void deleteStudent()
{

}