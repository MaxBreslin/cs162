#include "student.h"

using namespace std;

Student::Student() {
    m_size = 0;
    m_capacity = MAX_SUBMISSIONS;
    m_grade = '\0';
    memset(m_name, 0, MAX_CHARS + 1);
    memset(m_gnum, 0, MAX_CHARS + 1);
    for (int i = 0; i < m_capacity; i ++) {
        m_submissions[i] = Assignment();
    }
}

Student::Student(const Student &obj) {
    // Without memset first, strange values will fill the remaining space in the array.
    memset(m_name, 0, MAX_CHARS + 1);
    memset(m_gnum, 0, MAX_CHARS + 1);
    strcpy(m_name, obj.m_name);
    strcpy(m_gnum, obj.m_gnum);

    for (int i = 0; i < min(m_capacity, obj.m_capacity); i ++) {
        m_submissions[i] = obj.m_submissions[i];
    }

    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    m_grade = obj.m_grade;
}

Student::~Student() {
    m_size = 0;
    m_capacity = MAX_SUBMISSIONS;
    m_grade = '\0';
    memset(m_name, 0, MAX_CHARS + 1);
    memset(m_gnum, 0, MAX_CHARS + 1);
    for (int i = 0; i < m_capacity; i ++) {
        m_submissions[i] = Assignment();
    }
}

Student Student::operator=(const Student &obj) {
    memset(m_name, 0, MAX_CHARS + 1);
    memset(m_gnum, 0, MAX_CHARS + 1);
    strcpy(m_name, obj.m_name);
    strcpy(m_gnum, obj.m_gnum);

    for (int i = 0; i < min(m_capacity, obj.m_capacity); i ++) {
        m_submissions[i] = obj.m_submissions[i];
    }

    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    m_grade = obj.m_grade;

    return *this;
}

void Student::set_name(const char name[]) {
    strcpy(m_name, name);
}
void Student::get_name(char name[]) const {
    strcpy(name, m_name);
}
void Student::set_gnum(const char gnum[]) {
    int len = strlen(gnum);
    if (gnum[0] != 'G' || len != 9) {
        throw invalid_argument("Invalid gnum");
        return;
    }
    for (int i = 1; i < len; i ++) {
        if (gnum[i] < '0' || gnum[i] > '9') {
            throw invalid_argument("Invalid gnum");
            return;
        }
    }
    strcpy(m_gnum, gnum);
}
void Student::get_gnum(char gnum[]) const {
    strcpy(gnum, m_gnum);
}
void Student::set_grade(char grade) {
    m_grade = grade;
}
char Student::get_grade() const {
    return m_grade;
}

void Student::calculate_grade() {
    float sum = 0.0F;
    for (int i = 0; i < m_size; i ++) {
        sum += m_submissions[i].get_grade() * m_submissions[i].get_weight();
    }
    
    if (sum >= 3.4) {
        m_grade = 'A';
    }
    else if (sum >= 2.8) {
        m_grade = 'B';
    }
    else if (sum >= 2.0) {
        m_grade = 'C';
    }
    else if (sum >= 1.2) {
        m_grade = 'D';
    }
    else {
        m_grade = 'F';
    }

}

int Student::get_size() const {
    return m_size;
}
int Student::get_capacity() const {
    return m_capacity;
}

void Student::display() const {
    cout << m_gnum << " " << m_name << " Final Grade: " << m_grade << endl;
    for (int i = 0; i < m_size; i ++) {
        cout << "        ";
        m_submissions[i].display();
    }
}

void Student::print_grade() const {
    float sum = 0.0F;
    cout.precision(2);
    cout << m_gnum << " " << m_name << " Grade: " << m_grade << endl;
    for (int i = 0; i < m_size; i ++) {
        cout << "        ";
        sum += m_submissions[i].print_grade();
    }
    cout << "                Total: " << sum << endl;
}

void Student::add_submission(Assignment submission) {
    if (m_size == m_capacity) {
        throw length_error("Student is full");
        return;
    }
    m_submissions[m_size] = submission;
    m_size ++;
}

void Student::remove_submission(const char assignment[]) {
    char temp_name[MAX_CHARS + 1];
    for (int i = 0; i < m_size; i ++) {
        m_submissions[i].get_name(temp_name);
        if (strcmp(temp_name, assignment) == 0) {
            for (int j = i; j < m_size - 1; j ++) {
                m_submissions[j] = m_submissions[j + 1];
            }
            m_size --;
            return;
        }
    }
    throw invalid_argument("Assignment not found");
}

