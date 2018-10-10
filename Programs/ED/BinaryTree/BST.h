#include <iostream>
#include <queue>
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
    void ancestors(int dato);
    int whatLevelamI(int dato);

  private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);

    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void recorridoNivel();

    bool ancestorsHelper(NodeT *r, int dato);
    int heightHelper(NodeT *r);

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

    return false;
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
    std::queue<NodeT *> nodeQueue;

    if (root == nullptr)
        return;

    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        std::cout << nodeQueue.front()->getData() << " ";

        if (nodeQueue.front()->getLeft() != nullptr)
            nodeQueue.push(nodeQueue.front()->getLeft());

        if (nodeQueue.front()->getRight() != nullptr)
            nodeQueue.push(nodeQueue.front()->getRight());

        nodeQueue.pop();
    }

    std::cout << std::endl;
}

void BST::print(int c)
{
    //1 - PreOrder
    //2 - InOrder
    //3 - PostOrder
    //5 - RecorridoNivel

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
        break;

    case 5:
        recorridoNivel();
        break;
    }

    std::cout << std::endl;
}

bool BST::ancestorsHelper(NodeT *r, int dato)
{
    bool inLeft, inRight;

    if (r == nullptr)
        return false;

    if (dato == r->getData())
        return true;

    if (dato < r->getData())
        inLeft = ancestorsHelper(r->getLeft(), dato);

    else
        inRight = ancestorsHelper(r->getRight(), dato);

    if (inLeft || inRight)
    {
        std::cout << r->getData() << std::endl;
        return true;
    }
    else
        return false;
}

void BST::ancestors(int dato)
{
    ancestorsHelper(root, dato);
}

int BST::heightHelper(NodeT *r)
{
    if (r == nullptr)
        return 0;

    int leftHeight = heightHelper(r->getLeft());
    int rightHeight = heightHelper(r->getRight());

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; 
}

int BST::height()
{
    heightHelper(root);
}

int BST::whatLevelamI(int dato)
{
    NodeT *current = root;

    int levelCounter = 0;

    while (current != nullptr)
    {
        if (current->getData() == dato)
        {
            return levelCounter;
        }

        current = (current->getData() > dato) ? current->getLeft() : current->getRight();
        levelCounter++;
    }

    return -1;
}
