#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void invertTreeUtil( TreeNode* root ){
    if( root == NULL )
        return;
    TreeNode* left = root->left;
    root->left = root->right;
    root->right = left;
    invertTreeUtil( root->left );
    invertTreeUtil( root->right );
}

TreeNode* invertTree(TreeNode* root) {
    invertTreeUtil( root );
    return root;
}

int main() {

    //
    return 0;
}