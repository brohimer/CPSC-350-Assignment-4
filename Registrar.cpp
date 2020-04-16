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

  windows[num_windows];

  for (int i = 0; i < num_windows; i++)
  {
    Window* windy = new Window();
    windows[i] = windy;
    cout << "Window Created" << endl;
  }

  for (int i = 0; i < num_windows; i++)
  {
    cout << windows[i]->isOccupied() << endl;
  }
}

Registrar::~Registrar()
{

}

void Registrar::update_students_waiting()
{
  //students_waiting = student_queue->size();
}
