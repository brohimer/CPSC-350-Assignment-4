#include "Student.h"

class Window
{

//Window Class: isOccupied(), setOccupied(), setUnoccupied()

  public:
    Window(); //Default constructor
    ~Window(); //Destructor

    bool isOccupied();
    void setOccupied();
    void setUnoccupied();
    void increment_idle_time();
    void insert_student(Student* student);
    Student* remove_student();
    Student* return_student();
    int getIdleTime();
    void increment_student_window_time();
    bool check_if_student_is_done();


  private:
    bool Occupied;
    int total_idle_time;
    Student* student_at_window;

};
