#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    map<int, int> countMap;
    for( int i=0; i<A.size(); i++ ){
        ListNode* trav = A[i];
        while( trav != NULL ){

            auto it = countMap.find( trav->val );
            if( it != countMap.end() ){
                it->second++;
            } else {
                pair<int, int> pair1( trav->val, 1 );
                countMap.insert( pair1 );
            }

            trav = trav->next;

        }
    }

    ListNode* head = NULL;
    ListNode* trav = head;
    for( auto it = countMap.begin(); it != countMap.end(); it++ ){

        int count = it->second;
        while( count-- ){

            ListNode* newNode = new ListNode( it->first );

            if( trav == NULL ){
                trav = head = newNode;
            } else {
                trav->next = newNode;
            }

            trav = newNode;

        }
    }
    return head;

}

int main() {


    return 0;
}