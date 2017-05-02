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

/**
 * Level Order Traversal is same as 'BFS' in graphs!
 * */
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

/**
 * Pre Order Traversal is a 'DFS' strategy like in graphs!
 * */
void preOrderTraversal( Node* root ){

    if( root == NULL )
        return;

    cout<<root->data<<" ";
    preOrderTraversal( root->left );
    preOrderTraversal( root->right );
}

/**
 * In Order Traversal is a 'DFS' strategy like in graphs!
 * Also it's a sorted sequence!
 * */
void inOrderTraversal( Node* root ){

    if( root == NULL )
        return;

    inOrderTraversal( root->left );
    cout<<root->data<<" ";
    inOrderTraversal( root->right );
}

/**
 * Post Order Traversal is a 'DFS' strategy like in graphs!
 * */
void postOrderTraversal( Node* root ){

    if( root == NULL )
        return;

    postOrderTraversal( root->left );
    postOrderTraversal( root->right );
    cout<<root->data<<" ";
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

    cout<<"levelOrderTraversal: ";
    levelOrderTraversal( root );    // 10 7 15 8 12 9
    cout<<endl;

    cout<<"preOrderTraversal: ";
    preOrderTraversal( root );    // 10 7 8 9 15 12
    cout<<endl;

    cout<<"inOrderTraversal: ";
    inOrderTraversal( root );    // 7 8 9 10 12 15
    cout<<endl;

    cout<<"postOrderTraversal: ";
    postOrderTraversal( root );    // 9 8 7 12 15 10
    cout<<endl;

    return 0;
}