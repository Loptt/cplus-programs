#include <iostream>
#include <string>
#include <unordered_set>
#include "LinkedList.h"
using namespace std;

template <class T>
void removeDuplicates(LinkedListNode<T> *root)
{
    unordered_set<T> elements;

    LinkedListNode<T> *current = root;

    while (current->getNext() != nullptr)
    {
        if (elements.find(current->getNext()->getData()) == elements.end())
        {
            elements.insert(current->getNext()->getData());
            cout << "Adding " << current->getNext()->getData() << endl;
        }
        else
        {
            cout << "Deleting " << current->getNext()->getData() << endl;
            LinkedListNode<T> *temp = current->getNext();
            current->setNext(current->getNext()->getNext());
            delete temp;
        }

        current = current->getNext();
    }
}

int main()
{
    LinkedList<int> list;

    list.addLast(2);
    list.addLast(3);
    list.addLast(7);
    list.addLast(1);
    list.addLast(7);
    list.addLast(3);
    list.addLast(4);
    list.addLast(4);

    list.print();

    removeDuplicates(list.getHead());

    list.print();

    return 0;
}