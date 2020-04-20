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
  Student* notolivermathias = new Student(1,1);

  cout << "Students Waiting: "<< reggie->get_students_waiting() << endl;
  reggie->add_student_to_queue(notolivermathias);
  cout << "Students Waiting: "<< reggie->get_students_waiting() << endl;
  cout << "Windows Open: "<<reggie->get_number_of_windows_open() << endl;
  reggie->send_first_student_in_line_to_first_open_window();
  cout << "Windows Open: "<< reggie->get_number_of_windows_open() << endl;
  reggie->increment_student_window_times_if_at_windows();
  reggie->move_done_students();
  cout << "Windows Open: "<< reggie->get_number_of_windows_open() << endl;
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
        //Non-first lines of an information block
        else if (newBlock == false)
        {
          //Getting the number of students
          if (lineOfStudentCount == true)
          {
            cout << line << " Finding the count" << endl;
            targetLineNumber = lineNumber + stoi(line);
            lineOfStudentCount = false;
          }
          //Making students with waiting times
          else if (lineNumber != targetLineNumber)
          {
            cout << line << " Making a student" << endl;
            m_registrar->add_student_to_queue(new Student(stoi(line), minuteArrived));
          }
          //This is the last student before next block of info
          else
          {
            cout << line << " Making last student" << endl;
            m_registrar->add_student_to_queue(new Student(stoi(line), minuteArrived));
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
  inFS.close();

  //Just printing each student in the queue to test
  while (!m_registrar->empty_queue())
  {
    cout << "\nRemoving student from front " << endl;
    m_registrar->remove_student_from_queue().printInfo();
  }


}
