#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

void levelOrderTraversal( TreeNode* root ){

    if( root == NULL )
        return;

    queue<TreeNode*> q;
    q.push( root );

    while( !q.empty() ){

        cout<<q.front()->val<<" ";
        if( q.front()->left != NULL )
            q.push( q.front()->left );
        if( q.front()->right != NULL )
            q.push( q.front()->right);
        q.pop();
    }
}

void inOrderTraversal( TreeNode* root ){

    if( root == NULL )
        return;

    inOrderTraversal( root->left );
    cout<<root->val<<" ";
    inOrderTraversal( root->right );
}

TreeNode* preOrderFill( TreeNode* A ){
    if( A == NULL )
        return NULL;

    if( A->left != NULL ) {

        TreeNode* rtSubTree = A->right;

        A->right = preOrderFill( A->left );

        TreeNode* trav = A->right;
        while( trav->right != NULL ){
            trav = trav->right;
        }
        trav->right = preOrderFill( rtSubTree );

    } else if( A->right != NULL ){
        A->right = preOrderFill( A->right );
    }
    A->left = NULL;
    return A;
}

TreeNode* flatten(TreeNode* A) {

    A = preOrderFill( A );
    return A;
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

    inOrderTraversal( flatten( root ) );

    return 0;
}