#pragma once
#include <iostream>
#include <cstring>

const int SIZE = 100;

struct    data
{
          char                name[SIZE + 1];
          float               gpa;
          unsigned long int   gnum;
          bool                enrolled;
          double              tuition;
};

data load();
void print(data);
