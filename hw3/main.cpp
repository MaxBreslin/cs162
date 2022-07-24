#include "main.h"

int main() {
    List list;
    char * file_name = nullptr;
    std::ifstream infile;
    char * total_string = nullptr;
    char * token = nullptr;
    int word_index = 0;

    file_name = get_fname();
    infile.open(file_name);
    delete[] file_name;
    while (!infile.is_open()) {
        std::cout << "File not found" << std::endl;
        file_name = get_fname();
        infile.open(file_name);
        delete[] file_name;
    }

    total_string = create_string(infile);
    
    token = strtok(total_string, " ");
    while (token) {
        if ((word_index = list.contains(token)) != list.get_size()) {
            list.get_index(word_index).increment_count();
        }
        else {
            list.insert(Word(token));
        }

        token = strtok(nullptr, " ");
    }
    memset(total_string, 0, strlen(total_string));
    delete[] total_string;
    

    list.sort();
    list.print();

    return 0;
}

char * get_fname() {
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
    return file_name;
}

char * create_string(std::ifstream &infile) {
    char * total_string = nullptr;
    char * temp = nullptr;
    int size = 0;
    char byte = 0;
    while(infile.good() && infile.peek() != EOF) {
        byte = infile.get();
        if (byte == '\n') {
            byte = ' ';
        }
        if (total_string) {
            temp = new char[size + 2];
            memset(temp, 0, size + 2);
            strcpy(temp, total_string);
            memset(total_string, 0, size + 1);
            delete[] total_string;
            total_string = temp;
            total_string[size ++] = byte;
        } 
        else {
            total_string = new char[size + 2];
            memset(total_string, 0, size + 2);
            total_string[0] = byte;
            size = 1;
        }
    }
    return total_string;
}
