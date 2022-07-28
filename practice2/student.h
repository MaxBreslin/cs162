#pragma once
#include <iostream>
#include <cstring>

class     student
{
     private:
     char                * name;
     float               * gpa;
     unsigned long int   * gnum;
     bool                * enrolled;
     double              * tuition;

     public:
     student();
     ~student();
     student(char *, float, unsigned long int, bool, double);
     friend std::ostream & operator << (std::ostream &, const student &);
};

