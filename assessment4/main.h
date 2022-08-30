#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct    node
{
     string    * data;
     node      * next;
     node() {
          next = nullptr;
          data = nullptr;
     }
     node(string value, node * head) {
          data = new string(value);
          next = head;
     }
     ~node() {
          if (data) delete data;
          next = nullptr;
          data = nullptr;
     }
};
int main();
node * print(node *);
node * insert(node *, string);
node * erase(node *);
node * update(node *, string, string);

