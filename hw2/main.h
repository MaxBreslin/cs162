#pragma once

#include "student.h"

const int MAX_STUDENTS = 30;
const int MAX_FILE_NAME = 30;
const int MAX_OPTION = 30;
const int NUM_FILES = 3;

// main is the starting point of the program and will call welcome and menu.
int main();

// welcome displays a simple introduction message to the user.
void welcome();

// menu displays a menu of options to the user and returns the user's choice.
char menu();

// get_file_name prompts the user for the name of the file to be loaded and stores it in file_name.
void get_file_names(char file_names[NUM_FILES][MAX_FILE_NAME + 1]);

void get_name(char name[MAX_OPTION + 1]);
