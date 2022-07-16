#pragma once

#include "student.h"

const int MAX_STUDENTS = 30;
const int NUM_OPTIONS = 8;

// main is the starting point of the program and will call welcome and menu.
int main();

// welcome displays a simple introduction message to the user.
void welcome();

// menu displays a menu of options to the user and returns the user's choice.
char menu();
