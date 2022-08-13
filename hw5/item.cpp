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

void Item::print() const {
    std::cout << name << ": " << quantity << " @ $" << price << std::endl;
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
unsigned int Item::get_quantity() {
    return quantity;
}
float Item::get_price() {
    return price;
}

