#include "Registrar.h"

Registrar::Registrar()
{
  current_tick = 0;
  windows_open = 0;
  total_windows = 0;
  students_waiting = 0;

  //making an array of open windows
  windows = new Window[5];

  //making a new empty student queue
  students = new StudentQueue();
  doneStudents = new StudentQueue();
}

Registrar::Registrar(int num_windows)
{
  current_tick = 0;
  students_waiting = 0;
  windows_open = num_windows;
  total_windows = num_windows;

  //making an array of open windows
  windows = new Window[num_windows];

  for (int i = 0; i < total_windows; ++i)
  {
    windows[i].setUnoccupied();
  }

  //making a new empty student queue
  students = new StudentQueue();
  doneStudents = new StudentQueue();
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
  for (int i = 0; i < total_windows; i++)
  {
    if (!windows[i].isOccupied())
      current_windows_open += 1;
  }
  windows_open = current_windows_open;
}

int Registrar::get_number_of_windows_open()
{
  update_number_of_windows_open();
  return windows_open;
}

int Registrar::get_students_waiting()
{
  return students_waiting;
}

void Registrar::add_student_to_queue(Student* student)
{
  students->insertBack(*student);
  students_waiting++;
}

Student Registrar::remove_student_from_queue()
{
  students_waiting--;
  return students->removeFront();
}

bool Registrar::empty_queue()
{
  return students_waiting == 0;
}

void Registrar::update_current_tick()
{
  current_tick++;
}

void Registrar::update_students_waiting()
{
  students_waiting = students->numberOfArrivedStudents(current_tick);
}

void Registrar::send_first_student_in_line_to_first_open_window()
{
  update_number_of_windows_open();
  if (windows_open < 1) cout << "NO WINDOWS OPEN" << endl;
  Student first_student = remove_student_from_queue();
  windows[get_index_of_first_available_window()].insert_student(first_student);
  windows_open--;
}

//increment students time at windows
void Registrar::increment_student_window_times_if_at_windows()
{
  for (int i = 0; i < total_windows; i++)
  {
    if (windows[i].isOccupied())
    {
      windows[i].increment_student_window_time();
    }
  }
}

//clear done students from windows.
void Registrar::move_done_students()
{
  for (int i = 0; i < total_windows; i++)
  {
    if (windows[i].isOccupied())
    {
      if (windows[i].check_if_student_is_done())
      {
        doneStudents->insertBack(windows[i].remove_student());
        cout << "Mins in List: "<< doneStudents->removeFront().get_number_of_minutes_in_line() << endl;
        cout << "Moved Done Student" << endl;
      }
    }
  }
}

void Registrar::increment_all_student_wait_times_if_in_line_and_have_arrived()
{
  students->increment_all_student_wait_times_if_in_line_and_have_arrived(current_tick);
}
