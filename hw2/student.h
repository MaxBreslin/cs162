#pragma once

#include "assignment.h"

const int MAX_SUBMISSIONS = 10;

class Student {
public:
    Student();
    Student(const Student &obj);
    ~Student();

    Student operator=(const Student &obj);

    void set_name(const char name[]);
    void get_name(char name[]) const;

    void set_gnum(const char gnum[]);
    void get_gnum(char gnum[]) const;

    void set_grade(char grade);
    char get_grade() const;
    void calculate_grade();

    int get_size() const;
    int get_capacity() const;

    void add_submission(Assignment submission);
    void remove_submission(const char assignment[]);

    void display() const;
    void print_grade() const;

private:
    char m_name[MAX_CHARS + 1];
    char m_gnum[MAX_CHARS + 1];
    char m_grade;
    Assignment m_submissions[MAX_SUBMISSIONS];
    int m_size, m_capacity;
};


void load(std::ifstream &name_file, std::ifstream &gnum_file, std::ifstream &assignment_file, Student roster[], int &size, const int &capacity);

void load_names(std::ifstream &name_file, Student roster[], const int &size);
void load_gnums(std::ifstream &gnum_file, Student roster[], int &size, const int &capacity);
void load_assignments(std::ifstream &assignment_file, Student roster[], const int &size);

void display(const Student roster[], const int &size);
void grade(const Student roster[], const int &size, const char name_or_gnum[]);
void gpa(const Student roster[], const int &size);
void pct(const Student roster[], const int &size);
void remove(Student roster[], int &size);
void remove_student(Student roster[], int &size, const char name[]);
void remove_assignment(Student roster[], const int &size, const char student_name[], const char assignment_name[]);
void add(Student roster[], int &size, const int &capacity);
void add_student(Student roster[], int &size, const int &capacity, const char name[], const char gnum[]);
void add_assignment(Student roster[], const int &size, const char student_name[], const char assignment_name[], const int &grade, const float &weight);

char assignment_or_student();
