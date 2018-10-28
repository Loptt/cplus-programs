
//METODO RECURSIVO. SE NECESITA AGREGAR LA FUNCION checkValidChildren a BST

bool BST::checkValidChildren(NodeT *r)
{
    if (r == NULL)
        return true;

    bool valid = true;
    
    if (r->getLeft() != NULL)
        valid = r->getLeft()->getData() < r->getData();
    
    if (r->getRight() != NULL)
        valid = r->getRight()->getData() > r->getData() && valid;

    return checkValidChildren(r->getLeft()) && checkValidChildren(r->getRight()) && valid;
}

bool BST::check()
{
    return checkValidChildren(root);
}