#pragma once
#include <string>

struct SCHOOL {
    std::string schoolName;
    std::string town;
    std::string address;
};


void FindSchoolByName(const std::string& inputName);
void addSchool(const SCHOOL& givenSchool);
void showAllSchools();
void deleteSchoolByLine(int n);
