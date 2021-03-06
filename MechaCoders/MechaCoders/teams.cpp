#include <iostream>
#include <string>
#include <fstream>
#include "team.h"
#include "main.h"
#include "student.h"

using namespace std;

void FindTeamByName(const std::string& inputName)
{
    if (!teams.is_open()) return;
    string line;
    int counter = 0;
    while (getline(teams, line, '\n')) {
        string name = "";
        for (int i = 0; i < line.length(); i++) {
            char symbol = line.at(i);
            if (symbol == ',') {
                break;
            }
            else {
                name = name + symbol;
            }
        }
        if (setStringLower(name) == setStringLower(inputName))
        {
            counter++;
            cout << line << endl;
        }
    }
    if (counter < 1)
        cout << "No student name matches found." << endl;
}
void addTeam(const TEAM& givenTeam)
{
    try {
        if (!teams.is_open()) throw "1";
        string saveLine = "\n" + givenTeam.teamName + "|" + givenTeam.description +"|"+ givenTeam.creationDate + ";";
        cout << saveLine;
        teams << saveLine;
        closeTeamsFile();
        openTeamsFile();
        system("pause");
    }
    catch (string val) {
        if (val == "1") { cout << "Couldn't open file."; }
    }
}

void showAllTeams() {
    std::string text;
    int line = 0;
    while (getline(teams, text, '\n'))
    {
        if (text.empty())
            continue;
        line++;
        cout << "-" << line << "-" << endl;
        string name; int counter = 0;
        for (int i = 0; i < text.length(); i++) {
            char symbol = text.at(i);
            if (symbol == '|' or symbol == ';') {
                counter++;
                if (counter == 1)
                {
                    cout << "Name: " << " ";
                }
                else if (counter == 2)
                {
                    cout << "Description: " << " ";
                }
                else if (counter == 3)
                {
                    cout << "Date of Creation: " << " ";
                }
                cout << name << endl;
                name.clear();
            }
            else {
                name = name + symbol;
            }
        }
        name.clear();
        cout << endl;
    }
}

void deleteTeamByLine(int n)
{
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char c;
    int line_no = 1;
    while (teams.get(c))
    {
        if (c == '\n')
            line_no++;

        if (line_no != n)
            ofs << c;
    }

    ofs.close();

    teams.close();

    remove("teams.txt");
    int _ = rename("temp.txt", "teams.txt");

    openTeamsFile();
}

