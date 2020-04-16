#include "Window.h"

class Registrar
{

//Registrar Class:
//.Current input file line, next group(), .current_time

  public:
    Registrar(); //Default constructor
    Registrar(int num_windows); //overload constructor
    ~Registrar(); //Destructor

    void update_students_waiting();

  private:
    int current_tick;
    int windows_open;
    int students_waiting;
    Window* windows;

};
