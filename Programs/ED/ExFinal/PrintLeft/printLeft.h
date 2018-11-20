void BST::printLeft()
{
    if (root == nullptr)
        return;

    queue<NodeT *> top;
    queue<NodeT *> bot;

    bool inTop = true;

    top.push(root);
    cout << root->getData() << " ";

    NodeT *curr;
    
    while(!top.empty() || !bot.empty())
    {
        if (inTop)
        {
            curr = top.front();
            if (curr->getLeft() != nullptr)
                bot.push(curr->getLeft());
            if(curr->getRight() != nullptr)
                bot.push(curr->getRight());

            top.pop();

            if (top.empty())
            {
                if (!bot.empty())
                    cout << bot.front()->getData() << " ";
                inTop = false;
            }
        }
        else
        {
            curr = bot.front();
            if (curr->getLeft() != nullptr)
                top.push(curr->getLeft());
            if(curr->getRight() != nullptr)
                top.push(curr->getRight());

            bot.pop();

            if (bot.empty())
            {
                if (!top.empty())
                    cout << top.front()->getData() << " ";
                inTop = true;
            }
        }
    }

    cout << endl;
}