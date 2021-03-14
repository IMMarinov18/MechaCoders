#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "main.h"
using namespace std;

string setStringLower(string i);
int getLinesFromFile();
void FindStudentsByFName(const std::string& inputName);
void addStudent(const STUDENT& givenStudent);
void deleteStudentByLine(int n);
void showAllStudents();

string setStringLower(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (!islower(input[i]))
        {
            input[i] = tolower(input[i]);
        }
    }
    return input;
}


int getLinesFromFile()
{
    string text;
    const char newLine = ';';
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

void FindStudentsByFName(const std::string& inputName)
{
    if (!students.is_open()) return;
    string line;
    int counter = 0;
    while (getline(students, line, '\n')) {
        string name = "";
        for (int i = 0; i < line.length(); i++) {
            char symbol = line.at(i);
            if (symbol == ',') {
                break;
            }
            else {
                name = name + symbol;
            }
        }
        if (setStringLower(name) == setStringLower(inputName))
        {
            counter++;
            cout << line << endl;
        }
    }
    if (counter < 1)
        cout << "No student name matches found." << endl;
}
void addStudent(const STUDENT& givenStudent)
{
    try {
        if (!students.is_open()) throw "1";
        string saveLine = "\n" + givenStudent.studentFName + "|" + givenStudent.studentLName + "|" + givenStudent.grade + "|" + givenStudent.Class + "|" + givenStudent.studentEmail + "|" + givenStudent.studentsTeam.teamName + ";";
        cout << saveLine;
        students << saveLine;
        closeStudentsFile();
        openStudentsFile();
    }
    catch (string val) {
        if (val == "1") { cout << "Couldn't open file."; }
    }
}

void deleteStudentByLine(int n)
{
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char c;
    int line_no = 1;
    while (students.get(c))
    {
        if (c == '\n')
            line_no++;

        if (line_no != n)
            ofs << c;
    }

    ofs.close();

    closeStudentsFile();

    remove("students.txt");
    int _ = rename("temp.txt", "students.txt");

    openStudentsFile();
}

void showAllStudents() {
    std::string text;
    int line = 0;
    while (getline(students, text, '\n'))
    {
        if (text.empty())
            continue;
        line++;
        cout << line << ". ";
        string name;
        for (int i = 0; i < text.length(); i++) {
            char symbol = text.at(i);
            if (symbol == '|') {
                cout << name << " ";
                name.clear();
            }
            else {
                name = name + symbol;
            }
        }
        name.clear();
        cout << endl;
    }
}