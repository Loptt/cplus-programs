#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    queue<int> miStack;
    miStack.push(400);
    miStack.push(300);
    miStack.push(600);

    cout << "La cantidad es: " << miStack.size() << endl;

    while (!miStack.empty())
    {
        cout << miStack.front() << endl;
        miStack.pop();
    }

    return 0;
}