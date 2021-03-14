#include <iostream>
#include "textMenus.h"
using namespace std;

void infoAboutProject()
{
    cout << "+-----------------------+" << endl;
    cout << "|  MechaCoders Project  |" << endl;
    cout << "|-----------------------|" << endl;
    cout << "|      Version 2.0      |" << endl;
    cout << "+-----------------------+" << endl;
}

void mainMenuInteraction1Menu()
{
    cout << "+----------------------+" << endl;
    cout << "|   1. Add Student     |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   2. Show All Data   |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   3. Find Student    |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   4. Delete Student  |" << endl;
    cout << "|----------------------|" << endl;
    cout << "| 0. Back to Main Menu |" << endl;
    cout << "+----------------------+" << endl;
    cout << "Your choice?: ";
}

void mainMenuInteraction2Menu()
{
    cout << "+----------------------+" << endl;
    cout << "|   1. Add Teacher     |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   2. Show All Data   |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   3. Find Teacher    |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   4. Delete Teacher  |" << endl;
    cout << "|----------------------|" << endl;
    cout << "| 0. Back to Main Menu |" << endl;
    cout << "+----------------------+" << endl;
    cout << "Your choice?: ";
}

void mainMenuInteraction3Menu()
{
    cout << "+----------------------+" << endl;
    cout << "|   1. Add A Team      |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   2. Show All Teams  |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   3. Find Team       |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   4. Delete Team     |" << endl;
    cout << "|----------------------|" << endl;
    cout << "| 0. Back to Main Menu |" << endl;
    cout << "+----------------------+" << endl;
    cout << "Your choice?: ";
}

void mainMenuInteraction4Menu()
{
    cout << "+----------------------+" << endl;
    cout << "|   1. Add A School    |" << endl;
    cout << "|----------------------|" << endl;
    cout << "| 2. Show All Schools  |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   3. Find School     |" << endl;
    cout << "|----------------------|" << endl;
    cout << "|   4. Delete School   |" << endl;
    cout << "|----------------------|" << endl;
    cout << "| 0. Back to Main Menu |" << endl;
    cout << "+----------------------+" << endl;
    cout << "Your choice?: ";
}

void chooseTypeText()
{
    cout << "+-----------------+" << endl;
    cout << "|   1. Schools    |" << endl;
    cout << "|-----------------|" << endl;
    cout << "|   2. Teachers   |" << endl;
    cout << "|-----------------|" << endl;
    cout << "|   3. Teams      |" << endl;
    cout << "|-----------------|" << endl;
    cout << "|   4. Students   |" << endl;
    cout << "+-----------------+" << endl;
    cout << endl << "Your choice?: ";
}

void mainMenuText()
{
    cout << "+------------------WELCOME------------------+" << endl;
    cout << "|   1. Add, Edit, Delete and Show Data.     |" << endl;
    cout << "|-------------------------------------------|" << endl;
    cout << "|2. Information about our team and project. |" << endl;
    cout << "|-------------------------------------------|" << endl;
    cout << "|           3. Exit the project             |" << endl;
    cout << "+-------------------------------------------+" << endl;
    cout << endl;
}

void programLeaveText()
{
    cout << "Thank you for using our program!" << endl;
}

void retryInput()
{
    cout << "Please enter a valid Number: ";
}

void beforeInputText()
{
    cout << "Choose an option from the menu by entering a number: ";
}