#ifndef ABSTRACTLIST_H
#define ABSTRACTLIST_H

#include "DoublyLinkedList.h"

template<class T>
class List
{
  public:
    List();
    virtual ~List();

    virtual void insertFront(T data) = 0;
    virtual void insertBack(T data) = 0;
    virtual T removeFront() = 0;
    virtual T removeBack() = 0;
    virtual T removeAtPos(int pos) = 0;
    virtual T remove(T val) = 0;


};

#endif

template<class T>
List<T>::List() { }

template<class T>
List<T>::~List() { }
