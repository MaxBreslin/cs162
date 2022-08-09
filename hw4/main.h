#pragma once
#include "list.h"

int main();

// Prompts the user for a file name and returns a pointer
// to a dynamic c-string containing the user's input.
char * get_fname();

// Reads the contents of the input file and adds every
// byte to a dynamic c-string which is returned.
char * create_string(std::ifstream &);
