#include "Window.h"

//Window implementation

//Default constructor
Window::Window()
{
  m_occupied = false;
  m_totalIdleTime = -1;
}

//Destructor
Window::~Window() { }

//Returns true if occupied
bool Window::isOccupied()
{
  return m_occupied;
}

//Returns true if student is done
bool Window::studentDone()
{
  return (m_student.isDone());
}

//Sets window to occupied
void Window::setOccupied()
{
  m_occupied = true;
}

//Sets window to unoccupied
void Window::setUnoccupied()
{
  m_occupied = false;
}

//Increments idle time
void Window::incIdleTime()
{
  m_totalIdleTime += 1;
}

//Increments the student's window time
void Window::incStudentWindowTime()
{
  if (m_occupied)
    m_student.incMinutesAtWindow();
}

//Inserts a student at window
void Window::insertStudent(Student student)
{
  m_student = student;
  m_occupied = true;
}

//Removes and returns a student from window
Student Window::removeStudent()
{
  m_occupied = false;
  return m_student;
}

//Returns student at window
Student Window::getStudent()
{
  return m_student;
}

//Returns the idle time
int Window::getIdleTime()
{
  return m_totalIdleTime;
}
