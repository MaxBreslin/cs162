#include "node.h"

Node::Node() {
    data = nullptr;
    next = nullptr;
}
Node::~Node() {
    delete data;
    delete next;
    data = nullptr;
    next = nullptr;
}
Node::Node(const Node &obj) {
    data = new Word(*obj.data);
    next = new Node(*obj.next);
}
Node::Node(Node &&obj) {
    data = obj.data;
    next = obj.next;
    obj.data = nullptr;
    obj.next = nullptr;
}
Node::Node(Word obj) {
    data = &obj;
    next = nullptr;
}

Node & Node::operator=(const Node &obj) {
    delete data;
    delete next;
    data = new Word(*obj.data);
    next = new Node(*obj.next);
}
Node & Node::operator=(Node &&obj) {
    delete data;
    delete next;
    data = obj.data;
    next = obj.next;
    obj.data = nullptr;
    obj.next = nullptr;
}

std::ostream & operator<<(std::ostream &out, const Node &obj) {
    out << *obj.data;
    return out;
}
std::istream & operator>>(std::istream &in, Node &obj) {
    in >> *obj.data;
    return in;
}

Node * Node::get_next() const {
    return next;
}
Word * Node::get_data() const {
    return data;
}
void Node::set_next(Node * next) {
    delete this->next;
    this->next = next;
}
void Node::set_data(Word * data) {
    delete this->data;
    this->data = data;
}

bool operator<(const Node &x, const Node &y) {
    return *x.get_data() < *y.get_data();
}
bool operator<=(const Node &x, const Node &y) {
    return *x.get_data() <= *y.get_data();
}
bool operator==(const Node &x, const Node &y) {
    return *x.get_data() == *y.get_data();
}
bool operator!=(const Node &x, const Node &y) {
    return *x.get_data() != *y.get_data();
}
bool operator>=(const Node &x, const Node &y) {
    return *x.get_data() >= *y.get_data();
}
bool operator>(const Node &x, const Node &y) {
    return *x.get_data() > *y.get_data();
}