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

    Student removeStudentFromQueue(); //Removes and returns the first waiting student

    int getStudentsWaiting(); //Returns the number of students waiting
    int getFirstOpenWindowIndex(); //Returns the index of the first open window
    int getWindowsOpen(); //Returns the number of open windows

    void updateWindowsOpen(); //Updates the number of windows open
    void updateStudentsWaiting(); //Updates the number of students waiting
    void updateCurrentTick(); //Updates the current clock tick

    void addStudentToQueue(Student* student); //Adds a student to the queue

    void sendFirstStudentToFirstOpenWindow(); //Sends the first student to the first window
    void moveDoneStudents(); //Clears done students from the windows

    void incStudentWindowTimes(); //Increments the window times of students
    void incArrivedStudentWaitTimes(); //Increments the wait times of arrived students in queue

  private:
    int m_currentTick; //Current tick
    int m_windowsOpen; //Number of open windows
    int m_totalWindows; //Total number of windows
    int m_studentsWaiting; //Number of students waiting
    Window* m_windows; //Array of windows
    StudentQueue* m_students; //Queue of waiting students
    StudentQueue* m_doneStudents; //Queue of finished students

};
