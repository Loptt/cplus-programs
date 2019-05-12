#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
void deleteMiddle(LinkedListNode<T> *middle)
{
    if (middle->getNext() == nullptr)
        return;
    
    middle->setData(middle->getNext()->getData());
    LinkedListNode<T> *temp = middle->getNext();

    middle->setNext(middle->getNext()->getNext());

    delete temp;
}

int main(int argc, char const *argv[])
{
    LinkedList<int> list;

    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);
    list.addLast(6);
    list.addLast(7);

    list.print();

    deleteMiddle(list.getHead()->getNext()->getNext()->getNext());

    list.print();

    return 0;
}
