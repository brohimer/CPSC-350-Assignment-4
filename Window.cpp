#include "Window.h"

Window::Window()
{
  Occupied = false;
}

Window::~Window()
{

}

bool Window::isOccupied()
{
  return Occupied;
}
void Window::setOccupied()
{
  Occupied = true;
}

void Window::setUnoccupied()
{
  Occupied = false;
}
