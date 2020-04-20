#include "StudentQueue.h"

StudentQueue::StudentQueue()
{
  list = new DoublyLinkedList<Student>();
}

StudentQueue::~StudentQueue()
{
  delete list;
}

void StudentQueue::insertFront(Student data)
{
  //No implementation needed.
}

void StudentQueue::insertBack(Student data)
{
  list->insertBack(data);
}

Student StudentQueue::removeFront()
{
  return list->removeFront();
}

Student StudentQueue::removeBack()
{
  //No implementation needed.
}

Student StudentQueue::removeAtPos(int pos)
{
  //No implementation needed.
}

Student StudentQueue::remove(Student val)
{
  //No implementation needed.
}

bool StudentQueue::isEmpty()
{
  return list->isEmpty();
}

int StudentQueue::size()
{
  return list->getSize();
}

int StudentQueue::numberOfStudentsBehindTheFirstThatArrivedAtTheSameTime()
{
  int return_value = 0;
  int first_student_arival_time = list->returnObjectAtIndex(0).get_arrival_time();
  for (int i = 1; i < size(); i++)
  {
    Student current_student = list->returnObjectAtIndex(i);
    if (current_student.get_arrival_time() == first_student_arival_time)
    {
      return_value++;
    }
  }

  return return_value;
}

int StudentQueue::numberOfArrivedStudents(int current_tick)
{
  int return_value = 0;
  for (int i = 0; i < size(); i++)
  {
    Student current_student = list->returnObjectAtIndex(i);
    if (current_student.get_arrival_time() <= current_tick)
    {
      return_value++;
    }
  }

  return return_value;
}

void StudentQueue::increment_all_student_wait_times_if_in_line_and_have_arrived(int current_tick)
{
  for (int i = 0; i < size(); i++)
  {
    Student* current_student = list->returnObjectPointerAtIndex(i);
    //this means the student has arrived.
    if (current_student->get_arrival_time() <= current_tick)
    {
      //incrementing wait time in line
      current_student->update_tick();
      cout << current_student->get_number_of_minutes_in_line() << endl;
    }
  }
}
