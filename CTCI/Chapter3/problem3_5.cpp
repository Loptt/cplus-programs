#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int> s)
{
    stack<int> sorted;
    int val = 0;
    int popCounter = 0;

    while (!s.empty())
    {
        val = s.top();
        s.pop();

        if (sorted.empty())
        {
            sorted.push(val);
            continue;
        }

        while (val > sorted.top())
        {
            s.push(sorted.top());
            sorted.pop();
            popCounter++;
        }

        sorted.push(val);

        for (int i = 0; i < popCounter; ++i)
        {
            sorted.push(s.top());
            s.pop();
        }

        popCounter = 0;
    }

    return sorted;
}

int main()
{
    stack<int> myStack;

    myStack.push(3);
    myStack.push(1);
    myStack.push(5);
    myStack.push(2);
    myStack.push(9);
    myStack.push(10);

    myStack = sortStack(myStack);

    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;

    return 0;
}