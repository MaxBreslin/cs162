#include "student.h"
// Parameter Constructor
student::student(   char * name, 
                    float gpa, 
                    unsigned long int gnum, 
                    bool enrolled, 
                    double tuition) : student::student()
{
     // *** DO NOT CHANGE CODE BEFORE THIS LINE
     this->name = new char[std::strlen(name) + 1];
     std::strcpy(this->name, name);

     this->gpa = new float(gpa);
     this->gnum = new unsigned long int(gnum);
     this->enrolled = new bool(enrolled);
     this->tuition = new double(tuition);

}

// **** DO NOT CHANGE CODE AFTER THIS LINE

// Default Constructor
student::student() {
     name      = nullptr;
     gpa       = nullptr;
     gnum      = nullptr;
     enrolled  = nullptr;
     tuition   = nullptr;
}

//Destructor for practice assessment
student::~student()
{
     delete [] name;
     delete gpa;
     delete gnum;
     delete enrolled;
     delete tuition;
}

std::ostream & operator << (std::ostream & out, const student & source)
{
     out  <<  "Name: " << source.name << " "
          <<  "GPA: " << *source.gpa << " "
          << "GNUM: G" << *source.gnum << " "
          << "Enrolled: ";
     if (*source.enrolled == true) out << "Y";
          else out << "N";
     out << " ";
     out << "Tuition: $";
     out << static_cast<int>(static_cast<int>(*source.tuition * 100.00) / 100);
     out << ".";
     if (static_cast<int>(static_cast<int>(*source.tuition * 100.00) % 100) < 10)
          out << "0";
     out << static_cast<int>(static_cast<int>(*source.tuition * 100.00) % 100);
     return out;
}
