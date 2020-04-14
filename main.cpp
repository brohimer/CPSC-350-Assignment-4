#include "DoublyLinkedList.h"

int main()
{
  DoublyLinkedList<char>* listy = new DoublyLinkedList<char>();
  listy->insertBack('f');
  listy->insertBack('g');
  listy->insertBack('h');
  // listy->removeFront();
  listy->printList();
  listy->removeAtPos(0);
  listy->printList();
  listy->removeAtPos(1);
  listy->printList();
  listy->removeBack();
  listy->printList();
  delete listy;
  return 0;
}
