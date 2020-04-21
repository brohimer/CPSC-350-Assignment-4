#include "Simulation.h"

Simulation::Simulation()
{

}

Simulation::~Simulation()
{
  delete m_registrar;
}

void Simulation::test()
{
  Registrar* reggie = new Registrar(5);
  reggie->incCurrentTick();
  Student* notolivermathias = new Student(0,1);

  cout << "Students Waiting: "<< reggie->getStudentsWaiting() << endl;
  reggie->addStudentToQueue(notolivermathias);
  cout << "Students Waiting: "<< reggie->getStudentsWaiting() << endl;
  cout << "Windows Open: "<<reggie->getWindowsOpen() << endl;
  reggie->incArrivedStudentWaitTimes();
  reggie->incArrivedStudentWaitTimes();
  reggie->incArrivedStudentWaitTimes();
  reggie->sendFirstStudentToFirstOpenWindow();
  cout << "Windows Open: "<< reggie->getWindowsOpen() << endl;
  reggie->incStudentWindowTimes();
  reggie->incStudentWindowTimes();

  reggie->moveDoneStudents();
  cout << "Windows Open: "<< reggie->getWindowsOpen() << endl;
}

void Simulation::start(string file)
{
  ifstream inFS;
  string line = "";
  int lineNumber = 0;
  int minuteArrived = 0;
  int targetLineNumber = 0; //Line to end an information section
  bool newBlock = true;
  bool lineOfStudentCount = true;
  int totalStudents = 0;

  //Reading input file and parsing lines
  inFS.open("test.txt");
  while (!inFS.eof())
  {
    getline(inFS, line);
    if (!inFS.fail())
    {
      //Not first line of the file
      if (lineNumber != 0)
      {
        //New block of information, so get minute students arrived
        if (newBlock == true)
        {
          //cout << line << " Getting da minute." << endl;
          minuteArrived = stoi(line);
          newBlock = false;
          lineOfStudentCount = true;
        }
        //Non-first lines of an information block
        else if (newBlock == false)
        {
          //Getting the number of students
          if (lineOfStudentCount == true)
          {
            //cout << line << " Finding the count" << endl;
            targetLineNumber = lineNumber + stoi(line);
            lineOfStudentCount = false;
          }
          //Making students with waiting times
          else if (lineNumber != targetLineNumber)
          {
            //cout << line << " Making a student" << endl;
            m_registrar->addStudentToQueue(new Student(stoi(line), minuteArrived));
            totalStudents += 1;
          }
          //This is the last student before next block of info
          else
          {
            //cout << line << " Making last student" << endl;
            m_registrar->addStudentToQueue(new Student(stoi(line), minuteArrived));
            totalStudents += 1;
            newBlock = true;
          }
        }
      }


      //For line 0, create a new registrar with X windows
      else
      {
        //cout << line << " Registrar Made." << endl;
        m_registrar = new Registrar(stoi(line));
      }
      lineNumber++;
    }
  }
  inFS.close();

  int totalWindows = m_registrar->getWindowsOpen();

  cout << endl << " testing!" << endl;
  // m_registrar->incCurrentTick();
  // m_registrar->incCurrentTick();
  //
  // m_registrar->updateStudentsWaiting();
  // cout << m_registrar->getStudentsWaiting() << endl;
  // m_registrar->sendFirstStudentToFirstOpenWindow();
  // cout << m_registrar->getStudentsWaiting() << endl;
  // m_registrar->sendFirstStudentToFirstOpenWindow();


  //Now that we obtained all students and arrival times, we simulate
  while (m_registrar->getDoneStudents() != totalStudents)
  {
    m_registrar->incCurrentTick();
    m_registrar->updateStudentsWaiting();
    m_registrar->updateWindowsOpen();
    m_registrar->incStudentWindowTimes();
    m_registrar->incArrivedStudentWaitTimes();
    m_registrar->moveDoneStudents();

    cout << "tick: " << m_registrar->getCurrentTick() << endl;

    //Set x to the number of arrived students,
    //and send as many to a window as possible
    int x = m_registrar->getStudentsWaiting();
    for (int j = 0; j < x; ++j)
    {
      m_registrar->sendFirstStudentToFirstOpenWindow();
    }
  }
  for (int i = 0; i < totalStudents; ++i)
  {
    cout << "ello" << endl;
    m_registrar->m_doneStudents->removeFront().printInfo();
  }
}
