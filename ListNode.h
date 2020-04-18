#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

///ListNode header

template <class T>
class ListNode
{
  public:
    T data;
    ListNode<T>* next;
    ListNode<T>* prev;

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
  next = NULL;
  prev = NULL;
}

//Overloaded constructor
template <class T>
ListNode<T>:: ListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

//Destructor
template <class T>
ListNode<T>::~ListNode()
{
  delete next;
  delete prev;
}
