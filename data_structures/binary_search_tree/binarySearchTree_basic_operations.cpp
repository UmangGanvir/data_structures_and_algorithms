#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

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

Node* insert( Node* root, int data ){
    if( root == NULL ){
        return new Node( data );
    } else {
        Node* trav = root;
        while( 1 ){
            if( data <= trav->data ){

                // left traversal
                if( trav->left == NULL ){
                    trav->left = new Node(data);
                    break;
                } else {
                    trav = trav->left;
                }

            } else {

                // right traversal
                if( trav->right == NULL ){
                    trav->right = new Node(data);
                } else {
                    trav = trav->right;
                }

            }
        }
    }
}

bool searchRecursive( Node* root, int data ){
    if( root == NULL )
        return false;
    if( root->data == data )
        return true;

    if( data < root->data ){
        return searchRecursive( root->left, data );
    } else {
        return searchRecursive( root->right, data );
    }
}

bool search( Node* root, int data ){

    if( root == NULL )
        return false;

    Node* trav = root;
    while( trav != NULL ){

        if( trav->data == data )
            return true;

        if( data <= trav->data ){
            trav = trav->left;
        } else {
            trav = trav->right;
        }
    }
    return false;
}

int main() {

    /*
     *          10
     *      7       15
     *       8    12
     * */

    // Recursive Implementations

    Node* root = NULL;
    root = insertRecursive( root, 10 );
    root = insertRecursive( root, 15 );
    root = insertRecursive( root, 12 );
    root = insertRecursive( root, 7 );
    root = insertRecursive( root, 8 );

    cout<<"8 was recursively "<<(searchRecursive( root, 8 ) ? "found!" : "not found!")<<endl;
    cout<<"25 was recursively "<<(searchRecursive( root, 25 ) ? "found!" : "not found!")<<endl;

    // Iterative Implementations
    Node* root2 = NULL;
    root2 = insert( root2, 10 );
    root2 = insert( root2, 15 );
    root2 = insert( root2, 12 );
    root2 = insert( root2, 7 );
    root2 = insert( root2, 8 );

    cout<<"8 was iteratively "<<(search( root2, 8 ) ? "found!" : "not found!")<<endl;
    cout<<"25 was iteratively "<<(search( root2, 25 ) ? "found!" : "not found!")<<endl;

    return 0;
}