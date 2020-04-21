#include "StudentQueue.h"

//Implementation of StudentQueue

//Default constructor
StudentQueue::StudentQueue()
{
  m_list = new DoublyLinkedList<Student>();
}

//Destructor
StudentQueue::~StudentQueue()
{
  delete m_list;
}

//No implementation needed
void StudentQueue::insertFront(Student data) { }

void StudentQueue::insertBack(Student data)
{
  m_list->insertBack(data);
}

//Removes and returns a student from the front
Student StudentQueue::removeFront()
{
  return m_list->removeFront();
}

//No implementation needed
Student StudentQueue::removeBack() { }

//No implementation needed
Student StudentQueue::removeAtPos(int pos) { }

//No implementation needed
Student StudentQueue::remove(Student val) { }

//Returns the front student
Student* StudentQueue::getFront()
{
  return m_list->returnObjectPointerAtIndex(0);
}

//Returns true if empty
bool StudentQueue::isEmpty()
{
  return m_list->isEmpty();
}

//Returns the size of the queue
int StudentQueue::size()
{
  return m_list->getSize();
}

//Returns the number of arrived students behind the first
int StudentQueue::numberOfArrivedStudentsBehindFirst()
{
  int return_value = 0;
  int first_student_arival_time = m_list->returnObjectAtIndex(0).getMinuteArrived();
  for (int i = 1; i < size(); i++)
  {
    Student current_student = m_list->returnObjectAtIndex(i);
    if (current_student.getMinuteArrived() == first_student_arival_time)
    {
      return_value++;
    }
  }

  return return_value;
}

//Returns the number of arrived students at current time
int StudentQueue::numberOfArrivedStudents(int current_tick)
{
  int return_value = 0;
  for (int i = 0; i < size(); i++)
  {
    Student current_student = m_list->returnObjectAtIndex(i);
    if (current_student.getMinuteArrived() <= current_tick)
    {
      return_value++;
    }
  }
  return return_value;
}

//Increments the wait times of arrived students
void StudentQueue::incArrivedStudentWaitTimes(int current_tick)
{
  for (int i = 0; i < size(); i++)
  {
    Student* current_student = m_list->returnObjectPointerAtIndex(i);
    //this means the student has arrived.
    if (current_student->getMinuteArrived() <= current_tick)
    {
      //incrementing wait time in line
      current_student->incMinutesWaited();
      //cout << current_student->getMinutesWaited() << endl;
    }
  }
}
