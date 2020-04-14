#include "Student.h"

Student::Student()
{
  minutes_needed_at_window = 0;
  minute_arrived = 0;
  number_of_minutes_waited = 0;
}

Student::Student(int time_needed)
{
  minutes_needed_at_window = time_needed;
  minute_arrived = 0;
  number_of_minutes_waited = 0;
}

Student::~Student()
{

}

void Student::update_tick()
{
  number_of_minutes_waited += 1;
}
