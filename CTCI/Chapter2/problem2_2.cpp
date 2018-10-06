#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
T returnKLastElement(LinkedListNode<T> *root, int k)
{
    LinkedListNode<T> *current = root;
    LinkedListNode<T> *fast = root;

    for (int i = 0; i < k; ++i)
    {
        if (fast == nullptr)
            return 0;
            
        fast = fast->getNext();
    }

    while (fast != nullptr)
    {
        fast = fast->getNext();
        current = current->getNext();
    }

    return current->getData();
}

int main()
{
    LinkedList<int> list;

    int k;
    cin >> k;

    list.addLast(2);
    list.addLast(1);
    list.addLast(4);
    list.addLast(6);
    list.addLast(8);
    list.addLast(3);

    cout << returnKLastElement(list.getHead(), k) << endl;

    return 0;
}