#pragma once
#include <string>
#include "student.h"
#include "team.h"
#include "teacher.h"

struct SCHOOL {
    std::string schoolName;
    std::string town;
    std::string address;
    STUDENT sStudents[10];
    TEAM sTeams[10];
    TEACHER sTeachers[10];
};