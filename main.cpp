#include "DoublyLinkedList.h"

int main()
{
  DoublyLinkedList<char> listy;
  listy.insertBack('f');
  listy.removeFront();
  listy.printList();
  listy.removeAtPos(0);
  return 0;
}
