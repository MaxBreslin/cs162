#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct    node
{
     string    * data;
     node      * next;
     node() {
          next = nullptr;
          data = nullptr;
     }
     node(string data, node * next) {
          this->next = next;
          this->data = new string(data);
     }
     ~node() {
          if (data) delete data;
          next = nullptr;
          data = nullptr;
     }
};
int main();
void print(node *);
node * insert(node *&, string);
void erase(node *&);
