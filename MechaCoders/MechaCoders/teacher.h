#pragma once
#include <vector>
#include <string>
#include "team.h"

struct TEACHER {
    std::string teachersFName;
    std::string teachersLName;
    std::string teacherEmail;
    std::string grade;
    char Class;
};

void addTeacher(const TEACHER& gt);
void deleteTeacherByLine(int n);
void showAllTeachers();
void FindTeacherByFName(const std::string& inputName);