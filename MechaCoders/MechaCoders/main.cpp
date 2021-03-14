#include <string>
#include <fstream>
#include "textMenus.h"
#include "functions.h"
#include "main.h"

using namespace std;



void chooseDataType() {
    chooseTypeText();
    beforeInputText();
    showInputTypeMenu();
}

bool mainMenu() {
    mainMenuText(); // Method in "menutexts.h"
    beforeInputText();
    return showInputMainMenuInteraction();
}

int main() {
    //string a = "a  k";
   // trim(a); cout << a << endl;
    openAllFiles();
    while (mainMenu());
    closeAllFiles();
}