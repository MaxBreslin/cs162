#include "list.h"

List::List() {
    index = nullptr;
    size = 0;
}

List::List(const List &obj) {
    index = nullptr;
    size = 0;

    Node * temp = nullptr;

    if (obj.index) {
        for (size_t i = 0; i < obj.length(); i ++) {
            temp = new Node(*obj.at(i).data);
            append(temp);
        }
        size = obj.size;
    }
}

List::~List() {
    Node * temp = index;
    while (temp) {
        temp = index->next;
        delete index;
        index = temp;
    }

    index = nullptr;
    size = 0;
}

List & List::operator=(const List &obj) {
    if (this != &obj) {
        Node * temp = index;
        while (temp) {
            temp = index->next;
            delete index;
            index = temp;
        }

        index = nullptr;
        size = 0;

        if (obj.index) {
            for (size_t i = 0; i < obj.length(); i ++) {
                temp = new Node(*obj.at(i).data);
                append(temp);
            }
            size = obj.size;
        }
    }
    return *this;
}

void List::print() const {
    if (!index) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node * temp = index;
    while (temp) {
        temp->data->print();
        temp = temp->next;
    }
}

Node * List::counted_traversal(const size_t &index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node * curr = this->index;
    size_t pos = 0;

    while(pos != index) {
        pos ++;
        curr = curr->next;
    }

    return curr;
}

void List::append(Node * const &node) {
    if (index) {
        counted_traversal(size - 1)->next = node;
    }
    else {
        index = node;
    }
    size ++;
}

size_t List::length() const {
    return size;
}

Node & List::at(const size_t &index) const {
    return *counted_traversal(index);
}

int List::compare(const Node &lhs, const Node &rhs) const {
    return strcmp(lhs.data->get_name(), rhs.data->get_name());
}

void List::sorted_insert(Node * const &node) {
    if (!index) {
        append(node);
        return;
    }
    Node * curr = index;
    Node * prev = nullptr;

    while (curr) {
        if (compare(*curr, *node) == 0) {
            throw std::runtime_error("?Duplicate item");
            return;
        }
        if (compare(*curr, *node) > 0) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    
    if (prev) {
        prev->next = node;
        node->next = curr;
    }
    else {
        node->next = index;
        index = node;
    }
    size ++;
}

Node * List::find(const char * const &str) const {
    Node * temp = nullptr;
    for (size_t i = 0; i < size; i ++) {
        if (strcmp((temp = counted_traversal(i))->data->get_name(), str) == 0) {
            return temp;
        }
    }
    return nullptr;
}
Node * List::find(const Node &node) const {
    const char * temp = node.data->get_name();
    Node * return_node = find(temp);
    delete[] temp;
    return return_node;
}
