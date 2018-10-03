#include "Node.h"

class BST
{
  public:
    BST();
    ~BST();

    void add(int data);
    bool search(int data);
    void remove(int data);

  private:
    NodeT *root;
};

BST::BST()
{
    root = nullptr;
}

bool BST::search(int data)
{
    NodeT *current = root;

    while (current != nullptr)
    {
        if (current->getData == data)
        {
            return true;
        }

        current = (current->getData() > data) ? current->getLeft() : current->getRight();
    }
}

void BST::add(int data)
{
    NodeT *current = root;
    NodeT *father = nullptr;

    while (current != nullptr)
    {
        if (current->getData() == data)
            return;

        father = current;
        current = (current->getData() > data) ? current->getLeft() : current->getRight();
    }

    if (father == nullptr)
    {
        root = new NodeT(data);
        return;
    }

    if (father->getData() > data)
    {
        father->setLeft(new NodeT(data));
    }
    else
    {
        father->setRight(new NodeT(data));
    }
}