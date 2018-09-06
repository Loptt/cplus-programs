#include <iostream>
#include <string>
#include "LinkedList.h"

int main()
{
    LinkedList<std::string> list;

    list.addFirst("Meco");
    list.addFirst("Totoneco");
    list.addFirst("Seseleco");
    list.addLast("HEHe");

    list.print();

    LinkedList<std::string> list2(list);

    list2 += "XDDD";
    list2 += list;

    list2.print();

    return 0;
}
