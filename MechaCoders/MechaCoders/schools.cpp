#include <iostream>
#include <string>
#include <fstream>
#include "school.h"
#include "main.h"
#include "student.h"

using namespace std;

void FindSchoolByName(const std::string& inputName)
{
    if (!schools.is_open()) return;
    string line;
    int counter = 0;
    while (getline(schools, line, '\n')) {
        string name = "";
        for (int i = 0; i < line.length(); i++) {
            char symbol = line.at(i);
            if (symbol == '|') {
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
        cout << "No school name matches found." << endl;
}
void addSchool(const SCHOOL& givenSchool)
{
    try {
        if (!schools.is_open()) throw "1";
        string saveLine = "\n" + givenSchool.schoolName + "|" + givenSchool.town + "|" + givenSchool.address + ";";
        cout << saveLine;
        schools << saveLine;
        closeSchoolFile();
        openSchoolFile();
    }
    catch (string val) {
        if (val == "1") { cout << "Couldn't open file."; }
    }
}

void showAllSchools() {
    std::string text;
    int line = 0;
    while (getline(schools, text, '\n'))
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
                    cout << "School Name: " << " ";
                }
                else if (counter == 2)
                {
                    cout << "School Town: " << " ";
                }
                else if (counter == 3)
                {
                    cout << "School Address: " << " ";
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

void deleteSchoolByLine(int n)
{
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char c;
    int line_no = 1;
    while (schools.get(c))
    {
        if (c == '\n')
            line_no++;

        if (line_no != n)
            ofs << c;
    }

    ofs.close();

    schools.close();

    remove("schools.txt");
    int _ = rename("temp.txt", "schools.txt");

    openSchoolFile();
}

