#include "Node.h"

template <class T>
class LinkedList
{
  public:
    LinkedList();
    LinkedList(const LinkedList<T> &list);
    ~LinkedList();

    bool isEmpty();

    void addFirst(T data);
    void addLast(T data);

    void deleteFirst();
    void deleteLast();

    bool add(T data, int position);

    int deleteAll();
    void del(int position);

    T get(int position);
    T set(T data, int position);
    bool change(int position1, int position2);

    void print();

    void reverse();
    void shift(int amount);
    void spin(int interval);

    bool operator==(LinkedList<T> list);
    void operator+=(T data);
    void operator+=(LinkedList<T> list);
    void operator=(const LinkedList<T> &list);

  private:
    Node<T> *head;
    int size;

    void deleteAllHelper();
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    this->size = list.size;

    Node<T> *currentOld = list.head;

    this->head = new Node<T>(currentOld->getData());

    Node<T> *currentNew = this->head;

    while (currentOld->getNext() != NULL)
    {
        currentOld = currentOld->getNext();
        currentNew->setNext(new Node<T>(currentOld->getData()));
        currentNew = currentNew->getNext();
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    deleteAllHelper();
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return head == NULL;
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
        return;
    }

    Node<T> *current = head;

    while (current->getNext() != NULL)
        current = current->getNext();

    current->setNext(new Node<T>(data));
    size++;
}

template <class T>
void LinkedList<T>::deleteFirst()
{
    if (head == NULL)
        return;

    Node<T> *current = head;
    head = head->getNext();
    delete current;
    size--;
}

template <class T>
void LinkedList<T>::deleteLast()
{
    if (head->getNext() == NULL)
    {
        deleteFirst();
        return;
    }

    Node<T> *current = head;

    while (current->getNext()->getNext() != NULL)
    {
        current = current->getNext();
    }

    delete current->getNext();
    current->setNext(NULL);
    size--;
}

template <class T>
bool LinkedList<T>::add(T data, int position)
{
    if (position > size)
        return false;

    if (position == 0)
        addFirst(data);

    else if (position == size)
        addLast(data);

    else
    {
        Node<T> *current = head;

        for (int i = 1; i < position; ++i)
        {
            current = current->getNext();
        }

        current->setNext(new Node<T>(data, current->getNext()));
        size++;
    }

    return true;
}

template <class T>
int LinkedList<T>::deleteAll()
{
    deleteAllHelper();

    int cant = size;
    size = 0;
    return cant;
}

template <class T>
void LinkedList<T>::deleteAllHelper()
{
    Node<T> *current = head;

    while (head != NULL)
    {
        head = head->getNext();
        delete current;
        current = head;
    }
}

template <class T>
void LinkedList<T>::del(int position)
{
    if (position == 0)
        deleteFirst();

    else if (position == size - 1)
        deleteLast();

    else
    {
        Node<T> *current = head;

        for (int i = 1; i < position; ++i)
        {
            current = current->getNext();
        }

        Node<T> *temp = current->getNext();
        current->setNext(current->getNext()->getNext());
        delete temp;
    }
}

template <class T>
T LinkedList<T>::get(int position)
{
    Node<T> *current = head;

    for (int i = 0; i < position; ++i)
    {
        current = current->getNext();
    }

    return current->getData();
}

template <class T>
T LinkedList<T>::set(T data, int position)
{
    Node<T> *current = head;

    for (int i = 0; i < position; ++i)
    {
        current = current->getNext();
    }

    T oldData = current->getData();
    current->setData(data);
    return oldData;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
    if (pos1 == pos2)
        return true;

    Node<T> *current = head;
    Node<T> *firstPosition = NULL;

    int greaterPos = pos1 > pos2 ? pos1 : pos2;
    int lesserPos = pos1 < pos2 ? pos1 : pos2;

    T tmp;

    for (int i = 0; i < greaterPos; ++i)
    {
        if (i == lesserPos)
        {
            firstPosition = current;
        }

        current = current->getNext();
    }

    if (current == NULL || firstPosition == NULL)
        return false;

    tmp = firstPosition->getData();
    firstPosition->setData(current->getData());
    current->setData(tmp);

    return true;
}

template <class T>
void LinkedList<T>::print()
{
    Node<T> *current = head;
    while (current != NULL)
    {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }

    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::reverse()
{
    if (size < 2)
        return;

    Node<T> *current1 = head;
    Node<T> *current2 = current1->getNext();

    current1->setNext(NULL);

    while (current2 != NULL)
    {
        head = current2;
        current2 = current2->getNext();
        head->setNext(current1);
        current1 = head;
    }
}

template <class T>
void LinkedList<T>::shift(int amount)
{
    Node<T> *current1 = head;
    Node<T> *current2 = head;

    amount = amount % size;

    if (amount < 0)
    {
        amount = size + amount;
    }

    for (int i = 0; i < amount - 1; ++i)
    {
        current1 = current1->getNext();
    }

    current2 = current1->getNext();

    while (current2->getNext() != NULL)
    {
        current2 = current2->getNext();
    }

    current2->setNext(head);
    head = current1->getNext();
    current1->setNext(NULL);
}

template <class T>
bool LinkedList<T>::operator==(LinkedList<T> list2)
{
    if (size != size)
        return false;

    Node<T> *current1 = head;
    Node<T> *current2 = list2.head;

    for (int i = 0; i < size; ++i)
    {
        if (current1->getData() != current2->getData())
        {
            return false;
        }

        current1 = current1->getNext();
        current2 = current2->getNext();
    }

    return true;
}

template <class T>
void LinkedList<T>::operator+=(T data)
{
    addLast(data);
}

template <class T>
void LinkedList<T>::operator+=(LinkedList<T> list2)
{
    Node<T> *current = this->head;

    while (current->getNext() != NULL)
    {
        current = current->getNext();
    }

    current->setNext(list2.head);
    size += list2.size;

    print();
}

template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &list)
{
    Node<T> *currentOld = list.head;
    Node<T> *currentNew = this->head;

    if (list.size > this->size)
    {
        int toAdd = list.size - this->size;

        while (currentNew->getNext() != NULL)
        {
            currentNew->setData(currentOld->getData());
            currentOld = currentOld->getNext();
            currentNew = currentNew->getNext();
        }

        for (int i = 0; i < toAdd; ++i)
        {
            currentOld = currentOld->getNext();
            currentNew->setNext(new Node<T>(currentOld->getData()));
            currentNew = currentNew->getNext();
        }
    }
    else
    {
        int toDelete = this->size - list.size;

        while (currentOld->getNext() != NULL)
        {
            currentNew->setData(currentOld->getData());
            currentOld = currentOld->getNext();
            currentNew = currentNew->getNext();
        }

        Node<T> *temp = currentNew->getNext();

        for (int i = 0; i < toDelete; ++i)
        {
            delete currentNew;
            currentNew = temp;
            temp = temp->getNext();
        }
    }

    size = list.size;
}