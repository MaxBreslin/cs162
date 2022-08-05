#include "main.h"

int main()
{
     char n1[] = "Doug Jones";
     char n2[] = "Henrietta Smyth III";
     student s1(n1, 3.4, 123456, true, 123.04);   // parm constructor
     student s2(n2, 4.5, 987654, true, 120.50);   // parm constructor
     student s3;                                  // default constructor
     student s4(s3);                              // copy constructor
     student s5(s2);                              // copy constructor

     std::cout << "S1: " << s1 << std::endl;
     std::cout << "S2: " << s2 << std::endl;
     std::cout << "S3: " << s3 << std::endl;
     std::cout << "S4: " << s4 << std::endl;
     std::cout << "S5: " << s5 << std::endl;
     
     return 0;
}
