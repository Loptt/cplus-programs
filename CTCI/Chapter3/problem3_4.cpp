#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class MyQueue
{
  public:
    MyQueue();

    void add(int data);
    int remove();
    int peek();
    bool isEmpty();

    void print();

  private:
    stack<int> s;
    int first;
};

MyQueue::MyQueue() : first(0)
{

}

bool MyQueue::isEmpty()
{
    return s.empty();
}

void MyQueue::add(int data)
{
    if (isEmpty())
        first = data;

    s.push(data);
}

int MyQueue::remove()
{
    stack<int> aux;

    while(!s.empty())
    {
        aux.push(s.top());
        s.pop();
    }

    int val = aux.top();
    aux.pop();

    first = aux.top();

    while(!aux.empty())
    {
        s.push(aux.top());
        aux.pop();
    }

    return val;
}

int MyQueue::peek()
{
    return first;
}

void MyQueue::print()
{
    stack<int> aux;

    while(!s.empty())
    {
        aux.push(s.top());
        s.pop();
    }

    while(!aux.empty())
    {
        cout << aux.top() << " ";
        s.push(aux.top());
        aux.pop();
    }

    cout << endl;
}


int main()
{
    MyQueue queue;
    queue.add(1);
    queue.add(2);
    queue.add(3);
    queue.add(4);
    queue.add(5);

    queue.print();

    return 0;
}