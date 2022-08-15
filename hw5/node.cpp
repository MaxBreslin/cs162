#include "node.h"

Node::Node() {
    data = nullptr;
    next = nullptr;
}
Node::Node(const Item &obj) {
    data = new Item(obj);
    next = nullptr;
}
Node::Node(const char * const &name) {
    data = new Item(name);
    next = nullptr;
}
Node::~Node() {
    delete data;
    data = nullptr;
}