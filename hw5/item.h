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