#pragma once
#ifndef FILE.H
#define FILE.H

#include <string>
#include "team.h"

struct TEACHER {
    std::string teachersFName;
    std::string teachersLName;
    TEAM teams[10];
    std::string teacherEmail;
};



#endif