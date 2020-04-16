#include "Registrar.h"

Registrar::Registrar()
{
  current_tick = 0;
  windows_open = 0;
  students_waiting = 0;
}

Registrar::~Registrar()
{

}

void Registrar::update_students_waiting()
{
  //students_waiting = student_queue->size();
}
