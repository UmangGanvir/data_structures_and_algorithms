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

Node* insertAtBeginning( Node* head, int data ){

    Node* newNode = new Node( data, NULL );

    if( head == NULL )
        return newNode;

    newNode->next = head;
    return newNode;
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

Node* insertAtPosition( Node* head, int position, int data ){

    Node* newNode = new Node( data, NULL );

    if( head == NULL )
        return newNode;

    if( position == 1 ){
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    while( position > 2 && temp->next != NULL ){
        temp = temp->next;
        position--;
    }

    Node* previousNodeAtPosition = temp->next;
    temp->next = newNode;
    newNode->next = previousNodeAtPosition;
    return head;
}

Node* deleteAtBeginning( Node* head ){

    if( head == NULL )
        return head;

    Node* newHead = head->next;
    delete head;
    return newHead;
}

Node* deleteAtEnd( Node* head ){

    if( head == NULL )
        return head;

    if( head->next == NULL ){
        delete head;
        return NULL;
    }

    Node* temp = head;
    while( temp->next->next != NULL ){
        temp = temp->next;
    }

    Node* toBeDeletedNode = temp->next;
    temp->next = temp->next->next;
    delete toBeDeletedNode;
    return head;
}

Node* deleteAtPosition( Node* head, int position ){

    if( head == NULL )
        return head;

    if( position == 1 ){
        Node* toBeDeletedNode = head;
        head = head->next;
        delete toBeDeletedNode;
        return head;
    }

    Node* temp = head;
    while( position > 2 ){
        temp = temp->next;
        position--;
    }

    Node* toBeDeletedNode = temp->next;
    if( temp->next != NULL ){
        temp->next = temp->next->next;
        delete toBeDeletedNode;
    }
    return head;
}

int main() {

    Node* head = NULL;

    /*
     * INSERTS
     * */

    head = insertAtBeginning( head, 1 );        // 1
    head = insertAtBeginning( head, 2 );        // 2 1
    head = insertAtBeginning( head, 3 );        // 3 2 1

//    printList( head );

    head = insertAtEnd( head, 4 );              // 3 2 1 4
    head = insertAtEnd( head, 5 );              // 3 2 1 4 5

//    printList( head );

    head = insertAtPosition( head, 1, 6 );      // 6 3 2 1 4 5
    head = insertAtPosition( head, 3, 7 );      // 6 3 7 2 1 4 5
    head = insertAtPosition( head, 8, 8 );      // 6 3 7 2 1 4 5 8

//    printList( head );

    /*
     * DELETION
     * */

    head = deleteAtBeginning( head );           // 3 7 2 1 4 5 8

//    printList( head );

    head = deleteAtEnd( head );                 // 3 7 2 1 4 5

//    printList( head );

    head = deleteAtPosition( head, 1 );         // 7 2 1 4 5
    head = deleteAtPosition( head, 3 );         // 7 2 4 5
    head = deleteAtPosition( head, 4 );         // 7 2 4

//    printList( head );

    return 0;
}