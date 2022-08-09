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

    void append(Node * const &);
    void append(const Node &);
    void sorted_insert(Node * const &);
    void sorted_insert(const Word &);
    Node * find(const char *) const;
    Node * find(const Node &) const;

private:
	Node * index;
    size_t size;

    Node * counted_traversal(const size_t &index) const;
};
