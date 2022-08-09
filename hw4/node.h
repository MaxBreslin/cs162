#pragma once
#include "word.h"

struct Node {
    Word * data;
    Node * next;
};

bool operator>(const Node &, const Node &);
bool operator==(const Node &, const Node &);
bool operator==(const Node &, const char * const &);
bool operator==(const char * const &, const Node &);
bool operator>=(const Node &, const Node &);
