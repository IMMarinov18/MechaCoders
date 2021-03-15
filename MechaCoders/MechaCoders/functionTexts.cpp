#include <iostream>
#include <string>
#include "student.h"
#include "teacher.h"
#include "textMenus.h"
#include "functions.h"
#include <ctime>
#include "school.h"
using namespace std;

void enterDescription(std::string &desc)
{
    cin.ignore();
    getline(std::cin, desc);
    return;
}

void removeSpaces(string& str) {
    if (str.empty())
        return;
    
    string::iterator currentChar = str.begin();

    while (currentChar < str.end())
    {
        if (*currentChar == ' ')
        {
            str.erase(currentChar, currentChar + 1);
        }
        else {
            currentChar++;
        }
    }
}

void clearScreen()
{
    system("cls");
}


char enterCharInput()
{
    char userInput;

    cin >> userInput;
    return userInput;
}

string enterStringInput()
{
    string userInput;
    cin >> userInput;
    return userInput;
}

void enterStudentInput()
{
    STUDENT student;
    cout << "Enter Student's First Name: ";
    cin >> student.studentFName;
    removeSpaces(student.studentFName);
    cout << "Enter Student's Last Name: ";
    cin >> student.studentLName;
    removeSpaces(student.studentLName);
    cout << "Enter Student's Grade: ";
    cin >> student.grade;
    removeSpaces(student.grade);
    cout << "Enter Student's Class: ";
    cin >> student.Class;
    //removeSpaces(student.Class);
    cout << "(- if student doesn't have an email) Enter Student's Email: ";
    cin >> student.studentEmail;
    removeSpaces(student.studentEmail);
    cout << "(- if student doesn't have a team) Enter Student's Team: ";
    cin >> student.studentsTeam.teamName;
    removeSpaces(student.studentsTeam.teamName);
    addStudent(student);
    cout << endl << "Student has been added successfully!" << endl;
}

void enterTeacherInput()
{
    TEACHER teacher;
    cout << "Enter Teacher's First Name: ";
    cin >> teacher.teachersFName;
    removeSpaces(teacher.teachersFName);
    cout << "Enter Student's Last Name: ";
    cin >> teacher.teachersLName;
    removeSpaces(teacher.teachersLName);
    cout << "Enter Teacher's Grade: ";
    cin >> teacher.grade;
    removeSpaces(teacher.grade);
    cout << "Enter Teacher's Class: ";
    cin >> teacher.Class;
    cout << "(- if student doesn't have an email) Enter Student's Email: ";
    cin >> teacher.teacherEmail;
    removeSpaces(teacher.teacherEmail);
    addTeacher(teacher);
    cout << endl << "Teacher has been added successfully!" << endl;
}

void enterSchoolInput()
{
    SCHOOL school;
    cout << "Enter School's Name: ";
    cin >> school.schoolName;
    removeSpaces(school.schoolName);
    cout << "Enter School's Town: ";
    cin >> school.town;
    removeSpaces(school.town);
    cout << "Enter School's Address: ";
    cin.ignore();
    getline(cin, school.address);
    removeSpaces(school.address);
    addSchool(school);
    cout << endl << "School has been added successfully!" << endl;
}

void enterTeamInput()
{
    TEAM team;
    cout << "Enter Team\'s Name: ";
    cin >> team.teamName;
    cout << "Enter Team\'s Description: " << endl;
    enterDescription(team.description);

    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    string time = to_string((5 + ltm->tm_hour)) + ':' + to_string(30 + ltm->tm_min) + ':' + to_string(ltm->tm_sec);
    team.creationDate = time;

    addTeam(team);
    cout << endl << "Team has been added successfully!" << endl;
}

void showStudentsMenu()
{
    bool chosenCorrect = false;
    while (!chosenCorrect)
    {
        char val = enterCharInput();
        if (val == '1')
        {
            // Add Student
            clearScreen();
            enterStudentInput();
            chosenCorrect = true;
        }
        if (val == '2')
        {
            // Show All Students
            clearScreen();
            showAllStudents();
            system("pause");
            chosenCorrect = true;
        }
        if (val == '3')
        {
            // Find A Student
            clearScreen();
            string input = enterStringInput();
            FindStudentsByFName(input);
            chosenCorrect = true;
        }
        if (val == '4')
        {
            // Delete Student
            clearScreen();
            string input = enterStringInput();
            int intInput = stoi(input);
            deleteStudentByLine(intInput);
        }
        if (val == '0')
        {
            // Go Back
            chosenCorrect = true;
        }
        if (chosenCorrect == false)
        {
            clearScreen();
            mainMenuInteraction1Menu();
            retryInput(); // Method in "menutexts.h"
        }
    }
}

