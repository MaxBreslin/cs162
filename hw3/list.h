#pragma once
#include "word.h"

class List {
public:
    List();
    List(const List &);
    ~List();
    List& operator=(const List &);

    int get_size() const;
    Word & get_index(const int &) const;

    void insert(const Word &);
    int contains(char * const &) const;
    int contains(const Word &) const;
    void print() const;
    void sort();

private:
    Word * index;
    int size;
};