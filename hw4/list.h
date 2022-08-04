#pragma once
#include "node.h"

class List {
public:
    // General Class Elements Required in CS 162
    List();                       // Default constructor
    ~List();                       // Default destructor
    List(const List &);           // Copy constructor
    List(List &&);                // Move constructor
    List(Node *);              // Parm constructor
    List & operator = (const List &);// Copy assignment
    List & operator = (List &&);  // Move assignment

    friend std::ostream & operator << (std::ostream &, const List &);
    friend std::istream & operator >> (std::istream &, List &);

    // List ADT Elements
    bool is_empty() const;                  // True if list is empty
    bool is_full() const;                   // True if list is full
    Node & operator[](std::size_t);                // Reference index
    const Node & operator[](std::size_t) const;    // Value index
    const Node & at(std::size_t);                  // Accessor
    Node * find(Node *);                        // Search
    bool remove(std::size_t);                    // Positional deletion
    bool remove(Node *);                      // Value deletion (multiple deletions)
    bool insert(Node *, size_t);              // Positional insertion
    bool insert(Node *);                      // Ordered insertion
    bool erase();                                // Erase all elements
    size_t length() const;                         // Number of elements in list

private:
    size_t size;               // Size of the list
    size_t capacity;           // Capacity of the list
    Node * head;               // Head pointer
    Node * tail;               // Tail pointer
};

          
bool operator <  (const List &, const List &);
bool operator <= (const List &, const List &);
bool operator == (const List &, const List &);
bool operator != (const List &, const List &);
bool operator >= (const List &, const List &);
bool operator >  (const List &, const List &);