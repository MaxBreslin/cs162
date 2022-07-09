#include <iostream>

using namespace std;

class Test {
public:
    Test();
    Test(const Test &passed);
    int get_int(void) const { return m_test_int; }
    void set_int(int val) { m_test_int = val; }
private:
    int m_test_int;
};

Test::Test() {
    m_test_int = 5;
}

Test::Test(const Test &passed) {
    m_test_int = passed.m_test_int;
}

int main() {
    Test test1;
    test1.set_int(10);
    Test test2(test1);
    test1.set_int(20);
    cout << test1.get_int() << "\n";
    cout << test2.get_int() << "\n";
    return 0;
}