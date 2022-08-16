#pragma once
#include "item.h"

struct Node {
    Node();
    Node(const Item &);
    Node(const char * const &);
    ~Node();


    Item * data;
    Node * next;
};
