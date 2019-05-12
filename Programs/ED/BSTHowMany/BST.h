#include "NodeT.h"

class BST {
    public:
        BST();
        ~BST();
        void add(int data);
        bool search(int data);
        void remove(int data);
        void print(int c);
        void ancestors(int data);
        int whatLevelamI(int data);
        int count();
        int height();

        int howManyAreSmallerThanME(int dato);

    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int pred(NodeT *r);
        int succ(NodeT *r);
        void preOrder(NodeT *r);
        void inOrder(NodeT *r);
        void postOrder(NodeT *r);
        void liberar(NodeT *r);
        void printLeaves(NodeT *r);
        void printLevelbyLevel();
        int cuenta(NodeT *r);
        int altura(NodeT *r);

        int countChildrenSmaller(NodeT* r, int dato);
};

BST::BST() {
    root = NULL;
}

BST::~BST(){
    liberar(root);
}

int BST::howManyChildren(NodeT *r){
    int c = 0;
    if (r->getLeft() != NULL){
        c++;
    }
    if (r->getRight() != NULL){
        c++;
    }
    return c;
}

int BST::pred(NodeT *r){
    NodeT *aux = r->getLeft();
    while (aux->getRight() != NULL){
        aux = aux->getRight();
    }
    return aux->getData();
}

int BST::succ(NodeT *r){
    NodeT *aux = r->getRight();
    while (aux->getLeft() != NULL){
        aux = aux->getLeft();
    }
    return aux->getData();
}

void BST::preOrder(NodeT *r){
    if (r != NULL){
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r){
    if (r != NULL){
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r){
    if (r != NULL){
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::liberar(NodeT *r){
    if (r != NULL){
        liberar(r->getLeft());
        liberar(r->getRight());
        delete r;
    }
}

void BST::printLeaves(NodeT *r){
    if (r != NULL){
        if (r->getLeft() == NULL && r->getRight() == NULL){
            cout << r->getData() << " ";
        } 
        else{
            printLeaves(r->getLeft());
            printLeaves(r->getRight());
        }
    }
}

void BST::printLevelbyLevel(){
    queue<NodeT*> fila;
    if (root != NULL){
        fila.push(root);
        NodeT *curr;
        while (!fila.empty()){
            curr = fila.front();
            fila.pop();
           cout << curr->getData() << " ";
            if (curr->getLeft() != NULL){
                fila.push(curr->getLeft());
            }
            if (curr->getRight() != NULL){
                fila.push(curr->getRight());
            }
        }
    }
}

void BST::add(int data) {
    NodeT *father = NULL;
    NodeT *curr = root;
    while(curr != NULL) {
        if(curr->getData() == data) {
            return;
        }
        father = curr;
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    if(father == NULL) {
        root = new NodeT(data);
    } else {
        if(father->getData() > data) {
            father->setLeft(new NodeT(data));
        } else {
            father->setRight(new NodeT(data));
        }
    }
}

bool BST::search(int data) {
    NodeT* curr = root;
    while(curr != NULL) {
        if(curr->getData() == data) {
            return true;
        }
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    return false;
}

void BST::ancestors(int data){
    NodeT* curr  = root;
    stack<int> pila;
    while (curr != NULL){
        if (curr->getData() == data){
            if (pila.empty()){
                cout << "NO EXITEN ANCESTROS"<<endl;
            }
            else{
                while (!pila.empty()){
                    cout << pila.top()<< " ";
                    pila.pop();
                }
                cout << endl;
            }
            return;
        }
        pila.push(curr->getData());
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    cout << "EL DATO NO EXISTE"<<endl;
}

int BST::whatLevelamI(int data){
    NodeT *curr = root;
    int nivel = 0;
    while (curr != NULL){
        if (curr->getData() == data){
            return nivel;
        }
        nivel++;
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();        
    }
    return -1;
}

void BST::remove(int data){
    NodeT *curr = root;
    NodeT *father = NULL;
    while (curr != NULL && curr->getData() != data){
        father = curr;
        curr = (curr->getData() > data) ?
                curr->getLeft() : curr->getRight();
    }
    if (curr == NULL){
        return;
    }
    int c = howManyChildren(curr);
    switch (c){
        case 0 : if (father == NULL){
                    root = NULL;
                }
                else{
                    if (father->getData() > data){
                        father->setLeft(NULL);
                    }
                    else{
                        father->setRight(NULL);
                    }
                }
                delete curr;
                break;
        case 1: if (father == NULL){
                    if (curr->getLeft() != NULL){
                        root = curr->getLeft();
                    }
                    else{
                        root = curr->getRight();
                    }
                }
                else{
                    if (father->getData() > data){
                        if (curr->getLeft() != NULL){
                            father->setLeft(curr->getLeft());
                        }
                        else{
                            father->setLeft(curr->getRight());
                        }
                    }
                    else{
                        if (curr->getLeft() != NULL){
                            father->setRight(curr->getLeft());
                        }
                        else{
                            father->setRight(curr->getRight());
                        }
                    }
                }
                delete curr;
                break;
        case 2: int x = succ(curr);
                remove(x);
                curr->setData(x);
                break;
        }

}

void BST::print(int c){
    switch(c){
        case 1: preOrder(root);
                break;
        case 2: inOrder(root);
                break;
        case 3: postOrder(root);
                break;
        case 4: printLeaves(root);
                break;
        case 5: printLevelbyLevel();
                break;
    }
    cout << endl;
}

int BST::count(){
    return cuenta(root);
}

int BST::cuenta(NodeT *r){
    if (r == NULL){
        return 0;
    }
    return 1+cuenta(r->getLeft())+cuenta(r->getRight());
}

int BST::height(){
    return altura(root);
}

int BST::altura(NodeT *r){
    if (r == NULL){
        return 0;
    }
    int izq = altura(r->getLeft());
    int der = altura(r->getRight());
    return 1 + (izq > der ? izq : der);
}

int BST::countChildrenSmaller(NodeT *r, int dato)
{
    if (r == NULL)
        return 0;

    if (r->getData() >= dato)
        return countChildrenSmaller(r->getLeft(), dato);
    
    return countChildrenSmaller(r->getLeft(), dato) + countChildrenSmaller(r->getRight(), dato) + 1;
}

int BST::howManyAreSmallerThanME(int dato)
{
    return countChildrenSmaller(root, dato);
}