void showTeamsMenu()
{
    bool chosenCorrect = false;
    while (!chosenCorrect)
    {
        char val = enterCharInput();
        if (val == '1')
        {
            // Add Team
            clearScreen();
            enterTeamInput();
            chosenCorrect = true;
        }
        if (val == '2')
        {
            // Show All Teams
            clearScreen();
            showAllTeams();
            system("pause");
            chosenCorrect = true;
        }
        if (val == '3')
        {
            // Find A Team
            clearScreen();
            string input = enterStringInput();
            FindTeamByName(input);
            chosenCorrect = true;
        }
        if (val == '4')
        {
            // Delete Teams
            clearScreen();
            string input = enterStringInput();
            int intInput = stoi(input);
            deleteTeamByLine(intInput);
        }
        if (val == '0')
        {
            // Go Back
            chosenCorrect = true;
        }
        if (chosenCorrect == false)
        {
            clearScreen();
            mainMenuInteraction3Menu();
            retryInput(); // Method in "menutexts.h"
        }
    }
}

void showTeachersMenu()
{
    bool chosenCorrect = false;
    while (!chosenCorrect)
    {
        char val = enterCharInput();
        if (val == '1')
        {
            clearScreen();
            enterTeacherInput();
            chosenCorrect = true;
        }
        if (val == '2')
        {
            clearScreen();
            showAllTeachers();
            system("pause");
            chosenCorrect = true;
        }
        if (val == '3')
        {
            clearScreen();
            string input = enterStringInput();
            FindStudentsByFName(input);
            chosenCorrect = true;
        }
        if (val == '4')
        {
            clearScreen();
            string input = enterStringInput();
            int intInput = stoi(input);
            deleteStudentByLine(intInput);
        }
        if (val == '0')
        {
            chosenCorrect = true;
        }
        if (chosenCorrect == false)
        {
            clearScreen();
            mainMenuInteraction2Menu();
            retryInput(); // Method in "texts.cpp"
        }
    }
    clearScreen();
}

void showSchoolsMenu()
{
    bool chosenCorrect = false;
    while (!chosenCorrect)
    {
        char val = enterCharInput();
        if (val == '1')
        {
            // Add School
            clearScreen();
            enterSchoolInput();
            chosenCorrect = true;
        }
        if (val == '2')
        {
            // Show All Schools
            clearScreen();
            showAllSchools();
            system("pause");
            chosenCorrect = true;
        }
        if (val == '3')
        {
            // Find A School
            clearScreen();
            string input = enterStringInput();
            FindSchoolByName(input);
            chosenCorrect = true;
        }
        if (val == '4')
        {
            // Delete School
            clearScreen();
            string input = enterStringInput();
            int intInput = stoi(input);
            deleteSchoolByLine(intInput);
        }
        if (val == '0')
        {
            // Go Back
            chosenCorrect = true;
        }
        if (chosenCorrect == false)
        {
            clearScreen();
            mainMenuInteraction4Menu();
            retryInput(); // Method in "menutexts.h"
        }
    }
}

bool showInputMainMenuInteraction()
{
    bool chosenCorrect = false;
    while (!chosenCorrect)
    {
        char val = enterCharInput();
        if (val == '1')
        {
            clearScreen();
            chooseDataType();
            // Add, edit, delete and show data
            chosenCorrect = true;
        }
        if (val == '2')
        {
            clearScreen();
            infoAboutProject();
            // show information about the project
            chosenCorrect = true;
        }
        if (val == '3')
        {
            // exit the project
            clearScreen();
            programLeaveText(); // Method in "menutexts.h"
            closeAllFiles();
            exit(0);
        }
        if (chosenCorrect == false)
        {
            clearScreen();
            mainMenuText();
            retryInput(); // Method in "menutexts.h"
        }

    }
    return true;
}

void showInputTypeMenu()
{

    bool chosenCorrect = false;
    while (!chosenCorrect)
    {
        char val = enterCharInput();
        if (val == '1')
        {
            //Schools
            mainMenuInteraction4Menu();
            showSchoolsMenu();
            chosenCorrect = true;
        }
        if (val == '2')
        {
            // Teachers
            mainMenuInteraction2Menu();
            showTeachersMenu();
            chosenCorrect = true;
        }
        if (val == '3')
        {
            // Teams
            mainMenuInteraction3Menu();
            showTeamsMenu();
            chosenCorrect = true;
        }
        if (val == '4')
        {
            mainMenuInteraction1Menu();
            showStudentsMenu();
            // Students
            chosenCorrect = true;
        }
        if (chosenCorrect == false)
        {
            clearScreen();
            chooseTypeText();
            retryInput(); // Method in "menutexts.h"
        }
    }
}
