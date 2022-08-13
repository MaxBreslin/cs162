#pragma once
#include "item.h"

struct Node {
    Node() {
        data = nullptr;
        next = nullptr;
    }
    Node(const Item &obj) {
        data = new Item(obj);
        next = nullptr;
    }
    ~Node() {
        delete data;
        data = nullptr;
    }
    Item * data;
    Node * next;
};
