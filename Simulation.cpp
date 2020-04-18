#include "Simulation.h"

Simulation::Simulation()
{

}

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
          cout << line << " Getting da minute." << endl;
          minuteArrived = stoi(line);
          newBlock = false;
          lineOfStudentCount = true;
        }
        //Getting the number of students
        else if (newBlock == false)
        {
          if (lineOfStudentCount == true)
          {
            cout << line << " Finding the count" << endl;
            targetLineNumber = lineNumber + stoi(line);
            lineOfStudentCount = false;
          }
          //Making new students
          else if (lineNumber != targetLineNumber)
          {
            cout << line << " Making a student" << endl;
          }
          else
          {
            cout << line << " Making last student" << endl;
            newBlock = true;
          }
        }
      }


      //For line 0, create a new registrar with X windows
      else
      {
        cout << line << " Registrar Made." << endl;
        m_registrar = new Registrar(stoi(line));
      }
      lineNumber++;
    }
  }
}
