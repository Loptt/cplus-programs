
template <class T>
void LinkedList<T>::remove3(){
    if (isEmpty())
        return;

    Node<T> *curr = head;
    head = head->getNext();
    delete curr;

    if (head == nullptr)
        return;

    curr = head;

    Node<T> *temp = curr;
    int counter = 1;

    while (curr->getNext() != nullptr)
    {
        if (((counter+1) % 3) == 0)
        {
            temp = curr->getNext();
            curr->setNext(curr->getNext()->getNext());
            delete temp;
        }
        else
        {
            curr = curr->getNext();
        }

        counter++;
    }
}