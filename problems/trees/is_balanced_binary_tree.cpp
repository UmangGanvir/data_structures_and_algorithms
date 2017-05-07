#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertRecursive( TreeNode* root, int data ){
    if( root == NULL ){
        root = new TreeNode( data );
    } else if( data <= root->val ){
        root->left = insertRecursive( root->left, data );
    } else {
        root->right = insertRecursive( root->right, data );
    }
    return root;
}

int height1( TreeNode* root, unordered_map<TreeNode*, int>& nodeHeightMap ){
    if( root == NULL )
        return -1;

    int height = -1;

    auto htIt = nodeHeightMap.find( root );
    if( htIt != nodeHeightMap.end() ){
        height = htIt->second;
    } else {
        height = 1 + max( height1( root->left, nodeHeightMap ), height1( root->right, nodeHeightMap ) );
        pair<TreeNode*,int> pair1( root, height );
        nodeHeightMap.insert( pair1 );
    }

    cout<<"node - "<<root->val<<" has height: "<<height<<endl;

    return height;
}

bool isBalancedUtil( TreeNode* root, unordered_map<TreeNode*, int>& nodeHeightMap ){
    if( root == NULL )
        return true;

    int leftHeight = height1( root->left, nodeHeightMap );
    int rightHeight = height1( root->right, nodeHeightMap );

    if( abs( leftHeight - rightHeight ) > 1 )
        return false;

    return isBalancedUtil( root->left, nodeHeightMap ) && isBalancedUtil( root->right, nodeHeightMap );
}

int isBalanced(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<TreeNode*, int> nodeHeightMap;
    return isBalancedUtil( A, nodeHeightMap );
}

int main() {

    /*
     *          10
     *      7       15
     *       8    12
     *        9
     * */

    TreeNode* root = NULL;
    root = insertRecursive( root, 10 );
    root = insertRecursive( root, 15 );
    root = insertRecursive( root, 12 );
    root = insertRecursive( root, 7 );
    root = insertRecursive( root, 8 );
    root = insertRecursive( root, 9 );

    cout<<"Tree is "<<( isBalanced( root ) ? "Balanced" : "NOT Balanced" )<<endl;
    return 0;
}