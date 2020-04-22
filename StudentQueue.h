// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 4-22-2020
// Assignment: Registrar Office

/*
  Header for the student queue
*/

#include "Student.h"
#include "List.h"

class StudentQueue : public List<Student>
{

  public:
    StudentQueue(); //Default constructor
    ~StudentQueue(); //Destructor

    void insertFront(Student data); //No Implementation needed
    void insertBack(Student data); //Inserts a student to the back
    Student removeFront(); //Removes and returns a student from the front
    Student removeBack(); //No implementation needed
    Student removeAtPos(int pos); //No implementation needed
    Student remove(Student val); //No implementation needed
    Student getFront(); //Returns the front student
    Student getStudentAtIndex(int i); //Returns a student at the index

    bool isEmpty(); //Returns true if empty
    int size(); //Returns the size of the queue

    int numberOfArrivedStudentsBehindFirst(); //Returns the number of arrived students behind the first
    int numberOfArrivedStudents(int current_tick); //Returns the number of arrived students at current time
    void incArrivedStudentWaitTimes(int current_tick); //Increments the wait times of arrived students

  private:
    DoublyLinkedList<Student>* m_list; //List of students

};
