#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node( int data1, Node* nextNodePtr ){
        this->data = data1;
        this->next = nextNodePtr;
    }
};

void printList( Node* head ){
    cout<<"List is: ";
    while( head != NULL ){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertAtEnd( Node* head, int data ){

    Node* newNode = new Node( data, NULL );

    if( head == NULL )
        return newNode;

    Node* temp = head;
    while( temp->next != NULL ){
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

Node* reverseLL( Node* head ){

    if( head == NULL || head->next == NULL )
        return head;

    Node* trav = head;

    Node* newNextNode = NULL;
    Node* temp = head;

    while( trav->next != NULL ){
        temp = trav->next;
        trav->next = newNextNode;
        newNextNode = trav;
        trav = temp;
    }

    trav->next = newNextNode;
    return trav;
}

Node* reverseLLRecursive( Node* newNextNodePtr, Node* head ){

    if( head == NULL )
        return head;

    if( head->next == NULL ){
        head->next = newNextNodePtr;
        return head;
    }

    Node* temp = head->next;
    head->next = newNextNodePtr;
    return reverseLLRecursive( head, temp );
}

void printLLForwardRecursion( Node* head ){
    if( head != NULL ){
        cout<<head->data<<" ";
        printLLForwardRecursion( head->next );
    }
}

void printLLBackwardRecursion( Node* head ){

    if( head == NULL )
        return;

    printLLBackwardRecursion( head->next );
    cout<<head->data<<" ";
}

int main() {

    /*
     * Iteration - Forward
     * */

    Node* emptyElemLLHead = NULL;
    Node* oneElemLLHead = new Node( 1, NULL );
    Node* twoElemLLHead = new Node( 1, new Node( 2, NULL ) );

    Node* nElemLL = new Node( 1, new Node( 2, NULL ) );
    nElemLL = insertAtEnd( nElemLL, 3 );
    nElemLL = insertAtEnd( nElemLL, 4 );
    nElemLL = insertAtEnd( nElemLL, 5 );

//    Node* reversedEmptyLLHead = reverseLL( emptyElemLLHead );
//    printList( reversedEmptyLLHead );                           // empty
//
//    Node* reversedOneElemLLHead = reverseLL( oneElemLLHead );
//    printList( reversedOneElemLLHead );                         // 1
//
//    Node* reversedTwoElemLLHead = reverseLL( twoElemLLHead );
//    printList( reversedTwoElemLLHead );                         // 2 1
//
//    Node* reversedNElemLLHead = reverseLL( nElemLL );
//    printList( reversedNElemLLHead );                           // 5 4 3 2 1

//    cout<<"Forward List is: ";
//    printLLForwardRecursion( nElemLL );
//    cout<<endl;

//    cout<<"Backward List is: ";
//    printLLBackwardRecursion( nElemLL );
//    cout<<endl;

    Node* reversedEmptyLLHead = reverseLLRecursive( NULL, emptyElemLLHead );
    printList( reversedEmptyLLHead );                           // empty

    Node* reversedOneElemLLHead = reverseLLRecursive( NULL, oneElemLLHead );
    printList( reversedOneElemLLHead );                         // 1

    Node* reversedTwoElemLLHead = reverseLLRecursive( NULL, twoElemLLHead );
    printList( reversedTwoElemLLHead );                         // 2 1

    Node* reversedNElemLLHead = reverseLLRecursive( NULL, nElemLL );
    printList( reversedNElemLLHead );                           // 5 4 3 2 1


    return 0;
}