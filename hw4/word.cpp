#include "word.h"

Word::Word() {
    data = nullptr;
    count = 0;
}

Word::Word(const Word &obj) {
    if (obj.data) {
        data = new char[strlen(obj.data) + 1];
        strcpy(data, obj.data);
        count = obj.count;
    }
    else {
        data = nullptr;
        count = 0;
    }
}

Word::Word(char * const &str) {
    if (str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        count = 1;
    }
    else {
        data = nullptr;
        count = 0;
    }
}

Word::~Word() {
    if (data) {
        memset(data, 0, strlen(data));
        delete[] data;
        data = nullptr;
    }
    count = 0;
}

Word & Word::operator=(const Word &obj) {
    if (this != &obj) {
        if (data) {
            memset(data, 0, strlen(data));
            delete[] data;
        }
        if (obj.data) {
            data = new char[strlen(obj.data) + 1];
            strcpy(data, obj.data);
            count = obj.count;
        }
        else {
            data = nullptr;
            count = 0;
        }
    }
    return *this;
}

std::ostream & operator<<(std::ostream &out, const Word &obj) {
    out << obj.data;
    return out;
}
std::istream & operator>>(std::istream &in, Word &obj) {
    delete obj.data;
    
    char * file_name = nullptr;
    char * temp = nullptr;
    int size = 0;
    char byte = 0;

    std::cout << "Enter input file name: ";
    while(std::cin.good() && std::cin.peek() != '\n') {
        byte = std::cin.get();
        if (file_name) {
            temp = new char[size + 2];
            memset(temp, 0, size + 2);
            strcpy(temp, file_name);
            memset(file_name, 0, size + 1);
            delete[] file_name;
            file_name = temp;
            file_name[size ++] = byte;
        } 
        else {
            file_name = new char[size + 2];
            memset(file_name, 0, size + 2);
            file_name[0] = byte;
            size = 1;
        }
    }
    std::cin.ignore(2, '\n');
    std::cin.clear();
    return in;
}

int Word::get_count() const {
    return count;
}

void Word::set_data(char * const &str) {
    if (str) {
        if (data) {
            memset(data, 0, strlen(data));
            delete[] data;
        }
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        count = 1;
    }
    else {
        if (data) {
            memset(data, 0, strlen(data));
            delete[] data;
            data = nullptr;
        }
        count = 0;
    }
}

char * Word::get_data() const {
    char * str = nullptr;
    if (data) {
        str = new char[strlen(data) + 1];
        memset(str, 0, strlen(data) + 1);
        strcpy(str, data);
    }
    return str;
}

void Word::increment_count() {
    count ++;
}