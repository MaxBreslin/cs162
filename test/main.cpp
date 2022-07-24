#include <iostream>

using namespace std;

class Simple {
public:
    Simple();
    Simple(int set);
    int get_int() {return m_int;}
    void set_int(int set) {m_int = set;}
private:
    int m_int;
};

int main() {
    int * p_test = new int;
    *p_test = 1;
    cout << p_test << endl;
    cout << *p_test << endl;

    char * b_char = new char;
    *b_char = 'a';
    cout << b_char << endl;
    cout << *b_char << endl;

    return 0;
}

Simple::Simple() {
    m_int = 0;
}
Simple::Simple(int set) {
    m_int = set;
}