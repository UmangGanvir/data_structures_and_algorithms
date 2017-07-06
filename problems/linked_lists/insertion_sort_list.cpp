#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList( ListNode* head ){
    cout<<"List is: ";
    while( head != NULL ){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* insertInSortedList( ListNode* head, ListNode* node ){

    // assume node to be new node
    node->next = NULL;

    if( head == NULL ){
        return node;
    }

    ListNode* trav = head;
    ListNode* prev = NULL;

    bool inserted = false;

    while( trav != NULL && !inserted ){

        ListNode* next = trav->next;

        if( trav->val > node->val ){

            if( trav == head ){
                head = node;
                node->next = trav;
                trav = node;
            } else {
                prev->next = node;
                node->next = trav;
                trav = node;
            }
            inserted = true;
        }

        prev = trav;
        trav = trav->next;
    }

    if( !inserted ){
        prev->next = node;
    }
    return head;
}

ListNode* insertionSortList(ListNode* A) {

    if( A == NULL || A->next == NULL )
        return A;

    ListNode* head = A;
    ListNode* trav = A->next;
    ListNode* prev = A;

    while( trav != NULL ){
        ListNode* next = trav->next;

        prev->next = NULL;
        head = insertInSortedList( head, trav );
        ListNode* lastNodeInSortedList = head;
        while( lastNodeInSortedList->next != NULL ){
            lastNodeInSortedList = lastNodeInSortedList->next;
        }
        lastNodeInSortedList->next = next;

        prev = lastNodeInSortedList;
        trav = next;
    }

    return head;
}

int main() {

    ListNode* listNode1 = new ListNode(1);
    ListNode* listNode2 = new ListNode(2);
    ListNode* listNode3 = new ListNode(3);
    ListNode* listNode4 = new ListNode(4);

    ListNode* head = listNode1;
    listNode1->next = listNode3;
    listNode3->next = listNode4;
    listNode4->next = listNode2;

    // 1 -> 3 -> 4 -> 2

    cout<<"Sorted List --- "<<endl;
    printList( insertionSortList(head) );
    // 1 -> 2 -> 3 -> 4

    return 0;
}