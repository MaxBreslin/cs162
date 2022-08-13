//******************************************************************************
// Author: Max Breslin
// Assignment: Homework 5
// Date: 8/12/2022
// Description: This program will prompt the user to input a filename. It will
//              then read the contents of the file and append every character
//              to a single dynamic c-string. This string will be tokenized and
//              each individual word will be inserted alphabetically to a dynamic 
//              singly linked list of words. Duplicates are not appended and
//              the word object holding the pointer to the duplicate word is
//              updated accordingly (the count member variable is incremented).
//              After every token has been read, the final list will be printed.
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
    int option = 0;

    welcome();

    while ((option = menu()) != 1) {
        switch(option) {
            case 2:
                erase(list);
                break;
            case 3:
                add(list);
                break;
            case 6:
                print(list);
                break;
            default:
                std::cout << "Invalid option." << std::endl;
                break;
        }
     }
     std::cout << "[done]" << std::endl;
     return EXIT_SUCCESS;
}

void welcome() {
    std::cout << "Welcome to shopping list maintenance!" << std::endl;
}

char menu() {
    int option = 0;

    std::cout << "Please enter one of the following options:" << std::endl
              << "1 - Quit the program" << std::endl
              << "2 - Erase all items from the list (resulting in an empty list)" << std::endl
              << "3 - Add an item to the list" << std::endl
              << "4 - Remove an item from the list" << std::endl
              << "5 - Update an item in the list" << std::endl
              << "6 - Display all items in the list" << std::endl
              << "Enter option: ";

    std::cin >> option;
    std::cin.ignore(2, '\n');
    
    return option;
}

void erase(List &list) {
    list.~List();
}

void add(List &list) {
    char * name = nullptr;
    char * temp = nullptr;
    int size = 0;
    char byte = 0;
    unsigned int quantity = 0;
    float price = 0.0F;
    Item item;
    Node * node = nullptr;

    std::cout << "Enter the name of the item: ";

    while(std::cin.good() && std::cin.peek() != '\n') {
        byte = std::cin.get();
        if (name) {
            temp = new char[size + 2];
            memset(temp, 0, size + 2);
            strcpy(temp, name);
            memset(name, 0, size + 1);
            delete[] name;
            name = temp;
            name[size ++] = byte;
        } 
        else {
            name = new char[size + 2];
            memset(name, 0, size + 2);
            name[0] = byte;
            size = 1;
        }
    }
    std::cin.ignore(2, '\n');
    std::cin.clear();

    std::cout << "Enter the quantity of the item: ";
    std::cin >> quantity;

    std::cout << "Enter the price of the item: ";
    std::cin >> price;

    item = Item(name, quantity, price);
    node = new Node(item);
    delete[] name;
    try {
        list.sorted_insert(node);
    }
    catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        delete node;
        return;
    }
    
}

void print(const List &list) {
    list.print();
}
