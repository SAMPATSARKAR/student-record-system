/**
 * StudentRecordSystem.cpp
 *
 * A simple menu-driven console application that manages student records
 * using core Data Structures and Algorithms concepts:
 *   - vector (dynamic array) as the underlying storage structure
 *   - Linear Search  (search by name)
 *   - Binary Search  (search by roll number - requires sorted data)
 *   - Bubble Sort    (sort by marks)
 *   - Selection Sort (sort by name)
 *
 * Author: Sam
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "Student.h"

using namespace std;

static vector<Student> students;

void printMenu() {
    cout << "\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n";
    cout << "1. Add Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by Name  (Linear Search)\n";
    cout << "4. Search Student by Roll No (Binary Search)\n";
    cout << "5. Sort by Marks  (Bubble Sort)\n";
    cout << "6. Sort by Name   (Selection Sort)\n";
    cout << "7. Delete Student\n";
    cout << "8. Exit\n";
}

int readInt(const string &prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

double readDouble(const string &prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

void loadSampleData() {
    students.push_back(Student(101, "Aman", "CSE", 78.5));
    students.push_back(Student(104, "Priya", "IT", 92.0));
    students.push_back(Student(102, "Rohit", "CSE", 65.0));
    students.push_back(Student(103, "Simran", "ECE", 88.5));
}

void addStudent() {
    int roll = readInt("Enter Roll No: ");
    string name, branch;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Branch: ";
    cin >> branch;
    double marks = readDouble("Enter Marks: ");
    students.push_back(Student(roll, name, branch, marks));
    cout << "Student added successfully.\n";
}

void displayAll() {
    if (students.empty()) {
        cout << "No records found.\n";
        return;
    }
    cout << "\nRollNo   Name            Branch     Marks\n";
    cout << "--------------------------------------------\n";
    for (const auto &s : students) {
        s.print();
    }
}

void deleteStudent() {
    int roll = readInt("Enter Roll No to delete: ");
    auto it = remove_if(students.begin(), students.end(),
                         [roll](const Student &s) { return s.getRollNo() == roll; });
    bool removed = (it != students.end());
    students.erase(it, students.end());
    cout << (removed ? "Student deleted.\n" : "Roll No not found.\n");
}

/** Linear Search: O(n) — works on unsorted data, searches by name. */
void linearSearchByName() {
    string key;
    cout << "Enter name to search: ";
    cin >> key;
    int comparisons = 0;
    for (const auto &s : students) {
        comparisons++;
        if (s.getName() == key) {
            cout << "Found -> ";
            s.print();
            cout << "Comparisons: " << comparisons << "\n";
            return;
        }
    }
    cout << "Student not found. Comparisons: " << comparisons << "\n";
}

/** Binary Search: O(log n) — requires the list to be sorted by roll number first. */
void binarySearchByRoll() {
    vector<Student> sorted = students;
    sort(sorted.begin(), sorted.end(), [](const Student &a, const Student &b) {
        return a.getRollNo() < b.getRollNo();
    });

    int roll = readInt("Enter Roll No to search: ");
    int low = 0, high = (int)sorted.size() - 1, comparisons = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        int midRoll = sorted[mid].getRollNo();
        if (midRoll == roll) {
            cout << "Found -> ";
            sorted[mid].print();
            cout << "Comparisons: " << comparisons << "\n";
            return;
        } else if (midRoll < roll) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Student not found. Comparisons: " << comparisons << "\n";
}

/** Bubble Sort: O(n^2) — sorts students in descending order of marks. */
void bubbleSortByMarks() {
    int n = (int)students.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].getMarks() < students[j + 1].getMarks()) {
                swap(students[j], students[j + 1]);
            }
        }
    }
    cout << "Sorted by Marks (descending):\n";
    displayAll();
}

/** Selection Sort: O(n^2) — sorts students alphabetically by name. */
void selectionSortByName() {
    int n = (int)students.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (students[j].getName() < students[minIdx].getName()) {
                minIdx = j;
            }
        }
        swap(students[minIdx], students[i]);
    }
    cout << "Sorted by Name (A-Z):\n";
    displayAll();
}

int main() {
    loadSampleData();
    int choice;
    do {
        printMenu();
        choice = readInt("Enter your choice: ");
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: linearSearchByName(); break;
            case 4: binarySearchByRoll(); break;
            case 5: bubbleSortByMarks(); break;
            case 6: selectionSortByName(); break;
            case 7: deleteStudent(); break;
            case 8: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 8);
    return 0;
}
