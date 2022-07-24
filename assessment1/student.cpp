#include "student.h"

student::student() {
     memset(name,0,MAX_CHARS + 1);
     gpa       = 0.0;
     gnum      = 0;
     enrolled  = false;
     tuition   = 0.0;
}

student::~student() {
     memset(name,0,MAX_CHARS + 1);
     gpa       = 0.0;
     gnum      = 0;
     enrolled  = false;
     tuition   = 0.0;
}

student::student(const student & source) : student::student()
{
     strcpy(name,source.name);
     gpa       = source.gpa;
     gnum      = source.gnum;
     enrolled  = source.enrolled;
     tuition   = source.tuition;
}
student & student::operator = (const student & source)
{
     if (this != &source) {
          memset(name,0,MAX_CHARS + 1);
          gpa       = 0.0;
          gnum      = 0;
          enrolled  = false;
          tuition   = 0.0;
          strcpy(name,source.name);
          gpa       = source.gpa;
          gnum      = source.gnum;
          enrolled  = source.enrolled;
          tuition   = source.tuition;
     }
     return *this;
}

void student::set_name(const char * name)
{
     if (strlen(name) >= MAX_CHARS) {
          std::cout << "Only " << MAX_CHARS << " characters were used to update name." << std::endl;
          strncpy(this->name,name,MAX_CHARS);
          this->name[MAX_CHARS] = '\0';
     }
     else {
          strcpy(this->name,name);
     }
}

void student::set_gpa(const float &gpa)
{
     if (gpa < 0.0 || gpa > 4.0) {
          throw std::invalid_argument("GPA must be between 0.0 and 4.0.");
     }
     this->gpa = gpa;
}

void student::set_gnum(const unsigned long int &gnum)
{
     if (gnum < 10000000 || gnum > 99999999) {
        throw std::invalid_argument("Invalid G-Number");
     }
     this->gnum = gnum;
}

void student::set_enrolled(const bool &enrolled)
{
     this->enrolled = enrolled;
}

void student::set_tuition(const double &tuition)
{
     if (tuition < 0.0) {
          throw std::invalid_argument("Tuition cannot be negative.");
     }
     this->tuition = tuition;
}
