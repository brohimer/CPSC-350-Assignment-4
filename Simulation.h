// Student-1-Name: Curren Taber
// Student-1-ID: 002325149
// Student-2-Name: Oliver Mathias
// Student-2-ID: 002289410
// Prof: Rene German
// Class: CPSC 350-1
// Date: 4-22-2020
// Assignment: Registrar Office

/*
  Header for the simulation class
*/

#include <iostream>
#include <fstream>
#include "Registrar.h"
using namespace std;

class Simulation
{
  public:
    Simulation(); //constructor
    ~Simulation(); //Destructor
    void start(string file); //main function that simulates all the students

  private:
    //pointer to the registrar object
    Registrar* m_registrar;

};
