#pragma once
#include "list.h"

int main();

void welcome();

char menu();

char * get_name();

void erase(List &);

void add(List &);

void remove(List &);
void remove_name(List &);
void remove_quantity(List &);
void remove_price(List &);

void update(List &);
void update_name(List &);
void update_quantity(List &);
void update_price(List &);

void print(const List &);

void to_file(const List &);
