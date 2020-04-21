#include "Student.h"
#include "List.h"

class StudentQueue : public List<Student>
{
  //Student Queue: isEmpty(), size(), insert(),
  //remove() (remember this is fifo)

  public:
    StudentQueue(); //Default constructor
    ~StudentQueue(); //Destructor

    void insertFront(Student data); //No Implementation needed
    void insertBack(Student data); //Inserts a student to the back
    Student removeFront(); //Removes and returns a student from the front
    Student removeBack(); //No implementation needed
    Student removeAtPos(int pos); //No implementation needed
    Student remove(Student val); //No implementation needed

    bool isEmpty(); //Returns true if empty
    int size(); //Returns the size of the queue

    int numberOfArrivedStudentsBehindFirst(); //Returns the number of arrived students behind the first
    int numberOfArrivedStudents(int current_tick); //Returns the number of arrived students at current time
    void incArrivedStudentWaitTimes(int current_tick); //Increments the wait times of arrived students

  private:
    DoublyLinkedList<Student>* m_list; //List of students

};
