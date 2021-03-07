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
    cout << numLines;
    cin >> numLines;
    return numLines;
}

std::vector<string> FindStudentsByFName(const std::string& inputName)
{
    vector<string> allFoundNames{NULL};
    if (!students.is_open()) return {};

    for (string line; getline(students, line); ) // Loops threw every line from the txt file
    {
        bool nameFound = false;
        for (int i = 0; nameFound == false and i < line.length(); i++)
        {
            string name = " ";
            char symbol = line.at(i);
            if (symbol) {
                if (symbol == ' ') {
                    for (int j = i - 1; j < line.length(); j++)
                    {
                        if (line[j] != ' ')
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
        string saveLine ="\n" + givenStudent.studentFName + " " + givenStudent.studentLName + " " + givenStudent.grade + " " + givenStudent.Class + " " + givenStudent.studentEmail + " " + givenStudent.studentsTeam.teamName + ";";
        cout << saveLine;
        students << saveLine;
    }
    catch (string val) {
        if (val == "1") {cout << "Couldn't open file.";}
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
    rename("temp.txt","students.txt");

    openFileStudents();
}

void changeStudentByLine() {
    string strReplace = "HELLO";
    string strNew = "GOODBYE";
    ifstream filein("filein.txt"); //File to read from
    ofstream fileout("fileout.txt"); //Temporary file
    if (!filein || !fileout)
    {
        cout << "Error opening files!" << endl;
        return;
    }

    string strTemp;
    //bool found = false;
    while (filein >> strTemp)
    {
        if (strTemp == strReplace) {
            strTemp = strNew;
            //found = true;
        }
        strTemp += "\n";
        fileout << strTemp;
        //if(found) break;
    }
}


void showAllStudents() {
    std::string text;
    while (getline(students, text))
    {
        cout << text << endl;
    }
}