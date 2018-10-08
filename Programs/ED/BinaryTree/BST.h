#include <iostream>
#include "Node.h"

class BST
{
  public:
    BST();
    ~BST();

    void add(int data);
    bool search(int data);
    void remove(int data);

    void print(int c);
    void print(int number, bool value);

    int height();

  private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);

    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void recorridoNivel();

    void libera(NodeT *r);
};

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
}

void BST::libera(NodeT *r)
{
    if (r != nullptr)
    {
        libera(r->getLeft());
        libera(r->getRight());
        delete r;
    }
}

bool BST::search(int data)
{
    NodeT *current = root;

    while (current != nullptr)
    {
        if (current->getData() == data)
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

int BST::howManyChildren(NodeT *r)
{
    int cant = 0;

    if (r->getLeft() != nullptr)
        cant++;

    if (r->getRight() != nullptr)
        cant++;

    return cant;
}

int BST::pred(NodeT *r)
{
    NodeT *aux = r->getLeft();

    while (aux->getRight() != nullptr)
        aux = aux->getRight();

    return aux->getData();
}

int BST::succ(NodeT *r)
{
    NodeT *aux = r->getRight();

    while (aux->getLeft() != nullptr)
        aux = aux->getLeft();

    return aux->getData();
}

void BST::remove(int data)
{
    NodeT *current = root;
    NodeT *father = nullptr;

    while (current != nullptr && current->getData() != data)
    {
        father = current;
        current = (current->getData() > data) ? current->getLeft() : current->getRight();
    }

    if (current == nullptr)
        return;

    int ch = howManyChildren(current);
    int x;

    switch (ch)
    {
    case 0:
        if (father == nullptr)
            root = nullptr;
        else
        {
            if (father->getData() > data)
                father->setLeft(nullptr);
            else
                father->setRight(nullptr);
        }

        delete current;
        break;

    case 1:
        if (father == nullptr)
        {
            if (current->getLeft() != nullptr)
                root = current->getLeft();
            else
                root = current->getRight();
        }
        else
        {
            if (father->getData() > data)
            {
                if (current->getLeft() != nullptr)
                    father->setLeft(current->getLeft());
                else
                    father->setLeft(current->getRight());
            }
            else
            {
                if (current->getLeft() != nullptr)
                    father->setRight(current->getLeft());
                else
                    father->setRight(current->getRight());
            }
        }

        delete current;
        break;

    case 2:
        x = pred(current);
        remove(x);
        current->setData(x);

        break;
    }
}

void BST::preOrder(NodeT *r)
{
    if (r != nullptr)
    {
        std::cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r)
{
    if (r != nullptr)
    {
        inOrder(r->getLeft());
        std::cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r)
{
    if (r != nullptr)
    {
        postOrder(r->getLeft());
        postOrder(r->getRight());
        std::cout << r->getData() << " ";
    }
}

void BST::recorridoNivel()
{
}

void BST::print(int c)
{
    //1 - PreOrder
    //2 - InOrder
    //3 - PostOrder

    switch (c)
    {
    case 1:
        preOrder(root);
        break;

    case 2:
        inOrder(root);
        break;

    case 3:
        postOrder(root);

    case 5:
        recorridoNivel();
    }

    std::cout << std::endl;
}

int BST::height()
{
}
