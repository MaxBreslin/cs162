#pragma once

#include "student.h"

const int MAX_STUDENTS = 30;
const int MAX_FILE_NAME = 30;
const int MAX_OPTION = 30;

// main is the starting point of the program and will call welcome and menu.
int main();

// welcome displays a simple introduction message to the user.
void welcome();

// menu displays a menu of options to the user and returns the user's choice.
char menu();

// get_file_name prompts the user for the name of the file to be loaded and stores it in file_name.
void get_file_name(char file_name[]);

// reset_roster resets roster, size, and file_name to their initial state.
void reset_roster(Student roster[], int &size, char file_name[]);
