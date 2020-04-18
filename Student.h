#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student
{
  //.amount of time they will take, .time they arrived,
  //.how many ticks they’ve waited, updateticks()

  public:
    Student(); //Default constructor
    Student(int duration, int arrival); //Overloaded constructor
    ~Student(); //Destructor

    void update_tick();
    void printInfo();

  private:
    int minutes_needed_at_window;
    int minute_arrived;
    int number_of_minutes_waited;
};

#endif
