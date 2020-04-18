#include "Simulation.h"

int main(int argc, char** argv)
{

  //making a new registrar with 5 windows
  Registrar* reggie = new Registrar(5);
  Student* notolivermathias = new Student();
  cout << reggie->get_students_waiting() << endl;
  reggie->add_student_to_queue(notolivermathias);
  cout << reggie->get_students_waiting() << endl;
  cout << reggie->get_number_of_windows_open() << endl;
  cout << reggie->get_index_of_first_available_window() << endl;

  /*
  Flow:
  Read in file
  Parse the number of windows -> create those
  Parse the Students(w/ time arrived, time needed) -> Create those students in the queue

  ALSO: make sure these students are added in order of arrival!!
  The queue should also have an int return that tells us how many student behind the
  first one have the same arrival time.

  then we start the loop:
  while (end_queue != initial_arrival_queue size)
  {

   //takes students from windows that are done and moves them to the done queue
   windows.clear_students_that_are_done();
   //gets current open windows
   int current_open_windows = windows.get_number_of_windows_open();

  if (queue.peek_first_student.arrival time == tick)
  {
    //down here we know at least the first student has arrived.
    int number_of_students_actually_in_line = queue.num_students_after_first_that_arrived_at_same_time
    try
    {
      for (i in range(number_of_students_actually_in_line))
      {
        windows.add_student_to_first_avail_window(queue.get_first_student)
      }
    }
    except:
      skip

  }

  //just to make sure we increment EVERY arrived student's wait time.
  queue.increment_all_student_wait_times_if_in_line_and_have_arrived();
  windows.increment_all_student_time_at_window()
  increment tick;
  }

  then here we print out the window stats and student stats.

  */


  // StudentQueue* q = new StudentQueue();
  // Student* s = new Student();
  // q->insertBack(*s); //dereferencing the student at pointer "s"
  // q->removeFront().printInfo(); //test to access from student queue

  // DoublyLinkedList<char>* listy = new DoublyLinkedList<char>();
  // listy->insertBack('f');
  // listy->insertBack('g');
  // listy->insertBack('h');
  // // listy->removeFront();
  // listy->printList();
  // listy->removeAtPos(0);
  // listy->printList();
  // listy->removeAtPos(1);
  // listy->printList();
  // listy->removeBack();
  // listy->printList();
  // delete listy;
  Simulation* s = new Simulation();

  if (argc < 2)
  {
    cout << "No file provided." << endl;
    return 1;
  }
  string file = argv[1];
  s->start(file);
  delete s;

  return 0;
}
