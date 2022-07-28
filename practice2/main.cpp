#include "main.h"

int main()
{
     char n1[] = "Doug Jones";
     char n2[] = "Henrietta Smyth III";
     student s1(n1, 3.4, 123456, true, 123.04);   // parm constructor
     student s2(n2, 4.5, 987654, true, 120.50);   // parm constructor
     std::cout << "S1: " << s1 << std::endl;
     std::cout << "S2: " << s2 << std::endl;
     
     return 0;
}
