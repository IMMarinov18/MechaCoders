#include <string>
#include <fstream>
#include "textMenus.h"
#include "SaveData.h"
#include "functions.h"
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
    openAllFiles();
    while (mainMenu());
    closeAllFiles();
}