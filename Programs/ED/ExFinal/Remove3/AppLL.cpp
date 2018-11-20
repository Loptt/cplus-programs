#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "remove3.h"

int main()
{
    LinkedList<int> list;
    list.addLast(2);
    list.addLast(1);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);
    list.addLast(1);
    list.addLast(8);
    list.addLast(10);
    list.addLast(11);
    list.addLast(12);
    list.addLast(13);

    list.print();

    list.remove3();

    list.print();

    return 0;

}