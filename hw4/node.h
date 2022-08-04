#pragma once
#include "word.h"

class Node {
public:
    // General Class Nodes Required in CS 162
    Node();                       // Default constructor
    ~Node();                       // Default destructor
    Node(const Node &);           // Copy constructor
    Node(Node &&);                // Move constructor
    Node(Word);              // Parm constructor
    Node & operator=(const Node &);// Copy assignment
    Node & operator=(Node &&);  // Move assignment

    friend std::ostream & operator<<(std::ostream &, const Node &);
    friend std::istream & operator>>(std::istream &, Node &);

    // Node Nodes
    Node * get_next() const;
    Word * get_data() const;
    void set_next(Node *);
    void set_data(Word *);

private:
    Word * data;
    Node * next;
};
          
bool operator<(const Node &, const Node &);
bool operator<=(const Node &, const Node &);
bool operator==(const Node &, const Node &);
bool operator!=(const Node &, const Node &);
bool operator>=(const Node &, const Node &);
bool operator>(const Node &, const Node &);