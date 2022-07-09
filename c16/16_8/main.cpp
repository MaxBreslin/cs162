#include <iostream>
#include <cstring>
#include <fstream>

#include "Student.h"
using namespace std;

int main() {
 
   Student studentList[50];
   int numStudents = 0;
   ifstream inFile;
   
   inFile.open("students.txt");
   loadValues(inFile, studentList, numStudents);
   printValues(studentList, numStudents);
   
   return 0;
}

