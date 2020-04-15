#include "Student.h"
#include "List.h"

class StudentQueue : public List<Student>
{
  //Student Queue: isEmpty(), size(), insert(),
  //remove() (remember this is fifo)

  public:
    StudentQueue(); //Default constructor
    ~StudentQueue(); //Destructor

    void insertFront(Student data);
    void insertBack(Student data);
    Student removeFront();
    Student removeBack();
    Student removeAtPos(int pos);
    Student remove(Student val);

    bool isEmpty();
    int size();


  private:
    DoublyLinkedList<Student>* list;

};
