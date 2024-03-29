#include "item.h"

Item::Item() {
    name = nullptr;
    quantity = 0;
    price = 0.0F;
}
Item::Item(const Item &obj) {
    name = nullptr;
    quantity = 0;
    price = 0.0F;
    
    if (obj.name) {
        name = new char[strlen(obj.name) + 1];
        memset(name, 0, strlen(obj.name) + 1);
        strcpy(name, obj.name);
    }
    quantity = obj.quantity;
    price = obj.price;
}
Item::Item(const char * const &name) {
    this->name = new char[strlen(name) + 1];
    memset(this->name, 0, strlen(name) + 1);
    strcpy(this->name, name);
    quantity = 0;
    price = 0.0F;
}
Item::Item(const char * const &name, const unsigned int &quantity, const float &price) {
    this->name = nullptr;
    this->quantity = 0;
    this->price = 0.0F;
    
    if (name) {
        this->name = new char[strlen(name) + 1];
        memset(this->name, 0, strlen(name) + 1);
        strcpy(this->name, name);
    }
    this->quantity = quantity;
    this->price = price;
}
Item::~Item() {
    if (name) {
        delete[] name;
        name = nullptr;
    }
    quantity = 0;
    price = 0.0F;
}

Item & Item::operator=(const Item &obj) {
    if (this != &obj) {
        if (name) {
            delete[] name;
            name = nullptr;
        }
        quantity = 0;
        price = 0.0F;
        
        if (obj.name) {
            name = new char[strlen(obj.name) + 1];
            memset(name, 0, strlen(obj.name) + 1);
            strcpy(name, obj.name);
        }
        quantity = obj.quantity;
        price = obj.price;
    }
    return *this;
}

void Item::print(std::ostream &out) const {
    float total = quantity * price;
    std::cout << GREEN;
    out << "\"" << name << "\": "<< quantity << " at $" << price 
              << " ($" << total << " total)" << std::endl;
    std::cout << RESET;
}

void Item::set_name(const char * const &name) {
    if (this->name) {
        delete[] this->name;
        this->name = nullptr;
    }
    if (name) {
        this->name = new char[strlen(name) + 1];
        memset(this->name, 0, strlen(name) + 1);
        strcpy(this->name, name);
    }
}

char * Item::get_name() {
    if (!name) {
        return nullptr;
    }
    char * temp = new char[strlen(name) + 1];
    memset(temp, 0, strlen(name) + 1);
    strcpy(temp, name);
    return temp;
}
void Item::get_name(char * name) {
    if (this->name) {
        delete[] this->name;
    }
    if (!name) {
        this->name = nullptr;
        return;
    }
    this->name = new char[strlen(name) + 1];
    memset(this->name, 0, strlen(name) + 1);
    strcpy(this->name, name);
}

void Item::set_quantity(const unsigned int &quantity) {
    this->quantity = quantity;
}
unsigned int Item::get_quantity() {
    return quantity;
}

void Item::set_price(const float &price) {
    this->price = price;
}
float Item::get_price() {
    return price;
}

