#include "LinkedList.h"

int main()
{
    LinkedList<int> list;

    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);

    LinkedList<int> list2;

    list2 = list.split(5);

    list.print();
    list2.print();

    cout << list2.check() << endl;
}