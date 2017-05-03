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

Node* findNode( Node* root, int data ){
    if( root == NULL )
        return root;
    if( root->data == data )
        return root;
    else if( data < root->data )
        return findNode( root->left, data );
    else
        return findNode( root->right, data );
}

Node* findMinNode( Node* root ){
    if( root == NULL )
        return NULL;
    Node* trav = root;
    while( trav->left != NULL )
        trav = trav->left;
    return trav;
}

Node* getSuccessor( Node* root, int data ){

    Node* currNode = findNode( root, data );
    if( currNode == NULL )
        return NULL;

    if( currNode->right != NULL ){
        return findMinNode( currNode->right );
    } else {

        Node* ancestor = root;
        Node* successor = NULL;
        while( ancestor != currNode ){
            if( data < ancestor->data ){
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
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
    cout<<"Inorder successor of 7: "<<getSuccessor( root, 7 )->data<<endl;
    cout<<"Inorder successor of 8: "<<getSuccessor( root, 8 )->data<<endl;
    cout<<"Inorder successor of 9: "<<getSuccessor( root, 9 )->data<<endl;
    cout<<"Inorder successor of 10: "<<getSuccessor( root, 10 )->data<<endl;
    cout<<"Inorder successor of 12: "<<getSuccessor( root, 12 )->data<<endl;
    if( getSuccessor( root, 15 ) )
        cout<<"Inorder successor of 15: "<<getSuccessor( root, 15 )->data<<endl;
    else
        cout<<"Inorder successor of 15: NULL"<<endl;

    return 0;
}