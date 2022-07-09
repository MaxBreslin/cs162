//******************************************************************************
// Author: Max Breslin
// Assignment: Homework 1
// Date: 7/2/2022
// Description: This program will open an interactive menu, allowing a user to 
//              read student data from a file and load it into an array of 
//              Student structs. It will then let the user observe different 
//              things about the data, including the mean GPA and participation 
//              statistics. The program will run until the user decides to quit.
// Input: Menu choices as strings and file containing comma-separated data in
//        the format of "name, gnum, grade".
// Output: Statistics about the input file data
// Sources: None
//******************************************************************************

#include "main.h"

using namespace std;

int main() {
    fstream file;
    Student roster[MAX_STUDENTS];
    int size = 0;
    int capacity = MAX_STUDENTS;
    char option;
    char file_name[MAX_FILE_NAME];

    welcome();

    while ((option = menu()) != 'Q') {
        switch(option) {
            case 'Q':
                break;
            case 'L':
                reset_roster(roster, size, file_name);
                get_file_name(file_name);
                file.open(file_name);
                if (file.is_open()) {
                    cout << "File opened successfully." << endl;
                }
                else {
                    cerr << "?Could not open file." << endl;
                    return 1;
                    break;
                }
                load(file, roster, size, capacity);
                cout << endl
                     << "[" << size << " records read from \"" << file_name << "\"]" << endl
                     << endl;
                file.close();
                break;
            case 'D':
                display(roster, size);
                break;
            case 'G':
                gpa(roster, size);
                break;
            case 'P':
                pct(roster, size);
                break;
            case 'E': // Additional option to indicate an invalid option choice (while letting the program continue)
                break;
            default:
                cerr << "?Option error" << endl;
                return 1;
                break;
        }
     }
     cout << "[done]" << endl;
     return 0;
}

void welcome() {
    cout << "Welcome to my class management program! Options are entered as a word, not a single character." << endl;
}

char menu() {
    char option[MAX_OPTION];
    memset(option, 0, MAX_OPTION);
    char upper_option[MAX_OPTION];
    memset(upper_option, 0, MAX_OPTION);

    cout << left << "Please enter one of the following options:" << endl;
    cout.width(14);
    cout << "\tLOAD" << "- Load roster data from an input file" << endl;
    cout.width(14);
    cout << "\tDISPLAY" << "- Display the current roster data" << endl;
    cout.width(14);
    cout << "\tGPA" << "- Display the average GPA for the roster" << endl;
    cout.width(14);
    cout << "\tPCT" << "- Display the Pass, Fail, and Completion percentages" << endl;
    cout.width(14);
    cout << "\tQUIT" << "- End this program" << endl
         << "Enter Option: ";
    cin.getline(option, MAX_OPTION);
    for (int i = 0; i < MAX_OPTION; i++) {
        upper_option[i] = toupper(option[i]);
    }
    if (strcmp(upper_option, "LOAD") != 0 && strcmp(upper_option, "DISPLAY") != 0 && strcmp(upper_option, "GPA") != 0 
        && strcmp(upper_option, "PCT") != 0 && strcmp(upper_option, "QUIT") != 0) {
        cerr << "?Unrecognized option: \"" << option << "\"" << endl;
        return 'E';
    }
    return toupper(option[0]);
}

void get_file_name(char file_name[]) {
    cout << "Enter file name of up to 30 characters: ";
    cin.getline(file_name, MAX_FILE_NAME);
}

void reset_roster(Student roster[], int &size, char file_name[]) {
    memset(roster, 0, size * sizeof(roster[0]));
    size = 0;
    memset(file_name, 0, MAX_FILE_NAME);
}