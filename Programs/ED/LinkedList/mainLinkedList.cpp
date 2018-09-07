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

    std::cout << "Lista 1: ";
    list.print();

    LinkedList<std::string> list2(list);

    list2 += "XDDD";

    std::cout << "Lista 2: ";
    list2.print();

    LinkedList<std::string> list3;
    list3.addFirst("Hola");
    list3.addFirst("kase");
    list3.addFirst("Nada");

    list2 += list3;

    list2 += "Final";

    std::cout << "Lista 2: ";

    list2.print(); 

    list2.spin(3);

    std::cout << "Lista 2: ";
    list2.print();

    list3 = list2;

    list2.print();

    std::cout << "Lista 3: ";
    list3.print();

    return 0;
}
