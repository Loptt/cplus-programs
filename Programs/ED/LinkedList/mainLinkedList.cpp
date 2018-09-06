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

    list2.print();

    LinkedList<std::string> list3;
    list3.addFirst("Hola");
    list3.addFirst("kase");
    list3.addFirst("Nada");

    list2 += list3;

    list2 += "Final";

    list2.print();

    return 0;
}
