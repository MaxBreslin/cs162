#pragma once
#include "node.h"

class List {
public:
    List();
    List(const List &);
    ~List();
    List & operator=(const List &);
    
    void print(std::ostream &) const;

    // Simply returns this->size.
    size_t length() const;

    Node & at(const size_t &) const;

    void sorted_unique_insert(Node * const &);

    void remove(const char * const &);
    void remove(const unsigned int &);
    void remove(const float &);

    void update(const char * const &, const char * const &);
    void update(const unsigned int &, const unsigned int &);
    void update(const float &, const float &);

private:
    Node * index;
    size_t size;

    void append(Node * const &);
    int compare(const Node &, const Node &) const;
};
