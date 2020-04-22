// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 4-22-2020
// Assignment: Registrar Office

/*
  this class contains the doubly linked list template class
  that we use to build the student queue class
*/

#include "ListNode.h"

//DoublyLinkedList header

template <class T>
class DoublyLinkedList{
  public:
    DoublyLinkedList<T>(); //Constructor
    ~DoublyLinkedList<T>(); //Destructor

    void insertFront(T data); //Inserts an element to the front
    void insertBack(T data); //Inserts an element to the back
    T removeFront(); //Removes a node from the front and returns its element
    T removeBack(); //Removes a node from the back and returns its element
    T search(T val); //Returns position of a searched node
    T removeAtPos(int pos); //Removes a node at a specified position and returns its element
    T remove(T val); //Removes a value-specified node and returns its value
    T returnObjectAtIndex(int i); //Returns the object stored at an index
    T* returnObjectPointerAtIndex(int i); //Returns the pointer to the object stored at an index

    unsigned int getSize(); //Returns the size
    bool isEmpty(); //Returns true if the list is empty
    void printList(); //Prints the list

  private:
    ListNode<T>* m_front; //Pointer to the front of the list
    ListNode<T>* m_back; //Pointer to the back of the list
    unsigned int m_size; //Size of the list
};

//-----------------------------

//DoublyLinkedList implementation

//Default constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  m_front = new ListNode<T>();
  m_back = new ListNode<T>();
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

//Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  while (!this->isEmpty())
  {
    this->removeFront();
  }
  m_front = NULL;
  m_back = NULL;
  delete m_front;
  delete m_back;
}

//Inserts an element to the front
template <class T>
void DoublyLinkedList<T>::insertFront(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  //check if isEmpty
  if (isEmpty())
  {
    m_back = node;
  }
  else
  {
    //set front.prev = the new ListNode<T>
    m_front->m_prev = node;
    node->m_next = m_front;
  }
  m_front = node;
  m_size++;
}

//Inserts an element to the back
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
    m_front = node;
  }
  else
  {
    //set front.prev = the new ListNode<T>
    m_back->m_next = node;
    node->m_prev = m_back;
  }
  m_back = node;
  m_size++;
}

//Removes a node from the front and returns its element
template <class T>
T DoublyLinkedList<T>::removeFront()
{
  if (isEmpty())
    cout << "The List is Empty!!" << endl;
  else
  {
    ListNode<T>* temp = m_front;
    //->next goes from front to back, left to right
    //front->next->_____________________back
    if(m_front->m_next == NULL)
    {
      //if this is true, we have only one node in list
      //back pointer is set to null
      m_back = NULL;
    }
    else //if there is more than one node in the list
    {
      //setting the 2nd element's backwards pointer to null
      //b/c we're about to remove the first element
      m_front->m_next->m_prev = NULL;
    }
    m_front = m_front->m_next;
    temp->m_next = NULL;
    T tmp = temp->m_data;
    m_size--;

    delete temp;
    return tmp;
  }
}

//Removes a node from the back and returns its element
template <class T>
T DoublyLinkedList<T>::removeBack()
{
  if (isEmpty())
    cout << "The List is Empty!!" << endl;
  else
  {
    ListNode<T>* temp = m_back;
    //->next goes from front to back, left to right
    //front->next____________________prev<-back
    if(m_back->m_prev == NULL)
    {
      //if this is true, we have only one node in list
      //back pointer is set to null
      m_front = NULL;
    }
    else //if there is more than one node in the list
    {
      //setting the 2nd element's backwards pointer to null
      //b/c we're about to remove the first element
      m_back->m_prev->m_next = NULL;
    }
    m_back = m_back->m_prev;
    temp->m_prev = NULL;
    int tmp = temp->m_data;
    m_size--;

    delete temp;
    return tmp;
  }
}

//Returns position of a searched node
template <class T>
//insert the value we're looking for
T DoublyLinkedList<T>::search(T val)
{
  int position = -1;
  ListNode<T>* curr = m_front;

  while (curr != NULL)
  {
    //iterate and attempt to find the value
    position++;
    if (curr->m_data == val) break;
    else curr = curr->m_next;
  }

  if (curr == NULL)
  //this means we went through the whole loop
  //wihout finding the value
    position = -1;

  return position;

}

