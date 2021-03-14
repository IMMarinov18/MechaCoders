#pragma once
#ifndef FILE_H
#define FILE_H

extern std::fstream schools;
extern std::fstream teachers;
extern std::fstream students;
extern std::fstream teams;

extern void openAllFiles();
extern void closeAllFiles();

#endif