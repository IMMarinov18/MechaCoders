#include <iostream>
#include <fstream>
#include "main.h"
using namespace std;

void openAllFiles();
void closeAllFiles();

std::fstream schools;
std::fstream teachers;
std::fstream students;
std::fstream teams;

void closeSchoolFile()
{
    schools.close();
}

void openSchoolFile()
{
    students.open("students.txt", std::ios::in | std::ios::out | std::ios::app);
}

void closeTeamsFile()
{
    teams.close();
}

void openTeamsFile()
{
    teams.open("teams.txt", std::ios::in | std::ios::out | std::ios::app);
}

void closeTeachersFile()
{
    teachers.close();
}

void openTeachersFile()
{
    teachers.open("teachers.txt", std::ios::in | std::ios::out | std::ios::app);
}

void closeStudentsFile()
{
    students.close();
}

void openStudentsFile()
{
    schools.open("schools.txt", std::ios::in | std::ios::out | std::ios::app);
}

void openAllFiles()
{
    openSchoolFile();
    openStudentsFile();
    openTeachersFile();
    openTeamsFile();
}

void closeAllFiles()
{
    closeSchoolFile();
    closeStudentsFile();
    closeTeachersFile();
    closeTeamsFile();
}