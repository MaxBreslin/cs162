//******************************************************************************
// Author: Max Breslin
// Assignment: Homework 2
// Date: 7/4/2022
// Description: This program will open an interactive menu, allowing a user to 
//              read student data from a file and load it into an array of 
//              Student structs. It will then let the user observe different 
//              things about the data, including the mean GPA and participation 
//              statistics. The program will run until the user decides to quit.
//
//              The program assumes that all data files have the same students
//              (gnum, name, etc.).
//
// Input: Menu choices as strings and file containing comma-separated data in
//        the format of "name, gnum, grade".
// Output: Statistics about the input file data
// Sources: None
//******************************************************************************

#include "main.h"

using namespace std;

int main() {
    Student roster[MAX_STUDENTS];

    int size = 0;
    int capacity = MAX_STUDENTS;
    char option = '\0';

    welcome();

    while ((option = menu()) != 'U') {
        switch(option) {
            case 'U':
                break;
            case 'O':
                load(roster, size, capacity);
                break;
            case 'I':
                display(roster, size);
                break;
            case 'P':
                gpa(roster, size);
                break;
            case 'R':
                grade(roster, size);
                break;
            case 'C':
                pct(roster, size);
                break;
            case 'E':
                remove(roster, size);
                break;
            case 'D':
                add(roster, size, capacity);
                break;
            case 'Z': // Additional option to indicate an invalid option choice (while letting the program continue)
                break;
            default:
                cerr << "?Option error" << endl;
                return EXIT_FAILURE;
                break;
        }
     }
     cout << "[done]" << endl;
     return EXIT_SUCCESS;
}

void welcome() {
    cout << "Welcome to my class management program! Options are entered as a word, not a single character." << endl;
}

char menu() {
    char option[MAX_CHARS + 1];
    memset(option, 0, MAX_CHARS + 1);
    char upper_option[MAX_CHARS + 1];
    memset(upper_option, 0, MAX_CHARS + 1);

    cout << left << "Please enter one of the following options:" << endl;
    cout.width(14);
    cout << "\tLOAD" << "- Load roster data from an input file" << endl;
    cout.width(14);
    cout << "\tDISPLAY" << "- Display the current roster data" << endl;
    cout.width(14);
    cout << "\tGPA" << "- Display the average GPA for the roster" << endl;
    cout.width(14);
    cout << "\tGRADE" << "- Display grade inforamtion for one student" << endl;
    cout.width(14);
    cout << "\tPCT" << "- Display the Pass, Fail, and Completion percentages" << endl;
    cout.width(14);
    cout << "\tREMOVE" << "- Remove item from a list" << endl;
    cout.width(14);
    cout << "\tADD" << "- Add item to a list" << endl;
    cout.width(14);
    cout << "\tQUIT" << "- End this program" << endl
         << "Enter Option: ";
    cin.getline(option, MAX_CHARS);
    for (int i = 0; i < MAX_CHARS; i ++) {
        upper_option[i] = toupper(option[i]);
    }
    if (strcmp(upper_option, "LOAD") != 0 && strcmp(upper_option, "DISPLAY") != 0 && strcmp(upper_option, "GPA") != 0 
        && strcmp(upper_option, "PCT") != 0 && strcmp(upper_option, "QUIT") != 0 && strcmp(upper_option, "GRADE") != 0
        && strcmp(upper_option, "REMOVE") != 0 && strcmp(upper_option, "ADD") != 0) {
        cerr << "?Unrecognized option: \"" << option << "\"" << endl;
        return 'Z';
    }
    return toupper(option[1]);
}
