#include <iostream>
#include <string>
#include "student.h"
#include "teacher.h"
#include "textMenus.h"
#include "functions.h"

using namespace std;

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
    cout << "Enter Student's Last Name: ";
    cin >> teacher.teachersLName;
    cout << "Enter Teacher's Grade: ";
    cin >> teacher.grade;
    cout << "Enter Teacher's Class: ";
    cin >> teacher.Class;
    cout << "(- if student doesn't have an email) Enter Student's Email: ";
    cin >> teacher.teacherEmail;
    addTeacher(teacher);
    cout << endl << "Teacher has been added successfully!" << endl;
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
            enterStudentInput();
            chosenCorrect = true;
        }
        if (val == '2')
        {
            // Show All Teams
            clearScreen();
            showAllStudents();
            system("pause");
            chosenCorrect = true;
        }
        if (val == '3')
        {
            // Find A Team
            clearScreen();
            string input = enterStringInput();
            FindStudentsByFName(input);
            chosenCorrect = true;
        }
        if (val == '4')
        {
            // Delete Teams
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
            mainMenuInteraction1Menu();
            retryInput(); // Method in "texts.cpp"
        }
    }
    clearScreen();
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
            exit(1);
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