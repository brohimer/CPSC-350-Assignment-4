#include "Student.h"

class StudentQueue
{
  //Student Queue: isEmpty(), size(), insert(),
  //remove() (remember this is fifo)

  public:
    StudentQueue(); //Default constructor
    ~StudentQueue(); //Destructor

    bool isEmpty();
    int size();
    void insert();
    Student* remove();

  private:
    DoublyLinkedList<int>* list;

};
