#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, char const *argv[])
{
    BST arbol;
    arbol.add(65);
    arbol.add(80);
    arbol.add(50);
    arbol.add(58);
    arbol.add(71);
    arbol.add(33);
    arbol.add(100);
    arbol.add(34);
    arbol.add(30);
    arbol.add(55);
    arbol.add(59);
    arbol.add(67);
    arbol.add(72);

    BST arbol2(arbol);

    arbol.print(1);

    arbol2.print(1);

    return 0;
}
