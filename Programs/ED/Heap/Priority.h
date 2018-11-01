#include <vector>

class Priority
{
  public:
    Priority();
    Priority(bool max);
    ~Priority();

    void push(int d);
    void pop();

    void print();
    bool empty();
    int size();
    int top();

  private:
    std::vector<int> heap;
    bool maxPriority;

    void swap(int &a, int &b);
};

Priority::Priority()
{
    maxPriority = true;
    heap.push_back(0);
}

Priority::Priority(bool p)
{
    maxPriority = p;
    heap.push_back(0);
}

Priority::~Priority()
{
}

void Priority::swap(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

void Priority::push(int data)
{
    heap.push_back(data);

    int pointer = heap.size() - 1;

    if (maxPriority)
    {
        while (heap[pointer] > heap[pointer / 2] && pointer > 1)
        {
            swap(heap[pointer], heap[pointer / 2]);

            pointer = pointer / 2;
        }
    }
    else
    {
        while (heap[pointer - 1] < heap[pointer / 2] && pointer > 1)
        {
            swap(heap[pointer], heap[pointer / 2]);

            pointer = pointer / 2;
        }
    }
}

void Priority::pop()
{
    swap(heap[1], heap[heap.size() - 1]);

    heap.pop_back();

    int pointer = 1;
    int maxChild = 0;
    int maxPoint = 0;

    if (maxPriority)
    {
        if (heap.size() > 2)
        {
            maxChild = heap[pointer * 2] > heap[pointer * 2 + 1] ? heap[pointer * 2] : heap[pointer * 2 + 1];
            maxPoint = heap[pointer * 2] > heap[pointer * 2 + 1] ? pointer * 2 : pointer * 2 + 1;
        }
        else
        {
            if (heap.size() == 2)
                swap(heap[1], heap[2]);

            pointer = heap.size();
        }

        while (maxChild > heap[pointer] && (pointer * 2 < heap.size()))
        {
            swap(heap[pointer], heap[maxPoint]);
            pointer = maxPoint;

            if (pointer * 2 + 1 >= heap.size())
            {
                maxChild = heap[pointer * 2];
                maxPoint = pointer * 2;
            }
            else
            {
                maxChild = heap[pointer * 2] > heap[pointer * 2 + 1] ? heap[pointer * 2] : heap[pointer * 2 + 1];
                maxPoint = heap[pointer * 2] > heap[pointer * 2 + 1] ? pointer * 2 : pointer * 2 + 1;
            }
        }
    }
    else
    {
        if (heap.size() > 2)
        {
            maxChild = heap[pointer * 2] < heap[pointer * 2 + 1] ? heap[pointer * 2] : heap[pointer * 2 + 1];
            maxPoint = heap[pointer * 2] < heap[pointer * 2 + 1] ? pointer * 2 : pointer * 2 + 1;
        }
        else
        {
            if (heap.size() == 2)
                swap(heap[1], heap[2]);

            pointer = heap.size();
        }

        while (maxChild < heap[pointer] && (pointer * 2 < heap.size()))
        {
            if (pointer * 2 + 1 >= heap.size())
            {
                maxChild = heap[pointer * 2];
                maxPoint = pointer * 2;
            }
            else
            {
                maxChild = heap[pointer * 2] < heap[pointer * 2 + 1] ? heap[pointer * 2] : heap[pointer * 2 + 1];
                maxPoint = heap[pointer * 2] < heap[pointer * 2 + 1] ? pointer * 2 : pointer * 2 + 1;
            }

            swap(heap[pointer], heap[maxPoint]);
            pointer = maxPoint;
        }
    }
}

void Priority::print()
{
    for (int i = 1; i < heap.size(); ++i)
    {
        std::cout << heap[i] << " ";
    }

    std::cout << std::endl;
}

bool Priority::empty()
{
    return heap.empty();
}

int Priority::size()
{
    return heap.size() - 1;
}

int Priority::top()
{
    return heap[1];
}