void load(ifstream &name_file, ifstream &gnum_file, ifstream &assignment_file, Student roster[], int &size, const int &capacity) {
    load_gnums(gnum_file, roster, size, capacity);
    load_names(name_file, roster, size);
    load_assignments(assignment_file, roster, size);
    for (int i = 0; i < size; i ++) {
        roster[i].calculate_grade();
    }
}

void load_names(ifstream &file, Student roster[], const int &size) {
    char name[MAX_CHARS + 1];
    memset(name, 0, MAX_CHARS + 1);
    char gnum[MAX_CHARS + 1];
    memset(gnum, 0, MAX_CHARS + 1);
    char compare_gnum[MAX_CHARS + 1];
    memset(compare_gnum, 0, MAX_CHARS + 1);
    int names_loaded = 0;

    for (int i = 0; i < size; i ++) {
        memset(name, 0, MAX_CHARS + 1);
        memset(gnum, 0, MAX_CHARS + 1);
        memset(compare_gnum, 0, MAX_CHARS + 1);

        if (!file.getline(name, MAX_CHARS, ',')) {
            break;
        }
        if (!file.getline(gnum, MAX_CHARS, '\n')) {
            break;
        }

        roster[i].get_gnum(compare_gnum);

        // The just-read gnum should match the current student's gnum, but if there was
        // a mixup in the file the program will iterate through the entire roster and
        // find the correct student.
        if (strcmp(gnum, compare_gnum) == 0) {
            roster[i].set_name(name);
            names_loaded ++;
        }
        else {
            for (int j = 0; j < size; j++) {
                roster[j].get_gnum(compare_gnum);
                if (strcmp(gnum, compare_gnum) == 0) {
                    roster[j].set_name(name);
                    names_loaded ++;
                    break;
                }
            }
        }
    }

    cout << "[" << names_loaded << " names added to the roster]" << endl;
}

void load_gnums(ifstream &file, Student roster[], int &size, const int &capacity) {
    char gnum[MAX_CHARS + 1];
    memset(gnum, 0, MAX_CHARS + 1);

    while (size < capacity) {
        Student s;
        memset(gnum, 0, MAX_CHARS + 1);
        if (!file.getline(gnum, MAX_CHARS, '\n')) {
            break;
        }
        s.set_gnum(gnum);
        roster[size] = s;
        size ++;
    }

    cout << "[" << size << " G-Numbers loaded]" << endl;
}

void load_assignments(ifstream &file, Student roster[], const int &size) {
    char name[MAX_CHARS + 1];
    memset(name, 0, MAX_CHARS + 1);
    char gnum[MAX_CHARS + 1];
    memset(gnum, 0, MAX_CHARS + 1);
    char compare_gnum[MAX_CHARS + 1];
    memset(compare_gnum, 0, MAX_CHARS + 1);
    int grade = 0;
    float weight = 0.0F;
    int assignments_loaded = 0;

    while (!file.eof()) {
        memset(name, 0, MAX_CHARS + 1);
        memset(gnum, 0, MAX_CHARS + 1);

        if (!file.getline(gnum, MAX_CHARS, ',')) {
            break;
        }
        if (!file.getline(name, MAX_CHARS, ',')) {
            break;
        }

        file >> grade;
        file.ignore(2, ',');
        file.precision(3);
        file >> weight;
        file.ignore(2, '\n');

        for (int i = 0; i < size; i ++) {
            memset(compare_gnum, 0, MAX_CHARS + 1);
            roster[i].get_gnum(compare_gnum);
            if (strcmp(gnum, compare_gnum) == 0) {
                try {
                    roster[i].add_submission(Assignment(name, gnum, grade, weight));
                }
                catch (const length_error &err) {
                    cerr << err.what() << endl;
                    break;
                }
                catch (const invalid_argument &err) {
                    cerr << err.what() << endl;
                    break;
                }
                assignments_loaded ++;
            }
        }
    }

    cout << "[" << assignments_loaded << " assignments added]" << endl;
}

void display(const Student roster[], const int &size) {
    for (int i = 0; i < size; i ++) {
        cout << " " << i << ". ";
        roster[i].display();
    }
}

