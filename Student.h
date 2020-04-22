// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 4-22-2020
// Assignment: Registrar Office

/*
  Header for the student class
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

//Header for Student

class Student
{
  //.amount of time they will take, .time they arrived,
  //.how many ticks they’ve waited, updateticks()

  public:
    Student(); //Default constructor
    Student(int duration, int arrival); //Overloaded constructor for minutes needed and time arrived
    ~Student(); //Destructor

    void incMinutesWaited(); //Updates minutes waited in the queue
    void incMinutesAtWindow(); //Increments the number of minutes at the window

    int getMinuteArrived(); //Returns the minute arrived at the registrar
    int getMinutesWaited(); //Returns the number of minutes waited in the queue
    int getMinutesAtWindow(); //Returns the number of minutes at the window
    bool isDone(); //Returns true if student is done

    void printInfo(); //Prints the stats of a student

  private:
    int m_minutesNeeded; //Minutes needed at the window
    int m_minuteArrived; //Minute arrived at the registrar
    int m_minutesWaited; //Minutes waited in the queue
    int m_minutesAtWindow; //Minutes spent at the window

};

#endif
