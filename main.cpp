// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 4-22-2020
// Assignment: Registrar Office

/*
  This main class prompts the user for a file path
  and then begins the simulation using that data.
*/

#include "Simulation.h"

int main(int argc, char** argv)
{
  //creates a simulation object
  Simulation* s = new Simulation();

  //makes sure we're actually getting a file path
  if (argc < 2)
  {
    cout << "No file provided." << endl;
    return 1;
  }
  //turns the file path into a string
  string file = argv[1];
  //starts the simulation using the given path
  s->start(file);
  //clears memory
  delete s;

  return 0;
}
