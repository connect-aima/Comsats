#include <iostream>  
using namespace std;

const int MAX_STUDENTS = 50;
int students[MAX_STUDENTS][5]; 
int countStudents = 0;         


void insertStudent() {
    if (countStudents >= MAX_STUDENTS) {
        cout << "Cannot insert more students.\n";
        return;
    }
    cout << "Enter Registration(last 3 digits), Year, Month, Day, Marks: ";
    for (int j = 0; j < 5; j++) {
        cin >> students[countStudents][j];
    }
    countStudents++;
    cout << "Student inserted successfully.\n";
}




void deleteStudent() {
    int reg;
    cout << "Enter registration number to delete: ";
    cin >> reg;

    int pos = -1;
    for (int i = 0; i < countStudents; i++) {
        if (students[i][0] == reg) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Student not found.\n";
        return;
    }

    for (int i = pos; i < countStudents - 1; i++) {
        for (int j = 0; j < 5; j++) {
            students[i][j] = students[i + 1][j];
        }
    }
    countStudents--;
    cout << "Student deleted successfully.\n";
}




void searchStudent() {
    int reg;
    cout << "Enter registration number to search: ";
    cin >> reg;

    for (int i = 0; i < countStudents; i++) {
        if (students[i][0] == reg) {
            cout << "Found: ";
            for (int j = 0; j < 5; j++) {
                cout << students[i][j] << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}





void displayAll() {
    if (countStudents == 0) {
        cout << "No students available.\n";
        return;
    }
    for (int i = 0; i < countStudents; i++) {
        for (int j = 0; j < 5; j++) {
            cout << students[i][j] << " ";
        }
        cout << endl;
    }
}





void displayCount() {
    cout << "Total students: " << countStudents << endl;
}





void highestMarks(){
 if (countStudents == 0) {
        cout << "No students.\n";
        return;
    }
    int maxMarks = students[0][4];
    int pos = 0;
    for (int i = 1; i < countStudents; i++) {
        if (students[i][4] > maxMarks) {
            maxMarks = students[i][4];
            pos = i;
        }
    }
    cout << "Student with highest marks: ";
    for (int j = 0; j < 5; j++) {
        cout << students[pos][j] << " ";
    }
    cout << endl;
}

void youngestOldest(){
    if (countStudents == 0) {
        cout << "No students.\n";
        return;
    }

    int youngest = 0, oldest = 0;
    for (int i = 1; i < countStudents; i++) {
        // compare year first, then month, then day
        if (students[i][1] > students[youngest][1] ||
            (students[i][1] == students[youngest][1] && students[i][2] > students[youngest][2]) ||
            (students[i][1] == students[youngest][1] && students[i][2] == students[youngest][2] && students[i][3] > students[youngest][3])) {
            youngest = i;
        }
        if (students[i][1] < students[oldest][1] ||
            (students[i][1] == students[oldest][1] && students[i][2] < students[oldest][2]) ||
            (students[i][1] == students[oldest][1] && students[i][2] == students[oldest][2] && students[i][3] < students[oldest][3])) {
            oldest = i;
        }
    }

    cout << "Youngest student: ";
    for (int j = 0; j < 5; j++) cout << students[youngest][j] << " ";
    cout << endl;

    cout << "Oldest student: ";
    for (int j = 0; j < 5; j++) cout << students[oldest][j] << " ";
    cout << endl;
}





   

int main() {
    int choice;
    do {
        cout << "---- Menu ----";
        cout << "1. Insert a new student\n";
        cout << "2. Delete a student\n";
        cout << "3. Search a student\n";
        cout << "4. Display all students\n";
        cout << "5. Display total count\n";
        cout << "6. Highest marks\n";
        cout << "7. Youngest & Oldest\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) insertStudent();
        else if (choice == 2) deleteStudent();
        else if (choice == 3) searchStudent();
        else if (choice == 4) displayAll();
        else if (choice == 5) displayCount();
        else if (choice == 6) highestMarks();
        else if (choice == 7) youngestOldest();
        else if (choice == 8) cout << "Exiting...\n";
        else cout << "Invalid choice!\n";

    } while (choice != 8);

    return 0;
}