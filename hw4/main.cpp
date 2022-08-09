//******************************************************************************
// Author: Max Breslin
// Assignment: Homework 3
// Date: 7/19/2022
// Description: This program will prompt the user to input a filename. It will
//              then read the contents of the file and append every character
//              to a single dynamic c-string. This string will be tokenized and
//              each individual word will be appended to a list of words.
//              Duplicates are not appended and the word object holding the
//              pointer to the duplicate word is updated accordingly (the count 
//              member variable is incremented). After every token has been
//              read, the final list will be printed.
//              
//
// Input: The filename as a string and a file containing space-separated 
//        and newline-separated words
// Output: A complete list of distinct words and their frequencies in the file
// Sources: None
//******************************************************************************

#include "main.h"

int main() {
    List list;
    char * file_name = nullptr;
    std::ifstream infile;
    char * total_string = nullptr;
    char * token = nullptr;
    Node * found_node = nullptr;

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
    infile.close();
    
    token = strtok(total_string, " ");
    while (token) {
        if ((found_node = list.find(token))) {
            found_node->data->increment_count();
        }
        else {
            list.sorted_insert(Word(token));
        }

        token = strtok(nullptr, " ");
    }
    memset(total_string, 0, strlen(total_string));
    delete[] total_string;
    
    std::cout << list;

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

        // This corrects tokenization errors like "line
        //                                         hello"
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
