#include "list.h"

List::List() {
    index = nullptr;
    size = 0;
}

List::List(const List &obj) {
    if (obj.index) {
        Node * curr = new Node;
        index = curr;
        index->data = new Word[obj.length()];
        for (size_t i = 0; i < obj.length(); i ++) {
            curr->next = new Node;
            curr = curr->next;
            curr->data = obj[i]->data;
        }
        size = obj.size;
    }
    else {
        index = nullptr;
        size = 0;
    }
}

List::~List() {
    if (index) {
        for (int i = 0; i < size; i ++) {
            index[i].~Word();
        }
        delete[] index;
        index = nullptr;
    }
    size = 0;
}

List& List::operator=(const List &obj) {
    if (this != &obj) {
        if (index) {
            for (int i = 0; i < size; i ++) {
                index[i].~Word();
            }
            delete[] index;
        }
        if (obj.index) {
            index = new Word[obj.size];
            for (int i = 0; i < obj.size; i ++) {
                index[i] = obj.index[i];
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

int List::get_size() const {
    return size;
}

Word & List::get_index(const int &index) const {
    if (index < size) {
        return this->index[index];
    }
    throw std::out_of_range("Index out of range");
}

void List::insert(const Word &obj) {
    Word * temp = nullptr;
    if (index) {
        temp = new Word[size + 1];
        for (int i = 0; i < size; i ++) {
            temp[i] = index[i];
        }
        temp[size] = obj;
        delete[] index;
        index = temp;
    }
    else {
        index = new Word[1];
        index[0] = obj;
    }
    size ++;
}

int List::contains(char * const &str) const {
    char * testable_word = nullptr;

    if (str) {
        for (int i = 0; i < size; i ++) {
            testable_word = index[i].get_data();
            if (strcmp(testable_word, str) == 0) {
                delete[] testable_word;
                return i;
            }
            delete[] testable_word;
        }
    }

    return size;
}

int List::contains(const Word &word) const {
    char * this_word = word.get_data();
    char * testable_word = nullptr;

    for (int i = 0; i < size; i ++) {
        testable_word = index[i].get_data();
        if (strcmp(this_word, testable_word) == 0) {
            delete[] testable_word;
            delete[] this_word;
            return i;
        }
        delete[] testable_word;
    }

    delete[] this_word;

    return size;
}

void List::sort() {
    Word temp;
    bool swapped = true;
    char * this_word = nullptr;
    char * that_word = nullptr;
    
    while (swapped) {
        swapped = false;
        for (int i = 0; i < size - 1; i ++) {
            this_word = index[i].get_data();
            that_word = index[i + 1].get_data();
            if (strcmp(this_word, that_word) > 0) {
                temp = index[i];
                index[i] = index[i + 1];
                index[i + 1] = temp;
                swapped = true;
            }
            delete[] this_word;
            delete[] that_word;
        }
    }
}

void List::print() const {
    char * temp = nullptr;
    for (int i = 0; i < size; i ++) {
        temp = index[i].get_data();
        std::cout << "Word: \"" << temp << "\" Count: " << index[i].get_count() << std::endl;
        delete[] temp;
    }
}