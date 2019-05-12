#include "Node.h"

template <class T>
class stack
{
  public:
    stack();
    ~stack();

    void push(T data);
    void pop();
    int size();
    bool empty();

    T top();

  private:
    Node<T> *tope;
    int tam;
};

template <class T>
stack<T>::stack()
{
    tope = nullptr;
    tam = 0;
}

template <class T>
stack<T>::~stack()
{
    Node<T> *current = tope;

    while (tope != nullptr)
    {
        tope = tope->getNext();
        delete current;
        current = tope;
    }
}

template <class T>
T stack<T>::top()
{
    return tope->getData();
}

template <class T>
int stack<T>::size()
{
    return tam;
}

template <class T>
bool stack<T>::empty()
{
    return tope == nullptr;
}

template <class T>
void stack<T>::push(T data)
{
    tope = new Node<T>(data, tope);
    tam++;
}

template <class T>
void stack<T>::pop()
{
    Node<T> *current = tope;
    tope = tope->getNext();
    delete current;
    tam--;
}