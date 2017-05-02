#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
    }
};

Node* insertRecursive( Node* root, int data ){
    if( root == NULL ){
        root = new Node( data );
    } else if( data <= root->data ){
        root->left = insertRecursive( root->left, data );
    } else {
        root->right = insertRecursive( root->right, data );
    }
    return root;
}

bool isValidBSTUtil( Node* root, int min, int max ){
    if( root == NULL )
        return true;

    if( root->data < min || root->data > max )
        return false;

    return isValidBSTUtil( root->left, min, root->data ) && isValidBSTUtil( root->right, root->data+1, max );
}

bool isValidBST( Node* root ){
    return isValidBSTUtil( root, numeric_limits<int>::min(), numeric_limits<int>::max() );
}

int main() {

    /*
     *          10
     *      7       15
     *       8    12
     *        9
     * */

    Node* root = NULL;
    root = insertRecursive( root, 10 );
    root = insertRecursive( root, 15 );
    root = insertRecursive( root, 12 );
    root = insertRecursive( root, 7 );
    root = insertRecursive( root, 8 );
    root = insertRecursive( root, 9 );

    if( isValidBST( root ) )
        cout<<"Binary Tree is valid a BST"<<endl;
    else
        cout<<"Binary Tree is NOT a valid BST"<<endl;

    return 0;
}