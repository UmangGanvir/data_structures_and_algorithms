#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

void levelOrderTraversal( Node* root ){

    if( root == NULL )
        return;

    queue<Node*> q;
    q.push( root );

    while( !q.empty() ){

        cout<<q.front()->data<<" ";
        if( q.front()->left != NULL )
            q.push( q.front()->left );
        if( q.front()->right != NULL )
            q.push( q.front()->right);
        q.pop();
    }
}

Node* findMinNode( Node* root ){
    if( root == NULL )
        return root;
    Node* trav = root;
    while( trav->left != NULL )
        trav = trav->left;
    return trav;
}

Node* deleteNode( Node* root, int data ){
    if( root == NULL )
        return root;

    if( data < root->data ) root->left = deleteNode( root->left, data );
    else if( data > root->data ) root->right = deleteNode( root->right, data );
    else {

        /* This node is to be deleted */

        if( root->left == NULL && root->right == NULL ){

            // Leaf node
            delete root;        // post this operation, root is a dangaling pointer
            root = NULL;
        } else if( root->right == NULL ){

            // only left subtree exists
            Node* toBeDeletedNode = root;
            root = root->left;
            delete toBeDeletedNode;
        } else if( root->left == NULL ){

            // only right subtree exists
            Node* toBeDeletedNode = root;
            root = root->right;
            delete toBeDeletedNode;
        } else {

            // both left and right subtree exist
            Node* minNode = findMinNode( root->right );
            root->data = minNode->data;
            root->right = deleteNode( root->right, minNode->data );
        }

    }
    return root;
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

    /* Test Cases */

    // 0 - Leaf Node - 12
    Node* node12 = findMinNode( root->right );
    root = deleteNode( root, node12->data );
    /*
     *          10
     *      7       15
     *       8
     *        9
     * */
    levelOrderTraversal( root );                    // 10 7 15 8 9
    cout<<endl;


    // 1 - Left subtree doesn't exist Node - 8
    Node* node7 = findMinNode( root->left );
    Node* node8 = node7->right;
    root = deleteNode( root, node8->data );
    /*
     *          10
     *      7       15
     *       9
     * */
    levelOrderTraversal( root );                    // 10 7 15 9
    cout<<endl;

    // 2 - Both left and right subtree exist Node - 10
    root = deleteNode( root, root->data );
    /*
     *          15
     *      7
     *       9
     * */
    levelOrderTraversal( root );                    // 15 7 9
    cout<<endl;

    return 0;
}