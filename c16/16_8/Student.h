#ifndef STUDENT_H
#define STUDENT_H
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Student {
    char firstName[101];
    char lastName[101];
    double gpa;
};


void loadValues(ifstream &inFile, Student studentList[], int &numStudents);
void printValues(Student studentList[], int numStudents);

#endif
