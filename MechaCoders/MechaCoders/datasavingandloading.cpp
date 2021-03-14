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

void openAllFiles()
{
    schools.open("schools.txt", std::ios::in | std::ios::out | std::ios::app);
    teachers.open("teachers.txt", std::ios::in | std::ios::out | std::ios::app);
    teams.open("teams.txt", std::ios::in | std::ios::out | std::ios::app);
    students.open("students.txt", std::ios::in | std::ios::out | std::ios::app);
}

void closeAllFiles()
{
    students.close();
    schools.close();
    teachers.close();
    teams.close();
}