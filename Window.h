class Window
{

//Window Class: isOccupied(), setOccupied(), setUnoccupied()

  public:
    Window(); //Default constructor
    ~Window(); //Destructor

    bool isOccupied();
    void setOccupied();
    void setUnoccupied();
    void increment_idle_time();


  private:
    bool Occupied;
    int total_idle_time;

};
