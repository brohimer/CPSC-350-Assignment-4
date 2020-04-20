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

    int numberOfStudentsBehindTheFirstThatArrivedAtTheSameTime();
    int numberOfArrivedStudents(int current_tick);

    void increment_all_student_wait_times_if_in_line_and_have_arrived(int current_tick);


  private:
    DoublyLinkedList<Student>* list;

};
