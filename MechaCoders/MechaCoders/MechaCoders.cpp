#include <iostream>
#include <string>
using namespace std;

int enterUserInput()
{
    int userInput;
    cin >> userInput;
    return userInput;
}

bool mainMenu()
{

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
        // show exit message
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

    while (mainMenu());
}