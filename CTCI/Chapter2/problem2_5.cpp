#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"
using namespace std;

LinkedListNode<int> *sum(LinkedListNode<int> *n1, LinkedListNode<int> *n2)
{
    LinkedListNode<int> *curr1 = n1;
    LinkedListNode<int> *curr2 = n2;

    LinkedListNode<int> *result = new LinkedListNode<int>(0);

    LinkedListNode<int> *currRes = result;

    int res = 0;
    bool carry = false;
    bool curr1End = false;

    res = curr1->getData() + curr2->getData();

    if (res >= 10)
    {
        res -= 10;
        carry = true;
    }
    else
    {
        carry = false;
    }

    currRes->setData(res);

    curr1 = curr1->getNext();
    curr2 = curr2->getNext();

    while (curr1 != nullptr && curr2 != nullptr)
    {
        res = curr1->getData() + curr2->getData();

        if (carry)
            res++;

        if (res >= 10)
        {
            res -= 10;
            carry = true;
        }
        else
        {
            carry = false;
        }

        currRes->setNext(new LinkedListNode<int>(res));

        curr1 = curr1->getNext();
        curr2 = curr2->getNext();

        currRes = currRes->getNext();
    }
}

int main()
{

    return 0;
}