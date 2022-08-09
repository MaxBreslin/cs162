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
    out << '"' << obj.data << "\" Count: " << obj.count << std::endl;
    return out;
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

bool operator>(const Word &lhs, const Word &rhs) {
    char * temp_rhs = rhs.get_data();
    char * temp_lhs = lhs.get_data();
    bool result = 0;
    if (strcmp(temp_lhs, temp_rhs) > 0) {
        result = 1;
    }
    delete[] temp_rhs;
    delete[] temp_lhs;
    return result;
}

bool operator==(const Word &lhs, const Word &rhs) {
    char * temp_rhs = rhs.get_data();
    char * temp_lhs = lhs.get_data();
    bool result = 0;
    if (strcmp(temp_lhs, temp_rhs) == 0) {
        result = 1;
    }
    delete[] temp_rhs;
    delete[] temp_lhs;
    return result;
}
bool operator==(const Word &lhs, const char * const &rhs) {
    char * temp_lhs = lhs.get_data();
    bool result = 0;
    if (strcmp(temp_lhs, rhs) == 0) {
        result = 1;
    }
    delete[] temp_lhs;
    return result;
}
bool operator==(const char * const &lhs, const Word &rhs) {
    return rhs == lhs;
}

bool operator>=(const Word &lhs, const Word &rhs) {
    return (lhs > rhs || lhs == rhs);
}