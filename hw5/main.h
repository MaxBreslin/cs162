#pragma once
#include "list.h"

int main();

// Prints a welcome message
void welcome();

// Displays a menu to the user and 
// returns the user's choice
int menu();

// Reads from std::cin and allocates input
// to a dynamic c-string. A pointer to this
// string is returned.
char * get_name();

// Erases the passed list
void erase(List &);

// Prompts the user for information about
// a new item and adds it to the passed list
void add(List &);

// Prompts the user for information about
// the item(s) to remove and calls the appropriate
// remove function
void remove(List &);
// Prompts the user for the name of the
// item to remove and removes it from the list
void remove_name(List &);
// Prompts the user for a quantity
// and removes every item with that quantity
// from the list
void remove_quantity(List &);
// Prompts the user for a price
// and removes every item with that price
// from the list
void remove_price(List &);

// Prompts the user for information about
// the item(s) to update and calls the appropriate
// update function
void update(List &);
// Prompts the user for the name of the
// item to update and a new name.
// Updates it in the list.
void update_name(List &);
// Prompts the user for a quantity and a
// new quantity. Updates the quantity in the list.
void update_quantity(List &);
// Prompts the user for a price and a new price.
// Updates the price in the list.
void update_price(List &);

// Prints the contents of the list to std::cout
void print(const List &);
// Prompts the user for a filename and writes the
// contents of the list to the file
void to_file(const List &);
