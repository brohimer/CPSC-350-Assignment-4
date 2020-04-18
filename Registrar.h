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

    // void update_students_waiting();
    int get_students_waiting();

    int get_index_of_first_available_window();
    void update_number_of_windows_open();
    int get_number_of_windows_open();
    void add_student_to_queue(Student* student);
    Student remove_student_from_queue();
    bool empty_queue();
    void update_students_waiting();

  private:
    int current_tick;
    int windows_open;
    int total_windows;
    int students_waiting;
    Window* windows;
    StudentQueue* students;

};
