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
    
    // Prints the entire list.
    friend std::ostream & operator<<(std::ostream &, const List &);
    
    // Simply returns this->size.
    size_t length() const;

    // Appends the passed node to the end of the list.
    // NO COPY IS MADE.
    void append(Node * const &);
    // Creates a copy of the passed node and appends it 
    // to the end of the list.
    void append(const Node &);
    // Inserts the passed node into the list at the
    // correct position (sorted alphabetically).
    // NO COPY IS MADE.
    void sorted_insert(Node * const &);
    // Creates a copy of the passed node and inserts it
    // into the list at the correct position (sorted alphabetically).
    void sorted_insert(const Node &);
    // Creates a new node with the passed word and inserts it
    // into the list at the correct position (sorted alphabetically).
    void sorted_insert(const Word &);
    
    // Returns a pointer to the first node containing the
    // passed string. If no node is found, returns nullptr.
    Node * find(const char * const &) const;
    // Returns a pointer to the first node containing the
    // same data as the passed node. If no node is found, 
    // returns nullptr.
    Node * find(const Node &) const;

private:
	Node * index;
    size_t size;

    // Helper function for a basic counted traversal.
    Node * counted_traversal(const size_t &index) const;
};
