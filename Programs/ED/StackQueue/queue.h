#include "Node.h"

template <class T>
class queue
{
  public:
    queue();
    ~queue();

    T front();
    void push(T data);
    void pop();
    int size();
    bool empty();

  private:
    Node<T> *ultimo;
    int tam;
};

template <class T>
queue<T>::queue()
{
    ultimo = nullptr;
    tam = 0;
}

template <class T>
queue<T>::~queue()
{
    if (ultimo != nullptr)
    {
        Node<T> *current = ultimo->getNext();
        ultimo->setNext(nullptr);
        ultimo = current;

        while (ultimo != nullptr)
        {
            ultimo = ultimo->getNext();
            delete current;
            current = ultimo;
        }
    }
}

template <class T>
T queue<T>::front()
{
    return ultimo->getNext()->getData();
}

template <class T>
void queue<T>::push(T data)
{
    if (ultimo == nullptr)
    {
        ultimo = new Node<T>(data);
        ultimo->setNext(ultimo);
    }
    else
    {
        ultimo->setNext(new Node<T>(data, ultimo->getNext()));
        ultimo = ultimo->getNext();
    }

    tam++;
}

template <class T>
void queue<T>::pop()
{
    Node<T> *current = ultimo->getNext();
    if (ultimo->getNext() == ultimo)
    {
        ultimo = nullptr;
    }
    else
    {
        ultimo->setNext(current->getNext());
    }

    delete current;
    tam--;
}

template <class T>
int queue<T>::size()
{
    return tam;
}

template <class T>
bool queue<T>::empty()
{
    return ultimo == nullptr;
}