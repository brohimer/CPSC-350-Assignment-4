#include "Student.h"

//Window header

class Window
{
  public:
    Window(); //Default constructor
    ~Window(); //Destructor

    bool isOccupied(); //Returns true if occupied
    bool studentDone(); //Returns true if student is done

    void setOccupied(); //Sets window to occupied
    void setUnoccupied(); //Sets window to unoccupied
    void incIdleTime(); //Increments idle time
    void incStudentWindowTime(); //Increments the student's window time
    void insertStudent(Student student); //Inserts a student at window

    Student removeStudent(); //Removes and returns a student from window
    Student getStudent(); //Returns student at window
    int getIdleTime(); //Returns the idle time

  private:
    bool m_occupied; //True if occupied
    int m_totalIdleTime; //Count for total idle time
    Student m_student; //Student at window

};
