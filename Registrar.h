// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 4-22-2020
// Assignment: Registrar Office

/*
  This class is the registrar header
  it controls most of the actions wrt. the queues and windows
*/

#include "Window.h"
#include "StudentQueue.h"

//Registrar header

class Registrar
{

//Registrar Class:
//.Current input file line, next group(), .current_time

  public:
    Registrar(); //Default constructor
    Registrar(int windows); //Overloaded constructor for number of windows
    ~Registrar(); //Destructor

    bool queueEmpty(); //Returns true if no students are waiting
    bool doneQueueEmpty(); //Returns true if done queue is empty

    Student removeStudentFromQueue(); //Removes and returns the first waiting student
    Student removeStudentFromDoneQueue(); //Removes and returns a student from the queue of done students

    int getStudentsWaiting(); //Returns the number of students waiting
    int getDoneStudents(); //Returns the number of done students
    int getFirstOpenWindowIndex(); //Returns the index of the first open window
    int getWindowsOpen(); //Returns the number of open windows
    int getCurrentTick(); //Returns the current tick
    Window& getWindow(int i); //Returns the window at the index
    Student getFirstDoneStudent(); //Returns the first done student to get its info
    Student getDoneStudentAt(int i); //Returns a done student at an index

    void updateWindowsOpen(); //Updates the number of windows open
    void updateStudentsWaiting(); //Updates the number of students waiting

    void addStudentToQueue(Student* student); //Adds a student to the queue

    void sendFirstStudentToFirstOpenWindow(); //Sends the first student to the first window
    void moveDoneStudents(); //Clears done students from the windows

    void incCurrentTick(); //Updates the current clock tick
    void incStudentWindowTimes(); //Increments the window times of students
    void incArrivedStudentWaitTimes(); //Increments the wait times of arrived students in queue

  private:
    int m_currentTick; //Current tick
    int m_windowsOpen; //Number of open windows
    int m_totalWindows; //Total number of windows
    int m_numStudentsWaiting; //Number of students waiting
    int m_numDoneStudents; //Number of done students
    StudentQueue* m_students; //Queue of waiting students
    StudentQueue* m_doneStudents; //Queue of finished students
    Window* m_windows; //Array of windows

};
