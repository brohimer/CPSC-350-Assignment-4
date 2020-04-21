#ifndef ABSTRACTLIST_H
#define ABSTRACTLIST_H

#include "DoublyLinkedList.h"

//List interface using DoublyLinkedList

template<class T>
class List
{
  public:
    List(); //Constructor
    virtual ~List(); //Destructor

    virtual void insertFront(T data) = 0; //Inserts an element to the front
    virtual void insertBack(T data) = 0; //Inserts an element to the back
    virtual T removeFront() = 0; //Removes a node from the front and returns its element
    virtual T removeBack() = 0; //Removes a node from the back and returns its element
    virtual T removeAtPos(int pos) = 0; //Removes a node at a specified position and returns its element
    virtual T remove(T val) = 0; //Removes a value-specified node and returns its value

};

#endif

//No implementation needed
template<class T>
List<T>::List() { }

//No implementation needed
template<class T>
List<T>::~List() { }
