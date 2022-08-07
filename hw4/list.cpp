#include "list.h"

List::List() {
    index = nullptr;
    size = 0;
}

List::List(const List &obj) {
    if (obj.index) {
        Node * curr = new Node;
        index = curr;
        for (size_t i = 0; i < obj.length(); i ++) {
            curr->data = new Word(*obj[i].data);
            curr->next = new Node;
            curr = curr->next;
        }
        size = obj.size;
    }
    else {
        index = nullptr;
        size = 0;
    }
}

List::~List() {
    Node * curr = index;
    while (curr) {
        curr = index->next;
        delete index->data;
        delete index;
        index = curr;
    }
    index = nullptr;
    size = 0;
}

List & List::operator=(const List &obj) {
    if (this != &obj) {
        Node * curr = index->next;
        while (curr) {
            delete index;
            index = curr;
            curr = index->next;
        }
        if (obj.index) {
            curr = new Node;
            index = curr;
            for (size_t i = 0; i < obj.length(); i ++) {
                curr->data = new Word(*obj[i].data);
                curr->next = new Node;
                curr = curr->next;
            }
            size = obj.size;
        }
        else {
            index = nullptr;
            size = 0;
        }
    }
    return *this;
}

Node & List::operator[](const size_t &index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return *counted_traversal(index);
}
const Node & List::operator[](const size_t &index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return *counted_traversal(index);
}

std::ostream & operator<<(std::ostream &out, const List &obj) {
    Node * curr = obj.index;
    while (curr) {
        out << *curr->data;
        curr = curr->next;
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

size_t List::length() const {
    return size;
}

void List::sorted_insert(const Node &node) {
    if (index) {
        Node * curr = index;
        Node * prev = nullptr;
        Node * temp = nullptr;
        while (curr->next) {
            if (*curr->data >= *node.data) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (!prev) {
            temp = new Node;
            temp->data = new Word(*node.data);
            temp->next = index;
            index = temp;
            size ++;
            return;
        }
        temp = new Node;
        prev->next = temp;
        temp->data = new Word(*node.data);
        temp->next = curr;
        size ++;
        return;
    }
    index = new Node;
    index->data = new Word(*node.data);
    index->next = nullptr;
    size ++;
}
void List::sorted_insert(Word * const &word) {
    if (index) {
        Node * curr = index;
        Node * prev = nullptr;
        Node * temp = nullptr;
        while (curr) {
            if (*curr->data >= *word) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (!prev) {
            temp = new Node;
            temp->data = word;
            temp->next = index;
            index = temp;
            size ++;
            return;
        }
        if (!curr) {
            temp = new Node;
            prev->next = temp;
            temp->data = word;
            temp->next = nullptr;
            size ++;
            return;
        }
        temp = new Node;
        prev->next = temp;
        temp->data = word;
        temp->next = curr;
        size ++;
        return;
    }
    index = new Node;
    index->data = word;
    index->next = nullptr;
    size ++;
}

Node * List::find(const Node &node) const {
    Node * curr = index;
    while (curr) {
        if (*curr->data == *node.data) {
            break;
        }
        curr = curr->next;
    }
    return curr;
}
Node * List::find(const char *str) const {
    Node * curr = index;
    while (curr) {
        if (*curr->data == str) {
            break;
        }
        curr = curr->next;
    }
    return curr;
}
