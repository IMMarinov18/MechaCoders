#pragma once
#include <iostream>
using namespace std;

void infoAboutProject()
{
    cout << "+-----------------------+"<<endl;
    cout << "|  MechaCoders Project  |" << endl;
    cout << "|-----------------------|"<<endl;
    cout << "|      Version 1.0      | " << endl << endl;
    cout << "+-----------------------+"<<endl;
}

void mainMenuInteraction1Menu()
{
    cout << "+--------------------+"<<endl;
    cout << "|  1. Add Data       |" << endl;
    cout << "|--------------------|"<<endl;
    cout << "|  2. Change Data    |" << endl;
    cout << "|--------------------|"<<endl;
    cout << "|  3. Show All Data  |" << endl;
    cout << "|--------------------|"<<endl;
    cout << "|  4. Find Data      |" << endl;
    cout << "|--------------------|"<<endl;
    cout << "|  5. Delete Data    |" << endl;
    cout << "|--------------------|"<<endl;
    cout << "|0. Back to Main Menu| " << endl;
    cout << "+--------------------+"<<endl;
     cout<<endl;
    cout<<"Your choice?: ";
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
    cout<<endl;
    cout<<"Your choice?: ";
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