#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Word {
public:
    Word();
    Word(const Word &);
    Word(char * const &);
    ~Word();
    Word& operator=(const Word &);

    int get_count() const;
    void set_data(char * const &);
    char * get_data() const;

    void increment_count();

private:
    char * data;
    int count;
};