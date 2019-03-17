#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int height(TreeNode *r)
{
    if (r == nullptr)
        return 0;

    int leftHeight = height(r->left);
    int rightHeight = height(r->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int diameterH(TreeNode *r)
{
    if (r == nullptr)
        return 0;

    int diameter = height(r->left) + height(r->right);

    int leftDiameter = diameterH(r->left);
    int rightDiameter = diameterH(r->right);

    return ((diameter > leftDiameter) ? (diameter > rightDiameter ? diameter : rightDiameter)
     : (leftDiameter > rightDiameter ? leftDiameter : rightDiameter));
}

int diameterOfBST(TreeNode* r)
{
    return diameterH(r);
}

int main() {
    return 0;
}

