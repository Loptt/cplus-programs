#include <iostream>
#include <queue>
#include "Node.h"

class BST
{
  public:
    BST();
    ~BST();

    BST(const BST &a2);

    void add(int data);
    bool search(int data);
    void remove(int data);

    void print(int c);

    int height();
    void ancestors(int dato);
    int whatLevelamI(int dato);

    int maxWidth();
    int nearestRelative(int d1, int d2);

    bool operator==(BST tree);

    void mirror();

    int count();

  private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);

    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void printLeaves(NodeT *r);
    void recorridoNivel();

    bool ancestorsHelper(NodeT *r, int dato);
    int heightHelper(NodeT *r);

    void libera(NodeT *r);

    bool isIdentical(NodeT *r, NodeT *r2);

    void swapChildren(NodeT *r);
    int cuenta(NodeT *);

    void createChildren(NodeT*, NodeT*);
};

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    libera(root);
}

void BST::createChildren(NodeT *rOld, NodeT *rNew)
{
    if (rOld == nullptr)
        return;

    if (rOld->getLeft() != nullptr)
        rNew->setLeft(new NodeT(rOld->getLeft()->getData()));

    if (rOld->getRight() != nullptr)
        rNew->setRight(new NodeT(rOld->getRight()->getData()));

    createChildren(rOld->getLeft(), rNew->getLeft());
    createChildren(rOld->getRight(), rNew->getRight());
}

BST::BST(const BST &tree)
{
    if (tree.root == nullptr)
    {
        root = nullptr;
        return;
    }

    root = new NodeT(tree.root->getData());

    createChildren(tree.root, root);
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

void BST::printLeaves(NodeT *r)
{
    if (r != nullptr)
    {
        if (r->getRight() == nullptr && r->getLeft() == nullptr)
        {
            std::cout << r->getData() << " ";
        }
        else
        {
            printLeaves(r->getLeft());
            printLeaves(r->getRight());
        }
    }
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

    case 4:
        printLeaves(root);

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

int BST::maxWidth()
{
    /* std::queue<NodeT *> nodeQueue;

    if (root == nullptr)
        return 0;

    int maxWidth = 0;
    int currMaxWidth = 1;

    NodeT *nextLevel = root;
    bool leftExists = false;
    bool rightExists = false;

    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        leftExists = nodeQueue.front()->getLeft() != nullptr;
        rightExists = nodeQueue.front()->getRight() != nullptr;

        if (nodeQueue.front() == nextLevel)
        {
            if (leftExists)
                nextLevel = nodeQueue.front()->getLeft();
            else if (rightExists)
                nextLevel = nodeQueue.front()->getRight();
            else
                nextLevel = nullptr;

            if (currMaxWidth > maxWidth)
                maxWidth = currMaxWidth;

            currMaxWidth = 0;
        }

        if (nodeQueue.front()->getLeft() != nullptr)
            nodeQueue.push(nodeQueue.front()->getLeft());

        if (nodeQueue.front()->getRight() != nullptr)
            nodeQueue.push(nodeQueue.front()->getRight());

        nodeQueue.pop();
        currMaxWidth++;
    }

    return maxWidth; */

    std::queue<NodeT *> topQueue;
    std::queue<NodeT *> botQueue;

    if (root == nullptr)
        return 0;

    int maxWidth = 1;

    int widthCounter = 0;

    topQueue.push(root);

    bool onTop = true;

    while(!topQueue.empty() || !botQueue.empty())
    {
        if (onTop)
        {
            if (topQueue.front()->getLeft() != nullptr)
                botQueue.push(topQueue.front()->getLeft());
            
            if (topQueue.front()->getRight() != nullptr)
                botQueue.push(topQueue.front()->getRight());

            topQueue.pop();

            widthCounter++;

            if (topQueue.empty())
            {
                if (widthCounter > maxWidth)
                    maxWidth = widthCounter;
                
                onTop = false;
                widthCounter = 0;
            }
        }
        else
        {
            if (botQueue.front()->getLeft() != nullptr)
                topQueue.push(botQueue.front()->getLeft());
            
            if (botQueue.front()->getRight() != nullptr)
                topQueue.push(botQueue.front()->getRight());

            botQueue.pop();

            widthCounter++;

            if (botQueue.empty())
            {
                if (widthCounter > maxWidth)
                    maxWidth = widthCounter;
                
                onTop = true;
                widthCounter = 0;
            }
        }
    }

    return maxWidth;
}

int BST::nearestRelative(int d1, int d2)
{
    if (d1 == d2)
        return d1;

    NodeT *current = root;
    NodeT *prev = root;

    while (current != nullptr)
    {
        if (!((current->getData() > d1 && current->getData()) > d2 || (current->getData() < d1 && current->getData() < d2)))
        {
            if (current->getData() == d1 || current->getData() == d2)
                return prev->getData();

            return current->getData();
        }

        prev = current;
        current = (current->getData() > d1) ? current->getLeft() : current->getRight();
    }

    return -1;
}

bool BST::isIdentical(NodeT *r1, NodeT *r2)
{
    if (r1 == nullptr && r2 == nullptr)
        return true;

    if ((r1 == nullptr && r2 != nullptr) || r1 != nullptr && r2 == nullptr)
        return false;

    if (r1->getData() != r2->getData())
        return false;

    return isIdentical(r1->getLeft(), r2->getLeft()) && isIdentical(r1->getRight(), r2->getRight());
}

bool BST::operator==(BST tree2)
{
    return isIdentical(root, tree2.root);
}

void BST::swapChildren(NodeT *r)
{
    if (r == nullptr)
        return;

    swapChildren(r->getLeft());
    swapChildren(r->getRight());

    NodeT *temp = r->getLeft();
    r->setLeft(r->getRight());
    r->setRight(temp);
}

void BST::mirror()
{
    swapChildren(root);
}
