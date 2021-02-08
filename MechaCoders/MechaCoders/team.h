#pragma once
#include <string>
#include "student.h"

struct TEAM {
    std::string teamName;
    std::string description;
    std::string dateOfSteUp;
    STUDENT students[10];
};