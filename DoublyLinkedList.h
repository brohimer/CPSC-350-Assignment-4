#include "ListNode.h"
#include <iostream>
using namespace std;

///header file for SingleLinkedList
template <class T>
class DoublyLinkedList{
  public:
    DoublyLinkedList<T>();
    ~DoublyLinkedList<T>();

    void insertFront(T data);
    void insertBack(T data);
    T removeFront();
    T removeBack();
    T search(T val); //returns value or position of node, depends on implementation
    T removeAtPos(int pos);
    T remove(T val);
    void remove_abs(ListNode<T>* v);

    unsigned int getSize();
    bool isEmpty();
    void printList();

  private:
    ListNode<T>* front;
    ListNode<T>* back;
    unsigned int size;

};


//implementation file for DoublyLinkedList<T>
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  //empty list
  size = 0;
  front = 0;
  back = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  //do this on our own
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return (size == 0);
}

//while the current pointer does not == 0
//print the data of current address, then set current to NEXT address
template <class T>
void DoublyLinkedList<T>::printList()
{
  cout << "List: " << endl;
  ListNode<T>* curr = front;
  while (curr != 0)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  //check if isEmpty
  if (isEmpty())
  {
    back = node;
  }
  else
  {
    //set front.prev = the new ListNode<T>
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  //check if isEmpty
  if (isEmpty())
  {
    //if we insert from the back in an empty list,
    //the front pointer will point to our new node
    //b/c there's only one element.
    //so front and back pointers point to the same node.
    front = node;
  }
  else
  {
    //set front.prev = the new ListNode<T>
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class T>
T DoublyLinkedList<T>::removeFront()
{
  if (isEmpty())
    cout << "The List is Empty!!" << endl;
  else
  {
    ListNode<T>* temp = front;
    //->next goes from front to back, left to right
    //front->next->_____________________back
    if(front->next == 0)
    {
      //if this is true, we have only one node in list
      //back pointer is set to null
      back = 0;
    }
    else //if there is more than one node in the list
    {
      //setting the 2nd element's backwards pointer to null
      //b/c we're about to remove the first element
      front->next->prev = 0;
    }
    front = front->next;
    temp->next = 0;
    int tmp = temp->data;
    size--;

    delete temp;
    return tmp;
  }
}

template <class T>
T DoublyLinkedList<T>::removeBack()
{
  if (isEmpty())
    cout << "The List is Empty!!" << endl;
  else
  {
    ListNode<T>* temp = back;
    //->next goes from front to back, left to right
    //front->next____________________prev<-back
    if(back->prev == 0)
    {
      //if this is true, we have only one node in list
      //back pointer is set to null
      front = 0;
    }
    else //if there is more than one node in the list
    {
      //setting the 2nd element's backwards pointer to null
      //b/c we're about to remove the first element
      back->prev->next = 0;
    }
    back = back->prev;
    temp->next = 0;
    int tmp = temp->data;
    size--;

    delete temp;
    return tmp;
  }
}

template <class T>
//insert the value we're looking for
T DoublyLinkedList<T>::search(T val)
{
  int position = -1;
  ListNode<T>* curr = front;

  while (curr != 0)
  {
    //iterate and attempt to find the value
    position++;
    if (curr->data == val) break;
    else curr = curr->next;
  }

  if (curr==0)
  //this means we went through the whole loop
  //wihout finding the value
    position = -1;

  return position;

}

template <class T>
T DoublyLinkedList<T>::removeAtPos(int pos)
{
  //add some error checking to make sure our pos is not negative
  //and is within the bounds of the list

  if ((pos > 0) && (isEmpty() == false))
  {
    //start at beginning so that we can traverse the linkedlist
    int idx = 0;
    ListNode<T>* curr = front;
    ListNode<T>* prev = front;

    //now we loop until our current and prev pointers are in the right position
    while(idx != pos)
    {
      prev = curr;
      curr = curr->next;
      idx++;
    }

    //below here we have the position of the node to be deleted
    //so now previous next becomes current next instead of current.

    prev->next = curr->next;
    curr->next = 0;

    int temp = curr->data;
    delete curr;
    size--;
    return temp;
  }

  else
    cout << "Position Invalid or List Empty." << endl;

}

template <class T>
T DoublyLinkedList<T>::remove(T val)
{
  ListNode<T>* curr = front;

  //loop until we find the value we want
  while(curr->data != val)
  {
    curr = curr->next;
    //if it's not in the list
    if (curr==0)
      return 0;
  }

  if (curr==front)
  {
    //removeFront();
    front = curr->next;
    curr->next->prev = 0;
  }
  //problem with remove function, curr is not engaged even when at the back!!
  //doesn't seem to recognize that it's at the back or something like that
  //else if (curr->data==1) works with this code b/c it's also the only one
  else if (curr->next==0)
  {
    //removeBack();
    back = curr->prev;
    curr->prev->next = 0;
  }
  else
  {
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
  }

  curr->next = 0;
  curr->prev = 0;
  //set temp eqal to target data so that
  //after we delete it, we can still return something
  int temp = curr->data;
  delete curr;
  size--;

  return temp;
}
