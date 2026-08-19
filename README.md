# Student Record Management System (C++ + DSA)

A simple menu-driven console application to manage student records, built to demonstrate core **Data Structures and Algorithms (DSA)** concepts in C++.

## Features
- Add, view, and delete student records (stored in a `std::vector`)
- **Linear Search** — search a student by name (O(n))
- **Binary Search** — search a student by roll number (O(log n), auto-sorts first)
- **Bubble Sort** — sort records by marks, descending (O(n²))
- **Selection Sort** — sort records alphabetically by name (O(n²))

## Project Structure
```
StudentRecordSystem/
├── src/
│   ├── Student.h                  # Model class
│   └── StudentRecordSystem.cpp    # Main application (menu + DSA logic)
└── README.md
```

## How to Run
```bash
cd src
g++ -std=c++17 -Wall -o StudentRecordSystem StudentRecordSystem.cpp
./StudentRecordSystem
```

## DSA Concepts Demonstrated
| Concept          | Where it's used                | Complexity              |
|-------------------|----------------------------------|--------------------------|
| vector (dynamic array) | Underlying student storage | O(1) amortized append   |
| Linear Search      | Search by name                 | O(n)                     |
| Binary Search      | Search by roll number          | O(log n)                 |
| Bubble Sort        | Sort by marks (descending)     | O(n²)                    |
| Selection Sort     | Sort by name (A–Z)             | O(n²)                    |

## Author
Sam
