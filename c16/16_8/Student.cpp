#include "Student.h"
using namespace std;

void loadValues(ifstream &inFile, Student studentList[], int &numStudents) {
    Student newStudent;
    while (!inFile.eof()) {
        inFile.getline(newStudent.firstName, 101, ';');
        inFile.getline(newStudent.lastName, 101, ';');
        inFile >> newStudent.gpa;
        inFile.ignore(5, '\n');
        studentList[numStudents] = newStudent;
        numStudents ++;
    }
}

void printValues(Student studentList[], int numStudents) {
    cout << fixed << showpoint << setprecision(1) << left;
    for (int i = 0; i < numStudents; i++) {
        cout << setw(15) << studentList[i].firstName << setw(15) << studentList[i].lastName << setw(3) << studentList[i].gpa << endl;
    }
}


