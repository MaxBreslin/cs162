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

#define name_f 0
#define gnum_f 1
#define assignment_f 2

int main() {
    ifstream files[NUM_FILES];
    char file_names[NUM_FILES][MAX_FILE_NAME + 1];
    for (int i = 0; i < NUM_FILES; i ++) {
        memset(file_names[i], 0, MAX_FILE_NAME + 1);
    }

    Student roster[MAX_STUDENTS];

    int size = 0;
    int capacity = MAX_STUDENTS;
    char option = '\0';

    char name[MAX_OPTION + 1];
    memset(name, 0, MAX_OPTION + 1);
    char assignment[MAX_OPTION + 1];
    memset(assignment, 0, MAX_OPTION + 1);
    
    welcome();

    while ((option = menu()) != 'U') {
        switch(option) {
            case 'U':
                break;
            case 'O':
                get_file_names(file_names);
                for (int i = 0; i < NUM_FILES; i ++) {
                    files[i].open(file_names[i]);
                    if (files[i].is_open()) {
                        cout << file_names[i] << " opened successfully." << endl;
                    }
                    else {
                        cerr << "?Could not open " << file_names[i] << "." << endl;
                        return EXIT_FAILURE;
                        break;
                    }
                }
                load(files[name_f], files[gnum_f], files[assignment_f], roster, size, capacity);
                for (int i = 0; i < NUM_FILES; i ++) {
                    files[i].close();
                }
                break;
            case 'I':
                display(roster, size);
                break;
            case 'P':
                gpa(roster, size);
                break;
            case 'R':
                cout << "Enter Student Name or Student G-Number: ";
                get_name(name);
                grade(roster, size, name);
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
    char option[MAX_OPTION + 1];
    memset(option, 0, MAX_OPTION + 1);
    char upper_option[MAX_OPTION + 1];
    memset(upper_option, 0, MAX_OPTION + 1);

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
    cin.getline(option, MAX_OPTION + 1);
    for (int i = 0; i < MAX_OPTION + 1; i ++) {
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

void get_file_names(char file_names[NUM_FILES][MAX_FILE_NAME + 1]) {
    char temp[MAX_FILE_NAME + 1];

    memset(temp, 0, MAX_FILE_NAME + 1);
    cout << "Enter file name of student names file of up to 30 characters: ";
    cin.getline(temp, MAX_FILE_NAME);
    strcpy(file_names[name_f], temp);

    memset(temp, 0, MAX_FILE_NAME);
    cout << "Enter file name of student G-Number file of up to 30 characters: ";
    cin.getline(temp, MAX_FILE_NAME);
    strcpy(file_names[gnum_f], temp);

    memset(temp, 0, MAX_FILE_NAME);
    cout << "Enter file name of student assignment file of up to 30 characters: ";
    cin.getline(temp, MAX_FILE_NAME);
    strcpy(file_names[assignment_f], temp);
}

void get_name(char name[MAX_OPTION + 1]) {
    memset(name, 0, MAX_OPTION + 1);
    cin.getline(name, MAX_OPTION + 1);
}
