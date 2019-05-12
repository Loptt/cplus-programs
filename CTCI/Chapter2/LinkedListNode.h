template <class T>
class LinkedListNode
{
  public:
    LinkedListNode();
    LinkedListNode(T data);
    LinkedListNode(T data, LinkedListNode *next);

    LinkedListNode<T> *getNext() { return next; }
    T getData() { return data; }

    void setNext(LinkedListNode *n) { next = n; }
    void setData(T d) { data = d; }

  private:
    LinkedListNode *next;
    T data;
};

template <class T>
LinkedListNode<T>::LinkedListNode()
{
    next = nullptr;
}

template <class T>
LinkedListNode<T>::LinkedListNode(T data)
{
    this->data = data;
}

template <class T>
LinkedListNode<T>::LinkedListNode(T data, LinkedListNode *next)
{
    this->data = data;
    this->next = next;
}