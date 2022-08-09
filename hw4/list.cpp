#include "list.h"

List::List() {
    index = nullptr;
    size = 0;
}

List::List(const List &obj) {
    index = nullptr;
    size = 0;

    if (obj.index) {
        for (size_t i = 0; i < obj.length(); i ++) {
            append(obj[i]);
        }
        size = obj.size;
    }
}

List::~List() {
    Node * temp = index;
    while (temp) {
        temp = index->next;
        delete index->data;
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
            delete index->data;
            delete index;
            index = temp;
        }

        index = nullptr;
        size = 0;

        if (obj.index) {
            for (size_t i = 0; i < obj.length(); i ++) {
                append(obj[i]);
            }
            size = obj.size;
        }
    }
    return *this;
}

Node & List::operator[](const size_t &index) {
    return *counted_traversal(index);
}
const Node & List::operator[](const size_t &index) const {
    return *counted_traversal(index);
}

std::ostream & operator<<(std::ostream &out, const List &obj) {
    for (size_t i = 0; i < obj.length(); i ++) {
        out << *obj[i].data;
    }
    return out;
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
void List::append(const Node &node) {
    Node * temp = new Node;
    temp->data = node.data;
    temp->next = node.next;
    append(temp);
}

size_t List::length() const {
    return size;
}

void List::sorted_insert(Node * const &node) {
    if (index) {
        Node * curr = index;
        Node * prev = nullptr;
        Node * temp = nullptr;

        while (curr) {
            if (*curr >= *node) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        temp = node;
        
        if (prev) {
            prev->next = temp;
            temp->next = curr;
        }
        else {
            temp->next = index;
            index = temp;
        }
    }
    else {
        index = node;
        index->next = nullptr;
    }
    size ++;
}
void List::sorted_insert(const Word &word) {
    Node * temp = new Node;
    temp->data = new Word(word);
    temp->next = nullptr;
    sorted_insert(temp);
}

Node * List::find(const char *str) const {
    Node * temp = nullptr;
    for (size_t i = 0; i < size; i ++) {
        if (*(temp = counted_traversal(i)) == str) {
            return temp;
        }
    }
    return nullptr;
}
Node * List::find(const Node &node) const {
    const char * temp = node.data->get_data();
    Node * return_node = find(temp);
    delete[] temp;
    return return_node;
}
