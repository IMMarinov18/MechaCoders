#pragma once
#include <iostream>
#include "student.h"
#include "main.h"

using namespace std;

void showInputTypeMenu();
void chooseDataType();

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
    cout << "Enter Student's Last Name: ";
    cin >> student.studentLName;
    cout << "Enter Student's Grade: ";
    cin >> student.grade;
    cout << "Enter Student's Class: ";
    cin >> student.Class;
    cout << "(- if student doesn't have an email) Enter Student's Email: ";
    cin >> student.studentEmail;
    cout << "(- if student doesn't have a team) Enter Student's Team: ";
    cin >> student.studentsTeam.teamName;
    addStudent(student);
    cout << endl << " Student has been added successfully!" << endl;
}


void showStudentsMenu()
{
    bool chosenCorrect = false;
    while (!chosenCorrect)
    {
        char val = enterCharInput();
        if (val == '1')
        {
            clearScreen();
            enterStudentInput();
            chosenCorrect = true;
        }
        if (val == '2')
        {
            clearScreen();
            chosenCorrect = true;
        }
        if (val == '3')
        {
            clearScreen();
            showAllStudents();
            system("pause");
            chosenCorrect = true;
        }
        if (val == '4')
        {
            clearScreen();
            string input = enterStringInput();
            FindStudentsByFName(input);
            chosenCorrect = true;
        }
        if (val == '5')
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