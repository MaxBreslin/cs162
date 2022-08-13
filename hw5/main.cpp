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

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);

    welcome();

    while ((option = menu()) != 1) {
        switch(option) {
            case 2:
                erase(list);
                break;
            case 3:
                add(list);
                break;
            case 4:
                remove(list);
                break;
            case 5:
                update(list);
                break;
            case 6:
                print(list);
                break;
            default:
                std::cout << "\033[;31m" << "?Invalid option." << "\033[0m" << std::endl;
                break;
        }
     }
     std::cout << "\033[;33m" << "[done]" << "\033[0m" << std::endl;
     return EXIT_SUCCESS;
}

void welcome() {
    std::cout << "Welcome to shopping list maintenance!" << std::endl;
}

char menu() {
    int option = 0;

    std::cout << std::endl
              << "Please enter one of the following options:" << std::endl
              << "1 - Quit the program" << std::endl
              << "2 - Erase all items from the list (resulting in an empty list)" << std::endl
              << "3 - Add an item to the list" << std::endl
              << "4 - Remove an item from the list" << std::endl
              << "5 - Update an item in the list" << std::endl
              << "6 - Display all items in the list" << std::endl
              << "Enter option: ";

    std::cin >> option;
    std::cin.ignore(2, '\n');

    std::cout << std::endl;

    return option;
}

char * get_name() {
    char * name = nullptr;
    char * temp = nullptr;
    int size = 0;
    char byte = 0;

    while (std::cin.good() && std::cin.peek() != '\n') {
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

    return name;
}

void erase(List &list) {
    list.~List();
}

void add(List &list) {
    char * name = nullptr;
    unsigned int quantity = 0;
    float price = 0.0F;
    Item item;
    Node * node = nullptr;

    std::cout << "Enter the name of the item: ";
    name = get_name();

    std::cout << "Enter the quantity of the item: ";
    std::cin >> quantity;

    std::cout << "Enter the price of the item: ";
    std::cin >> price;

    item = Item(name, quantity, price);
    node = new Node(item);
    try {
        list.sorted_insert(node);
    }
    catch (std::runtime_error &e) {
        std::cout << std::endl << e.what() << std::endl;
        delete[] name;
        delete node;
        return;
    }
    std::cout << std::endl
              << "\033[;32m" << "Item \"" << name << "\" with quantity " << quantity
              << " at $" << price << " added successfully." << "\033[0m" << std::endl;
    delete[] name;
}

void remove(List &list) {
    int option = 0;
    std::cout << "Enter match criterion (1 for name, 2 for quantity, 3 for price): ";
    std::cin >> option;

    while (option < 1 || option > 3) {
        std::cout << "\033[;31m" << "?Invalid option." << "\033[0m" << std::endl 
                  << "Enter match criterion (1 for name, 2 for quantity, 3 for price): ";
        std::cin >> option;
    }
    std::cin.ignore(2, '\n');

    switch (option) {
        case 1:
            remove_name(list);
            break;
        case 2:
            remove_quantity(list);
            break;
        case 3:
            remove_price(list);
            break;
        default:
            std::cout << "\033[;31m" << "?Invalid option." << "\033[0m" << std::endl;
            break;
    }
}

void remove_name(List &list) {
    char * name = nullptr;

    std::cout << "Enter the name of the item: ";
    name = get_name();
    
    try {
        list.remove(name);
    }
    catch (std::runtime_error &e) {
        std::cout << std::endl << e.what() << std::endl;
        delete[] name;
        return;
    }
    std::cout << std::endl
              << "\033[;32m" << "Item \"" << name << "\" removed." << "\033[0m" << std::endl;
    delete[] name;
}

void remove_quantity(List &list) {
    unsigned int quantity = 0;

    std::cout << "Enter the quantity of the item: ";
    std::cin >> quantity;
    
    try {
        list.remove(quantity);
    }
    catch (std::runtime_error &e) {
        std::cout << std::endl << e.what() << std::endl;
        return;
    }
    std::cout << std::endl
              << "\033[;32m" << "All items with quantity " << quantity << " removed." << "\033[0m" << std::endl;
}

void remove_price(List &list) {
    float price = 0.0F;

    std::cout << "Enter the price of the item: ";
    std::cin >> price;
    
    try {
        list.remove(price);
    }
    catch (std::runtime_error &e) {
        std::cout << std::endl << e.what() << std::endl;
        return;
    }
    std::cout << std::endl
              << "\033[;32m" << "All items with price " << price << " removed." << "\033[0m" << std::endl;
}

void update(List &list) {
    int option = 0;
    std::cout << "Enter match criterion (1 for name, 2 for quantity, 3 for price): ";
    std::cin >> option;

    while (option < 1 || option > 3) {
        std::cout << "\033[;31m" << "?Invalid option." << "\033[0m" << std::endl 
                  << "Enter match criterion (1 for name, 2 for quantity, 3 for price): ";
        std::cin >> option;
    }
    std::cin.ignore(2, '\n');

    switch (option) {
        case 1:
            update_name(list);
            break;
        case 2:
            update_quantity(list);
            break;
        case 3:
            update_price(list);
            break;
        default:
            std::cout << "\033[;31m" << "?Invalid option." << "\033[0m" << std::endl;
            break;
    }
}
void update_name(List &list) {
    char * name = nullptr;
    char * new_name = nullptr;

    std::cout << "Enter the name to update: ";
    name = get_name();
    std::cout << "Enter the new name of the item: ";
    new_name = get_name();
    
    try {
        list.update(name, new_name);
    }
    catch (std::runtime_error &e) {
        std::cout << std::endl << e.what() << std::endl;
        delete[] name;
        delete[] new_name;
        return;
    }
    std::cout << std::endl
              << "\033[;32m" << "Item \"" << name << "\" is now \"" << new_name << "\"." << "\033[0m" << std::endl;
    delete[] name;
    delete[] new_name;
}
void update_quantity(List &list) {
    unsigned int quantity = 0;
    unsigned int new_quantity = 0;

    std::cout << "Enter the quantity to update: ";
    std::cin >> quantity;
    std::cout << "Enter the new quantity: ";
    std::cin >> new_quantity;
    
    try {
        list.update(quantity, new_quantity);
    }
    catch (std::runtime_error &e) {
        std::cout << std::endl << e.what() << std::endl;
        return;
    }
    std::cout << std::endl
              << "\033[;32m" << "All items with quantity " << quantity << " now have quantity " << new_quantity << "." << "\033[0m" << std::endl;
}
void update_price(List &list) {
    float price = 0.0F;
    float new_price = 0.0F;

    std::cout << "Enter the price to update: ";
    std::cin >> price;
    std::cout << "Enter the new price: ";
    std::cin >> new_price;

    try {
        list.update(price, new_price);
    }
    catch (std::runtime_error &e) {
        std::cout << std::endl << e.what() << std::endl;
        return;
    }
    std::cout << std::endl
              << "\033[;32m" << "All items with price $" << price << " now have price $" << new_price << "." << "\033[0m" << std::endl;
}

void print(const List &list) {
    list.print();
}
