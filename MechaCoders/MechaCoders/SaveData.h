#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream students;
fstream teams;
fstream teachers;
fstream schools;

void openFileStudents()
{
    students.open("students.txt", ios::in | ios::out | ios::app);
}

void openFileTeams()
{
    teams.open("teams.txt", ios::in | ios::out);
}

void openFileTeachers()
{
    teachers.open("teachers.txt", ios::in | ios::out);
}

void openFileSchools()
{
    schools.open("schools.txt", ios::in | ios::out);
}
void openAllFiles()
{
    openFileStudents();
    openFileTeams();
    openFileTeachers();
    openFileSchools();
}

void closeFileStudents()
{
    students.close();
}

void closeFileTeams()
{
    teams.close();
}

void closeFileTeachers()
{
    teachers.close();
}

void closeFileSchools()
{
    schools.close();
}
void closeAllFiles()
{
    closeFileStudents();
    closeFileTeams();
    closeFileTeachers();
    closeFileSchools();
}