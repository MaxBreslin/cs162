#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>

const int MAX_CHARS = 30;

class Assignment {
public:
    Assignment();
    Assignment(const Assignment &obj);
    Assignment(const char name[], const char gnum[], int grade, double weight);
    ~Assignment();

    Assignment operator=(const Assignment &obj);

    int get_grade() const;
    float get_weight() const;

    void get_name(char name[]) const;

    void display() const;
    float print_grade() const;

private:
    char m_name[MAX_CHARS + 1];
    int m_grade;
    float m_weight;
    char m_gnum[MAX_CHARS + 1];
};