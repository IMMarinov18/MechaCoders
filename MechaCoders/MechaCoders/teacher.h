#pragma once
#include <vector>
#include <string>
#include "team.h"

struct TEACHER {
    std::string teachersFName;
    std::string teachersLName;
    std::vector<TEAM> teams[10];
    std::string teacherEmail;
    std::string grade;
    char Class;
};

extern void addTeacher(const TEACHER& gt);
extern void showAllTeachers();