///header file for single linked list
template <class T>
class ListNode{
  public:
    T data;
    ListNode<T>* next;
    ListNode<T>* prev;

    ListNode(); //default constructor
    ListNode(T d); //overload
    ~ListNode();

};

template <class T>
//ListNode implementation file
ListNode<T>:: ListNode(){
  data = 0;
  next = 0;//might have to use 0ptr
  prev = 0;
}

template <class T>
//next pointer is always set to 0, b/c we don't know whwere to insert this node
ListNode<T>:: ListNode(T d){
  data = d;
  next = 0;
  prev = 0;
}

template <class T>
ListNode<T>::~ListNode(){
  //we make this
}
