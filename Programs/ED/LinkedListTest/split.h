template <class T>
LinkedList<T> LinkedList<T>::split(int n)
{
    Node<T> *current = head;

    if (n >= size)
    {
        LinkedList<T> newList;
        return newList;
    }

    if (n == 0)
    {
        LinkedList<T> newList;
        newList.head = current;
        head = nullptr;
        return newList;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        current = current->getNext();
    }

    LinkedList<T> newList;
    newList.head = current->getNext();
    current->setNext(nullptr);

    newList.size = size - n;
    size = n;

    return newList;
}