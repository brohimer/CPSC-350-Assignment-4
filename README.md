# CPSC-350-Assignment-4

## 1. IDENTIFYING INFO
- Course Number and Section: CPSC 350-01
- Assignment 4

Student 1
- Full Name: Curren Taber
- Student ID: 002325149
- Chapman Email: ctaber@chapman.edu

Student 2
- Full Name: Oliver Mathias
- Student ID: 002289410
- Chapman Email: mathias@chapman.edu

## 2. SOURCE FILES
- README.md
- main.cpp
- DoublyLinkedList.h
- List.h
- ListNode.h
- Makefile
- Registrar.cpp
- Registrar.h
- Simulation.cpp
- Simulation.h
- Student.cpp
- Student.h
- StudentQueue.cpp
- StudentQueue.h
- Window.cpp
- Window.h
- test.txt


## 3. DESCRIPTION
This assignment simulates Chapman's registrar office.
The goal is to provide average wait and idle times for the windows and students in the office so the registrars can make predictions about capacity requirements.

It takes an input of a text file with information about the number of windows open, the number of students arrived, the time they arrived, and how long they need at a window.

- How to Run:
  - `cd` into the directory containing source files
  - Type `make all` into your command line
  - Type `./assignment4.out filename` into your command line
  - Follow the menu prompts

- Important Notes:
  - You cannot use an empty input file.
  - The input file must have one positive integer value per line.
  - The first line represents the number of registrar windows.
  - Following lines follow a repeating pattern of student: information:
    - Time student(s) arrive
    - Number of students arriving at specified time
    - Time needed for student(s)

## 4. REFERENCES
- Rene German
- Data Structures and Algorithms
- https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm
- https://stackoverflow.com/questions/7558280/initializing-an-array-of-objects
