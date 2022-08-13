#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Item {
public:
    Item();
    Item(const Item &);
    Item(const char * const &, const unsigned int &, const float &);
    ~Item();
    Item & operator=(const Item &);

    void print() const;
    
    char * get_name();
    void get_name(char *);
    unsigned int get_quantity();
    float get_price();

private:
    char * name;
    unsigned int quantity;
    float price;
};