//Removes a node at a specified position and returns its element
template <class T>
T DoublyLinkedList<T>::removeAtPos(int pos)
{
  //add some error checking to make sure our pos is not negative
  //and is within the bounds of the list

  if(pos == 0)
  {
    return removeFront();
  }

  else if(pos == m_size-1)
  {
    return removeBack();
  }

  else if ((pos > 0) && (isEmpty() == false))
  {
    //start at beginning so that we can traverse the linkedlist
    int idx = 0;
    ListNode<T>* curr = m_front;
    ListNode<T>* prev = m_front;

    //now we loop until our current and prev pointers are in the right position
    while(idx != pos)
    {
      prev = curr;
      curr = curr->m_next;
      idx++;
    }

    //below here we have the position of the node to be deleted
    //so now previous next becomes current next instead of current.

    //we found the position of the node to be deleted
    prev->m_next = curr->m_next;
    curr->m_next->m_prev = prev;
    curr->m_prev = NULL;
    curr->m_next = NULL;
    T temp = curr->m_data;
    curr = NULL;
    prev = NULL;
    delete curr;
    delete prev;

    m_size--;
    return temp;
  }

  else
    cout << "Position Invalid or List Empty." << endl;
}

//Removes a value-specified node and returns its value
template <class T>
T DoublyLinkedList<T>::remove(T val)
{
  ListNode<T>* curr = m_front;

  //loop until we find the value we want
  while(curr->m_data != val)
  {
    curr = curr->m_next;
    //if it's not in the list
    if (curr == NULL)
      return NULL;
  }

  if (curr == m_front)
  {
    //removeFront();
    m_front = curr->m_next;
    curr->m_next->m_prev = NULL;
  }
  //problem with remove function, curr is not engaged even when at the back!!
  //doesn't seem to recognize that it's at the back or something like that
  //else if (curr->data==1) works with this code b/c it's also the only one
  else if (curr->m_next == NULL)
  {
    //removeBack();
    m_back = curr->m_prev;
    curr->m_prev->m_next = NULL;
  }
  else
  {
    curr->m_next->m_prev = curr->m_prev;
    curr->m_prev->m_next = curr->m_next;
  }

  curr->m_next = NULL;
  curr->m_prev = NULL;
  //set temp eqal to target data so that
  //after we delete it, we can still return something
  T temp = curr->m_data;
  delete curr;
  m_size--;

  return temp;
}

//Returns the size
template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return m_size;
}

//Returns true if the list is empty
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return (m_size == 0);
}

//Prints the list
template <class T>
void DoublyLinkedList<T>::printList()
{
  cout << "List: " << endl;
  ListNode<T>* curr = m_front;
  //while the current pointer does not == 0
  //print the data of current address, then set current to NEXT address
  while (curr != NULL)
  {
    cout << curr->m_data << endl;
    curr = curr->m_next;
  }
}

//Returns the object stored at an index
template <class T>
T DoublyLinkedList<T>::returnObjectAtIndex(int i)
{
  //make sure it's not empty first
  int idx = 0;
  ListNode<T>* curr = m_front;
  ListNode<T>* prev = m_front;

  //now we loop until our current and prev pointers are in the right position
  while(idx != i)
  {
    prev = curr;
    curr = curr->m_next;
    idx++;
  }

  T temp = curr->m_data;
  return temp;
}

//Returns the pointer to the object stored at an index
template <class T>
T* DoublyLinkedList<T>::returnObjectPointerAtIndex(int i)
{
  //make sure it's not empty first
  int idx = 0;
  ListNode<T>* curr = m_front;
  ListNode<T>* prev = m_front;

  //now we loop until our current and prev pointers are in the right position
  while(idx != i)
  {
    prev = curr;
    curr = curr->m_next;
    idx++;
  }

  T* temp = &curr->m_data;
  return temp;
}
