#include "Window.h"

Window::Window()
{
  Occupied = false;
  total_idle_time = 0;
}

Window::~Window()
{

}

bool Window::isOccupied()
{
  return Occupied;
}
void Window::setOccupied()
{
  Occupied = true;
}

void Window::setUnoccupied()
{
  Occupied = false;
}

void Window::increment_idle_time()
{
  total_idle_time += 1;
}

void Window::insert_student(Student* student)
{
  student_at_window = student;
}

Student* Window::return_student()
{
  return student_at_window;
}
