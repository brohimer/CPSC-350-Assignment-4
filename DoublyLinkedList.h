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
    T removeBack(); //Removes a node from the front and returns its element
    T search(T val); //Returns position of a searched node
    T removeAtPos(int pos); //Removes a node at a specified position and returns its element
    T remove(T val); //Removes a value-specified node and returns its value
    T returnObjectAtIndex(int i);

    unsigned int getSize(); //Returns the size
    bool isEmpty(); //Returns true if the list is empty
    void printList(); //Prints the list

  private:
    ListNode<T>* front; //Pointer to the front of the list
    ListNode<T>* back; //Pointer to the back of the list
    unsigned int size; //Size of the list
};

//-----------------------------

//DoublyLinkedList implementation

//Default constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  front = new ListNode<T>();
  back = new ListNode<T>();
  size = 0;
  front = NULL;
  back = NULL;
}

//Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  while (!this->isEmpty())
  {
    this->removeFront();
  }
  front = NULL;
  back = NULL;
  delete front;
  delete back;
}

//Inserts an element to the front
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

//Removes a node from the front and returns its element
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
    if(front->next == NULL)
    {
      //if this is true, we have only one node in list
      //back pointer is set to null
      back = NULL;
    }
    else //if there is more than one node in the list
    {
      //setting the 2nd element's backwards pointer to null
      //b/c we're about to remove the first element
      front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    T tmp = temp->data;
    size--;

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
    ListNode<T>* temp = back;
    //->next goes from front to back, left to right
    //front->next____________________prev<-back
    if(back->prev == NULL)
    {
      //if this is true, we have only one node in list
      //back pointer is set to null
      front = NULL;
    }
    else //if there is more than one node in the list
    {
      //setting the 2nd element's backwards pointer to null
      //b/c we're about to remove the first element
      back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    int tmp = temp->data;
    size--;

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
  ListNode<T>* curr = front;

  while (curr != NULL)
  {
    //iterate and attempt to find the value
    position++;
    if (curr->data == val) break;
    else curr = curr->next;
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

  else if(pos == size-1)
  {
    return removeBack();
  }

  else if ((pos > 0) && (isEmpty() == false))
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

    //we found the position of the node to be deleted
    prev->next = curr->next;
    curr->next->prev = prev;
    curr->prev = NULL;
    curr->next = NULL;
    T temp = curr->data;
    curr = NULL;
    prev = NULL;
    delete curr;
    delete prev;

    size--;
    return temp;
  }

  else
    cout << "Position Invalid or List Empty." << endl;
}

//Removes a value-specified node and returns its value
template <class T>
T DoublyLinkedList<T>::remove(T val)
{
  ListNode<T>* curr = front;

  //loop until we find the value we want
  while(curr->data != val)
  {
    curr = curr->next;
    //if it's not in the list
    if (curr == NULL)
      return NULL;
  }

  if (curr == front)
  {
    //removeFront();
    front = curr->next;
    curr->next->prev = NULL;
  }
  //problem with remove function, curr is not engaged even when at the back!!
  //doesn't seem to recognize that it's at the back or something like that
  //else if (curr->data==1) works with this code b/c it's also the only one
  else if (curr->next == NULL)
  {
    //removeBack();
    back = curr->prev;
    curr->prev->next = NULL;
  }
  else
  {
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
  }

  curr->next = NULL;
  curr->prev = NULL;
  //set temp eqal to target data so that
  //after we delete it, we can still return something
  T temp = curr->data;
  delete curr;
  size--;

  return temp;
}

//Returns the size
template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

//Returns true if the list is empty
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return (size == 0);
}

//Prints the list
template <class T>
void DoublyLinkedList<T>::printList()
{
  cout << "List: " << endl;
  ListNode<T>* curr = front;
  //while the current pointer does not == 0
  //print the data of current address, then set current to NEXT address
  while (curr != NULL)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

//Removes a node from the front and returns its element
template <class T>
T DoublyLinkedList<T>::returnObjectAtIndex(int i)
{
  //make sure it's not empty first
  int idx = 0;
  ListNode<T>* curr = front;
  ListNode<T>* prev = front;

  //now we loop until our current and prev pointers are in the right position
  while(idx != i)
  {
    prev = curr;
    curr = curr->next;
    idx++;
  }

  T temp = curr->data;
  return temp;
}
