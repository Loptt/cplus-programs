template <class T>
bool LinkedList<T>::check()
{
    Node<T> *current = head;

    if (head == nullptr)
    {
        if (size != 0)
        {
            size = 0;
            return false;
        }
        else
        {
            return true;
        }
    }

    int sizeChecker = 1;

    while (current->getNext() != nullptr)
    {
        current = current->getNext();
        sizeChecker++;
    }

    if (size != sizeChecker)
    {
        size = sizeChecker;
        return false;
    }
    else
    {
        return true;
    }
}