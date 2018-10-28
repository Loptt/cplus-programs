
//METODO RECURSIVO. SE NECESITA AGREGAR LA FUNCION countChildrenSmaller a BST

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
