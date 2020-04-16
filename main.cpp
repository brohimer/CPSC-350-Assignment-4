#include "Simulation.h"
#include "Registrar.h"

int main(int argc, char** argv)
{

  //making a new registrar with 5 windows
  Registrar* reggie = new Registrar(5);
  Student* notolivermathias = new Student();
  cout << reggie->get_students_waiting() << endl;
  reggie->add_student_to_queue(notolivermathias);
  reggie->update_students_waiting();
  cout << reggie->get_students_waiting() << endl;

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
