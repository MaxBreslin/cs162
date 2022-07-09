#include "student.h"

using namespace std;

const int MAX_OPTION = 30;

void get_name_or_gnum(char name_or_gnum[MAX_OPTION]) {
    memset(name_or_gnum, 0, MAX_OPTION);
    cout << "Enter Student Name or Student G-Number: ";
    cin.getline(name_or_gnum, MAX_OPTION);
}
void get_name(char name[MAX_OPTION + 1]) {
    memset(name, 0, MAX_OPTION + 1);
    cin.getline(name, MAX_OPTION + 1);
}


int main() {
    char name_or_gnum[MAX_OPTION];
    Student roster[30];
    int size = 0;
    int capacity = 30;
    ifstream names_file("hw2_names.txt");
    ifstream gnums_file("hw2_gnums.txt");
    ifstream assignments_file("hw2_assignments.txt");
    load(names_file, gnums_file, assignments_file, roster, size, capacity);
    names_file.close();
    gnums_file.close();
    assignments_file.close();

    // get_name_or_gnum(name_or_gnum);
    // grade(roster, size, name_or_gnum);
    // pct(roster, size);
    // gpa(roster, size);
    // remove(roster, size);
    char option;
    while (1) {
        add(roster, size, capacity);
        cout << "Option: ";
        cin >> option;
        cin.ignore(2, '\n');
        if (option != 'c') { 
            display(roster, size);
        }
    }
}