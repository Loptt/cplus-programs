#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
  public:
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    void deleteFirst();
    void deleteLast();
    void del(int pos);
    int deleteAll();
    T get(int pos);
    T set(T data, int pos);
    bool change(int pos1, int pos2);
    int getSize();
    void print();

    bool check();
    LinkedList<T> split(int n);

    void operator=(const LinkedList<T> &list);

  private:
    Node<T> *head;
    int size;
    void borraTodo();
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}

template <class T>
void LinkedList<T>::borraTodo()
{
    Node<T> *curr = head;
    while (head != nullptr)
    {
        head = head->getNext();
        delete curr;
        curr = head;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    borraTodo();
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return (size == 0);

    //	return (head == nullptr);
}

template <class T>
void LinkedList<T>::addFirst(T data)
{
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data)
{
    if (this->isEmpty())
    {
        this->addFirst(data);
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
void LinkedList<T>::deleteFirst()
{
    if (!this->isEmpty())
    {
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
void LinkedList<T>::deleteLast()
{
    if (size <= 1)
    {
        deleteFirst();
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(nullptr);
        size--;
    }
}

template <class T>
bool LinkedList<T>::add(T data, int pos)
{
    if (pos > size)
    {
        return false;
    }
    if (pos == 0)
    {
        addFirst(data);
    }
    else if (pos == size)
    {
        addLast(data);
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}

template <class T>
void LinkedList<T>::del(int pos)
{
    if (pos == 0)
    {
        deleteFirst();
    }
    else if (pos == size - 1)
    {
        deleteLast();
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->getNext();
        }
        Node<T> *temp = curr->getNext();
        curr->setNext(temp->getNext());
        delete temp;
        size--;
    }
}

template <class T>
int LinkedList<T>::deleteAll()
{
    borraTodo();
    int cant = size;
    size = 0;
    return cant;
}

template <class T>
T LinkedList<T>::get(int pos)
{
    Node<T> *curr = head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->getNext();
    }
    return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos)
{
    Node<T> *curr = head;
    for (int i = 0; i < pos; i++)
    {
        curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
    if (pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >= size)
    {
        return false;
    }
    if (pos1 == pos2)
    {
        return true;
    }
    Node<T> *curr1 = head;

    int posMen = (pos1 < pos2 ? pos1 : pos2);
    int posMay = (pos1 > pos2 ? pos1 : pos2);

    /*	if (pos1 > pos2)
		posMay = pos1;
	else
		posMay = pos2;
*/
    for (int i = 0; i < posMen; i++)
    {
        curr1 = curr1->getNext();
    }
    Node<T> *curr2 = curr1;
    for (int i = posMen; i < posMay; i++)
    {
        curr2 = curr2->getNext();
    }
    T dataAux = curr1->getData();
    curr1->setData(curr2->getData());
    curr2->setData(dataAux);
    return true;
}

template <class T>
int LinkedList<T>::getSize()
{
    return size;
}

template <class T>
void LinkedList<T>::print()
{
    Node<T> *curr = head;
    cout << "INICIO" << endl;
    while (curr != nullptr)
    {
        cout << curr->getData() << " ";
        curr = curr->getNext();
    }
    cout << endl
         << "FIN" << endl;
}

template <class T>
LinkedList<T> LinkedList<T>::split(int n)
{
    Node<T> *current = head;

    if (n >= size)
    {
        LinkedList<T> newList;
        return newList;
    }

    if (n == 0)
    {
        LinkedList<T> newList;
        newList.head = current;
        head = nullptr;
        return newList;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        current = current->getNext();
    }

    LinkedList<T> newList;
    newList.head = current->getNext();
    current->setNext(nullptr);

    newList.size = size - n;
    size = n;

    return newList;
}

template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &list)
{
    int cant = deleteAll();

    if (list.head == nullptr)
    {
        return;
    }

    head = new Node<T>(list.head->getData());

    Node<T> *currentOld = list.head;
    Node<T> *currentNew = this->head;

    if (currentOld == nullptr)
        return;

    while (currentOld->getNext() != nullptr)
    {
        currentOld = currentOld->getNext();
        currentNew->setNext(new Node<T>(currentOld->getData()));
        currentNew = currentNew->getNext();
    }

    this->size = list.size;
}

template <class T>
bool LinkedList<T>::check()
{
    Node<T> *current = head;

    if (head == nullptr)
    {
        if (size != 0)
        {
            size = 0;
            return false;
        }
        else
        {
            return true;
        }
    }

    int sizeChecker = 1;

    while (current->getNext() != nullptr)
    {
        current = current->getNext();
        sizeChecker++;
    }

    if (size != sizeChecker)
    {
        cout << size << " " << sizeChecker << endl;
        size = sizeChecker;
        return false;
    }
    else
    {
        return true;
    }
}