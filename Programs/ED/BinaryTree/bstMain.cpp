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

    BST arbol2(arbol);

    arbol.print(2);
    arbol2.print(2);

    return 0;
}
