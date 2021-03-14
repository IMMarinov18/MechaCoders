#pragma once
#pragma warning(disable : 4996)
#include <string>

struct TEAM {
    std::string teamName;
    std::string description;
    std::string creationDate;
};

void FindTeamByName(const std::string& inputName);
void addTeam(const TEAM& givenTeam);
void deleteTeamByLine(int n);
void showAllTeams();