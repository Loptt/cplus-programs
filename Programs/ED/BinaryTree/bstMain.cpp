#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, char const *argv[])
{
    BST arbol;
    arbol.add(65);
    arbol.add(80);
    arbol.add(50);
    arbol.add(1);
    arbol.add(12);
    arbol.add(33);
    arbol.add(100);
    arbol.add(34);

    arbol.print(1);
    arbol.print(2);
    arbol.print(3);
    arbol.print(5);

    cout << arbol.height() << endl;

    return 0;
}
