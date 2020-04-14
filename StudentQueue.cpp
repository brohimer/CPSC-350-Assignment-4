#include "DoublyLinkedList.h"
#include "StudentQueue.h"


StudentQueue::StudentQueue()
{
  //change later to work with students
  list = new DoublyLinkedList<int>;
}

StudentQueue::~StudentQueue()
{
  delete list;
}

bool StudentQueue::isEmpty()
{
  return list->isEmpty();
}

int StudentQueue::size()
{
  return list->getSize();
}


//change these two later to work with student
void StudentQueue::insert()
{

}

Student* StudentQueue::remove()
{

}
