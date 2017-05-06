#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void printIntVector( vector<int> vec ){
    cout<<"Printing int vector: "<<endl;
    int n = (int) vec.size();
    for( int i=0; i<n; i++ )
        cout<<vec[i]<<" ";
    cout<<endl;
}

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

vector<int> preOrderTraversal( TreeNode* A ){
    vector<int> ans;

    if( A == NULL )
        return ans;

    stack<TreeNode*> s1;
    s1.push( A );

    while( !s1.empty() ){

        TreeNode* currNode = s1.top();
        ans.push_back( currNode->val );
        s1.pop();
        if( currNode->right != NULL )
            s1.push( currNode->right );
        if( currNode->left != NULL )
            s1.push( currNode->left );
    }

    return ans;
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

    printIntVector( preOrderTraversal( root ) );

    return 0;
}