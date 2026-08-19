#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iomanip>
#include <iostream>

/**
 * Student.h
 * Model class representing a single student record.
 */
class Student {
private:
    int rollNo;
    std::string name;
    std::string branch;
    double marks;

public:
    Student() : rollNo(0), name(""), branch(""), marks(0.0) {}

    Student(int rollNo, std::string name, std::string branch, double marks)
        : rollNo(rollNo), name(std::move(name)), branch(std::move(branch)), marks(marks) {}

    int getRollNo() const { return rollNo; }
    std::string getName() const { return name; }
    std::string getBranch() const { return branch; }
    double getMarks() const { return marks; }

    void print() const {
        std::cout << std::left
                   << std::setw(9) << rollNo
                   << std::setw(16) << name
                   << std::setw(11) << branch
                   << std::fixed << std::setprecision(2) << marks
                   << std::endl;
    }
};

#endif
