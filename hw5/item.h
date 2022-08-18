#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

#define GREEN "\033[;32m"
#define RED "\033[;31m"
#define YELLOW "\033[;33m"
#define RESET "\033[;0m"

class Item {
public:
    Item();
    Item(const Item &);
    Item(const char * const &);
    Item(const char * const &, const unsigned int &, const float &);
    ~Item();
    Item & operator=(const Item &);

    // Prints the contents of the item to the passed output stream
    void print(std::ostream &) const;
    
    // Sets the name of the item to the passed name
    void set_name(const char * const &);
    // Returns a pointer to a copy of the name of the item
    char * get_name();
    // Copies the name of the item to the passed pointer
    void get_name(char *);

    // Sets the quantity of the item to the passed quantity
    void set_quantity(const unsigned int &);
    // Simply returns this->quantity
    unsigned int get_quantity();

    // Sets the price of the item to the passed price
    void set_price(const float &);
    // Simply returns this->price
    float get_price();

private:
    char * name;
    unsigned int quantity;
    float price;
};