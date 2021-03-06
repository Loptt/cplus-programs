#include "LinkedListNode.h"

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

    LinkedListNode<T> *getHead() { return head; }
    void setHead(LinkedListNode<T> *n) { head = n; }

  private:
    LinkedListNode<T> *head;
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

    LinkedListNode<T> *currentOld = list.head;

    this->head = new LinkedListNode<T>(currentOld->getData());

    LinkedListNode<T> *currentNew = this->head;

    while (currentOld->getNext() != NULL)
    {
        currentOld = currentOld->getNext();
        currentNew->setNext(new LinkedListNode<T>(currentOld->getData()));
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
    head = new LinkedListNode<T>(data, head);
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

    LinkedListNode<T> *current = head;

    while (current->getNext() != NULL)
        current = current->getNext();

    current->setNext(new LinkedListNode<T>(data));
    size++;
}

template <class T>
void LinkedList<T>::deleteFirst()
{
    if (head == NULL)
        return;

    LinkedListNode<T> *current = head;
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

    LinkedListNode<T> *current = head;

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
        LinkedListNode<T> *current = head;

        for (int i = 1; i < position; ++i)
        {
            current = current->getNext();
        }

        current->setNext(new LinkedListNode<T>(data, current->getNext()));
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
    LinkedListNode<T> *current = head;

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
        LinkedListNode<T> *current = head;

        for (int i = 1; i < position; ++i)
        {
            current = current->getNext();
        }

        LinkedListNode<T> *temp = current->getNext();
        current->setNext(current->getNext()->getNext());
        delete temp;
    }
}

template <class T>
T LinkedList<T>::get(int position)
{
    LinkedListNode<T> *current = head;

    for (int i = 0; i < position; ++i)
    {
        current = current->getNext();
    }

    return current->getData();
}

template <class T>
T LinkedList<T>::set(T data, int position)
{
    LinkedListNode<T> *current = head;

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

    LinkedListNode<T> *current = head;
    LinkedListNode<T> *firstPosition = NULL;

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
    LinkedListNode<T> *current = head;
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

    LinkedListNode<T> *current1 = head;
    LinkedListNode<T> *current2 = current1->getNext();

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
    LinkedListNode<T> *current1 = head;
    LinkedListNode<T> *current2 = head;

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
void LinkedList<T>::spin(int interval)
{
    if (size <= 1)
        return;

    if (interval >= size)
    {
        reverse();
        return;
    }

    LinkedListNode<T> *current = head;
    LinkedListNode<T> *first = head;
    LinkedListNode<T> *previous = head;
    LinkedListNode<T> *first2 = head;
    LinkedListNode<T> *next = head->getNext();

    int remaining = size % interval;
    int times = size / interval;

    for (int i = 0; i < interval - 1; ++i)
    {
        head = next;
        next = next->getNext();
        head->setNext(previous);
        previous = head;
    }

    first->setNext(next);

    for (int i = 0; i < times - 1; ++i)
    {
        previous = next;
        first2 = next;
        current = next;
        next = next->getNext();

        for (int j = 0; j < interval - 1 && next->getNext() != NULL; ++j)
        {
            current = next;
            next = next->getNext();
            current->setNext(previous);
            previous = current;
        }

        first->setNext(current);
        first2->setNext(next);
        first = first2;
    }

    previous = next;
    first2 = next;
    current = next;

    if (next != NULL)
        next = next->getNext();

    for (int i = 1; i < remaining; ++i)
    {
        current = next;
        next = next->getNext();
        current->setNext(previous);
        previous = current;
    }

    first->setNext(current);
    first2->setNext(NULL);
}

template <class T>
bool LinkedList<T>::operator==(LinkedList<T> list2)
{
    if (size != size)
        return false;

    LinkedListNode<T> *current1 = head;
    LinkedListNode<T> *current2 = list2.head;

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
    LinkedListNode<T> *current = this->head;
    LinkedListNode<T> *current2 = list2.head;

    while (current->getNext() != NULL)
    {
        current = current->getNext();
    }

    while (current2 != NULL)
    {
        current->setNext(new LinkedListNode<T>(current2->getData()));
        current = current->getNext();
        current2 = current2->getNext();
    }

    size += list2.size;
}

template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &list)
{
    int cant = deleteAll();

    head = new LinkedListNode<T>(list.head->getData());

    LinkedListNode<T> *currentOld = list.head;
    LinkedListNode<T> *currentNew = this->head;

    if (currentOld == NULL)
        return;

    while (currentOld->getNext() != NULL)
    {
        currentOld = currentOld->getNext();
        currentNew->setNext(new LinkedListNode<T>(currentOld->getData()));
        currentNew = currentNew->getNext();
    }

    this->size = list.size;
}