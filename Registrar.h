#include "Window.h"
#include "StudentQueue.h"

class Registrar
{

//Registrar Class:
//.Current input file line, next group(), .current_time

  public:
    Registrar(); //Default constructor
    Registrar(int num_windows); //overload constructor
    ~Registrar(); //Destructor

    void update_students_waiting();
    void add_student_to_queue(Student* student);

  private:
    int current_tick;
    int windows_open;
    int students_waiting;
    Window* windows;
    StudentQueue* students;

};
