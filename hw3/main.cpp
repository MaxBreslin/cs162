//******************************************************************************
// Author: Max Breslin
// Assignment: Homework 2
// Date: 7/4/2022
// Description: This program will open an interactive menu, allowing a user to 
//              read data from three files describing student G-Nums, names, 
//              and assignments. It will then load the data into an array of 
//              Student objects. The user can observe different things about 
//              the data, including the mean GPA and participation statistics. 
//              They can also add or remove students or assignments. The 
//              program will run until the user decides to quit.
//
// Input: Menu choices as strings and files containing comma-separated strings
// Output: Statistics about the input file data and confirming or error messages
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
            case 'Z': // Additional option to indicate an invalid option 
                      // choice (while letting the program continue)
                break;
            default:
                cerr << "?Option error" << endl;
                return EXIT_FAILURE;
        }
     }
     cout << "[done]" << endl;
     return EXIT_SUCCESS;
}

void welcome() {
    cout << "Welcome to my class management program!"
         << " Options are entered as a word, not a single character." << endl;
}

char menu() {
    char option[MAX_CHARS + 1];
    memset(option, 0, MAX_CHARS + 1);
    char upper_option[MAX_CHARS + 1];
    memset(upper_option, 0, MAX_CHARS + 1);
    char all_options[NUM_OPTIONS][MAX_CHARS + 1] = {
        "LOAD",
        "DISPLAY",
        "GPA",
        "PCT",
        "GRADE",
        "REMOVE",
        "ADD",
        "QUIT"
    };

    cout << left << "Please enter one of the following options:" << endl;
    cout.width(14);
    cout << "\tLOAD" << "- Load roster and assignment data" << endl;
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
    for (int i = 0; i < NUM_OPTIONS; i ++) {
        if (strcmp(upper_option, all_options[i]) == 0) {
            return upper_option[1];
        }
    }
    cerr << "?Unrecognized option: \"" << option << "\"" << endl;
    return 'Z';
}
