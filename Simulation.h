#include <iostream>
#include <fstream>
#include "Registrar.h"
using namespace std;

class Simulation
{
  public:
    Simulation();
    ~Simulation();
    void start(string file);
  private:
    Registrar* m_registrar;

};
