#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#include "BST.h"
#include "printLeft.h"

int main(){
    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(4);
    tree.add(8);
    tree.add(7);
    tree.add(6);
    tree.add(1);

    tree.printLeft(); 
	return 0;
}