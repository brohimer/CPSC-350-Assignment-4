#include "Registrar.h"

Registrar::Registrar()
{
  current_tick = 0;
  windows_open = 0;
  students_waiting = 0;
}

Registrar::Registrar(int num_windows)
{
  current_tick = 0;
  students_waiting = 0;

  windows_open = num_windows;

  windows = new Window[num_windows];

  for (int i = 0; i < num_windows; i++)
  {
    windows[i].isOccupied();
    windows[i].getIdleTime();
  }

  //making a new empty student queue
  students = new StudentQueue();
}

Registrar::~Registrar()
{

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
