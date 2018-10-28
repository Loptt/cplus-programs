#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#include "BST.h"

int main()
{
    BST arbol;
    arbol.add(18);
    arbol.add(12);
    arbol.add(20);
    arbol.add(1);
    arbol.add(19);
    arbol.add(30);
    arbol.add(25);
    arbol.add(40);

    cout << arbol.howManyAreSmallerThanME(1) << endl;

    return 0;
}