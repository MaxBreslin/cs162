#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

#define MAX_CHAR 30

class     data
{
     private:
          char           type;
          char           prot[MAX_CHAR + 1];
          unsigned int   links;
          char           owner[MAX_CHAR + 1];
          char           group[MAX_CHAR + 1];
          unsigned int   blocks;
          char           month[MAX_CHAR + 1];
          unsigned int   day;
          unsigned int   year;
          char           time[MAX_CHAR + 1];
          char           name[MAX_CHAR + 1];

     public:
          data();
          ~data();
          data(const data &);
          data & operator = (const data &);

          friend std::ostream & operator << (std::ostream &, const data &);
          friend std::istream & operator >> (std::istream &, data &);
};

