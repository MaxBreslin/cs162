#include "main.h"

int main()
{
     // data      temp = load();
     // print(temp);

// *** ADD CODE HERE
     student      s;
     char      input[SIZE + 1]     = {0};
     int temp_int;
     float temp_float;
     double temp_double;

     std::cout << "Enter student's name (max "
          << SIZE
          << " characters): "
          ;
     std::cin.getline(input,SIZE);
     s.set_name(input);
     std::cout << "Enter student's G-Number(int): ";
     std::cin >> temp_int;
     s.set_gnum(temp_int);
     std::cin.ignore(8192,'\n');
     std::cout << "Is student enrolled this term? (Y/N): ";
     std::cin.getline(input,SIZE);
     if (toupper(input[0]) == 'Y')
          s.set_enrolled(true);
     else
          s.set_enrolled(false);
     std::cout << "Enter GPA (float X.YY): ";
     std::cin >> temp_float;
     s.set_gpa(temp_float);
     std::cin.ignore(8192,'\n');
     std::cout << "Enter current tuition (double XXX.YY): ";
     std::cin >> temp_double;
     s.set_tuition(temp_double);
     std::cin.ignore(8192,'\n');
     

     return 0;
}
