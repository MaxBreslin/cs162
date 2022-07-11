#pragma once

#include "assignment.h"

const int MAX_SUBMISSIONS = 10;
const int NUM_FILES = 3;
const int NUM_OTHER_OPTIONS = 3;

class Student {
public:
    Student();
    Student(const Student &obj);
    Student(const char name[], const char gnum[]);
    ~Student();

    Student operator=(const Student &obj);

    // These two functions simply set and get the m_name instance variable.
    void set_name(const char name[]);
    void get_name(char name[]) const;

    // set_gnum performs a check to make sure the gnum is valid.
    // get_gnum simply copies the gnum to the passed in char array.
    void set_gnum(const char gnum[]);
    void get_gnum(char gnum[]) const;

    // get_grade simply gets the m_grade instance variable.
    char get_grade() const;

    // calculate_grade calculates the grade of the student
    // and updates the m_grade instance variable.
    void calculate_grade();

    // These two functions simply get the m_size and m_capacity instance
    // variables, respectively.
    int get_size() const;
    int get_capacity() const;

    // add_submission performs a check to make sure the student
    // has space to store another submission and then add the submission.
    void add_submission(Assignment submission);

    // remove_submission removes the first submission with the
    // specified name.
    void remove_submission(const char assignment[]);

    // display displays the student's name, gnum, grade, and
    // assignments.
    void display() const;

    // Very similar to display, but has different formatting.
    void print_grade() const;

private:
    char m_name[MAX_CHARS + 1];
    char m_gnum[MAX_CHARS + 1];
    char m_grade;
    Assignment m_submissions[MAX_SUBMISSIONS];
    int m_size, m_capacity;
};

// load prompts the user to input file names and then calls 
// load_files with the correct file objects.
void load(Student roster[], int &size, const int &capacity);

// load_files calls the below loading functions with the correct 
// file objects and initializes each student's grade.
void load_files(std::ifstream &name_file, std::ifstream &gnum_file, 
                std::ifstream &assignment_file, Student roster[], 
                int &size, const int &capacity);
void load_names(std::ifstream &name_file, Student roster[], 
                const int &size);
void load_gnums(std::ifstream &gnum_file, Student roster[], int &size, 
                const int &capacity);
void load_assignments(std::ifstream &assignment_file, Student roster[], 
                      const int &size);

// display calls the display function for each student and
// formats the output.
void display(const Student roster[], const int &size);

// grade prompts the user to input a gnum or name and then calls
// print_grade with the correct student.
void grade(const Student roster[], const int &size);

// gpa prints the average GPA of the students in the roster.
void gpa(const Student roster[], const int &size);

// pct prints stats about the student grades.
void pct(const Student roster[], const int &size);

// remove prompts the user to choose between removing a student
// or an assignment and then calls the appropriate function.
void remove(Student roster[], int &size);

// remove_student removes the student with the specified name from
// the roster.
void remove_student(Student roster[], int &size, const char name[]);

// remove_assignment finds the student with the specified name and calls
// that student's remove_submission function with the specified assignment.
void remove_assignment(Student roster[], const int &size, const char student_name[], 
                       const char assignment_name[]);

// add prompts the user to choose between adding a student or an assignment
// and then calls the appropriate function.
void add(Student roster[], int &size, const int &capacity);

// add_student adds the student with the specified name and gnum to the roster.
void add_student(Student roster[], int &size, const int &capacity, const char name[], 
                 const char gnum[]);

// add_assignment finds the student with the specified name and calls
// that student's add_submission function with the specified assignment.
void add_assignment(Student roster[], const int &size, const char student_name[], 
                    const char assignment_name[], const int &grade, const float &weight);

// assignment_or_student is a helper function for the add and remove functions
// that opens a small menu and returns the user's choice
char assignment_or_student();
