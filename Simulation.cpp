#include "Simulation.h"

Simulation::Simulation()
{

}

Simulation::~Simulation()
{

}

void Simulation::start(string file)
{
  ifstream inFS;
  string line = "";
  int lineNumber = 0;
  int block = 0;

  inFS.open("test.txt");

  while (!inFS.eof())
  {
    getline(inFS, line);
    if (!inFS.fail())
    {
      if (lineNumber == 0)
      {
        //set number of windows
      }
      else
      {
        // if ()
        // {
        //
        // }
        // else if ()
        // {
        //
        // }
      }
      lineNumber++;
    }
  }
}
