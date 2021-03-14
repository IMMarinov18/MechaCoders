#pragma once

#include "team.h"

struct STUDENT {
    std::string studentFName;
    std::string studentLName;
    std::string grade;
    char Class = ' ';
    std::string studentEmail;
    TEAM studentsTeam;
};

extern std::string setStringLower(std::string i);
extern void FindStudentsByFName(const std::string& inputName);
extern void addStudent(const STUDENT& givenStudent);
extern void deleteStudentByLine(int n);
extern void showAllStudents();
