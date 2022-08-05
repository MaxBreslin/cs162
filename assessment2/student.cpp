#include "student.h"

// Destructor
student::~student() {
     if (name) {
          memset(name, 0, strlen(name));
          delete[] name;
          name = nullptr;
     }
     delete gpa;
     gpa = nullptr;
     delete gnum;
     gnum = nullptr;
     delete enrolled;
     enrolled = nullptr;
     delete tuition;
     tuition = nullptr;

}

// Copy Constructor
student::student(const student & source) : student::student()
{
     name = nullptr;
     gpa = nullptr;
     gnum = nullptr;
     enrolled = nullptr;
     tuition = nullptr;
     
     if (source.name) {
          name = new char[strlen(source.name) + 1];
          strcpy(name, source.name);
     }
     if (source.gpa) {
          gpa = new float(*source.gpa);
     }
     if (source.gnum) {
          gnum = new unsigned long int(*source.gnum);
     }
     if (source.enrolled) {
          enrolled = new bool(*source.enrolled);
     }
     if (source.tuition) {
          tuition = new double(*source.tuition);
     }
}

// *** DO NOT CHANGE CODE AFTER THIS LINE ***

// Default Constructor
student::student() {
     name      = nullptr;
     gpa       = nullptr;
     gnum      = nullptr;
     enrolled  = nullptr;
     tuition   = nullptr;
}

// Parameter Constructor
student::student(char * name, float gpa, unsigned long int gnum, bool enrolled, double tuition) : student::student()
{
     this->name     = new char[strlen(name) + 1]{0};
     strcpy(this->name,name);
     this->gpa      = new float(gpa);
     this->gnum     = new unsigned long int(gnum);
     this->enrolled = new bool(enrolled);
     this->tuition  = new double(tuition);
}

std::ostream & operator << (std::ostream & out, const student & source)
{
     out  <<   "Name: ";
     if (source.name != nullptr)
          out << source.name;
     else
          out << "-";
     out  <<  ", GPA: ";
     if (source.gpa != nullptr)
          out << *source.gpa;
     else
          out << "-";
     out  << ", GNUM: ";
     if (source.gnum != nullptr)
          out  << "G" << *source.gnum;
     else 
          out << "-";
     out  << ", Enrolled: ";
     if (source.enrolled != nullptr) {
          if (*source.enrolled == true) out << "Y";
               else out << "N";
     } else {
          out << "-";
     }
     out << ", Tuition: ";
     if (source.tuition != nullptr) { 
          out << "$" << static_cast<int>(static_cast<int>(*source.tuition * 100.00) / 100);
          out << ".";
          if (static_cast<int>(static_cast<int>(*source.tuition * 100.00) % 100) < 10)
               out << "0";
          out << static_cast<int>(static_cast<int>(*source.tuition * 100.00) % 100);
     } else {
          out << "-";
     }
     return out;
}
