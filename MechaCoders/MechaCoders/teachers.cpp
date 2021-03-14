#include <iostream>
#include <fstream>
#include "teacher.h"
#include "main.h"
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
    while (getline(students, text))
    {
        cout << text << endl;
    }
}