#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseLLUtil( ListNode* newNextNodePtr, ListNode* head ){

    if( head == NULL )
        return newNextNodePtr;

    ListNode* next = head->next;
    head->next = newNextNodePtr;
    return reverseLLUtil( head, next );
}

int main() {


    return 0;
}