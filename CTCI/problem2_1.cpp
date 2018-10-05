#include <iostream>
#include <string>
#include <unordered_set>
#include "LinkedListNode.h"
using namespace std;

template <class T>
void removeDuplicates(LinkedListNode<T> *root)
{
    unordered_set<T> elements;
    
    LinkedListNode<T> *current = root;

    while (current->getNext() != nullptr)
    {
        if (elements.find(current->getNext()->getData() == elements.end()))
        {
            elements.insert(current->getNext()->getData());
        }
        else
        {
            LinkedListNode<T> *temp = current->getNext();
            current->setNext(current->getNext()->getNext());
            delete temp;
        }

        current = current->getNext();
    }
}

int main()
{

    return 0;
}