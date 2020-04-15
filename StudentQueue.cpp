#include "StudentQueue.h"

StudentQueue::StudentQueue()
{
  list = new DoublyLinkedList<Student>;
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
