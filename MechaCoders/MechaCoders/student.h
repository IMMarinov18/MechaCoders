#pragma once
#include "team.h"

struct STUDENT {
    string studentFName;
    string studentLName;
    string grade;
    char Class = ' ';
    string studentEmail;
    TEAM studentsTeam;
};

string setStringLower(string input);
void FindStudentsByFName(const std::string& inputName);
void addStudent(const STUDENT& givenStudent);
void deleteStudentByLine(int n);
void showAllStudents();