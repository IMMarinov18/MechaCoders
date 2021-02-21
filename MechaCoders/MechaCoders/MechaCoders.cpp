#include <iostream>
#include <string>
#include <fstream>
using namespace std;
fstream students;
fstream teams;
fstream teachers;
fstream schools;


void openFileStudents()
{
    students.open("students.txt", ios::in | ios::out | ios::trunc);
}

void openFileTeams()
{
    teams.open("teams.txt", ios::in | ios::out | ios::trunc);
}

void openFileTeachers()
{
    teachers.open("teachers.txt", ios::in | ios::out | ios::trunc);
}

void openFileSchools()
{
    schools.open("schools.txt", ios::in | ios::out | ios::trunc);
}
void openFiles()
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
void closeFiles()
{
    closeFileStudents();
    closeFileTeams();
    closeFileTeachers();
    closeFileSchools();
}

int enterUserInput()
{
    int userInput;
    cin >> userInput;
    return userInput;
}

bool mainMenu()
{
    cout << "|-------------WELCOME-------------|" << endl;
    cout << "1. Add, Edit, Delete and Show Data." << endl;
    cout << "2. Information about our team and project." << endl;
    cout << "3. Exit the project" << endl;

    cout << " Choose an option from the menu by entering a number: ";
    int userInput = enterUserInput();

    switch (userInput)
    {
    case 1:
        // Add, edit, delete and show data
        break;
    case 2: 
        // show information about the project
        break;
    case 3:
        cout << "Thank you for you cooperation!";
        return false;
        break;
    default:
        cout << "\n Enter a valid number! \n";
        break;
    }
    return true;
}

int main()
{
    // show greetings menu

    openFiles();
    while (mainMenu());
    closeFiles();
}