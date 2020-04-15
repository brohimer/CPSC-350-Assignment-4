#ifndef ABSTRACTLIST_H
#define ABSTRACTLIST_H

#include "DoublyLinkedList.h"

template<class T>
class AbstractList
{
  public:
    AbstractList();
    virtual ~AbstractList();

    virtual void insertFront(T data) = 0;
    virtual void insertBack(T data) = 0;
    virtual T removeFront() = 0;
    virtual T removeBack() = 0;
    virtual T removeAtPos(int pos) = 0;
    virtual T remove(T val) = 0;

  private:
    DoublyLinkedList<T>* list;

};

#endif

template<class T>
AbstractList<T>::AbstractList()
{

}

template<class T>
AbstractList<T>::~AbstractList()
{

}
