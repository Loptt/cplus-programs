#include <iostream>
#include "Priority.h"
using namespace std;

int main()
{
    Priority myPriority(true);

    myPriority.push(5);
    myPriority.push(3);
    myPriority.push(7);
    myPriority.push(1);
    myPriority.push(9);
    myPriority.push(4);
    myPriority.push(6);

    while (!myPriority.empty())
    {
        myPriority.print();
        myPriority.pop();
    }

    return 0;
}