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

void inOrderTrav( TreeNode* root, int& currIdx, int k, int& ans ){

    if( root == NULL )
        return;

    inOrderTrav( root->left, currIdx, k, ans );
    currIdx++;
    if( currIdx == k ){
        ans = root->val;
        return;
    }
    inOrderTrav( root->right, currIdx, k, ans );
}

int kthsmallest( TreeNode* root, int k ){

    int currIdx = 0;
    int ans = -1;
    inOrderTrav( root, currIdx, k, ans );
    return ans;
}

int main() {

    //
    return 0;
}