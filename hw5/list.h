#pragma once
#include "node.h"

class List {
public:
    List();
    List(const List &);
    ~List();
    List & operator=(const List &);
    
    // Prints the contents of the list to the passed
    // output stream
    void print(std::ostream &) const;

    // Simply returns this->size.
    size_t length() const;

    // Returns a reference to the node at the passed index.
    Node & at(const size_t &) const;

    // If the node is not already in the list, inserts the 
    // passed node at the correct position (alphabetically sorted)
    void sorted_unique_insert(Node * const &);

    // Removes the node with the passed name from the list.
    void remove(const char * const &);
    // Removes every node with the passed quantity from the list.
    void remove(const unsigned int &);
    // Removes every node with the passed price from the list.
    void remove(const float &);

    // Updates the node with the first parameter to the second
    // parameter.
    void update(const char * const &, const char * const &);
    // Updates every node with the first parameter to the second
    // parameter.
    void update(const unsigned int &, const unsigned int &);
    // Updates every node with the first parameter to the second
    // parameter.
    void update(const float &, const float &);

private:
    Node * index;
    size_t size;

    // Inserts the passed node to the back of the list (does not
    // check for duplicates or sort)
    void append(Node * const &);
    // Compares the two passed nodes and returns 0 if they are equal,
    // -1 if the first node is less than the second, and 1 if the first
    // node is greater than the second.
    int compare(const Node &, const Node &) const;
};
