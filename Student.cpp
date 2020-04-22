// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 4-22-2020
// Assignment: Registrar Office

/*
  This student class implements all the
  member variables and methods for the student object relating to
  minutes waited, line location, window location, etc.
*/

#include "Student.h"

//Implementation of Student

//Default constructor
Student::Student()
{
  m_minutesNeeded = 0;
  m_minuteArrived = 0;
  m_minutesWaited = -1;
  m_minutesAtWindow = 0;
}

//Overloaded constructor for minutes needed and time arrived
Student::Student(int duration, int arrival)
{
  m_minutesNeeded = duration;
  m_minuteArrived = arrival;
  m_minutesWaited = -1;
  m_minutesAtWindow = 0;
}

//Destructor
Student::~Student() { }

//Updates minutes waited in the queue
void Student::incMinutesWaited()
{
  m_minutesWaited += 1;
}

//Increments the number of minutes at the window
void Student::incMinutesAtWindow()
{
  m_minutesAtWindow += 1;
  // cout << "Incremented Window Mins to: "<< m_minutesAtWindow << endl;
}

//Returns the minute arrived at the registrar
int Student::getMinuteArrived()
{
  return m_minuteArrived;
}

//Returns the number of minutes waited in the queue
int Student::getMinutesWaited()
{
  return m_minutesWaited;
  // cout << "incremented time in list" << endl;
}

//Returns the number of minutes at the window
int Student::getMinutesAtWindow()
{
  return m_minutesAtWindow;
}

//Returns true if student is done
bool Student::isDone()
{
  if (m_minutesAtWindow >= m_minutesNeeded)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Prints the stats of a student
void Student::printInfo()
{
  cout << "-------" << endl;
  cout << "Minutes needed: " << m_minutesNeeded << endl;
  cout << "Minute arrived: " << m_minuteArrived << endl;
  cout << "Minutes waited: " << m_minutesWaited << endl;
  cout << "Minutes at window: " << m_minutesAtWindow << endl;
  cout << "-------" << endl;
}
