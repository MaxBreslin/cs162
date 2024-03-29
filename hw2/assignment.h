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
    Assignment(const char name[], const char gnum[], 
               int grade, double weight);
    ~Assignment();

    Assignment operator=(const Assignment &obj);

    // These three functions simply get the m_grade, m_weight,
    // and m_name instance variables, respectively.
    int get_grade() const;
    float get_weight() const;
    void get_name(char name[]) const;
    
    // display formats the assignment data and displays it.
    void display() const;

    // Very similar to display, but has different formatting.
    float print_grade() const;

private:
    char m_name[MAX_CHARS + 1];
    int m_grade;
    float m_weight;
    char m_gnum[MAX_CHARS + 1];
};
