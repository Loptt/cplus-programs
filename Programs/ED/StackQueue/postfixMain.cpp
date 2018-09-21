#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
#include <functional>
using namespace std;

int processOperation(int firstArg, int secondArg, char operation)
{
    switch (operation)
    {
    case '+':
        return firstArg + secondArg;

    case '-':
        return firstArg - secondArg;

    case '*':
        return firstArg * secondArg;

    default:
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    string d, data;
    stack<int> miStack;
    queue<int> miQueue;
    priority_queue<int, vector<int>, greater<int>> miPQueue;

    int firstArg, secondArg;

    getline(cin, data);
    while (data != "#")
    {
        stringstream ss;
        ss << data;
        while (ss >> d)
        {
            //If input is a number
            if (d[0] >= 0x30)
            {
                miStack.push(stoi(d));
                miQueue.push(stoi(d));
                miPQueue.push(stoi(d));
            }
            //If input is an operation
            else
            {
                //Stack
                secondArg = miStack.top();
                miStack.pop();
                firstArg = miStack.top();
                miStack.pop();

                miStack.push(processOperation(firstArg, secondArg, d[0]));

                //Queue
                secondArg = miQueue.front();
                miQueue.pop();
                firstArg = miQueue.front();
                miQueue.pop();

                miQueue.push(processOperation(firstArg, secondArg, d[0]));

                //Priority Queue
                secondArg = miPQueue.top();
                miPQueue.pop();
                firstArg = miPQueue.top();
                miPQueue.pop();

                miPQueue.push(processOperation(firstArg, secondArg, d[0]));
            }
        }

        cout << miStack.top() << " " << miQueue.front() << " " << miPQueue.top() << endl;

        miStack.pop();
        miQueue.pop();
        miPQueue.pop();

        getline(cin, data);
    }

    return 0;
}
