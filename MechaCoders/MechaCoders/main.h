#pragma once

extern std::fstream schools;
extern std::fstream teachers;
extern std::fstream students;
extern std::fstream teams;

void openAllFiles();
void closeAllFiles();

void closeSchoolFile();
void openSchoolFile();
void closeTeamsFile();
void openTeamsFile();
void closeTeachersFile();
void openTeachersFile();
void closeStudentsFile();
void openStudentsFile();