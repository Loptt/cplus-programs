#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"
using namespace std;

void partition(LinkedListNode<int> *root, int x)
{
    if (root == nullptr)
        return;
    
    vector<int> smaller, larger;

    LinkedListNode<int> *current = root;

    while (current != nullptr)
    {
        if (current->getData() < x)
            smaller.push_back(current->getData());
        else
            larger.push_back(current->getData());

        current = current->getNext();
    }

    current = root;

    for (int i = 0; i < smaller.size(); ++i)
    {
        current->setData(smaller[i]);
        current = current->getNext();
    }

    for (int i = 0; i < larger.size(); ++i)
    {
        current->setData(larger[i]);
        current = current->getNext();
    }
}

int main()
{
    LinkedList<int> list;

    list.addLast(3);
    list.addLast(5);
    list.addLast(8);
    list.addLast(5);
    list.addLast(10);
    list.addLast(2);   
    list.addLast(1);

    list.print();

    partition(list.getHead(), 5);

    list.print();

    return 0;
}