#pragma once
#include "word.h"

class List {
public:
    List();
    List(const List &);
    ~List();
    List & operator=(const List &);

    // Simply returns this->size
    int get_size() const;
    // Returns a reference to the word at the 
    // passed location in this->index
    Word & get_index(const int &) const;

    // Inserts a word at the back of this->index
    void insert(const Word &);
    // Returns the location of the first word in 
    // this->index with a data member variable which
    // matches the passed c-string or this->size
    // if no matching word is found
    int contains(char * const &) const;
    // Same as above, but a Word object is passed
    // instead of a c-string
    int contains(const Word &) const;
    // Prints the contents of this->index
    void print() const;
    // Sorts this->index alphabetically
    void sort();

private:
    Word * index;
    int size;
};