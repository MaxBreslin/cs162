#include "main.h"

int main()
{
     std::ifstream  file("inputp.txt");
     ::data    list[MAX_ITEMS]
          ,    buffer
     ;
     int       size      = 0
          ,    capacity  = MAX_ITEMS
     ; 

     while(file.good() == true && file.peek() != EOF) 
     {
          file >> buffer;
          ::data    copybuf(buffer);
          if (file.good() == true && size < capacity)
          {
               list[size++] = copybuf;
          } 
     }

     for(auto idx = 0; idx < size; idx++) {
          std::cout << list[idx] << std::endl;
     }
     std::cout << "\n[done]" << std::endl;

     file.clear();
     file.close();

     return 0;
}