void grade(const Student roster[], const int &size, const char name_or_gnum[]) {
    char compare[MAX_CHARS + 1];
    memset(compare, 0, MAX_CHARS + 1);
    cout << endl;
    // Is it a gnum?
    if ('0' <= name_or_gnum[1] && name_or_gnum[1] <= '9') {
        for (int i = 0; i < size; i ++) {
            memset(compare, 0, MAX_CHARS + 1);
            roster[i].get_gnum(compare);
            if (strcmp(compare, name_or_gnum) == 0) {
                roster[i].print_grade();
                return;
            }
        }
        cerr << "?Unrecognized gnum: \"" << name_or_gnum << "\"" << endl;
    }
    else {
        for (int i = 0; i < size; i ++) {
            memset(compare, 0, MAX_CHARS + 1);
            roster[i].get_name(compare);
            if (strcmp(compare, name_or_gnum) == 0) {
                roster[i].print_grade();
                return;
            }
        }
        cerr << "?Unrecognized name: \"" << name_or_gnum << "\"" << endl;
    }
}

void gpa(const Student roster[], const int &size) {
    double sum = 0.0;

    for (int i = 0; i < size; i ++) {
        switch (roster[i].get_grade()) {
            case 'A':
                sum += 4.0;
                break;
            case 'B':
                sum += 3.0;
                break;
            case 'C':
                sum += 2.0;
                break;
            case 'D':
                sum += 1.0;
                break;
            default:
                break;
        }
    }

    cout.precision(2);
    cout << endl
         << "Average GPA for " << size << " students is " << sum / size << endl
         << endl;
}

void pct(const Student roster[], const int &size) {
    int not_passing = 0, completions = 0, passing = 0;

    for (int i = 0; i < size; i ++) {
        switch (roster[i].get_grade()) {
            case 'A':
            case 'B':
            case 'C':
                passing ++;
                completions ++;
                break;
            case 'D':
            case 'F':
                completions ++;
                break;
            default:
                break;
        }
    }

    not_passing = size - passing;

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
    cout << not_passing << "(" << 100.0 * not_passing / size << "%)" << endl << endl;
    cout.setf(ios::dec, ios::floatfield);
}

void remove(Student roster[], int &size) {
    char student_or_assignment = '\0';
    char name[MAX_CHARS + 1];
    memset(name, 0, MAX_CHARS + 1);
    char assignment[MAX_CHARS + 1];
    memset(assignment, 0, MAX_CHARS + 1);
    
    student_or_assignment = assignment_or_student();
    if (student_or_assignment == 'S') {
        memset(name, 0, MAX_CHARS + 1);
        cout << "Enter student name: ";
        cin.getline(name, MAX_CHARS + 1);
        cout << "Removing student \"" << name << "\" from roster" << endl;
        try {
            remove_student(roster, size, name);
        }
        catch (const invalid_argument &err){
            cerr << err.what() << endl;
            return;
        }
        cout << "done!" << endl;
    }
    else if (student_or_assignment == 'A') {
        memset(name, 0, MAX_CHARS + 1);
        memset(assignment, 0, MAX_CHARS + 1);
        cout << "Enter student name: ";
        cin.getline(name, MAX_CHARS + 1);
        cout << "Enter assignment name: ";
        cin.getline(assignment, MAX_CHARS + 1);
        cout << "Removing all records of \"" << assignment << "\" for \"" << name << "\"" << endl;
        try {
            remove_assignment(roster, size, name, assignment);
        }
        catch (const invalid_argument &err){
            cerr << err.what() << endl;
            return;
        }
        cout << "done!" << endl;
    }
    else if (student_or_assignment == 'B') {
        cout << "Returning to previous menu" << endl;
    }
    else {
        cerr << "?Unrecognized choice: \"" << student_or_assignment << "\"" << endl;
    }
}

void remove_student(Student roster[], int &size, const char name[]) {
    char temp_name[MAX_CHARS + 1];
    memset(temp_name, 0, MAX_CHARS + 1);
    for (int i = 0; i < size; i ++) {
        roster[i].get_name(temp_name);
        if (strcmp(temp_name, name) == 0) {
            for (int j = i; j < size - 1; j ++) {
                roster[j] = roster[j + 1];
            }
            roster[i].calculate_grade();
            size --;
            return;
        }
    }
    throw invalid_argument("Student not found");
}
void remove_assignment(Student roster[], const int &size, const char student_name[], const char assignment_name[]) {
    char temp_name[MAX_CHARS + 1];
    memset(temp_name, 0, MAX_CHARS + 1);
    for (int i = 0; i < size; i ++) {
        roster[i].get_name(temp_name);
        if (strcmp(temp_name, student_name) == 0) {
            roster[i].remove_submission(assignment_name);
            roster[i].calculate_grade();
            return;
        }
    }
    throw invalid_argument("Student not found");
}

