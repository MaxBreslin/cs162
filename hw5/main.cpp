//******************************************************************************
// Author: Max Breslin
// Assignment: Homework 5
// Date: 8/12/2022
// Description: This program will open an interactive menu, allowing a user to 
//              add to, remove from, update, and print a list of items. This 
//              list will be sorted alphabetically and unique. It will be a
//              linked list of node structs, each containing a pointer to an
//              item object.
//
//              
// Input: Menu options, file names, and item information
// Output: List information to either std::cout or a specified file
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
            case 7:
                to_file(list);
                break;
            default:
                std::cout << RED << "Invalid option" << RESET << std::endl;
                return EXIT_FAILURE;
        }
     }
     std::cout << YELLOW << "[done]" << RESET << std::endl;
     return EXIT_SUCCESS;
}

void welcome() {
    std::cout << "Welcome to shopping list maintenance!" << std::endl;
}

int menu() {
    int option = 0;

    std::cout << std::endl
              << "Please enter one of the following options:" << std::endl
              << "1 - Quit the program" << std::endl
              << "2 - Erase all items from the list (resulting in an empty list)" << std::endl
              << "3 - Add an item to the list" << std::endl
              << "4 - Remove an item from the list" << std::endl
              << "5 - Update an item in the list" << std::endl
              << "6 - Display all items in the list" << std::endl
              << "7 - Output the list to a file" << std::endl
              << "Enter option: ";

    std::cin >> option;
    while (std::cin.fail() || option < 1 || option > 7) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << RED << "Invalid option" << RESET << std::endl;
        std::cout << "Enter option: ";
        std::cin >> option;
    }
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
    std::cout << GREEN << "List successfully erased" << RESET << std::endl;
}

void add(List &list) {
    char * name = nullptr;
    unsigned int quantity = 0;
    float price = 0.0F;
    Item item;
    Node * node = nullptr;

    std::cout << "Enter the name of the item: ";
    name = get_name();
    name[0] = toupper(name[0]);

    std::cout << "Enter the quantity of the item: ";
    std::cin >> quantity;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << RED << "Invalid option" << RESET << std::endl;
        std::cout << "Enter the quantity of the item: ";
        std::cin >> quantity;
    }

    std::cout << "Enter the price of the item: ";
    std::cin >> price;
    while (std::cin.fail() || price < 0.0F) {
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << RED << "Invalid option" << RESET << std::endl;
        std::cout << "Enter the price of the item: ";
        std::cin >> price;
    }

    item = Item(name, quantity, price);
    node = new Node(item);
    try {
        list.sorted_unique_insert(node);
    }
    catch (const char * &e) {
        std::cout << std::endl << e << std::endl;
        delete[] name;
        delete node;
        return;
    }
    std::cout << std::endl
              << GREEN << "Item \"" << name << "\" with quantity " << quantity
              << " at $" << price << " added successfully" << RESET << std::endl;
    delete[] name;
}

void remove(List &list) {
    int option = 0;
    std::cout << "Enter match criterion (1 for name, 2 for quantity, 3 for price): ";
    std::cin >> option;

    while (option < 1 || option > 3) {
        std::cout << RED << "Invalid option" << RESET << std::endl 
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
            std::cout << RED << "Invalid option" << RESET << std::endl;
            break;
    }
}

void remove_name(List &list) {
    char * name = nullptr;

    std::cout << "Enter the name of the item: ";
    name = get_name();
    name[0] = toupper(name[0]);
    
    try {
        list.remove(name);
    }
    catch (const char * &e) {
        std::cout << std::endl << e << std::endl;
        delete[] name;
        return;
    }
    std::cout << std::endl
              << GREEN << "Item \"" << name << "\" removed" << RESET << std::endl;
    delete[] name;
}

void remove_quantity(List &list) {
    unsigned int quantity = 0;

    std::cout << "Enter the quantity of the item: ";
    std::cin >> quantity;
    
    try {
        list.remove(quantity);
    }
    catch (const char * &e) {
        std::cout << std::endl << e << std::endl;
        return;
    }
    std::cout << std::endl
              << GREEN << "All items with quantity " << quantity << " removed" << RESET << std::endl;
}

void remove_price(List &list) {
    float price = 0.0F;

    std::cout << "Enter the price of the item: ";
    std::cin >> price;
    
    try {
        list.remove(price);
    }
    catch (const char * &e) {
        std::cout << std::endl << e << std::endl;
        return;
    }
    std::cout << std::endl
              << GREEN << "All items with price " << price << " removed" << RESET << std::endl;
}

void update(List &list) {
    int option = 0;
    std::cout << "Enter match criterion (1 for name, 2 for quantity, 3 for price): ";
    std::cin >> option;

    while (option < 1 || option > 3) {
        std::cout << RED << "Invalid option" << RESET << std::endl 
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
            std::cout << RED << "Invalid option" << RESET << std::endl;
            break;
    }
}
void update_name(List &list) {
    char * name = nullptr;
    char * new_name = nullptr;

    std::cout << "Enter the name to update: ";
    name = get_name();
    name[0] = toupper(name[0]);
    std::cout << "Enter the new name of the item: ";
    new_name = get_name();
    new_name[0] = toupper(new_name[0]);
    
    try {
        list.update(name, new_name);
    }
    catch (const char * &e) {
        std::cout << std::endl << e << std::endl;
        delete[] name;
        delete[] new_name;
        return;
    }
    std::cout << std::endl
              << GREEN << "Item \"" << name << "\" is now \"" << new_name << "\"" << RESET << std::endl;
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
    catch (const char * &e) {
        std::cout << std::endl << e << std::endl;
        return;
    }
    std::cout << std::endl
              << GREEN << "All items with quantity " << quantity << " now have quantity " << new_quantity << "" << RESET << std::endl;
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
    catch (const char * &e) {
        std::cout << std::endl << e << std::endl;
        return;
    }
    std::cout << std::endl
              << GREEN << "All items with price $" << price << " now have price $" << new_price << "" << RESET << std::endl;
}

void print(const List &list) {
    list.print(std::cout);
}

void to_file(const List &list) {
    std::ofstream file;
    char * filename = nullptr;

    file.setf(std::ios::fixed, std::ios::floatfield);
    file.precision(2);

    std::cout << "Enter filename (all contents will be overwritten): ";
    filename = get_name();
    file.open(filename);
    if (!file.is_open()) {
        std::cout << RED << "Error opening file" << RESET << std::endl;
        delete[] filename;
        return;
    }
    list.print(file);
    std::cout << std::endl
              << GREEN << "List written to \"" 
              << filename << "\"" << RESET << std::endl;
    delete[] filename;
    file.close();
}