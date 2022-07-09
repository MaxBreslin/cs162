#include "student.h"

using namespace std;

Student init_student() {
    Student s;
    memset(s.name, 0, MAX_CHARS + 1);
    memset(s.gnum, 0, MAX_CHARS + 1);
    memset(s.grade, 0, MAX_CHARS + 1);
    return s;
}

void load(fstream &file, Student roster[], int &size, int &capacity) {
    Student s;
    s = init_student();
    while (file.getline(s.name, MAX_CHARS, ',') && file.getline(s.gnum, MAX_CHARS, ',') && file.getline(s.grade, MAX_CHARS, '\n')) {
        if (size == capacity) {
            break;
        }
        roster[size] = s;
        size ++;
        s = init_student();
    }
}

void display(Student roster[], int size) {
    for (int i = 0; i < size; i ++) {
        cout.width(2);
        cout << right << i << '.';
        cout.width(31);
        cout << roster[i].name;
        cout.width(11);
        cout << roster[i].gnum ;
        cout.width(6);
        cout << roster[i].grade << endl;
    }
}
void gpa(Student roster[], int size) {
    double sum = 0.0;
    int graded_students, aud_students = 0;

    for (int i = 0; i < size; i ++) {
        if (roster[i].grade[1] == 'U') { // check if student is auditing
            aud_students ++;
            continue;
        }
        switch (roster[i].grade[0]) {
            case 'A':
                sum += 4.0;
                break;
            case 'B':
                sum += 3.0;
                break;
            case 'C':
            case 'P':
                sum += 2.0;
                break;
            case 'D':
                sum += 1.0;
                break;
            default:
                break;
        }
    }

    graded_students = size - aud_students;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    cout << endl
         << "Average GPA for " << graded_students << " students is " << sum / graded_students << endl
         << aud_students << " students were auditing the class and did not have a grade" << endl
         << endl;
}

void pct(Student roster[], int size) {
    int not_passing, completions = 0, passing = 0, aud = 0;

    for (int i = 0; i < size; i ++) {
        if (roster[i].grade[1] == 'U') { // check if student is auditing
            aud ++;
            completions ++;
            continue;
        }
        switch (roster[i].grade[0]) {
            case 'A':
            case 'B':
            case 'C':
            case 'P':
                passing ++;
                completions ++;
                break;
            case 'D':
            case 'F':
            case 'N':
                completions ++;
                break;
            default:
                break;
        }
    }

    not_passing = size - aud - passing;

    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    cout.width(20);
    cout << endl << right << "Total Students: " << left;
    cout.width(3);
    cout << size << "(100.00%)" << endl << right;
    cout.width(20);
    cout << "Total Completions: " << left;
    cout.width(3);
    cout << completions << "(" << 100.0 * completions / size << "%)" << endl << right;
    cout.width(20);
    cout << "Passing Grades: " << left;
    cout.width(3); 
    cout << passing << "(" <<  100.0 * passing / size << "%)" << endl << right;
    cout.width(20);
    cout << "Non-Passing Grades: " << left;
    cout.width(3);
    cout << not_passing << "(" << 100.0 * not_passing / size << "%)" << endl << right;
    cout.width(20);
    cout << "AUD Grades: " << left;
    cout.width(3); 
    cout << aud << "(" << 100.0 * aud / size << "%)" << endl << endl;
}