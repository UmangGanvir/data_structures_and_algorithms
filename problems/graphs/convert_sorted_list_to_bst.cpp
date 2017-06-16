#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* createBinaryFromSortedArr( int startIdx, int endIdx, vector<int>& A ){

    if( startIdx < 0 || endIdx >= A.size() || startIdx > endIdx )
        return NULL;

    if( startIdx == endIdx )
        return new TreeNode( A[startIdx] );

    int currRootIdx = startIdx + ( endIdx - startIdx )/2;
    TreeNode* currRootNode = new TreeNode( A[currRootIdx] );
    currRootNode->left = createBinaryFromSortedArr( startIdx, currRootIdx-1, A );
    currRootNode->right = createBinaryFromSortedArr( currRootIdx+1, endIdx, A );
    return currRootNode;
}

TreeNode* sortedListToBST(ListNode* A) {

    vector<int> Arr;

    ListNode* trav = A;
    while( trav != NULL ){
        Arr.push_back( trav->val );
        trav = trav->next;
    }

    return createBinaryFromSortedArr(0, (int) (Arr.size() - 1), Arr );
}

int main() {

    ListNode* startNode = new ListNode( 1 );
    startNode->next = new ListNode(2);
    startNode->next->next = new ListNode(3);
    startNode->next->next->next = new ListNode(4);
    startNode->next->next->next->next = new ListNode(5);

    sortedListToBST( startNode );

    return 0;
}