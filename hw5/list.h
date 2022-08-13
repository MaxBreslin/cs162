#pragma once
#include "node.h"

class List {
public:
    List();
    List(const List &);
    ~List();
    List & operator=(const List &);
    
    void print() const;

    // Simply returns this->size.
    size_t length() const;

    Node & at(const size_t &) const;

    // Appends the passed node to the end of the list.
    // NO COPY IS MADE.
    void append(Node * const &);

    void sorted_insert(Node * const &);

private:
	Node * index;
    size_t size;

    // Helper function for a basic counted traversal.
    Node * counted_traversal(const size_t &index) const;
    int compare(const Node &, const Node &) const;
};
