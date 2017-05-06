#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeUtil( int startIdx, int endIdx, vector<int>& A ){

    if( startIdx > endIdx ){
        return NULL;
    }

    if( startIdx == endIdx ){
        TreeNode* root = new TreeNode( A[startIdx] );
        return root;
    }

    int max = A[startIdx];
    int idxOfMax = startIdx;
    for( int i=startIdx; i<=endIdx; i++ ){
        if( A[i] > max ){
            max = A[i];
            idxOfMax = i;
        }
    }

    TreeNode* root = new TreeNode( max );
    root->left = buildTreeUtil( startIdx, idxOfMax-1, A );
    root->right = buildTreeUtil( idxOfMax+1, endIdx, A );
    return root;
}

TreeNode* buildTree(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    TreeNode* root = buildTreeUtil( 0, A.size()-1, A );
    return root;
}

void inOrderTraversal( TreeNode* root ){

    if( root == NULL )
        return;

    inOrderTraversal( root->left );
    cout<<root->val<<" ";
    inOrderTraversal( root->right );
}

int main() {

    vector<int> A = { 1, 2, 3 };
//    buildTree( A );
    inOrderTraversal( buildTree( A ) );
    return 0;
}