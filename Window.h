
class Window
{

//Window Class: isOccupied(), setOccupied(), setUnoccupied()

  public:
    Window(); //Default constructor
    ~Window(); //Destructor

    bool isOccupied();
    void setOccupied();
    void setUnoccupied();


  private:
    bool Occupied;

};
