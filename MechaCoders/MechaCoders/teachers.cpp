#include <iostream>
#include <fstream>
#include "teacher.h"
#include "main.h"
#include "student.h"
using namespace std;

void addTeacher(const TEACHER& givenTeacher)
{
    try {
        string saveLine = "\n" + givenTeacher.teachersFName + "," + givenTeacher.teachersLName + "," + givenTeacher.grade + "," + givenTeacher.Class + "," + givenTeacher.teacherEmail +";";
        cout << saveLine;
        teachers << saveLine;
        closeAllFiles();
        openAllFiles();
    }
    catch (string val) {
        if (val == "1") { cout << "Couldn't open file."; }
    }
}

void deleteTeacherByLine(int n)
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

    teachers.close();

    remove("students.txt");
    int _ = rename("temp.txt", "students.txt");

    openAllFiles();
}

void showAllTeachers() {
    std::string text;
    int line = 0;
    while (getline(teachers, text,'\n'))
    {
        if (text.empty())
            continue;
        line++;
        cout << line << ". ";
        string name;
        for (int i = 0; i < text.length(); i++) {
            char symbol = text.at(i);
            if (symbol == ',') {
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

void FindTeacherByFName(const std::string& inputName)
{
    if (!teachers.is_open()) return;
    string line;
    int counter = 0;
    while (getline(teachers, line, '\n')) {
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
        cout << "No teacher name matches found." << endl;
}