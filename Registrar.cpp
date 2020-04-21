#include "Registrar.h"

//Registrar implementation

//Default constructor
Registrar::Registrar()
{
  m_currentTick = -1;
  m_windowsOpen = 0;
  m_totalWindows = 0;
  m_numStudentsWaiting = 0;

  //making an array of open windows
  m_windows = new Window[5];

  //making a new empty student queue
  m_students = new StudentQueue();
  m_doneStudents = new StudentQueue();
}

//Overloaded constructor for number of windows
Registrar::Registrar(int windows)
{
  m_currentTick = -1;
  m_numStudentsWaiting = 0;
  m_windowsOpen = windows;
  m_totalWindows = windows;

  //making an array of open windows
  m_windows = new Window[windows];

  for (int i = 0; i < m_totalWindows; ++i)
  {
    m_windows[i].setUnoccupied();
  }

  //making a new empty student queue
  m_students = new StudentQueue();
  m_doneStudents = new StudentQueue();
}

//Destructor
Registrar::~Registrar() { }

//Returns true if no students are waiting
bool Registrar::queueEmpty()
{
  return m_numStudentsWaiting == 0;
}

//Returns true if the done queue is empty
bool Registrar::doneQueueEmpty()
{
  return m_doneStudents->size() == 0;
}

//Removes and returns the first waiting student
Student Registrar::removeStudentFromQueue()
{
  m_numStudentsWaiting--;
  return m_students->removeFront();
}

 //Returns the number of students waiting
int Registrar::getStudentsWaiting()
{
  return m_numStudentsWaiting;
}

//Returns the number of students waiting
int Registrar::getDoneStudents()
{
 return m_doneStudents->size();
}

//Returns the index of the first open window
int Registrar::getFirstOpenWindowIndex()
{
  for (int i = 0; i < m_totalWindows; ++i)
  {
    if (m_windows[i].isOccupied() == false)
    {
      return i;
    }
  }
}

//Returns the number of open windows
int Registrar::getWindowsOpen()
{
  return m_windowsOpen;
}

//Returns the current tick
int Registrar::getCurrentTick()
{
  return m_currentTick;
}

//Updates the number of windows open
void Registrar::updateWindowsOpen()
{
  int current_windows_open = 0;
  for (int i = 0; i < m_totalWindows; ++i)
  {
    if (!m_windows[i].isOccupied())
    {
      current_windows_open += 1;
      m_windows[i].incIdleTime();
    }
  }
  m_windowsOpen = current_windows_open;
}

//Updates the number of students waiting
void Registrar::updateStudentsWaiting()
{
  m_numStudentsWaiting = m_students->numberOfArrivedStudents(m_currentTick);
}

//Adds a student to the queue
void Registrar::addStudentToQueue(Student* student)
{
  m_students->insertBack(*student);
  m_numStudentsWaiting++;
}

//Sends the first student to the first window
void Registrar::sendFirstStudentToFirstOpenWindow()
{
  if (m_windowsOpen < 1)
  {
    cout << "NO WINDOWS OPEN" << endl;
  }
  if (m_students->getFront()->getMinuteArrived() == m_currentTick)
  {
    Student first_student = removeStudentFromQueue();
    int i = getFirstOpenWindowIndex();
    cout << "I'm moving to window " << i << endl;
    m_windows[i].insertStudent(first_student);
    m_windowsOpen--;
  }
}

//Clears done students from the windows
void Registrar::moveDoneStudents()
{
  for (int i = 0; i < m_totalWindows; ++i)
  {
    if (m_windows[i].isOccupied())
    {
      if (m_windows[i].studentDone())
      {
        m_windows[i].setUnoccupied();
        m_doneStudents->insertBack(m_windows[i].removeStudent());
        // m_doneStudents->removeFront().printInfo();
        // cout << "Moved Done Student" << endl;
      }
    }
  }
}

//Updates the current clock tick
void Registrar::incCurrentTick()
{
  m_currentTick++;
}

//Increments the window times of students
void Registrar::incStudentWindowTimes()
{
  for (int i = 0; i < m_totalWindows; ++i)
  {
    if (m_windows[i].isOccupied())
    {
      m_windows[i].incStudentWindowTime();
    }
  }
}

//Increments the wait times of arrived students in queue
void Registrar::incArrivedStudentWaitTimes()
{
  m_students->incArrivedStudentWaitTimes(m_currentTick);
}
