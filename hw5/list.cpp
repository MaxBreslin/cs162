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

void List::print(std::ostream &out) const {
    if (!index) {
        std::cout << RED;
        out << "List is empty" << std::endl;
        std::cout << RESET;
        return;
    }
    Node * temp = index;
    while (temp) {
        temp->data->print(out);
        temp = temp->next;
    }
}

size_t List::length() const {
    return size;
}

Node & List::at(const size_t &index) const {
    if (!(index < size)) {
        throw "Index out of bounds";
    }

    Node * curr = this->index;
    size_t pos = 0;

    while (pos < index) {
        pos ++;
        curr = curr->next;
    }

    return *curr;
}

void List::sorted_unique_insert(Node * const &node) {
    if (!index) {
        append(node);
        return;
    }

    Node * curr = index;
    Node * prev = nullptr;

    while (curr) {
        if (compare(*curr, *node) == 0) {
            throw "\033[;31mDuplicate item\033[0m";
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

void List::remove(const char * const &name) {
    if (!index) {
        throw "\033[;31mList is empty\033[0m";
        return;
    }
    Node * curr = index;
    Node * prev = nullptr;
    while (curr) {
        if (compare(*curr, name) == 0) {
            if (prev) {
                prev->next = curr->next;
            }
            else {
                index = curr->next;
            }
            delete curr;
            size --;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    throw "\033[;31mItem with name not found\033[0m";
}
void List::remove(const unsigned int &quantity) {
    if (!index) {
        throw "\033[;31mList is empty\033[0m";
        return;
    }
    Node * curr = index;
    Node * prev = nullptr;
    Node * temp = nullptr;
    bool removed = 0;
    while (curr) {
        if (curr->data->get_quantity() == quantity) {
            if (prev) {
                prev->next = curr->next;
            }
            else {
                index = curr->next;
            }
            temp = curr->next;
            delete curr;
            curr = temp;
            size --;
            removed = 1;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    if (!removed) {
        throw "\033[;31mItem with quantity not found\033[0m";
    }
}
void List::remove(const float &price) {
    if (!index) {
        throw "\033[;31mList is empty\033[0m";
        return;
    }
    Node * curr = index;
    Node * prev = nullptr;
    Node * temp = nullptr;
    bool removed = 0;
    while (curr) {
        if (curr->data->get_quantity() == price) {
            if (prev) {
                prev->next = curr->next;
            }
            else {
                index = curr->next;
            }
            temp = curr->next;
            delete curr;
            curr = temp;
            size --;
            removed = 1;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    if (!removed) {
        throw "\033[;31mItem with price not found\033[0m";
    }
}

void List::update(const char * const &name, const char * const &new_name) {
    if (!index) {
        throw "\033[;31mList is empty\033[0m";
        return;
    }
    Node * curr = index;
    while (curr) {
        if (compare(*curr, name) == 0) {
            curr->data->set_name(new_name);
            return;
        }
        curr = curr->next;
    }
    throw "\033[;31mItem with name not found\033[0m";
}
void List::update(const unsigned int &quantity, const unsigned int &new_quantity) {
    if (!index) {
        throw "\033[;31mList is empty\033[0m";
        return;
    }
    Node * curr = index;
    bool updated = 0;
    while (curr) {
        if (curr->data->get_quantity() == quantity) {
            curr->data->set_quantity(new_quantity);
            updated = 1;
        }
        curr = curr->next;
    }
    if (!updated) {
        throw "\033[;31mItem with quantity not found\033[0m";
    }
}
void List::update(const float &price, const float &new_price) {
    if (!index) {
        throw "\033[;31mList is empty\033[0m";
        return;
    }
    Node * curr = index;
    bool updated = 0;
    while (curr) {
        if (curr->data->get_price() == price) {
            curr->data->set_price(new_price);
            updated = 1;
        }
        curr = curr->next;
    }
    if (!updated) {
        throw "\033[;31mItem with price not found\033[0m";
    }
}

void List::append(Node * const &node) {
    if (index) {
        at(size - 1).next = node;
    }
    else {
        index = node;
    }
    size ++;
}

int List::compare(const Node &lhs, const Node &rhs) const {
    char * lhs_name = lhs.data->get_name();
    char * rhs_name = rhs.data->get_name();
    int result = strcmp(lhs_name, rhs_name);
    delete[] lhs_name;
    delete[] rhs_name;
    return result;
}
