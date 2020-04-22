// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 4-22-2020
// Assignment: Registrar Office

/*
  This class is the template class for each node
  in the doubly linked list, (so we can store objects like students)
*/


#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

///ListNode header

template <class T>
class ListNode
{
  public:
    T m_data;
    ListNode<T>* m_next;
    ListNode<T>* m_prev;

    ListNode(); //Default constructor
    ListNode(T d); //Overloaded constructor
    ~ListNode(); //Destructor
};

#endif

//-----------------------------

//ListNode implementation

//Default constructor
template <class T>
ListNode<T>:: ListNode()
{
  m_next = NULL;
  m_prev = NULL;
}

//Overloaded constructor
template <class T>
ListNode<T>:: ListNode(T d)
{
  m_data = d;
  m_next = NULL;
  m_prev = NULL;
}

//Destructor
template <class T>
ListNode<T>::~ListNode()
{
  delete m_next;
  delete m_prev;
}
