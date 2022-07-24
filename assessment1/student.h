#pragma once
#include <iostream>
#include <cstring>
#include "main.h"

const int MAX_CHARS = 30;
class     student
{
     private:
     char                name[MAX_CHARS + 1];
     float               gpa;
     unsigned long int   gnum;
     bool                enrolled;
     double              tuition;

     public:
     student();
     ~student();
     student(const student &);
     student & operator = (const student &);

     void set_name(const char *);
     void set_gpa(const float &);
     void set_gnum(const unsigned long int &);
     void set_enrolled(const bool &);
     void set_tuition(const double &);
};

