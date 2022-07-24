#include "data.h"

// Print a variable of type "data"
void print(data source) 
{
     std::cout << "Student: " << source.name
          << " (G";
     std::cout.width(8);
     std::cout.fill('0');
     std::cout << std::right << source.gnum;
     std::cout.width(1);
     std::cout << " ";
     if (source.enrolled == false) {
         std::cout << "Not ";
     }
     std::cout << "Enrolled) GPA: ";
     std::cout.precision(3);
     std::cout << source.gpa;
     std::cout << " Tuition: $";
     std::cout.precision(5);
     std::cout << source.tuition;
     std::cout << std::endl;
}

// Input values from cin and store in variable of type 'data'
data load()
{
     data      result;
     char      input[SIZE + 1]     = {0};
     std::cout << "Enter student's name (max "
          << SIZE
          << " characters): "
          ;
     std::cin.getline(input,SIZE);
     strncpy(result.name,input,SIZE);
     std::cout << "Enter student's G-Number(int): ";
     std::cin >> result.gnum;
     std::cin.ignore(8192,'\n');
     std::cout << "Is student enrolled this term? (Y/N): ";
     std::cin.getline(input,SIZE);
     if (toupper(input[0]) == 'Y')
          result.enrolled = true;
     else
          result.enrolled = false;
     std::cout << "Enter GPA (float X.YY): ";
     std::cin >> result.gpa;
     std::cin.ignore(8192,'\n');
     std::cout << "Enter current tuition (double XXX.YY): ";
     std::cin >> result.tuition;
     std::cin.ignore(8192,'\n');

     return result;
}
