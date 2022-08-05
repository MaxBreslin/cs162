#pragma once
#include "node.h"

class List {
public:
    List();
    List(const List &);
    ~List();
    List & operator=(const List &);
    Node & operator[](const size_t &);
    const Node & operator[](const size_t &) const;
    
    friend std::ostream & operator<<(std::ostream &, const List &);
    
    // Simply returns this->size
    size_t length() const;
    // Returns a reference to the word at the 
    // passed location in this->index
    Node & get_index(const int &) const;

    void sorted_insert(const Node &);
    void sorted_insert(const Word &);
    Node * find(const Node &) const;
    Node * find(const char *) const;

private:
	Node * index;
    size_t size;

    Node * counted_traversal(const size_t &index) const;
};