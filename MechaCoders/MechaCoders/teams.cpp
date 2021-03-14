#include <iostream>
#include <string>
#include <fstream>
#include "team.h"
#include "main.h"
#include "student.h"

using namespace std;

int getLinesFromFile()
{
    string text;
    const char newLine = ';';
    int numLines = 0;
    while (getline(teams, text, '\n'))
    {
        for (size_t i = 0; i < text.length(); i++)
        {
            if (text.at(i) == newLine)
            {
                numLines++;
            }
        }
    }
    return numLines;
}

void FindTeamByFName(const std::string& inputName)
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
void addStudent(const TEAM& givenTeam)
{
    try {
        if (!teams.is_open()) throw "1";
        string saveLine = "\n" + givenTeam.teamName + givenTeam.description + givenTeam.creationDate + ";";
        cout << saveLine;
        teams << saveLine;
        closeAllFiles();
        openAllFiles();
    }
    catch (string val) {
        if (val == "1") { cout << "Couldn't open file."; }
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

    students.close();

    remove("teams.txt");
    int _ = rename("temp.txt", "teams.txt");

    openAllFiles();
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
        string name;
        for (int i = 0; i < text.length(); i++) {
            char symbol = text.at(i);
            if (symbol == '|') {
                cout << name << " ";
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