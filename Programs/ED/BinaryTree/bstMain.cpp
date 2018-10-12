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

    BST arbol2;
    arbol2.add(65);
    arbol2.add(80);
    arbol2.add(50);
    arbol2.add(58);
    arbol2.add(71);
    arbol2.add(32);
    arbol2.add(100);
    arbol2.add(34);

    arbol.print(2);
    
    arbol.mirror();
    
    arbol.print(2);

    return 0;
}
