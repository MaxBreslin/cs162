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
    Word & operator=(const Word &);

    // Simply returns this->count
    int get_count() const;
    // Creates a new dynamic c-string with the
    // value of the passed c-string and sets
    // this->data to it
    void set_data(char * const &);
    // Copies this->data into a new dynamic c-string
    // and returns a pointer to it
    char * get_data() const;

    // Increments this->count by one
    void increment_count();

private:
    char * data;
    int count;
};