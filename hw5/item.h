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

    void print(std::ostream &) const;
    
    void set_name(const char * const &);
    char * get_name();
    void get_name(char *);

    void set_quantity(const unsigned int &);
    unsigned int get_quantity();

    void set_price(const float &);
    float get_price();

private:
    char * name;
    unsigned int quantity;
    float price;
};