#include <iomanip>
#include "Simulation.h"

Simulation::Simulation() { }

Simulation::~Simulation()
{
  delete m_registrar;
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

  cout << endl << "Running!" << endl;

  //Now that we obtained all students and arrival times, we simulate
  while (m_registrar->getDoneStudents() != totalStudents)
  {
    m_registrar->incCurrentTick();
    cout << endl << "tick: " << m_registrar->getCurrentTick() << endl;
    m_registrar->updateStudentsWaiting();
    m_registrar->updateWindowsOpen();
    m_registrar->incStudentWindowTimes();
    m_registrar->incArrivedStudentWaitTimes();
    m_registrar->moveDoneStudents();

    //Set x to the number of arrived students,
    //and send as many to a window as possible
    int x = m_registrar->getStudentsWaiting();
    for (int j = 0; j < x; ++j)
    {
      m_registrar->sendFirstStudentToFirstOpenWindow();
    }
  }

  //Now, we calculate the stats from our queue of finished students
  double meanStudentWait = 0.0;
  double medianStudentWait = 0.0;
  int longestStudentWait = 0;
  int studentsWaitingOverTenMin = 0;
  double medianWindowIdle = 0.0;
  int longestWindowIdle = 0;
  int windowsIdleOverTenMin = 0;

  //Calculate the mean  student wait time
  //Calculate the median student wait time
  //Calculate the number of wait times over 10
  for (int i = 0; i < totalStudents; ++i)
  {
    meanStudentWait += m_registrar->getDoneStudentAt(i).getMinutesWaited();
    if (m_registrar->getDoneStudentAt(i).getMinutesWaited() > longestStudentWait)
    {
      longestStudentWait = m_registrar->getDoneStudentAt(i).getMinutesWaited();
    }
    if (m_registrar->getDoneStudentAt(i).getMinutesWaited() > 10)
    {
      studentsWaitingOverTenMin += 1;
    }
  }
  meanStudentWait /= totalStudents;

  //Calculate the median of student wait time
  if (totalStudents % 2 == 0)
  {
    //For an even lengthed queue
    int leftMiddle = (totalStudents / 2) - 1;
    int rightMiddle = (totalStudents / 2);
    double leftWait = m_registrar->getDoneStudentAt(leftMiddle).getMinutesWaited();
    double rightWait = m_registrar->getDoneStudentAt(rightMiddle).getMinutesWaited();
    medianStudentWait = (leftWait + rightWait) / 2;
  }
  else
  {
    //For an odd lengthed queue
    int middle = totalStudents / 2;
    medianStudentWait = m_registrar->getDoneStudentAt(middle).getMinutesWaited();
  }

  //Calculate the mean window idle time
  //Calculate the longest window idle time
  //Calculate the number of windows idle over 5 minutes
  for (int i = 0; i < totalWindows; ++i)
  {
    medianWindowIdle += m_registrar->getWindow(i).getIdleTime();
    if (m_registrar->getWindow(i).getIdleTime() > longestWindowIdle)
    {
      longestWindowIdle = m_registrar->getWindow(i).getIdleTime();
    }
    if (m_registrar->getWindow(i).getIdleTime() > 5)
    {
      windowsIdleOverTenMin += 1;
    }
  }
  medianWindowIdle /= totalWindows;


  cout << endl << setw(50) << setfill('-') << " " << endl << endl;
  cout << setw(50) << setfill(' ') << left << "SIMULATION RESULTS:" << endl << endl;
  cout << setw(50) << setfill('.') << left << "Mean student wait time: " << " " << meanStudentWait << endl;
  cout << setw(50) << left << "Median student wait time: " << " " << medianStudentWait << endl;
  cout << setw(50) << left << "Longest student wait time: " << " " << longestStudentWait << endl;
  cout << setw(50) << left << "Number of students waiting over 10 minutes: " << " " << studentsWaitingOverTenMin << endl;
  cout << setw(50) << left << "Mean window idle time: " << " " << medianWindowIdle << endl;
  cout << setw(50) << left << "Longest window idle time: " << " " << longestWindowIdle << endl;
  cout << setw(50) << left << "Number of windows idle over 5 minutes: " << " " << windowsIdleOverTenMin << endl << endl;

}
