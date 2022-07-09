#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

const int MAX_CHARS = 30;

struct Student {
    char name[MAX_CHARS + 1];
    char gnum[MAX_CHARS + 1];
    char grade[MAX_CHARS + 1]; 
};

// init_student returns a Student struct with members containing all zeros.
Student init_student();

// load loads the data from the specified file into the Student struct array.
void load(std::fstream &file, Student roster[], int &size, int &capacity);

// display displays the data contained in the Student struct array.
void display(Student roster[], int size);

// gpa calculates and displays the mean GPA of every student in the Student struct array.
void gpa(Student roster[], int size);

// pct calculates and displays the percentage of students who have a "complete", "passing", 
// "non-passing", and "auditing" grade.
void pct(Student roster[], int size);
