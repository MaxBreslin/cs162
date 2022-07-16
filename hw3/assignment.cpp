#include "assignment.h"

using namespace std;

Assignment::Assignment() {
    memset(m_name, 0, MAX_CHARS + 1);
    memset(m_gnum, 0, MAX_CHARS + 1);
    m_grade = 0;
    m_weight = 0.0F;
}

Assignment::Assignment(const Assignment &obj) {
    memset(m_name, 0, MAX_CHARS + 1);
    memset(m_gnum, 0, MAX_CHARS + 1);
    strcpy(m_name, obj.m_name);
    strcpy(m_gnum, obj.m_gnum);
    m_grade = obj.m_grade;
    m_weight = obj.m_weight;
}

Assignment::Assignment(const char name[], const char gnum[], 
                       int grade, double weight) {
    memset(m_name, 0, MAX_CHARS + 1);
    memset(m_gnum, 0, MAX_CHARS + 1);
    strcpy(m_name, name);
    strcpy(m_gnum, gnum);
    m_grade = grade;
    m_weight = weight;
}

Assignment::~Assignment() {
    memset(m_name, 0, MAX_CHARS + 1);
    memset(m_gnum, 0, MAX_CHARS + 1);
    m_grade = 0;
    m_weight = 0.0F;
}

Assignment Assignment::operator=(const Assignment &obj) {
    if (this != &obj) {
        memset(m_name, 0, MAX_CHARS + 1);
        memset(m_gnum, 0, MAX_CHARS + 1);
        strcpy(m_name, obj.m_name);
        strcpy(m_gnum, obj.m_gnum);
        m_grade = obj.m_grade;
        m_weight = obj.m_weight;
    }
    
    return *this;
}

void Assignment::get_name(char name[]) const {
    memset(name, 0, MAX_CHARS + 1);
    strcpy(name, m_name);
}

int Assignment::get_grade() const {
    return m_grade;
}
float Assignment::get_weight() const {
    return m_weight;
}

void Assignment::display() const {
    cout.precision(3);
    cout << m_grade << " (" << m_weight * 100 << "%) " << m_name << endl;
}

float Assignment::print_grade() const {
    float total = m_grade * m_weight;
    cout.precision(3);
    cout << m_name << " Weight: " << m_weight * 100 << "%  Score: " 
         << m_grade << " Contribution: " << total << endl;
    return total;
}
