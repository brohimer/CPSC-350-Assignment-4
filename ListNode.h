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
