#include <iostream>
#include <string>
#include "student.h"
#include "SaveData.h"
#include "datasavingandloading.cpp"
using namespace std;


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
            if (symbol == ' ') {
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
        string saveLine = "\n" + givenStudent.studentFName + " " + givenStudent.studentLName + " " + givenStudent.grade + " " + givenStudent.Class + " " + givenStudent.studentEmail + " " + givenStudent.studentsTeam.teamName + ";";
        cout << saveLine;
        students << saveLine;
        closeAllFiles();
        openAllFiles();
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

    students.close();

    remove("students.txt");
    int _ = rename("temp.txt", "students.txt");

    openAllFiles();
}

void showAllStudents() {
    std::string text;
    while (getline(students, text))
    {
        cout << text << endl;
    }
}