void add(Student roster[], int &size, const int &capacity) {
    char student_or_assignment = '\0';
    float weight = 0.0F;
    int grade = 0;
    char name[MAX_CHARS + 1];
    memset(name, 0, MAX_CHARS + 1);
    char assignment_or_gnum[MAX_CHARS + 1];
    memset(assignment_or_gnum, 0, MAX_CHARS + 1);
    
    student_or_assignment = assignment_or_student();
    if (student_or_assignment == 'S') {
        memset(name, 0, MAX_CHARS + 1);
        memset(assignment_or_gnum, 0, MAX_CHARS + 1);
        cout << "Enter student name: ";
        cin.getline(name, MAX_CHARS + 1);
        cout << "Enter G-Number for " << name << ": ";
        cin.getline(assignment_or_gnum, MAX_CHARS + 1);
        
        try {
            add_student(roster, size, capacity, name, assignment_or_gnum);
        }
        catch (const length_error &err){
            cerr << err.what() << endl;
            return;
        }
        catch (const invalid_argument &err){
            cerr << err.what() << endl;
            return;
        }
        cout << name << " (" << assignment_or_gnum << ") added" << endl;
    }
    else if (student_or_assignment == 'A') {
        memset(name, 0, MAX_CHARS + 1);
        memset(assignment_or_gnum, 0, MAX_CHARS + 1);
        cout << "Enter student name: ";
        cin.getline(name, MAX_CHARS + 1);
        cout << "Enter assignment name: ";
        cin.getline(assignment_or_gnum, MAX_CHARS + 1);
        cout << "Enter assignment weight: ";
        cin >> weight;
        cin.ignore(2, '\n');
        cout << "Enter assignment grade: ";
        cin >> grade;
        cin.ignore(2, '\n');

        try {
            add_assignment(roster, size, name, assignment_or_gnum, weight, grade);
        }
        catch (const length_error &err){
            cerr << err.what() << endl;
            return;
        }
        catch (const invalid_argument &err){
            cerr << err.what() << endl;
            return;
        }
        cout << "\"" << assignment_or_gnum << "\" added to " << name << endl;
    }
    else if (student_or_assignment == 'B') {
        cout << "Returning to previous menu" << endl;
    }
    else {
        cerr << "?Unrecognized choice: \"" << student_or_assignment << "\"" << endl;
    }
}
void add_student(Student roster[], int &size, const int &capacity, const char name[], const char gnum[]) {
    if (size == capacity) {
        throw length_error("Roster is full");
    }
    try {
        roster[size].set_gnum(gnum);
    }
    catch (const invalid_argument &err){
        throw err;
        return;
    }
    roster[size].set_name(name);
    roster[size].calculate_grade();
    size ++;
}
void add_assignment(Student roster[], const int &size, const char name[], const char assignment[], const int &grade, const float &weight) {
    char temp_name[MAX_CHARS + 1];
    memset(temp_name, 0, MAX_CHARS + 1);
    char temp_gnum[MAX_CHARS + 1];
    memset(temp_gnum, 0, MAX_CHARS + 1);
    for (int i = 0; i < size; i ++) {
        roster[i].get_name(temp_name);
        if (strcmp(temp_name, name) == 0) {
            if (roster[i].get_size() == roster[i].get_capacity()) {
                throw length_error("Student is full");
                return;
            }
            roster[i].get_gnum(temp_gnum);
            roster[i].add_submission(Assignment(assignment, temp_gnum, grade, weight));
            roster[i].calculate_grade();
            return;
        }
    }
    throw invalid_argument("Student not found");
}

char assignment_or_student() {
    char temp;
    cout << "Enter:" << endl
         << "        A or a  - for Assignment" << endl
         << "        S or s  - for Student" << endl
         << "        B or b  - return to previous" << endl
         << "Enter choice: ";
    cin >> temp;
    cin.ignore(2, '\n');
    return toupper(temp);
}