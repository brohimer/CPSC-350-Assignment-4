#include "Registrar.h"

Registrar::Registrar()
{
  current_tick = 0;
  windows_open = 0;
  total_windows = 0;
  students_waiting = 0;
}

Registrar::Registrar(int num_windows)
{
  current_tick = 0;
  students_waiting = 0;
  windows_open = num_windows;
  total_windows = num_windows;

  //making an array of open windows
  windows = new Window[num_windows];

  //making a new empty student queue
  students = new StudentQueue();
}

Registrar::~Registrar()
{

}

int Registrar::get_index_of_first_available_window()
{
  for (int i = 0; i < total_windows; ++i)
  {
    if (windows[i].isOccupied() == false)
    {
      return i;
    }
  }
}

void Registrar::update_number_of_windows_open()
{
  int current_windows_open = 0;
  for (int i = 0; i < total_windows; ++i)
  {
    if (!windows[i].isOccupied())
      current_windows_open += 1;
  }
  windows_open = current_windows_open;
}

int Registrar::get_number_of_windows_open()
{
  return windows_open;
}

void Registrar::update_students_waiting()
{
  students_waiting = students->size();
}

int Registrar::get_students_waiting()
{
  return students_waiting;
}

void Registrar::add_student_to_queue(Student* student)
{
  students->insertBack(*student);
}
